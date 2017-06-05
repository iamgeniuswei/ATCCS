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
#include "atccsqueue.h"
class ATCCSException 
{
public:
    enum Exception
    {
        STDEXCEPTION = 1,
        POINTERISNULL,
        CUSTOMEXCEPTION
    };
public:
    ATCCSException();
    ATCCSException(unsigned int type, const std::string& errorString);
    ATCCSException(const ATCCSException& orig);
    virtual ~ATCCSException();
    void setErrorString(std::string _errorString);
    std::string errorString() const;
    void setType(unsigned int _type);
    unsigned int type() const;
    void setId(unsigned int _id);
    unsigned int id() const;
private:
    unsigned int _id = 0;
    unsigned int _type = 0; 
    std::string _errorString;
    static std::mutex ID_MUTEX;
    static unsigned int ID;
};

#endif /* ATCCSEXCEPTION_H */

