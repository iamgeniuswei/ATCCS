/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Testclass_dimmrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午10:55
 */

#ifndef TESTCLASS_DIMMREALTIMEDATA_H
#define TESTCLASS_DIMMREALTIMEDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "dimmrealtimedata.h"

class Testclass_dimmrealtimedata : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(Testclass_dimmrealtimedata);
    CPPUNIT_TEST(testDimmrealtimedata);
    CPPUNIT_TEST(testPersist);
    CPPUNIT_TEST(testSetrealtimedata);
    CPPUNIT_TEST_SUITE_END();

public:
    Testclass_dimmrealtimedata();
    virtual ~Testclass_dimmrealtimedata();
    void setUp();
    void tearDown();

private:
    dimmrealtimedata *dimm;
    void testDimmrealtimedata();
    void testSetrealtimedata();
    void testPersist();
};

#endif /* TESTCLASS_DIMMREALTIMEDATA_H */

