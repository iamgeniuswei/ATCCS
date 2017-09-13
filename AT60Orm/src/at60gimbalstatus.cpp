/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60GimbalStatus.cpp
 * Author: lenovo
 * 
 * Created on May 8, 2017, 4:16 PM
 */

#include "at60gimbalstatus.h"
#include "at60gimbalstatus-odb.hxx"
#include "ORMHelper.h"
at60gimbalstatus::at60gimbalstatus() {
}

at60gimbalstatus::at60gimbalstatus(const at60gimbalstatus& orig) {
}

at60gimbalstatus::~at60gimbalstatus() {
}

unsigned long long at60gimbalstatus::persistStatus() 
{    
    unsigned long long id =0;
    id = ORMHelper::persist<at60gimbalstatus*>(this);
    return id;
}

