/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: lenovo
 *
 * Created on 2017-6-21, 16:09:37
 */

#include "newtestclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass()
{
}

newtestclass::~newtestclass()
{
}

void newtestclass::setUp()
{
}

void newtestclass::tearDown()
{
}

void newtestclass::testMethod()
{
    CPPUNIT_ASSERT(true);
}

void newtestclass::testFailedMethod()
{
    CPPUNIT_ASSERT(false);
}

