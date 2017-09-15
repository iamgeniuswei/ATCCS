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
#include "atccspublicstatus.h"
#include "atccsslavedomestatus.h"
#include "atccsinstruction.h"
#include "atccsexceptionhandler.h"
ATCCSSlaveDomeController::ATCCSSlaveDomeController(unsigned short at, unsigned short device) 
    :ATCCSDeviceController(at, device)
{

}


ATCCSSlaveDomeController::~ATCCSSlaveDomeController() 
{
}

bool ATCCSSlaveDomeController::isStatusOK() const
{
    return true;
}


bool ATCCSSlaveDomeController::isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    bool ret = false;
    if(instruction)
    {
        switch(instruction->instruction())
        {
            case _SLAVEDOME_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect(instruction, rawData);
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SETDOMEPOSITION:
            {
                ret = checkResult_SetDomePosition(instruction, rawData);
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SETSHADEPOSITION:
            {
                ret = checkResult_SetShadePosition(instruction, rawData);
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SETROTATESPEED:
            {
                ret = checkResult_SetRotatePosition(instruction, rawData);
                break;
            }
            case _SLAVEDOME_INSTRUCTION_STOP:
            {
                ret = checkResult_Stop(instruction, rawData);
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SCUTTLEACTION:
            {
                ret = checkResult_ScuttleAction(instruction, rawData);
                break;
            }
            case _SLAVEDOME_INSTRUCTION_SHADEACTION:
            {
                ret = checkResult_ShadeAction(instruction, rawData);
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




bool ATCCSSlaveDomeController::checkResult_Connect(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_ScuttleAction(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_SetDomePosition(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_SetRotatePosition(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_SetShadePosition(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_ShadeAction(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}

bool ATCCSSlaveDomeController::checkResult_Stop(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData) {
    return true;
}






