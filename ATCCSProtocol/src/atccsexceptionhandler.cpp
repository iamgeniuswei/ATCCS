/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSExceptionHandler.cpp
 * Author: lenovo
 * 
 * Created on May 23, 2017, 3:12 PM
 */

#include "atccsexceptionhandler.h"
#include <iostream>
#include <string.h>
#include <stdarg.h>
/**
 * initialize static data members
 */
ATCCSExceptionHandler *ATCCSExceptionHandler::_instance = new ATCCSExceptionHandler;
ATCCSExceptionHandler::ATCCSExceptionHandlerGarbo ATCCSExceptionHandler::_ehGarbo;
ATCCSQueue<std::shared_ptr<ATCCSException>> ATCCSExceptionHandler::_exceptions;

ATCCSExceptionHandler::ATCCSExceptionHandler() {
}


ATCCSExceptionHandler::~ATCCSExceptionHandler() 
{
    
}

void ATCCSExceptionHandler::setMsg(std::string& msg, const char* format, ...)
{
    char temp[256] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, format);
    vsnprintf(temp, 255, format, arg_ptr);
    va_end(arg_ptr);
    msg += temp;
}

void ATCCSExceptionHandler::addException(unsigned int type, const char* format, ...)
{
    std::string msg;
    char temp[256] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, format);
    vsnprintf(temp, 255, format, arg_ptr);
    va_end(arg_ptr);
    msg += temp;
    try
    {
        std::shared_ptr<ATCCSException> temp = std::make_shared<ATCCSException>(type, msg);
        _exceptions.push(temp);
    }
    catch(std::exception &e)
    {
        std::cerr << type << msg << std::endl;
    }    
}



void ATCCSExceptionHandler::addException(unsigned int type, const char* file, const char* func, unsigned long line, const std::string& msg)
{
    try
    {
        std::shared_ptr<ATCCSException> temp = std::make_shared<ATCCSException>(type, file, func, line, msg);
        _exceptions.push(temp);
    }
    catch(std::exception &e)
    {
        std::cerr << type << "--" << msg << " @" << file << " @" << func << " @" << line << std::endl;
    }
}

std::shared_ptr<ATCCSException> ATCCSExceptionHandler::lastException() 
{
    return _exceptions.wait_and_pop();
}

void ATCCSExceptionHandler::addException(unsigned int type, const char *file, const char *func, unsigned long line, const char *msg)
{
}
void ATCCSExceptionHandler::addException(unsigned int type, const char *file, const char *func, unsigned long line, char msg[])
{
    
}
void ATCCSExceptionHandler::addException(unsigned int type, const char *file, const char *func, unsigned long line, unsigned int at, unsigned int device, const char *msg)
{
    
}


