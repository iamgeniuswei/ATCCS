/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60instruction.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 4:12 PM
 */

#include "at60instruction.h"
#include "at60instruction-odb.hxx"
#include "ORMHelper.h"
at60instruction::at60instruction() {
}

at60instruction::at60instruction(const at60instruction& orig) {
}

at60instruction::~at60instruction() {
}

unsigned long long at60instruction::persistInstruction() 
{
    return ORMHelper::persist<at60instruction*>(this);
}

void at60instruction::persistInstructionResult() 
{
    ORMHelper::update<at60instruction*>(this);
}
