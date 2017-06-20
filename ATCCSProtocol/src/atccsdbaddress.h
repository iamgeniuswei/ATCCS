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

class ATCCSDBAddress 
{
public:
    ATCCSDBAddress();
    ATCCSDBAddress(const std::string& type,
                    const std::string &user, 
                    const std::string& password, 
                    const std::string& db, 
                    const std::string& ip, 
                    unsigned short port);
    std::string ip() const;
    std::string db() const;
    std::string password() const;
    std::string user() const;
    std::string type() const;
    unsigned short port() const;
    void setPort(unsigned short _port);
    void setIp(const std::string& _ip);
    void setDb(const std::string& _db);
    void setPassword(const std::string& _password);
    void setUser(const std::string& _user);
    void setType(const std::string& _type);
private:
    std::string _type;
    std::string _user;
    std::string _password;
    std::string _db;
    std::string _ip;
    unsigned short _port = 0;
};

#endif /* ATCCSDBADDRESS_H */

