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

#include "at60filtercontroller.h"
#include "at60instruction.h"
#include "at60filterstatus.h"
#include "atccsexceptionhandler.h"
AT60FilterController::AT60FilterController() 
    :ATCCSFilterController(AT60, FILTER)
{

}


AT60FilterController::~AT60FilterController() 
{
}

/**
 * create the concrete AT's executory instruction shared_ptr, which
 * is persisted into database by ODB. 
 * here, function returns at60instruction's shared_ptr.
 * @return std::shared_ptr<atccsinstruction>
 */
std::shared_ptr<atccsinstruction> AT60FilterController::instructionInstance()
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
 * create the concrete AT's Filter's real-time status shared_ptr,
 * which is persisted into database by ODB. 
 * here, function returns at60filterstatus's shared_ptr.
 * @return std::shared_ptr<atccspublicstatus>
 */
std::shared_ptr<atccspublicstatus> AT60FilterController::statusInstance()
{
    _realtimeStatus = std::make_shared<at60filterstatus>();
    return _realtimeStatus;
}




