/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsdevice.h
 * Author: lenovo
 *
 * Created on May 18, 2017, 9:43 AM
 */

#ifndef ATCCSDEVICE_H
#define ATCCSDEVICE_H
#include <odb/core.hxx>
#include <string>

/**
 * @brief atccsdevice is a persistence class and stored in a dictionary table,
 * which enumerates the devices of an AT. 
 */
#pragma db object
class atccsdevice {
public:
    atccsdevice();
    atccsdevice(const atccsdevice& orig);
    virtual ~atccsdevice();
private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id;
    std::string _name;
    std::string _description;
};

#endif /* ATCCSDEVICE_H */

