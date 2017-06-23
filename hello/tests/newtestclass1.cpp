/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass1.cpp
 * Author: lenovo
 *
 * Created on 2017-6-21, 16:19:36
 */

#include "newtestclass1.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1()
{
}

newtestclass1::~newtestclass1()
{
}

void newtestclass1::setUp()
{
}

void newtestclass1::tearDown()
{
}

void newtestclass1::testMethod()
{
    CPPUNIT_ASSERT(true);
}

void newtestclass1::testFailedMethod()
{
    CPPUNIT_ASSERT(true);
}

