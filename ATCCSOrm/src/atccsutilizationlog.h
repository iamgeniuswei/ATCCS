/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsutilizationlog.h
 * Author: lenovo
 *
 * Created on May 18, 2017, 10:53 AM
 */

#ifndef ATCCSUTILIZATIONLOG_H
#define ATCCSUTILIZATIONLOG_H
#include <odb/core.hxx>
#include <string>
#pragma db object
class atccsutilizationlog {
public:
    atccsutilizationlog();
    atccsutilizationlog(const atccsutilizationlog& orig);
    virtual ~atccsutilizationlog();
private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id = 0;
    unsigned int _at = 0;
    unsigned int _start = 0;
    unsigned int _end = 0;
    unsigned int _user = 0;
    unsigned int _priority = 0;
    unsigned int _status = 0;
    std::string _descirption;

};

#endif /* ATCCSUTILIZATIONLOG_H */

