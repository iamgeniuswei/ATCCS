/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TC_EMESetting.h
 * Author: lenovo
 *
 * Created on Jun 27, 2017, 4:01:41 PM
 */

#ifndef TC_EMESETTING_H
#define TC_EMESETTING_H

#include <cppunit/extensions/HelperMacros.h>
#include "emesetting.h"
class TC_EMESetting : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(TC_EMESetting);

    CPPUNIT_TEST(testEMESetting);
    CPPUNIT_TEST(testInitSysSetting);
    CPPUNIT_TEST(testHostAddress);
    CPPUNIT_TEST(testDbAddress);
    CPPUNIT_TEST(testSettingFilePath);
    CPPUNIT_TEST(testInitDBAddress);
    CPPUNIT_TEST(testInitHostAddress);

    CPPUNIT_TEST_SUITE_END();

public:
    TC_EMESetting();
    virtual ~TC_EMESetting();
    void setUp();
    void tearDown();

private:
    void testEMESetting();
    void testInitSysSetting();
    void testHostAddress();
    void testDbAddress();
    void testSettingFilePath();
    void testInitDBAddress();
    void testInitHostAddress();
    EMESetting *set;

};

#endif /* TC_EMESETTING_H */

