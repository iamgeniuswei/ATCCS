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
#include "at60instruction.h"
#include "at60focusstatus.h"
#include "atccsexceptionhandler.h"
ATCCSFocusController::ATCCSFocusController() 
    :ATCCSDeviceController(FOCUS)
{

}


ATCCSFocusController::~ATCCSFocusController() 
{
}

bool ATCCSFocusController::isStatusOK() const
{
    return true;
}


bool ATCCSFocusController::isExecutoryInstructionOK() 
{
    bool ret = false;
    if(_executoryInstruction)
    {
        switch(_executoryInstruction->instruction())
        {
            case _FOCUS_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect();
                break;
            }
            case _FOCUS_INSTRUCTION_FINDHOME:
            {
                ret = checkResult_FindHome();
                break;
            }
            case _FOCUS_INSTRUCTION_SETPOSITION:
            {
                ret = checkResult_SetPostion();
                break;
            }
            case _FOCUS_INSTRUCTION_SETFIXEDSPEED:
            {
                ret = checkResult_SetFixedSpeed();
                break;
            }
            case _FOCUS_INSTRUCTION_STOP:
            {
                ret = checkResult_Stop();
                break;
            }
            case _FOCUS_INSTRUCTION_ENABLETCOMPENSATE:
            {
                ret = checkResult_EnableTCompensate();
                break;
            }
            case _FOCUS_INSTRUCTION_SETTCOMPENSATE:
            {
                ret = checkResult_SetTCompensateCoefficiency();
                break;
            }            
            default:
                break;
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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return false;
}


bool ATCCSFocusController::checkResult_Connect() {
    return true;
}

bool ATCCSFocusController::checkResult_EnableTCompensate() {
    return true;
}

bool ATCCSFocusController::checkResult_FindHome() {
    return true;
}

bool ATCCSFocusController::checkResult_SetFixedSpeed() {
    return true;
}

bool ATCCSFocusController::checkResult_SetPostion() {
    return true;
}

bool ATCCSFocusController::checkResult_SetTCompensateCoefficiency() {
    return true;
}

bool ATCCSFocusController::checkResult_Stop() {
    return true;
}







