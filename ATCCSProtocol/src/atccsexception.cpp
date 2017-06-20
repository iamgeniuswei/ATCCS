/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSException.cpp
 * Author: lenovo
 * 
 * Created on May 23, 2017, 11:26 AM
 */

#include "atccsexception.h"
#include <iostream>
#include <libintl.h>
/**
 * initialize static data members
 */
unsigned int ATCCSException::ID = 1;
std::mutex ATCCSException::ID_MUTEX;

ATCCSException::ATCCSException(unsigned int type, const std::string& msg) noexcept
    :_type(type),
        _msg(msg)
{
try
    {
        std::lock_guard<std::mutex> lk(ID_MUTEX);
        _id = ID++;
        char id[24] = {0};
        snprintf(id, 24, "%d", _id);
        _exceptionString += id;
        switch (_type)
        {
            case STDEXCEPTION:
            {
                _exceptionString += gettext("-<std exception#1>: ");
                break;
            }
            case POINTERISNULL:
            {
                _exceptionString += gettext("-<pointer is null#2>: ");
                break;
            }
            case CUSTOMERROR:
            {
                _exceptionString += gettext("-<custom error#3>: ");
                break;
            }
            case DEBUGINFO:
            {
                _exceptionString += gettext("-<debug info#4>: ");
                break;
            }
            default:
            {
                _exceptionString += gettext("-<undefined error#5>: ");
                break;
            }
        }
        _exceptionString += _msg;
    }
    catch(std::exception &e)
    {
        std::cerr << type << "--" << msg << std::endl;
    }
}




ATCCSException::ATCCSException(unsigned int type, const char* file, const char* func, unsigned int line, const std::string& msg) noexcept
    :_type(type),
        _file(file),
        _func(func),
        _line(line),
        _msg(msg)
{
    try
    {
        std::lock_guard<std::mutex> lk(ID_MUTEX);
        _id = ID++;
        char id[24] = {0};
        snprintf(id, 24, "%d", _id);
        _exceptionString += id;
        switch (_type)
        {
            case STDEXCEPTION:
            {
                _exceptionString += gettext("-<std exception#1>: ");
                break;
            }
            case POINTERISNULL:
            {
                _exceptionString += gettext("-<pointer is null#2>: ");
                break;
            }
            case CUSTOMERROR:
            {
                _exceptionString += gettext("-<custom error#3>: ");
                break;
            }
            case DEBUGINFO:
            {
                _exceptionString += gettext("-<debug info#4>: ");
                break;
            }
            default:
            {
                _exceptionString += gettext("-<undefined error#5>: ");
                break;
            }
        }
        _exceptionString += _msg;
        _exceptionString += " @";
        _exceptionString += file;
        _exceptionString += " @";
        _exceptionString += func;
        char li[24] = {0};
        snprintf(li, 24, "%d", line);
        _exceptionString += " @";
        _exceptionString += li;
    }
    catch(std::exception &e)
    {
        std::cerr << type << "--" << msg << " @" << file << " @" << func << " @" << line << std::endl;
    }
}

ATCCSException::~ATCCSException() noexcept
{

}

const char* ATCCSException::what() const noexcept
{
    return _exceptionString.c_str();
}




