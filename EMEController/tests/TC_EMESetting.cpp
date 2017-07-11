/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TC_EMESetting.cpp
 * Author: lenovo
 *
 * Created on Jun 27, 2017, 4:01:41 PM
 */

#include "TC_EMESetting.h"
#include "emesetting.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TC_EMESetting);

TC_EMESetting::TC_EMESetting()
{
}

TC_EMESetting::~TC_EMESetting()
{
}

void TC_EMESetting::setUp()
{
    set = new EMESetting();
}

void TC_EMESetting::tearDown()
{
    delete set;
}

void TC_EMESetting::testEMESetting()
{
    CPPUNIT_ASSERT(set->dbAddress() == nullptr);
    CPPUNIT_ASSERT(set->hostAddress() == nullptr);
}

void TC_EMESetting::testInitSysSetting()
{
    CPPUNIT_ASSERT(set->initSysSetting() == true);
}

void TC_EMESetting::testHostAddress()
{
    
}

void TC_EMESetting::testDbAddress()
{

}

void TC_EMESetting::testSettingFilePath()
{

}

void TC_EMESetting::testInitDBAddress()
{

}

void TC_EMESetting::testInitHostAddress()
{

}

