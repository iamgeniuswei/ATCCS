/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80instruction.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:42 PM
 */

#ifndef AT80INSTRUCTION_H
#define AT80INSTRUCTION_H
#include "atccsinstruction.h"

#pragma db object
class at80instruction : public atccsinstruction
{
public:
    at80instruction();
    at80instruction(const at80instruction& orig) = delete;
    at80instruction(const at80instruction&& orig) = delete;
    at80instruction& operator=(const at80instruction& orig) = delete;
    at80instruction& operator=(const at80instruction&& orig) = delete;
    virtual ~at80instruction();
    unsigned long long persistInstruction() override;
    void persistInstructionResult() override;



protected:

private:

};

#endif /* AT80INSTRUCTION_H */

