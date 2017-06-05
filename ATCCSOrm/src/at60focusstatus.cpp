/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60focusstatus.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 9:56 AM
 */

#include "at60focusstatus.h"
#include "at60focusstatus-odb.hxx"
#include "ORMHelper.h"
at60focusstatus::at60focusstatus() {
}

at60focusstatus::at60focusstatus(const at60focusstatus& orig) {
}

at60focusstatus::~at60focusstatus() {
}

unsigned long long at60focusstatus::persistStatus() 
{
    unsigned long long id =0;
    id = ORMHelper::persist<at60focusstatus*>(this);
    return id;
}
