/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsat.h
 * Author: lenovo
 *
 * Created on May 18, 2017, 9:39 AM
 */

#ifndef ATCCSAT_H
#define ATCCSAT_H
#include <odb/core.hxx>
#include <string>

/**
 * @brief atccsat is a persistence class and stored in a dictionary table, which
 * enumerates the ATs in an observation station. 
 */
#pragma db object
class atccsat 
{
public:
    atccsat();
    atccsat(const atccsat& orig);
    virtual ~atccsat();
private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id;
    std::string _name;
    std::string _description;
};
#endif /* ATCCSAT_H */

