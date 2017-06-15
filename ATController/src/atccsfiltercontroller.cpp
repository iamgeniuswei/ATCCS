/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60FilterController.cpp
 * Author: lenovo
 * 
 * Created on May 16, 2017, 7:06 PM
 */

#include "atccsfiltercontroller.h"
#include "atccs_public_define.h"
#include "atccs_filter_define.h"
#include "at60instruction.h"
#include "at60filterstatus.h"
#include "atccsexceptionhandler.h"

ATCCSFilterController::ATCCSFilterController(unsigned short at, unsigned short device)
: ATCCSDeviceController(at, device)
{

}

ATCCSFilterController::~ATCCSFilterController()
{
}

bool ATCCSFilterController::isStatusOK() const
{
    return true;
}


bool ATCCSFilterController::canExecutePlan()
{
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        if (_realtimeStatus)
        {
            unsigned int temp = _realtimeStatus->curstatus();
            return temp != _FILTER_STATUS_DISCONNECT &&
                    temp != _FILTER_STATUS_CONNECTING &&
                    temp != _FILTER_STATUS_DISCONNECTING &&
                    temp != _FILTER_STATUS_NOTFINDHOME &&
                    temp != _FILTER_STATUS_HOMING &&
                    temp != _FILTER_STATUS_EMERGENCYING &&
                    temp != _FILTER_STATUS_EMERGENCY;

        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return false;
}

bool ATCCSFilterController::isExecutoryInstructionOK()
{
    bool ret = false;
    if (_executoryInstruction)
    {
        switch (_executoryInstruction->instruction())
        {
            case _FILTER_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect();
                break;
            }
            case _FILTER_INSTRUCTION_FINDHOME:
            {
                ret = checkResult_FindHome();
                break;
            }
            case _FILTER_INSTRUCTION_SETPOSITION:
            {
                ret = checkResult_SetFilterPosition();
                break;
            }
            default:
                break;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, 
                                            "atccsinstruction instance is null, fails to check filter's instruction result.");
#endif        
    }
    return ret;
}

bool ATCCSFilterController::checkResult_Connect()
{
    if (_realtimeStatus)
    {
        if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
            return false;
        if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_FILTER_PARAM_CONNECT)))
            return false;
        _AT_FILTER_PARAM_CONNECT *param = (_AT_FILTER_PARAM_CONNECT*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            unsigned int curStatus = _realtimeStatus->curstatus();
            if (param->connect == CONNECT)
            {
                return (curStatus != _FILTER_STATUS_DISCONNECT)&&
                        (curStatus != _FILTER_STATUS_CONNECTING)&&
                        (curStatus != _FILTER_STATUS_DISCONNECTING);
            }
            else if (param->connect == DISCONNECT)
            {
                return curStatus == _FILTER_STATUS_DISCONNECT;
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, 
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
    return false;
}

bool ATCCSFilterController::checkResult_FindHome()
{
    return true;
}

bool ATCCSFilterController::checkResult_SetFilterPosition()
{
    if(_realtimeStatus)
    {
        std::shared_ptr<atccsfilterstatus> temp = std::dynamic_pointer_cast<atccsfilterstatus>(_realtimeStatus);
        if (temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_FILTER_PARAM_CONNECT)))
                return false;
            _AT_FILTER_PARAM_SETPOSITION *param = (_AT_FILTER_PARAM_SETPOSITION*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            try
            {
                std::lock_guard<std::mutex> lk(_statusLock);
                std::cout << temp->curstatus() <<"--"<<_FILTER_STATUS_SLEWED << std::endl;
                std::cout << temp->filterPosition() << "--" << param->position << std::endl;
                return (temp->curstatus() == _FILTER_STATUS_SLEWED)
                        &&(temp->filterPosition() == param->position);
            }
            catch(std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                    __FILE__, __func__, __LINE__, e.what());
#endif
            }
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__,
                                                "atccsfilterstatus instance is nullptr, fails to check instruction's result.");
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, 
                                            __FILE__, __func__, __LINE__, 
                                            "atccsfilterstatus instance is null, fails to check instruction's result.");
#endif        
    }
    return false;
}


