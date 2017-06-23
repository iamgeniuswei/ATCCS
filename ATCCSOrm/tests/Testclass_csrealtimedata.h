/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Testclass_csrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017-6-22, 16:38:31
 */

#ifndef TESTCLASS_CSREALTIMEDATA_H
#define TESTCLASS_CSREALTIMEDATA_H

#include <cppunit/extensions/HelperMacros.h>
#include "csrealtimedata.h"
class Testclass_csrealtimedata : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(Testclass_csrealtimedata);

    CPPUNIT_TEST(testCsrealtimedata);
    CPPUNIT_TEST(testPersistRealtimeData);
    CPPUNIT_TEST(testSetRealtimeData);

    CPPUNIT_TEST_SUITE_END();

public:
    Testclass_csrealtimedata();
    virtual ~Testclass_csrealtimedata();
    void setUp();
    void tearDown();

private:
    void testCsrealtimedata();
    void testPersistRealtimeData();
    void testSetRealtimeData();
    csrealtimedata *cs;

};

#endif /* TESTCLASS_CSREALTIMEDATA_H */

