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

//

unsigned int ATCCSDeviceController::INSTRUCTION_TIMEOUT = 30;
unsigned int ATCCSDeviceController::INSTRUCTION_RETRANSMISSION = 3;

ATCCSDeviceController::ATCCSDeviceController(unsigned short id)
: _id(id)
{

}

ATCCSDeviceController::~ATCCSDeviceController()
{
#ifdef OUTDEBUGINFO
    std::cout << "~ATCCSDeviceController\n";
#endif
}

void ATCCSDeviceController::run()
{
    while (!stop())
    {
        try
        {
            //fetch a raw data of the instruction from the instruction queue.
            std::shared_ptr<ATCCSData> data = _fifoQueue.wait_and_pop();
            //the queue returns per 1 second, so sometimes there is no data.
            if (data == nullptr)
                continue;
            //            setCurrentInstruction(data);
            unsigned int ret = atccsinstruction::INSTRUCTION_UNKOWNN;
            ret = setExecutoryInstruction(data);
            if (ret == atccsinstruction::INSTRUCTION_PASS)
            {
                int size = sendInstruction(data);
                if (size == data->size())
                {
                    waitInstructionResult();
                }
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());

#endif
        }
    }
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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
    return ret;
}

/**
 * wait the instruction's result.
 */
void ATCCSDeviceController::waitInstructionResult()
{
    auto base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    if (_executoryInstruction)
    {
        while (_executoryInstruction->result() == atccsinstruction::RESULT_WAITINGTOEXECUTE)
        {
            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            if ((now - base) > INSTRUCTION_TIMEOUT)
                break;
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);
        }
        if (_executoryInstruction->result() == atccsinstruction::RESULT_EXECUTING)
        {
            _timeout = _executoryInstruction->timeout();
            base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
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
                _executoryInstruction->setResult(atccsinstruction::RESULT_SUCCESS);
                _executoryInstruction->persistInstructionResult();
#endif
                std::cout << "Executory Instruction OK" << std::endl;
            }
            else
            {
#ifdef DATAPERSISTENCE
                _executoryInstruction->setResult(atccsinstruction::RESULT_TIMEOUT);
                _executoryInstruction->persistInstructionResult();
#endif
                std::cout << "Executory Instruction Timeout" << std::endl;
            }
        }
        else
        {
#ifdef DATAPERSISTENCE
            _executoryInstruction->setResult(atccsinstruction::RESULT_TIMEOUT);
            _executoryInstruction->persistInstructionResult();
#endif
            std::cout << "Executory Instruction Timeout" << std::endl;
        }
    }
    else
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
}

unsigned int ATCCSDeviceController::timeout()
{
    return _timeout;             
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
    try
    {
        if (!_realtimeStatus)
            _realtimeStatus = statusInstance();
        if (_realtimeStatus)
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            _realtimeStatus->setStatus(data);
#ifdef DATAPERSISTENCE
            _realtimeStatus->persistStatus();
#endif
        }
        else
        {
#ifdef OUTDEBUGINFO
            //FIXME:
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif        
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
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
    try
    {
        if (!_executoryInstruction)
            _executoryInstruction = instructionInstance();
        if (_executoryInstruction)
        {
            std::lock_guard<std::mutex> lk(_instructionLock);
            ret = _executoryInstruction->setInstructionValue(data);
            if (ret == atccsinstruction::INSTRUCTION_PASS)
            {
                _executoryInstructionRawData = data;
#ifdef DATAPERSISTENCE
                _executoryInstruction->persistInstruction();
#endif
                _executoryInstruction->out();
            }
            else if (ret == atccsinstruction::INSTRUCTION_PARAMOUTOFRANGE)
            {
#ifdef DATAPERSISTENCE
                _executoryInstruction->persistInstruction();
#endif
            }
            else
            {
#ifdef OUTDEBUGINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                    __FILE__, __func__, __LINE__, "");
#endif
            }
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
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
    try
    {
        if (_executoryInstruction)
        {
            std::lock_guard<std::mutex> lk(_instructionLock);
            unsigned int ret = _executoryInstruction->setInstructionResult(data);
#ifdef DATAPERSISTENCE
            if (ret == atccsinstruction::RESULT_EXECUTING)
                _executoryInstruction->persistInstructionResult();
#endif
        }
        else
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif        
    }
}

/**
 * set the device address.
 * @param ip
 * @param port
 */
void ATCCSDeviceController::setDeviceAddress(const std::string &ip, unsigned short port)
{
    try
    {
        if (!_instructionSender)
            _instructionSender = std::make_shared<ATCCSDataSender>();
        if (_instructionSender)
        {
            _instructionSender->setTargetAddress(ip, port);
        }
        else
        {
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__,
                                                "");
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }

}

void ATCCSDeviceController::setDeviceAddress(std::shared_ptr<ATCCSAddress> address)
{
    if (address)
    {
        setDeviceAddress(address->ip(), address->port());
    }
    else
    {
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
    }
}

/**
 * set device real-time online status.
 * @param online true(online), false(offline)
 * @param time  UTC, last time when to get the status.
 */
void ATCCSDeviceController::setRealtimeOnline(bool online, unsigned int time)
{
    try
    {
        if (!_realtimeOnline)
            _realtimeOnline = std::make_shared<ATCCSOnline>();
        if (_realtimeOnline)
        {
            _realtimeOnline->setOnline(online, time);
        }
        else
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
}

/**
 * query the device online or not.
 * @return true if device is online, false if offline.
 */
bool ATCCSDeviceController::isOnline() const
{
    try
    {
        if (_realtimeOnline)
        {
            return _realtimeOnline->online();
        }
        else
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }
    }
    catch (std::exception &e)
    {
        //FIXME
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return false;
}

bool ATCCSDeviceController::canExecutePlan()
{
    return true;
}

unsigned int ATCCSDeviceController::id() const
{
    return _id;
}
