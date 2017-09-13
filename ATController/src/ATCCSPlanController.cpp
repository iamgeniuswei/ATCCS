/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSPlanController.cpp
 * Author: lenovo
 * 
 * Created on September 12, 2017, 4:07 PM
 */

#include <locale>

#include "ATCCSPlanController.h"
#include "atccsexceptionhandler.h"
#include "atccsdata.h"
ATCCSPlanController::ATCCSPlanController()
{
}

ATCCSPlanController::~ATCCSPlanController()
{
}

void ATCCSPlanController::run()
{
    while (!stop())
    {
        try
        {
            std::shared_ptr<ATCCSData> instruction = popControlData();
            if(instruction == nullptr)
                continue;
            updateInstruction(instruction);
        }
        catch(std::exception &e)
        {
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                gettext("ATCCSPlanController fails to fetch an instruction."), e.what());
        }
    }
}

void ATCCSPlanController::setPlanPerformer(std::shared_ptr<ATCCSPlanPerformer> _planPerformer)
{
    this->_planPerformer = _planPerformer;
}

void ATCCSPlanController::updateInstruction(std::shared_ptr<ATCCSData> data)
{
    if(_planPerformer)
        _planPerformer->updateInstruction(data);
}


