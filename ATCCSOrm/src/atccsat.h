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
#pragma db object
class atccsat {
public:
    atccsat();
    atccsat(const atccsat& orig);
    virtual ~atccsat();
private:
    friend class odb::access;
    unsigned int _id;
    std::string _name;
    std::string _description;
};
#pragma db member(atccsat::_id) id
#endif /* ATCCSAT_H */

