/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSExceptionPrinter.h
 * Author: lenovo
 *
 * Created on September 8, 2017, 8:44 AM
 */

#ifndef ATCCSEXCEPTIONPRINTER_H
#define ATCCSEXCEPTIONPRINTER_H
#include "atccsthread.h"
class ATCCSExceptionPrinter : public ATCCSThread
{
public:
    ATCCSExceptionPrinter();
    ATCCSExceptionPrinter(const ATCCSExceptionPrinter& orig) = delete;
    ATCCSExceptionPrinter(const ATCCSExceptionPrinter&& orig) = delete;
    ATCCSExceptionPrinter& operator=(const ATCCSExceptionPrinter& orig) = delete;
    ATCCSExceptionPrinter& operator=(const ATCCSExceptionPrinter&& orig) = delete;
    virtual ~ATCCSExceptionPrinter();
    void run() override;


protected:

private:

};

#endif /* ATCCSEXCEPTIONPRINTER_H */

