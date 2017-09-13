/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsplaninstruction.cpp
 * Author: lenovo
 * 
 * Created on September 12, 2017, 4:09 PM
 */

#include "atccsplaninstruction.h"
#include "atccs_plan_define.h"
#include "atccsdata.h"
#include "atccs_public_define.h"

atccsplaninstruction::atccsplaninstruction()
{
}

atccsplaninstruction::~atccsplaninstruction()
{
}

void atccsplaninstruction::setPlanInstruction(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
        return;
    if(!data->validate())
        return;
    if(data->size() != (sizeof(_ATCCSPHeader) + sizeof(_AT_PLAN_INSTRUCTION)))
        return;
    
    _AT_PLAN_INSTRUCTION *plan_instruction = (_AT_PLAN_INSTRUCTION*)(data->data()+sizeof(_ATCCSPHeader));
    if(plan_instruction)
    {
        _instruction = plan_instruction->instruction;
        _strategy = plan_instruction->strategy;
        _start = plan_instruction->start;
        _end = plan_instruction->end;
    }    
}

void atccsplaninstruction::unsetPlanInstruction()
{
    _instruction = _strategy = _start = _end = 0;
}



unsigned int atccsplaninstruction::end() const
{
    return _end;
}

unsigned int atccsplaninstruction::start() const
{
    return _start;
}

unsigned int atccsplaninstruction::instruction() const
{
    return _instruction;
}

unsigned int atccsplaninstruction::strategy() const
{
    return _strategy;
}

