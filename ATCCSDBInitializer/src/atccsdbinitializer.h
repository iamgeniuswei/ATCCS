/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDBInitializer.h
 * Author: lenovo
 *
 * Created on July 27, 2017, 11:04 AM
 */

#ifndef ATCCSDBINITIALIZER_H
#define ATCCSDBINITIALIZER_H
#include <string>
class ATCCSDBInitializer
{
public:
    ATCCSDBInitializer();
    ATCCSDBInitializer(const ATCCSDBInitializer& orig) = delete;
    ATCCSDBInitializer(const ATCCSDBInitializer&& orig) = delete;
    ATCCSDBInitializer& operator=(const ATCCSDBInitializer& orig) = delete;
    ATCCSDBInitializer& operator=(const ATCCSDBInitializer&& orig) = delete;
    virtual ~ATCCSDBInitializer();
    static void initializeTable(const std::string& tableName);
    static void initializeSystemTable();
    static void initializeATTable(unsigned int at);
    static void initializeEMETable();

protected:
    static void initializeAT60Table();
    static void initializeAT80Table();

};

#endif /* ATCCSDBINITIALIZER_H */

