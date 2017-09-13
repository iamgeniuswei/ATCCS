/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60filterstatus.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 9:43 AM
 */

#include "at60filterstatus.h"
#include "at60filterstatus-odb.hxx"
#include "ORMHelper.h"
at60filterstatus::at60filterstatus() {
}

at60filterstatus::at60filterstatus(const at60filterstatus& orig) {
}

at60filterstatus::~at60filterstatus() {
}

unsigned long long at60filterstatus::persistStatus() 
{
    unsigned long long id =0;
    id = ORMHelper::persist<at60filterstatus*>(this);
    return id;
}


