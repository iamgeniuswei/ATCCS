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

#include "at60focuscontroller.h"
#include "atccs_public_define.h"
#include "atccs_focus_define.h"
#include "at60instruction.h"
#include "at60focusstatus.h"
#include "atccsexceptionhandler.h"
AT60FocusController::AT60FocusController() 
    :ATCCSFocusController(AT60, FOCUS)
{

}


AT60FocusController::~AT60FocusController() 
{
}

/**
 * create the concrete AT's executory instruction shared_ptr, which
 * is persisted into database by ODB. 
 * here, function returns at60instruction's shared_ptr.
 * @return std::shared_ptr<atccsinstruction>
 */
std::shared_ptr<atccsinstruction> AT60FocusController::instructionInstance()
{
    if(_executoryInstruction == nullptr)
    {
        try
        {
            _executoryInstruction = std::make_shared<at60instruction>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }   
    }
    return _executoryInstruction;
}

/**
 * create the concrete AT's Focus' real-time status shared_ptr,
 * which is persisted into database by ODB. 
 * here, function returns at60focusstatus's shared_ptr.
 * @return std::shared_ptr<atccspublicstatus>
 */
std::shared_ptr<atccspublicstatus> AT60FocusController::statusInstance()
{
    _realtimeStatus = std::make_shared<at60focusstatus>();
    return _realtimeStatus;
}









