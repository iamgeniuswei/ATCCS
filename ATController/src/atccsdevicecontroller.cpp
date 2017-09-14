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
#include <locale>
using namespace odb::core;
#endif
#include "atccsaddress.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"


unsigned int ATCCSDeviceController::INSTRUCTION_TIMEOUT = 30;
unsigned int ATCCSDeviceController::INSTRUCTION_RETRANSMISSION = 3;

ATCCSDeviceController::ATCCSDeviceController(unsigned short at, unsigned short device)
: _at(at), _device(device)
{

}

ATCCSDeviceController::~ATCCSDeviceController()
{

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
            if(_isPlanning)
            {
                ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                    gettext("------------------------------A Plan's instruction Start------------------------------"));
                executeInstruction(data);
                ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                    gettext("------------------------------The Plan's instruction End------------------------------"));
            }
            else
            {
                ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                    gettext("------------------------------A Independent instruction Start------------------------------"));
                executeIndependentInstruction(data);
                ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                    gettext("------------------------------The Independent instruction End------------------------------"));
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s",
                                                gettext("ATCCSDeviceController fails to fetch an instruction. AT: "),
                                                _at, " Device: ", _device, e.what());
#endif
        }
    }
}

/**
 * 执行一条指令
 * @param data, 待解析的指令原始数据
 */
void ATCCSDeviceController::executeInstruction(std::shared_ptr<ATCCSData> data)
{    
    _isExecutoryInstructionDone = false;
    //Only the instruction is all right, and the parameters are validated,
    //the instruction can be sent to according device.
    unsigned int ret = atccsinstruction::INSTRUCTION_UNKOWNN;
    ret = updateExecutoryInstruction(data);
    if (ret == atccsinstruction::INSTRUCTION_PASS)
    {
        int size = sendInstruction(data);
        if (size == data->size())
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s%d%s%d%s%d",
                                                gettext("ATCCSDeviceController has sent instruction to device correctly. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
            waitInstructionResult();
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d%s%s%s%s%s%s%d",
                                                gettext("The instruction is fail to be sent and neglected. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
        }
    }
    _isExecutoryInstructionDone = true;
}




/**
 * 执行独立指令,区别于计划观测指令,独立指令无需等待上一条指令完成,即可向望远镜推送下一条指令
 * @param data
 */
void ATCCSDeviceController::executeIndependentInstruction(std::shared_ptr<ATCCSData> data)
{
    _isExecutoryInstructionDone = false;
    //Only the instruction is all right, and the parameters are validated,
    //the instruction can be sent to according device.
    unsigned int ret = atccsinstruction::INSTRUCTION_UNKOWNN;
    ret = updateExecutoryInstruction(data);
    if (ret == atccsinstruction::INSTRUCTION_PASS)
    {
        int size = sendInstruction(data);
        if (size == data->size())
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s%d%s%d%s%d",
                                                gettext("The instruction has been sent to device correctly. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
//            waitInstructionResult();
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d%s%s%s%s%s%s%d",
                                                gettext("The instruction is fail to be sent and neglected. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
        }
    }
    _isExecutoryInstructionDone = true;
}


/**
 * set the executory instruction according to raw instruction data
 * encapsulated in ATCCSData.
 * @param data, raw instruction data.
 * @return INSTRUCTION_PASS if successes, else fails.
 */
unsigned int ATCCSDeviceController::updateExecutoryInstruction(std::shared_ptr<ATCCSData> data)
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
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,"%s%d%s%d%s%d%s",
                                                        "Fails to persist instruction. AT: ", _at,
                                                        " Device: ",_device, 
                                                        " Instruction: ", _executoryInstruction->instruction(),
                                                        e.what());
#endif                    
                }                
#endif
                
//#ifdef OUTDEBUGINFO
//                _executoryInstruction->out();
//#endif                
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
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,"%s%d%s%d%s%d%s",
                                                        gettext("Fails to persist instruction. AT: "), _at,
                                                        gettext(" Device: "),_device, 
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());
#endif
                }
#endif
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR,"%s%d%s%d%s%d",
                                                        gettext("The instruction's parameters are out of range and the instruction is neglected. AT: "), _at,
                                                        gettext(" Device: "),_device, 
                                                        gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
                _executoryInstruction->reset();
                _isExecutoryInstructionSuccess = false;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR,"%s%d%s%d",
                                                        gettext("The instruction is error and neglected. AT: "), _at,
                                                        gettext(" Device: "),_device);
#endif
                _executoryInstruction->reset();
                _isExecutoryInstructionSuccess = false;
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,"%s%d%s%d%s",
                                                gettext("Fails to set executory instruction. AT: "), _at, 
                                                gettext(" Device: "),_device, e.what());
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The instruction is fail to create, fails to set executory instruction. AT: "), _at, 
                                            gettext(" Device: "), _device);
#endif
    }
    return ret;
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
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d",
                                            gettext("The socket is fail to create, fails to send instruction. AT: "), _at,
                                            gettext(" Device: "), _device);
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
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,"%s%d%s%d%s%d%s",
                                                        gettext("Fails to persist instruction result. AT: "), _at,
                                                        gettext(" Device: "),_device, 
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());
#endif
                }
#endif
                _isExecutoryInstructionSuccess = true;
#ifdef OUTDEBUGINFO
                    ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO,"%s%d%s%d%s%d",
                                                        gettext("The instruction is success. AT: "), _at,
                                                        gettext(" Device: "),_device, 
                                                        gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
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
                    ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                        gettext("Fails to persist instruction result. AT: "), _at,
                                                        gettext(" Device: "), _device,
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());
#endif
                }
#endif
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO,"%s%d%s%d%s%d",
                                                        gettext("The instruction is timeout and neglected. AT: "), _at,
                                                        gettext(" Device: "),_device, 
                                                        gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
            }
        }
        else if(_executoryInstruction->result() == atccsinstruction::RESULT_PARAMOUTOFRANGE || 
                _executoryInstruction->result() == atccsinstruction::RESULT_CANNTEXECUTE)
        {
#ifdef DATAPERSISTENCE
            try
            {
                _executoryInstruction->persistInstructionResult();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO 
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                        gettext("Fails to persist instruction result. AT: "), _at,
                                                        gettext(" Device: "), _device,
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());
#endif
            }
#endif            
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
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                        gettext("Fails to persist instruction result. AT: "), _at,
                                                        gettext(" Device: "), _device,
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());
#endif
            }
#endif

#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO,"%s%d%s%d%s%d",
                                                        gettext("The instruction's feedback is timeout and the instruction is neglected. AT: "), _at,
                                                        gettext(" Device: "),_device, 
                                                        gettext(" Instruction: "), _executoryInstruction->instruction());
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The instruction is fail to create, fails to set executory instruction. AT: "), _at, 
                                            gettext(" Device: "), _device);
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
        try
        {
            std::lock_guard<std::mutex> lk(_instructionLock);
            return (_executoryInstruction->instruction() == instruction)
                    && (_executoryInstruction->result() == atccsinstruction::RESULT_SUCCESS);
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d%s",
                                                gettext("Fails to query executory instruction result. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), instruction,
                                                e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The instruction is fail to create, fails to query executory instruction result. AT: "), _at, 
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), instruction);
#endif
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
 * 更新望远镜设备实时状态.
 * @param data, 原始实时状态数据.
 */
void ATCCSDeviceController::updateRealtimeStatus(std::shared_ptr<ATCCSData> data)
{
    if(_realtimeStatus == nullptr)
    {
        //不能直接创建实时状态的实例,必须延迟到具体子类中创建,以实现数据的持久化
        try
        {
            _realtimeStatus = statusInstance();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("ATCCSDeviceController fails to update real time status. AT: "), _at, 
                                            gettext(" Device: "), _device);
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
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s",
                                            gettext("ATCCSDeviceController fails to update real time status. AT: "), _at, 
                                            gettext(" Device: "), _device,
                                            e.what());
#endif        
    }
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
            std::cout << _executoryInstruction->device() << " " << _executoryInstruction->result() << std::endl;
            if (ret == atccsinstruction::RESULT_EXECUTING)
            {
#ifdef DATAPERSISTENCE
                try
                {
                    _executoryInstruction->persistInstructionResult();
                }
                catch(std::exception &e)
                {
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d%s",
                                                        gettext("Fails to persist instruction result. AT: "), _at,
                                                        gettext(" Device: "), _device,
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());                    
                }
#endif
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d%s",
                                                        gettext("Fails to set instruction result. AT: "), _at,
                                                        gettext(" Device: "), _device,
                                                        gettext(" Instruction: "), _executoryInstruction->instruction(),
                                                        e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The instruction is fail to be created, fails to set executory instruction. AT: "), _at, 
                                            gettext(" Device: "), _device);
#endif        
    }
}

/**
 * 设置目标设备IPv4地址和端口.
 * @param ip    IPv4地址
 * @param port  端口
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
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("ATCCSDeviceController fails to set device address. AT: "), _at, 
                                            gettext(" Device: "), _device);
#endif  
            return;
        }
    }
    _instructionSender->setTargetAddress(ip, port);
}

/**
 * 设置目标设备IPv4地址和端口
 * @param address   IPv4地址和端口封装类的智能指针
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
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("ATCCSDeviceController fails to set device address. AT: "), _at, 
                                            gettext(" Device: "), _device);
#endif        
    }
}

/**
 * set device real-time online status.
 * @param online bool
 * @param time  unsigned int
 */
void ATCCSDeviceController::updateRealtimeOnline(bool online, unsigned int time)
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
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The online is fail to be created, fails to set real time online. AT: "), _at, 
                                            gettext(" Device: "), _device);
#endif            
            return;
        }
    }

    _realtimeOnline->setOnline(online, time);

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
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("Fails to query real time online. AT: "), _at, 
                                            gettext(" Device: "), _device,
                                            e.what());          
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The online is fail to be created, fails to query real time online. AT: "), _at, 
                                            gettext(" Device: "), _device);
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

bool ATCCSDeviceController::isExecutoryInstructionFinished(unsigned int instruction) const
{
    if(_executoryInstruction)
    {
        return (_executoryInstruction->instruction() == instruction) && _isExecutoryInstructionDone;
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The instruction is fail to be created, fails to query whether executory instruction is finished. AT: "), _at, 
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), instruction);
#endif        
    }
    return false;
}
