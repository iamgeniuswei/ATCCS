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
    std::cout << "~ATCCSExceptionHandler\n";
}

void ATCCSExceptionHandler::addException(std::shared_ptr<ATCCSException> exception) 
{
    _exceptions.push(exception);
}

void ATCCSExceptionHandler::addException(unsigned int type, const char* file, const char* func, unsigned long line, const char* msg) 
{
    try 
    {
        std::string debug_info;
        switch (type) {
            case ATCCSException::STDEXCEPTION:
            {
                debug_info += "std exception: ";
                break;
            }
            case ATCCSException::POINTERISNULL:
            {
                debug_info += "pointer is null: ";
                break;
            }
            case ATCCSException::CUSTOMEXCEPTION:
            {
                debug_info += "custom error: ";
                break;
            }
            default:
            {
                debug_info += "undefined error: ";
                break;
            }
        }
        debug_info += msg;
        debug_info += " @";
        debug_info += file;
        debug_info += " @";
        debug_info += func;
        debug_info += " @";
        char *line_str = new char[10];
        memset(line_str, 0, 10);
        sprintf(line_str, "%d", line);
        debug_info += line_str;
        std::shared_ptr<ATCCSException> e = std::make_shared<ATCCSException>(type, debug_info);
        _exceptions.push(e);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << " @" << __FILE__ << " @" << __func__ << __LINE__ << std::endl;
    }
}

//template<typename ... ARGS>
//void
//ATCCSExceptionHandler::addException(unsigned int type, ARGS args)
//{
//    
//}



std::shared_ptr<ATCCSException> ATCCSExceptionHandler::lastException() 
{
    return _exceptions.wait_and_pop();
}
