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

#include "at60slavedomecontroller.h"
#include "atccs_public_define.h"
#include "atccs_dome_define.h"
#include "at60instruction.h"
#include "at60slavedomestatus.h"
#include "atccsexceptionhandler.h"

AT60SlaveDomeController::AT60SlaveDomeController()
: ATCCSSlaveDomeController(AT60, SLAVEDOME)
{

}

AT60SlaveDomeController::~AT60SlaveDomeController()
{
}

/**
 * create the concrete AT's executory instruction shared_ptr, which
 * is persisted into database by ODB. 
 * here, function returns at60instruction's shared_ptr.
 * @return std::shared_ptr<atccsinstruction>
 */
std::shared_ptr<atccsinstruction> AT60SlaveDomeController::instructionInstance()
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
 * create the concrete AT's slavedome's real-time status shared_ptr,
 * which is persisted into database by ODB. 
 * here, function returns at60slavedomestatus's shared_ptr.
 * @return std::shared_ptr<atccspublicstatus>
 */
std::shared_ptr<atccspublicstatus> AT60SlaveDomeController::statusInstance()
{
    _realtimeStatus = std::make_shared<at60slavedomestatus>();
    return _realtimeStatus;
}








