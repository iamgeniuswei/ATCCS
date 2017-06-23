/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Testclass_sqmrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午10:21
 */

#ifndef TESTCLASS_SQMREALTIMEDATA_H
#define TESTCLASS_SQMREALTIMEDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "sqmrealtimedata.h"
class Testclass_sqmrealtimedata : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(Testclass_sqmrealtimedata);
    CPPUNIT_TEST(testSQMRealtimedata);
    CPPUNIT_TEST(testPersist);
    CPPUNIT_TEST(testSetRealtimeData);
    CPPUNIT_TEST_SUITE_END();

public:
    Testclass_sqmrealtimedata();
    virtual ~Testclass_sqmrealtimedata();
    void setUp();
    void tearDown();

private:
    sqmrealtimedata *sqm;
    void testSQMRealtimedata();
    void testSetRealtimeData();
    void testPersist();
};

#endif /* TESTCLASS_SQMREALTIMEDATA_H */

