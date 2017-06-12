/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60GimbalController.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 11:00 AM
 */

#include "at60gimbalcontroller.h"
#include "at60instruction.h"
#include "at60gimbalstatus.h"
#include "atccsexceptionhandler.h"

AT60GimbalController::AT60GimbalController()
: ATCCSGimbalController(AT60, GIMBAL)
{

}

AT60GimbalController::~AT60GimbalController()
{
}

/**
 * create the concrete AT's executory instruction shared_ptr, which
 * is persisted into database by ODB. here, function returns 
 * at60instruction's shared_ptr.
 * @return std::shared_ptr<atccsinstruction>
 */
std::shared_ptr<atccsinstruction> AT60GimbalController::instructionInstance()
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
 * create the concrete AT's gimbal's real-time status shared_ptr,
 * which is persisted into database by ODB. here, function returns
 * at60gimbalstatus's shared_ptr.
 * @return std::shared_ptr<atccspublicstatus>
 */
std::shared_ptr<atccspublicstatus> AT60GimbalController::statusInstance()
{
    if(_realtimeStatus == nullptr)
    {
        try
        {
            _realtimeStatus = std::make_shared<at60gimbalstatus>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }   
    }
    return _realtimeStatus;
}








