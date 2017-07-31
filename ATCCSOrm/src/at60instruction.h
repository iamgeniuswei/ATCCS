/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60instruction.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 4:12 PM
 */

#ifndef AT60INSTRUCTION_H
#define AT60INSTRUCTION_H
#include "atccsinstruction.h"

/**
 * @brief at60instruction is AT60's instruction.
 * @modified 2017-07-27
 * @description
 * 1) recompile the header file by odb complier with the --schema-name at60instruction
 */
#pragma db object
class at60instruction : public atccsinstruction
{
public:
    at60instruction();
    at60instruction(const at60instruction& orig);
    virtual ~at60instruction();
    unsigned long long persistInstruction() override;
    void persistInstructionResult() override;
    private:

};

#endif /* AT60INSTRUCTION_H */

