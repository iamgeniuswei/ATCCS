/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atutilization.h
 * Author: lenovo
 *
 * Created on May 13, 2017, 7:56 PM
 */

#ifndef ATUTILIZATION_H
#define ATUTILIZATION_H
#include <string>
#include <odb/core.hxx>


#pragma db object
class atutilization {
public:
    atutilization();
    atutilization(const atutilization& orig) = delete;
    virtual ~atutilization();
private:
    friend class odb::access;
    
#pragma db id auto
    unsigned int _id = 0;
    unsigned short _at = 0;
    unsigned int _user = 0;
    unsigned int _occupation = 0;
    unsigned int _plan = 0;
    std::string description;
};

#endif /* ATUTILIZATION_H */

