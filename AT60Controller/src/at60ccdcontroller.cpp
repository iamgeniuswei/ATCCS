/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60CCDController.cpp
 * Author: lenovo
 * 
 * Created on May 14, 2017, 11:05 AM
 */

#include "at60ccdcontroller.h"
#include "at60instruction.h"
#include "at60ccdstatus.h"
#include "atccsexceptionhandler.h"

AT60CCDController::AT60CCDController()
: ATCCSCCDController(AT60, CCD)
{

}

AT60CCDController::~AT60CCDController()
{
}

/**
 * create the concrete AT's executory instruction shared_ptr, which
 * is persisted into database by ODB. 
 * here, function returns at60instruction's shared_ptr.
 * @return std::shared_ptr<atccsinstruction>
 */
std::shared_ptr<atccsinstruction> AT60CCDController::instructionInstance()
{
    std::shared_ptr<atccsinstruction> instruction = nullptr;

    try
    {
        instruction = std::make_shared<at60instruction>();
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }

    return instruction;
}

/**
 * create the concrete AT's ccd's real-time status shared_ptr,
 * which is persisted into database by ODB. 
 * here, function returns at60ccdstatus's shared_ptr.
 * @return std::shared_ptr<atccspublicstatus>
 */
std::shared_ptr<atccspublicstatus> AT60CCDController::statusInstance()
{
    _realtimeStatus = std::make_shared<at60ccdstatus>();
    return _realtimeStatus;
}






