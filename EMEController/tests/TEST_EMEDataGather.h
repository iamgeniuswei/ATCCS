/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TEST_EMEDataGather.h
 * Author: lenovo
 *
 * Created on 2017-6-23, 16:22:43
 */

#ifndef TEST_EMEDATAGATHER_H
#define TEST_EMEDATAGATHER_H

#include <cppunit/extensions/HelperMacros.h>
#include <memory>
class EMEDataGather;
class TEST_EMEDataGather : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(TEST_EMEDataGather);

    CPPUNIT_TEST(testASCEMEDataGather);
    CPPUNIT_TEST(testRealtimeInstance);
    CPPUNIT_TEST(testASCResolveData);
    CPPUNIT_TEST(testType);
    CPPUNIT_TEST(testRun);

    CPPUNIT_TEST_SUITE_END();

public:
    TEST_EMEDataGather();
    virtual ~TEST_EMEDataGather();
    void setUp();
    void tearDown();

private:
    void testASCEMEDataGather();
    void testASCResolveData();
    void testType();
    void testRun();
    void testRealtimeInstance();
    std::shared_ptr<EMEDataGather> dataGather = nullptr;

};

#endif /* TEST_EMEDATAGATHER_H */

