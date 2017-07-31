/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsutilization.h
 * Author: lenovo
 *
 * Created on May 18, 2017, 9:47 AM
 */

#ifndef ATCCSUTILIZATION_H
#define ATCCSUTILIZATION_H
#include <odb/core.hxx>
#include <string>
#pragma db object

class atccsutilization
{
public:
    explicit atccsutilization();
    atccsutilization(unsigned int at = 0);
    virtual ~atccsutilization();
    void updateUtilization();
private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id;
    unsigned int _at;
    unsigned int _start = 0;
    unsigned int _end = 0;
    unsigned int _user = 0;
    unsigned int _plan = 0;
    unsigned int _occupation = 0;
    unsigned int _priority = 0;
    std::string _descirption;
};
#endif /* ATCCSUTILIZATION_H */

