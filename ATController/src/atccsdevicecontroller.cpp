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
    _independentInstruction = instructionInstance();
    _planInstruction = instructionInstance();
    _realtimeStatus = statusInstance();
    while (!stop())
    {
        try
        {
            //fetch a raw data of the instruction from the instruction queue.
            std::shared_ptr<ATCCSData> data = popControlData();
            //the queue returns per 1 second, so sometimes there is no data.
            if (data == nullptr)
                continue;
            resolveData(data);
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

void ATCCSDeviceController::resolveData(std::shared_ptr<ATCCSData> data)
{
    if (data == nullptr)
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
    if (header->AT.at == _at && header->AT.device == _device)
    {
        switch (header->msg)
        {
            case ATSTATUSREPORT:
            {
                updateRealtimeStatus(data);
                break;
            }
            case ATINSTRUCTION:
            {
                handleIndependentInstrutcion(data);
                break;
            }
            case ATINSTRUCTIONACK:
            {
                handleInstructionResult(data);
                break;
            }
            case ATHEARTBEAT:
            {
                updateRealtimeOnline(data);
            }
        }
    }
}

void ATCCSDeviceController::handleInstructionResult(std::shared_ptr<ATCCSData> data)
{
    if (data == nullptr)
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
    _AT_INSTRUCTION_RESULT *result = (_AT_INSTRUCTION_RESULT*) (data->data() + sizeof (_ATCCSPHeader));
    if (result->plan != 0)
    {
        updateInstructionResult(data, _planInstruction);
    }
    else
    {
        updateIndependentInstructionResult(data);
    }

}

void ATCCSDeviceController::updateInstructionResult(std::shared_ptr<ATCCSData> data, std::shared_ptr<atccsinstruction> instruction /* = nullptr */)
{
    if (instruction == nullptr)
        return;
    try
    {
        unsigned int ret = instruction->updateInstructionResult(data);
        if (ret == atccsinstruction::RESULT_EXECUTING)
        {
#ifdef DATAPERSISTENCE
            try
            {
                instruction->persistInstructionResult();
            }
            catch (std::exception &e)
            {
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d%s",
                                                    gettext("Fails to persist instruction result. AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), instruction->instruction(),
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
                                            gettext(" Instruction: "), instruction->instruction(),
                                            e.what());
#endif            
    }
}

void ATCCSDeviceController::updateIndependentInstructionResult(std::shared_ptr<ATCCSData> data)
{

}

void ATCCSDeviceController::handleIndependentInstrutcion(std::shared_ptr<ATCCSData> data)
{
    if (data == nullptr)
        return;
    if (updateIndependentInstruction(data) == atccsinstruction::RESULT_WAITINGTOEXECUTE)
    {
        if (sendInstruction(data) == data->size())
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s%d%s%d%s%d",
                                                gettext("The instruction has been sent to device correctly. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _independentInstruction->instruction());
#endif            
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d%s%s%s%s%s%s%d",
                                                gettext("The instruction is fail to be sent and neglected. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _independentInstruction->instruction());
#endif
        }
    }
}

unsigned int ATCCSDeviceController::updateInstruction(std::shared_ptr<ATCCSData> data, std::shared_ptr<atccsinstruction> instruction)
{
    unsigned int ret = atccsinstruction::RESULT_DATAERROR;
    if (data == nullptr || instruction == nullptr)
        return ret;

    try
    {
        ret = instruction->updateInstruction(data);
        if (ret == atccsinstruction::RESULT_WAITINGTOEXECUTE)
        {
#ifdef DATAPERSISTENCE
            try
            {
                instruction->persistInstruction();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                    "Fails to persist instruction. AT: ", _at,
                                                    " Device: ", _device,
                                                    " Instruction: ", instruction->instruction(),
                                                    e.what());
#endif                    
            }
#endif                
        }
        else if (ret == atccsinstruction::RESULT_PARAMOUTOFRANGE)
        {
#ifdef DATAPERSISTENCE
            try
            {
                instruction->persistInstruction();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                    gettext("Fails to persist instruction. AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), instruction->instruction(),
                                                    e.what());
#endif
            }
#endif
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("The instruction's parameters are out of range and the instruction is neglected. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), instruction->instruction());
#endif
            instruction->reset();
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d",
                                                gettext("The instruction is error and neglected. AT: "), _at,
                                                gettext(" Device: "), _device);
#endif
            instruction->reset();
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s",
                                            gettext("AT: "), _at,
                                            gettext(" Device: "), _device, e.what());
#endif
    }
    return ret;
}

unsigned int ATCCSDeviceController::updateIndependentInstruction(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = atccsinstruction::RESULT_DATAERROR;
    if (_independentInstruction == nullptr)
    {
        return ret;
    }

    try
    {
        ret = _independentInstruction->updateInstruction(data);
        if (ret == atccsinstruction::RESULT_WAITINGTOEXECUTE)
        {
#ifdef DATAPERSISTENCE
            try
            {
                _independentInstruction->persistInstruction();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                    "Fails to persist instruction. AT: ", _at,
                                                    " Device: ", _device,
                                                    " Instruction: ", _independentInstruction->instruction(),
                                                    e.what());
#endif                    
            }
#endif                
        }
        else if (ret == atccsinstruction::RESULT_PARAMOUTOFRANGE)
        {
#ifdef DATAPERSISTENCE
            try
            {
                _independentInstruction->persistInstruction();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                    gettext("Fails to persist instruction. AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _independentInstruction->instruction(),
                                                    e.what());
#endif
            }
#endif
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("The instruction's parameters are out of range and the instruction is neglected. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _independentInstruction->instruction());
#endif
            _independentInstruction->reset();
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d",
                                                gettext("The instruction is error and neglected. AT: "), _at,
                                                gettext(" Device: "), _device);
#endif
            _independentInstruction->reset();
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s",
                                            gettext("AT: "), _at,
                                            gettext(" Device: "), _device, e.what());
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

bool ATCCSDeviceController::handlePlanInstruction(std::shared_ptr<ATCCSData> data)
{
    if (data == nullptr)
        return false;
    if (updateInstruction(data, _planInstruction) != atccsinstruction::RESULT_WAITINGTOEXECUTE)
        return false;
    _planInstructionRawData = data;
    if (sendInstruction(data) != data->size())
        return false;
#ifdef OUTDEBUGINFO
    ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s%d%s%d%s%d",
                                        gettext("The instruction has been sent to device correctly. AT: "), _at,
                                        gettext(" Device: "), _device,
                                        gettext(" Instruction: "), _planInstruction->instruction());
#endif
    return true;
}

bool ATCCSDeviceController::queryPlanInstructionResult(int &result)
{
    result = atccsinstruction::RESULT_WAITINGTOEXECUTE;
    if (_planInstruction == nullptr)
        return false;
    if (_planInstruction->result() == atccsinstruction::RESULT_WAITINGTOEXECUTE)
        return false;
    if(_planInstruction->result() == atccsinstruction::RESULT_PARAMOUTOFRANGE)
    {
        result = atccsinstruction::RESULT_PARAMOUTOFRANGE;
        return true;
    }
    if (_planInstruction->result() == atccsinstruction::RESULT_EXECUTING)
    {
        return isInstructionSuccess(_planInstruction, _planInstructionRawData);
    }
}

void ATCCSDeviceController::persistPlanInstructionResult(bool success /* = true */)
{
    try
    {
        switch (success)
        {
            case true:
            {
                _planInstruction->setResult(atccsinstruction::RESULT_SUCCESS);
                _planInstruction->persistInstructionResult();
                break;
            }
            case false:
            {
                _planInstruction->setResult(atccsinstruction::RESULT_TIMEOUT);
                _planInstruction->persistInstructionResult();
                break;
            }
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to persist instruction result. AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _planInstruction->instruction(),
                                            e.what());
#endif
    }
}

unsigned int ATCCSDeviceController::timeout()
{
    if (_planInstruction)
        return _planInstruction->timeout();
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

bool ATCCSDeviceController::isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    return false;
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
    if (_realtimeStatus == nullptr)
    {
        return;
    }
    try
    {
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            _realtimeStatus->setStatus(data);
        }
#ifdef DATAPERSISTENCE
        _realtimeStatus->persistStatus();
#endif
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%s%d%s%d%c%s",
                                            gettext("ATCCSDeviceController fails to update real time status. "),
                                            gettext("AT: "), _at,
                                            gettext(" Device: "), _device, '\n',
                                            e.what());
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
void ATCCSDeviceController::updateRealtimeOnline(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
        return;
    if (_realtimeOnline == nullptr)
    {
        try
        {
            _realtimeOnline = std::make_shared<ATCCSOnline>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                                gettext("The online is fail to be created, fails to set real time online. AT: "), _at,
                                                gettext(" Device: "), _device);
#endif            
            return;
        }
    }
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    _realtimeOnline->setOnline(true, header->tv_sec);

}

/**
 * query the device online or not.
 * @return true if device is online, false if offline.
 */
bool ATCCSDeviceController::isOnline() const
{
    if (_realtimeOnline)
    {
        try
        {
            return _realtimeOnline->online();
        }
        catch (std::exception &e)
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

