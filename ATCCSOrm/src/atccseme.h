/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccseme.h
 * Author: lenovo
 *
 * Created on July 27, 2017, 9:37 AM
 */

#ifndef ATCCSEME_H
#define ATCCSEME_H
#include <odb/core.hxx>
#include <string>
/**
 * atccseme is a persistence class and stored in a dictionary table, which 
 * enumerates the environmental monitor equipments
 */
#pragma db object
class atccseme
{
public:
    atccseme();
    atccseme(const atccseme& orig) = delete;
    atccseme(const atccseme&& orig) = delete;
    atccseme& operator=(const atccseme& orig) = delete;
    atccseme& operator=(const atccseme&& orig) = delete;
    virtual ~atccseme();

private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id;
    std::string _name;
    std::string _description;
};

#endif /* ATCCSEME_H */

