/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Testclass_wsrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017-6-22, 16:08:31
 */

#ifndef TESTCLASS_WSREALTIMEDATA_H
#define TESTCLASS_WSREALTIMEDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "wsrealtimedata.h"
class Testclass_wsrealtimedata : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(Testclass_wsrealtimedata);

    CPPUNIT_TEST(testWsrealtimedata);
    CPPUNIT_TEST(testPersistRealtimeData);
    CPPUNIT_TEST(testSetRealtimeData);

    CPPUNIT_TEST_SUITE_END();

public:
    Testclass_wsrealtimedata();
    virtual ~Testclass_wsrealtimedata();
    void setUp();
    void tearDown();

private:
    void testWsrealtimedata();
    void testPersistRealtimeData();
    void testSetRealtimeData();
    wsrealtimedata *ws;
};

#endif /* TESTCLASS_WSREALTIMEDATA_H */

