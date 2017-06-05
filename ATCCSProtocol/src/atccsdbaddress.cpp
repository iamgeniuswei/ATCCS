/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDBAddress.cpp
 * Author: lenovo
 * 
 * Created on May 24, 2017, 5:11 PM
 */

#include "atccsdbaddress.h"

ATCCSDBAddress::ATCCSDBAddress() {
}

ATCCSDBAddress::ATCCSDBAddress(const std::string& type, const std::string& user, const std::string& password, const std::string& db, const std::string& ip, unsigned short port) 
    :_type(type), _user(user), _password(password), _db(db), _ip(ip), _port(port)
{

}


ATCCSDBAddress::ATCCSDBAddress(const ATCCSDBAddress& orig) {
}

ATCCSDBAddress::~ATCCSDBAddress() {
}

void ATCCSDBAddress::setPort(unsigned short _port) {
    this->_port = _port;
}

unsigned short ATCCSDBAddress::GetPort() const {
    return _port;
}

void ATCCSDBAddress::setIp(const std::string& _ip) {
    this->_ip = _ip;
}

std::string ATCCSDBAddress::ip() const {
    return _ip;
}

void ATCCSDBAddress::setDb(const std::string& _db) {
    this->_db = _db;
}

std::string ATCCSDBAddress::db() const {
    return _db;
}

void ATCCSDBAddress::setPassword(const std::string& _password) {
    this->_password = _password;
}

std::string ATCCSDBAddress::password() const {
    return _password;
}

void ATCCSDBAddress::setUser(const std::string& _user) {
    this->_user = _user;
}

std::string ATCCSDBAddress::user() const {
    return _user;
}

void ATCCSDBAddress::setType(const std::string& _type) {
    this->_type = _type;
}

std::string ATCCSDBAddress::type() const {
    return _type;
}

