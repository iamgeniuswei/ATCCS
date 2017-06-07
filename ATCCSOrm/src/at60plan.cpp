/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60plan.cpp
 * Author: lenovo
 * 
 * Created on May 15, 2017, 5:06 PM
 */

#include "at60plan.h"
#include "ORMHelper.h"
#include "at60plan-odb.hxx"
at60plan::at60plan() {
}

at60plan::at60plan(const at60plan& orig) {
}

unsigned int at60plan::persistPlan()
{
    unsigned long long id =0;
    id = ORMHelper::persist<at60plan*>(this);
    return id;
}

