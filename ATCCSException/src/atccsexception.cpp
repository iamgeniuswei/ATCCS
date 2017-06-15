/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSException.cpp
 * Author: lenovo
 * 
 * Created on June 15, 2017, 9:20 AM
 */

#include "atccsexception.h"

ATCCSException::ATCCSException(const std::string& msg) noexcept
    :_msg(msg),
            _file("<unknown file>"),
            _func("<unknown func>"),
            _line(0)    
{
    
}
    
ATCCSException::~ATCCSException() noexcept
{

}

void ATCCSException::init(const char* file, const char* func, unsigned int line)
{
    _file = file;
    _func = func;
    _line = line;
}


