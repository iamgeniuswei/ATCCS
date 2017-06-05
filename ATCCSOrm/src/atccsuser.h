/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsuser.h
 * Author: lenovo
 *
 * Created on May 18, 2017, 9:23 AM
 */

#ifndef ATCCSUSER_H
#define ATCCSUSER_H
#include <odb/core.hxx>
#include <string>
#pragma db object
class atccsuser {
public:
    atccsuser();
    atccsuser(const atccsuser& orig);
    virtual ~atccsuser();
private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id;
    std::string _username;
    std::string _password;
    unsigned int _role;
    unsigned int _status;
    std::string _description;
};

#endif /* ATCCSUSER_H */

