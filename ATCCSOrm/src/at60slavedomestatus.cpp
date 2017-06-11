/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60slavedomestatus.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 10:05 AM
 */

#include "at60slavedomestatus.h"
#include "at60slavedomestatus-odb.hxx"
#include "ORMHelper.h"
#include <iostream>
at60slavedomestatus::at60slavedomestatus() {
}

at60slavedomestatus::at60slavedomestatus(const at60slavedomestatus& orig) {
}

at60slavedomestatus::~at60slavedomestatus() {
}

unsigned long long at60slavedomestatus::persistStatus() {
    unsigned long long id =0;
    id = ORMHelper::persist<at60slavedomestatus*>(this);
    return id;
}

