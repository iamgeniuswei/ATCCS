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

ATCCSFilterController::ATCCSFilterController()
: ATCCSDeviceController(FILTER)
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
#ifdef OUTDEBUGINFO
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
#ifdef OUTDEBUGINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif        
    }
    return ret;
}

bool ATCCSFilterController::checkResult_Connect()
{
    return true;
}

bool ATCCSFilterController::checkResult_FindHome()
{
    return true;
}

bool ATCCSFilterController::checkResult_SetFilterPosition()
{
    return true;
}


