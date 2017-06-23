/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.h
 * Author: lenovo
 *
 * Created on 2017-6-22, 11:20:34
 */

#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H
#include "emerealtimedata.h"
#include <cppunit/extensions/HelperMacros.h>
class newtestclass : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testSetRealtimeDataRetNULL);
    CPPUNIT_TEST(testSetRealtimeDataRetERROR);
    CPPUNIT_TEST(testSetRealtimeDataRetSUCCESS);
    CPPUNIT_TEST(testDefaultConstructor);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testSetRealtimeDataRetNULL();
    void testSetRealtimeDataRetERROR();
    void testSetRealtimeDataRetSUCCESS();
    void testDefaultConstructor();
    emerealtimedata *eme;

};

#endif /* NEWTESTCLASS_H */

