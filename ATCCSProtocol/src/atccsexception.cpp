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
/**
 * initialize static data members
 */
unsigned int ATCCSException::ID = 1;
std::mutex ATCCSException::ID_MUTEX;

ATCCSException::ATCCSException() {
}

void ATCCSException::setErrorString(std::string _errorString) {
    this->_errorString = _errorString;
}

std::string ATCCSException::errorString() const {
    return _errorString;
}

void ATCCSException::setType(unsigned int _type) {
    this->_type = _type;
}

unsigned int ATCCSException::type() const {
    return _type;
}

void ATCCSException::setId(unsigned int _id) {
    this->_id = _id;
    
}

unsigned int ATCCSException::id() const {
    return _id;
}

ATCCSException::ATCCSException(const ATCCSException& orig) {
}

ATCCSException::~ATCCSException() 
{

}

ATCCSException::ATCCSException(unsigned int type, const std::string& errorString) 
    : _type(type), _errorString(errorString)
{
    std::lock_guard<std::mutex> lk(ID_MUTEX);
    _id = ID++;
}


