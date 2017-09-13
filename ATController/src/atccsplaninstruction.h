/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsplaninstruction.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 4:09 PM
 */

#ifndef ATCCSPLANINSTRUCTION_H
#define ATCCSPLANINSTRUCTION_H

#include <memory>

class ATCCSData;
class atccsplaninstruction
{
public:
    atccsplaninstruction();
    atccsplaninstruction(const atccsplaninstruction& orig) = delete;
    atccsplaninstruction(const atccsplaninstruction&& orig) = delete;
    atccsplaninstruction& operator=(const atccsplaninstruction& orig) = delete;
    atccsplaninstruction& operator=(const atccsplaninstruction&& orig) = delete;
    virtual ~atccsplaninstruction();
    void setPlanInstruction(std::shared_ptr<ATCCSData> data = nullptr);
    void unsetPlanInstruction();
    unsigned int end() const;
    unsigned int start() const;
    unsigned int instruction() const;
    unsigned int strategy() const;

protected:

private:
    unsigned int _instruction = 0;
    unsigned int _strategy = 0;
    unsigned int _start = 0;
    unsigned int _end = 0;
};

#endif /* ATCCSPLANINSTRUCTION_H */

