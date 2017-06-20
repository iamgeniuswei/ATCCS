/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60ExceptionDisplayer.cpp
 * Author: lenovo
 * 
 * Created on May 24, 2017, 9:16 AM
 */

#include "at60exceptiondisplayer.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
#include <iostream>
AT60ExceptionDisplayer::AT60ExceptionDisplayer() {
}

AT60ExceptionDisplayer::AT60ExceptionDisplayer(const AT60ExceptionDisplayer& orig) {
}

AT60ExceptionDisplayer::~AT60ExceptionDisplayer() {
}

void AT60ExceptionDisplayer::run() 
{
    while (!stop())
    {
        std::shared_ptr<ATCCSException> temp = ATCCSExceptionHandler::lastException();
        if(temp == nullptr)
            continue;
        std::cout << temp->what() << std::endl;
    }

}
