/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSExceptionPrinter.cpp
 * Author: lenovo
 * 
 * Created on September 8, 2017, 8:44 AM
 */

#include "ATCCSExceptionPrinter.h"
#include "atccsexceptionhandler.h"
ATCCSExceptionPrinter::ATCCSExceptionPrinter():
ATCCSThread()
{
}

ATCCSExceptionPrinter::~ATCCSExceptionPrinter()
{
}

void ATCCSExceptionPrinter::run()
{
    while (!stop())
    {
        std::shared_ptr<ATCCSException> temp = ATCCSExceptionHandler::lastException();
        if(temp == nullptr)
            continue;
        std::cout << temp->what() << std::endl;
    }
}


