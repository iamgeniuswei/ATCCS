#include "atccsdevicecontroller.h"
#include "atccsdatasender.h"
#include "atccspublicstatus.h"
#include "atccsinstruction.h"
#include <iostream>
#include "atccsonline.h"
#include "atccs_global.h"
#include "atccsdata.h"
#include <thread>
#ifdef DATAPERSISTENCE
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
using namespace odb::core;
#endif
#include "atccsaddress.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"


unsigned int ATCCSDeviceController::INSTRUCTION_TIMEOUT = 5;
unsigned int ATCCSDeviceController::INSTRUCTION_RETRANSMISSION = 3;

ATCCSDeviceController::ATCCSDeviceController(unsigned short at, unsigned short device)
: _at(at), _device(device)
{

}

ATCCSDeviceController::~ATCCSDeviceController()
{
#ifdef OUTDEBUGINFO
    std::cout << "~ATCCSDeviceController" << std::endl;
#endif
}

void ATCCSDeviceController::run()
{
    while (!stop())
    {
        try
        {
            //fetch a raw data of the instruction from the instruction queue.
            std::shared_ptr<ATCCSData> data = popControlData();
            //the queue returns per 1 second, so sometimes there is no data.
            if (data == nullptr)
                continue;
            
            executeInstruction(data);

        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
        }
    }
}

void ATCCSDeviceController::executeInstruction(std::shared_ptr<ATCCSData> data)
{    
    _isExecutoryInstructionDone = false;
    //Only the instruction is all right, and the parameters are validated,
    //the instruction can be sent to according device.
    unsigned int ret = atccsinstruction::INSTRUCTION_UNKOWNN;
    ret = setExecutoryInstruction(data);
    if (ret == atccsinstruction::INSTRUCTION_PASS)
    {
        int size = sendInstruction(data);
        if (size == data->size())
        {
#ifdef OUTDEBUGINFO
            std::cout << "AT: " << _at << " Device: " << _device << " Instruction: " << _executoryInstruction->instruction() << " has been sent to device correctly." << std::endl;
#endif
            waitInstructionResult();
        }
        else
        {
#ifdef OUTERRORINFO
            char msg[256] = {0};
            snprintf(msg, 256, "%s%d%s%d%s%d%s", "AT: ", _at, " Device: ", _device, " instruction: ", _executoryInstruction->instruction(), " is failed to be sent. The instruction is neglected.");
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, msg);
#endif
        }
    }
    _isExecutoryInstructionDone = true;
}





/**
 * send the raw instruction data to the target device.
 * if fails to send, automatically resend the data up
 * to 3 times, if still fails, return.
 * @param data The raw instruction data waiting to send.
 * @return the size of data has been sent.
 */
int ATCCSDeviceController::sendInstruction(std::shared_ptr<ATCCSData> data)
{
    int ret = 0;
    if (_instructionSender)
    {
        for (int i = 0; i < INSTRUCTION_RETRANSMISSION; i++)
        {
            if (data)
                ret = _instructionSender->sendData(data);
            if (ret == data->size())
                break;
            else
                continue;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, _device,
                                            "ATCCSDataSender instance is null, fails to send instruction.");
#endif
    }
    return ret;
}

/**
 * wait the instruction's result.
 */
void ATCCSDeviceController::waitInstructionResult()
{
    //There are 2 phases in the process of waiting instruction result.    
    if (_executoryInstruction)
    {
        //phase 1: wait the feedback of the instruction from the device.
        //  1) RESULT_EXECUTING,         // =1
        //  2) RESULT_PARAMOUTOFRANGE, // =2
        //  3) RESULT_CANNTEXECUTE,    // =3
        auto base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        while (_executoryInstruction->result() == atccsinstruction::RESULT_WAITINGTOEXECUTE)
        {
            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            if ((now - base) > INSTRUCTION_TIMEOUT)
                break;
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);
        }

        //phase 2: if the feedback is RESULT_EXECUTING, wait the device's status.
        if (_executoryInstruction->result() == atccsinstruction::RESULT_EXECUTING)
        {
            _timeout = _executoryInstruction->timeout();
            base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

            //The device's feedback contains the instruction's timeout
            //here, the waiting time changes from INSTRUCTION_TIMEOUT to timeout.
            while (!isExecutoryInstructionOK())
            {
                auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                if ((now - base) > _executoryInstruction->timeout())
                    break;
                std::chrono::milliseconds dura(1000);
                std::this_thread::sleep_for(dura);
            }
            if (isExecutoryInstructionOK())
            {
#ifdef DATAPERSISTENCE
                try
                {
                    _executoryInstruction->setResult(atccsinstruction::RESULT_SUCCESS);
                    _executoryInstruction->persistInstructionResult();
                }
                catch (std::exception &e)
                {
#ifdef OUTERRORINFO 
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
                }
#endif
                _isExecutoryInstructionSuccess = true;
                std::cout << "AT: " << _at << " Device: " << _device << " Instruction: " << _executoryInstruction->instruction() << " is success." << std::endl;
            }
            else
            {
#ifdef DATAPERSISTENCE
                try
                {
                    _executoryInstruction->setResult(atccsinstruction::RESULT_TIMEOUT);
                    _executoryInstruction->persistInstructionResult();
                }
                catch (std::exception &e)
                {
#ifdef OUTERRORINFO 
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
                }
#endif
#ifdef OUTERRORINFO
                char msg[256] = {0};
                snprintf(msg, 256, "%s%d%s%d%s%d%s", "AT: ", _at, " Device: ", _device, " Instruction: ", _executoryInstruction->instruction(), " is time out. The instruction is neglected.");
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                    __FILE__, __func__, __LINE__, msg);
#endif
            }
        }
        else
        {
#ifdef DATAPERSISTENCE
            try
            {
                _executoryInstruction->setResult(atccsinstruction::RESULT_NOFEEDBACK);
                _executoryInstruction->persistInstructionResult();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO 
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                    __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
            }
#endif
#ifdef OUTERRORINFO
            char msg[256] = {0};
            snprintf(msg, 256, "%s%d%s%d%s%d%s", "AT : ", _at, " Device : ", _device, " instruction: ", _executoryInstruction->instruction(), " 's feedback is time out. The instruction is neglected.");
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, msg);
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, _device,
                                            "atccsinstruction instance is null, fails to wait instruction result.");
#endif
    }
}

unsigned int ATCCSDeviceController::timeout()
{
    return _timeout;
}

bool ATCCSDeviceController::isExecutoryInstructionSuccess(unsigned int instruction) const
{
    if (_executoryInstruction)
    {
        std::lock_guard<std::mutex> lk(_instructionLock);
        return (_executoryInstruction->instruction() == instruction) 
                && (_executoryInstruction->result() == atccsinstruction::RESULT_SUCCESS);
    }
    else
    {

    }
    return false;
}

/**
 * decide whether to execute instruction.
 * @return true if can, false if can not.
 */
bool ATCCSDeviceController::canExecuteInstruction() const
{
    bool ret = false;
    ret = isOnline() && isStatusOK();
    return ret;
}

bool ATCCSDeviceController::isStatusOK() const
{
    return true;
}

bool ATCCSDeviceController::isExecutoryInstructionOK()
{
    return true;
}

bool ATCCSDeviceController::isExecutoryInstructionOK(unsigned int instruction)
{
    return true;
}

std::shared_ptr<atccsinstruction> ATCCSDeviceController::instructionInstance()
{
    return nullptr;
}

std::shared_ptr<atccspublicstatus> ATCCSDeviceController::statusInstance()
{
    return nullptr;
}

/**
 * set the Device's real-time status according to raw status data 
 * encapsulated in ATCCSData.
 * @param data, raw status data.
 */
void ATCCSDeviceController::setRealtimeStatus(std::shared_ptr<ATCCSData> data)
{
    if(_realtimeStatus == nullptr)
    {
        //here, we can not define _realtimeStatus directly.
        //atccspublicstatus will be persisted in database,
        //so we have to create a concrete sub-class instance
        //of atccspublicstaus.
        try
        {
            _realtimeStatus = statusInstance();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
            return;
        }
    }
    
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        _realtimeStatus->setStatus(data);
#ifdef DATAPERSISTENCE
        _realtimeStatus->persistStatus();
#endif
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif        
    }
}

/**
 * set the executory instruction according to raw instruction data
 * encapsulated in ATCCSData.
 * @param data, raw instruction data.
 * @return INSTRUCTION_PASS if successes, else fails.
 */
unsigned int ATCCSDeviceController::setExecutoryInstruction(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = atccsinstruction::INSTRUCTION_UNKOWNN;
    if (_executoryInstruction == nullptr)
    {
        _executoryInstruction = instructionInstance();
    }
    if (_executoryInstruction)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_instructionLock);
            ret = _executoryInstruction->setInstructionValue(data);
            if (ret == atccsinstruction::INSTRUCTION_PASS)
            {
                _executoryInstructionRawData = data;
                _isExecutoryInstructionSuccess = false;
#ifdef DATAPERSISTENCE
                try
                {
                    _executoryInstruction->persistInstruction();
                }
                catch (std::exception &e)
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif                    
                }                
#endif
                
#ifdef OUTDEBUGINFO
                _executoryInstruction->out();
#endif                
            }
            else if (ret == atccsinstruction::INSTRUCTION_PARAMOUTOFRANGE)
            {
#ifdef DATAPERSISTENCE
                try
                {
                    _executoryInstruction->persistInstruction();
                }
                catch (std::exception &e)
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
                }
#endif
#ifdef OUTERRORINFO
                char msg[256] = {0};
                snprintf(msg, 256, "%s%d%s%d%s%d%s", "AT: ", _at, " Device: ", _device, " instruction: ", _executoryInstruction->instruction(), " parameter out of range. The instruction is neglected.");
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                    __FILE__, __func__, __LINE__, msg);
#endif
                _executoryInstruction->reset();
                _isExecutoryInstructionSuccess = false;
            }
            else
            {
#ifdef OUTERRORINFO
                char msg[256] = {0};
                snprintf(msg, 256, "%s%d%s%d%s", "AT id: ", _at, " Device id: ", _device, " an instruction's size is error.  The instruction is neglected.");
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                    __FILE__, __func__, __LINE__, msg);
#endif
                _executoryInstruction->reset();
                _isExecutoryInstructionSuccess = false;
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif
        }
    }
    return ret;
}

/**
 * set the executory instruction's result according to raw instruction's
 * raw data encapsulated in ATCCSData.
 * @param data, raw instruction's result data.
 */
void ATCCSDeviceController::setExecutoryInstructionResult(std::shared_ptr<ATCCSData> data)
{
    if (_executoryInstruction)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_instructionLock);
            unsigned int ret = _executoryInstruction->setInstructionResult(data);
            if (ret == atccsinstruction::RESULT_EXECUTING)
            {
#ifdef DATAPERSISTENCE
                _executoryInstruction->persistInstructionResult();
#endif
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, _device,
                                            "atccsinstruction instance is null, fails to set instruction result.");
#endif        
    }
}

/**
 * set the device's address.
 * @param ip    std::string
 * @param port  unsigned short
 */
void ATCCSDeviceController::setDeviceAddress(const std::string &ip, unsigned short port)
{
    if (_instructionSender == nullptr)
    {
        try
        {
            _instructionSender = std::make_shared<ATCCSDataSender>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif  
            return;
        }
    }

    if (_instructionSender)
    {
        _instructionSender->setTargetAddress(ip, port);
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, _device, 
                                            "ATCCSDataSender instance is null, fails to setTargetAddress.");
#endif        
    }
}

/**
 * set the device's address
 * @param address   std::shared_ptr<ATCCSAddress>
 */
void ATCCSDeviceController::setDeviceAddress(std::shared_ptr<ATCCSAddress> address)
{
    if (address)
    {
        setDeviceAddress(address->ip(), address->port());
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, _device,
                                            "The source ATCCSAddress is null, fails to setDeviceAddress.");
#endif        
    }
}

/**
 * set device real-time online status.
 * @param online bool
 * @param time  unsigned int
 */
void ATCCSDeviceController::setRealtimeOnline(bool online, unsigned int time)
{
    if(_realtimeOnline == nullptr)
    {
        try
        {
            _realtimeOnline = std::make_shared<ATCCSOnline>();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, _device, e.what());
#endif            
            return;
        }
    }

    if (_realtimeOnline)
    {
        _realtimeOnline->setOnline(online, time);
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, _device,
                                            "ATCCSOnline instance is null, fails to setRealtimeOnline.");
#endif
    }
}

/**
 * query the device online or not.
 * @return true if device is online, false if offline.
 */
bool ATCCSDeviceController::isOnline() const
{
    if(_realtimeOnline)
    {
        try
        {
            return _realtimeOnline->online();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, _at, _device, e.what());            
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, _at, _device,
                                                "ATCCSOnline instance is null, fails to execute isOnline.");
#endif        
    }
    return false;
}

bool ATCCSDeviceController::canExecutePlan()
{
    return true;
}

unsigned int ATCCSDeviceController::at() const
{
    return _at;
}

unsigned int ATCCSDeviceController::device() const
{
    return _device;
}

bool ATCCSDeviceController::isExecutoryInstructionFinished(unsigned int instructon) const
{
    if(_executoryInstruction)
    {
        return (_executoryInstruction->instruction() == instructon) && _isExecutoryInstructionDone;
    }
    else
    {
        
    }
    return false;
}
