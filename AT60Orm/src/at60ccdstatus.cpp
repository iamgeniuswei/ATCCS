/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60ccdstatus.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 9:19 AM
 */

#include "at60ccdstatus.h"
#include "at60ccdstatus-odb.hxx"
#include "ORMHelper.h"
at60ccdstatus::at60ccdstatus() {
}

at60ccdstatus::at60ccdstatus(const at60ccdstatus& orig) {
}

at60ccdstatus::~at60ccdstatus() {
}

unsigned long long at60ccdstatus::persistStatus() 
{
    unsigned long long id =0;
    id = ORMHelper::persist<at60ccdstatus*>(this);
    return id;
}
