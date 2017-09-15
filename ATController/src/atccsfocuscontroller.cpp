/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60FocusController.cpp
 * Author: lenovo
 * 
 * Created on May 16, 2017, 7:08 PM
 */

#include "atccsfocuscontroller.h"
#include "atccs_public_define.h"
#include "atccs_focus_define.h"
#include "atccsexceptionhandler.h"
#include "atccspublicstatus.h"
#include "atccsfocusstatus.h"
#include "atccsinstruction.h"
ATCCSFocusController::ATCCSFocusController(unsigned short at, unsigned short device) 
    :ATCCSDeviceController(at, device)
{

}


ATCCSFocusController::~ATCCSFocusController() 
{
}

bool ATCCSFocusController::isStatusOK() const
{
    return true;
}


bool ATCCSFocusController::isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    bool ret = false;
    if(instruction)
    {
        switch(instruction->instruction())
        {
            case _FOCUS_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect(instruction, rawData);
                break;
            }
            case _FOCUS_INSTRUCTION_FINDHOME:
            {
                ret = checkResult_FindHome(instruction, rawData);
                break;
            }
            case _FOCUS_INSTRUCTION_SETPOSITION:
            {
                ret = checkResult_SetPostion(instruction, rawData);
                break;
            }
            case _FOCUS_INSTRUCTION_SETFIXEDSPEED:
            {
                ret = checkResult_SetFixedSpeed(instruction, rawData);
                break;
            }
            case _FOCUS_INSTRUCTION_STOP:
            {
                ret = checkResult_Stop(instruction, rawData);
                break;
            }
            case _FOCUS_INSTRUCTION_ENABLETCOMPENSATE:
            {
                ret = checkResult_EnableTCompensate(instruction, rawData);
                break;
            }
            case _FOCUS_INSTRUCTION_SETTCOMPENSATE:
            {
                ret = checkResult_SetTCompensateCoefficiency(instruction, rawData);
                break;
            }            
            default:
                break;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The instruction is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device);
#endif        
    }
    return ret;
}

bool ATCCSFocusController::canExecutePlan() 
{
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        if(_realtimeStatus)
        {
            unsigned int temp = _realtimeStatus->curstatus();
            return temp == _FOCUS_STATUS_FREEZED &&
                    temp == _FOCUS_STATUS_SLEWED;
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return false;
}


bool ATCCSFocusController::checkResult_Connect(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSFocusController::checkResult_EnableTCompensate(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSFocusController::checkResult_FindHome(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSFocusController::checkResult_SetFixedSpeed(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSFocusController::checkResult_SetPostion(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSFocusController::checkResult_SetTCompensateCoefficiency(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSFocusController::checkResult_Stop(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}







