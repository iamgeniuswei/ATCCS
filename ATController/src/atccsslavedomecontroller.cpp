/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60SlaveDomeController.cpp
 * Author: lenovo
 * 
 * Created on May 16, 2017, 7:13 PM
 */

#include "atccsslavedomecontroller.h"
#include "atccs_public_define.h"
#include "atccs_dome_define.h"
#include "at60instruction.h"
#include "at60slavedomestatus.h"
#include "atccsexceptionhandler.h"
ATCCSSlaveDomeController::ATCCSSlaveDomeController() 
    :ATCCSDeviceController(SLAVEDOME)
{

}


ATCCSSlaveDomeController::~ATCCSSlaveDomeController() 
{
}

bool ATCCSSlaveDomeController::isStatusOK() const
{
    return true;
}


bool ATCCSSlaveDomeController::isExecutoryInstructionOK() 
{
    bool ret = false;
    if(_executoryInstruction)
    {
        switch(_executoryInstruction->instruction())
        {
            case _SLAVEDOME_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect();
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SETDOMEPOSITION:
            {
                ret = checkResult_SetDomePosition();
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SETSHADEPOSITION:
            {
                ret = checkResult_SetShadePosition();
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SETROTATESPEED:
            {
                ret = checkResult_SetRotatePosition();
                break;
            }
            case _SLAVEDOME_INSTRUCTION_STOP:
            {
                ret = checkResult_Stop();
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SCUTTLEACTION:
            {
                ret = checkResult_ScuttleAction();
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SHADEACTION:
            {
                ret = checkResult_ShadeAction();
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
                                            __FILE__, __func__, __LINE__, "");
#endif        
    }
    return ret;
}

bool ATCCSSlaveDomeController::canExecutePlan() 
{
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        if(_realtimeStatus)
        {
            
            return _realtimeStatus->curstatus() == _SLAVEDOME_STAUTS_FOLLOWING;
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




bool ATCCSSlaveDomeController::checkResult_Connect() {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_ScuttleAction() {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_SetDomePosition() {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_SetRotatePosition() {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_SetShadePosition() {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_ShadeAction() {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_Stop() {
    return true;
}






