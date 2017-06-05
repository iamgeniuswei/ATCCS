/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atccsutilization.cpp
 * Author: lenovo
 * 
 * Created on May 18, 2017, 9:47 AM
 */

#include "atccsutilization.h"
#include "atccsutilization-odb.hxx"
#include "ORMHelper.h"

atccsutilization::atccsutilization() 
{
}

atccsutilization::atccsutilization(unsigned int at) 
{
    _at = at;
}


atccsutilization::~atccsutilization() {
}

void atccsutilization::updateUtilization() 
{
    ORMHelper::update<atccsutilization*>(this);
}


