/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Testclass_dustrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午10:44
 */

#ifndef TESTCLASS_DUSTREALTIMEDATA_H
#define TESTCLASS_DUSTREALTIMEDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "dustrealtimedata.h"
class Testclass_dustrealtimedata : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(Testclass_dustrealtimedata);
    CPPUNIT_TEST(testDustrealtimedata);
    CPPUNIT_TEST(testPersist);
    CPPUNIT_TEST(testSetrealtimedata);
    CPPUNIT_TEST_SUITE_END();

public:
    Testclass_dustrealtimedata();
    virtual ~Testclass_dustrealtimedata();
    void setUp();
    void tearDown();

private:
    dustrealtimedata *dust;
    void testDustrealtimedata();
    void testSetrealtimedata();
    void testPersist();
};

#endif /* TESTCLASS_DUSTREALTIMEDATA_H */

