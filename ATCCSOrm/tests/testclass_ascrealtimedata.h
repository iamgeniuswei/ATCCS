/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testclass_ascrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017-6-22, 15:28:55
 */

#ifndef TESTCLASS_ASCREALTIMEDATA_H
#define TESTCLASS_ASCREALTIMEDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "ascrealtimedata.h"

class testclass_ascrealtimedata : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(testclass_ascrealtimedata);

    CPPUNIT_TEST(testAscrealtimedata);
    CPPUNIT_TEST(testPersistRealtimeData);
    CPPUNIT_TEST(testSetRealtimeData);

    CPPUNIT_TEST_SUITE_END();

public:
    testclass_ascrealtimedata();
    virtual ~testclass_ascrealtimedata();
    void setUp();
    void tearDown();

private:
    void testAscrealtimedata();
    void testPersistRealtimeData();
    void testSetRealtimeData();
    ascrealtimedata *asc;
};

#endif /* TESTCLASS_ASCREALTIMEDATA_H */

