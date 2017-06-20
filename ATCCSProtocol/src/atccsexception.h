/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSException.h
 * Author: lenovo
 *
 * Created on May 23, 2017, 11:26 AM
 */

#ifndef ATCCSEXCEPTION_H
#define ATCCSEXCEPTION_H
#include <string>
#include <memory>
#include <mutex>
#include <exception>
#include "atccsqueue.h"

class ATCCSException : public std::exception
{
public:

    enum Exception
    {
        STDEXCEPTION = 1,
        POINTERISNULL,
        CUSTOMERROR,
        DEBUGINFO,
    };
public:
    ATCCSException(unsigned int type, const char *file, const char *func, unsigned int line, const std::string& msg) noexcept;
    ATCCSException(unsigned int type, const std::string& msg) noexcept;
    ATCCSException(const ATCCSException& orig) = delete;
    ATCCSException(const ATCCSException&& orig) = delete;
    ATCCSException& operator=(const ATCCSException& orig) = delete;
    ATCCSException& operator=(const ATCCSException&& orig) = delete;
    virtual ~ATCCSException() noexcept;
    const char* what() const noexcept override;

protected:
    unsigned int _id = 0;
    unsigned int _type = 0;
    std::string _msg;
    std::string _file;
    std::string _func;
    std::string _exceptionString;
    unsigned int _line = 0;
private:
    static std::mutex ID_MUTEX;
    static unsigned int ID;
};

#endif /* ATCCSEXCEPTION_H */

