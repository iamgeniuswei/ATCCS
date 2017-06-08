/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDBAddress.h
 * Author: lenovo
 *
 * Created on May 24, 2017, 5:11 PM
 */

#ifndef ATCCSDBADDRESS_H
#define ATCCSDBADDRESS_H
#include <string>

class ATCCSDBAddress {
public:
    ATCCSDBAddress();
    ATCCSDBAddress(const std::string& type, const std::string &user, const std::string& password, const std::string& db, const std::string& ip, unsigned short port);
    ATCCSDBAddress(const ATCCSDBAddress& orig);
    virtual ~ATCCSDBAddress();    
    void setIp(const std::string& _ip);
    std::string ip() const;
    void setDb(const std::string& _db);
    std::string db() const;
    void setPassword(const std::string& _password);
    std::string password() const;
    void setUser(const std::string& _user);
    std::string user() const;
    void setType(const std::string& _type);
    std::string type() const;
    void setPort(unsigned short _port);
    unsigned short port() const;
private:
    std::string _type;
    std::string _user;
    std::string _password;
    std::string _db;
    std::string _ip;
    unsigned short _port = 0;
};

#endif /* ATCCSDBADDRESS_H */

