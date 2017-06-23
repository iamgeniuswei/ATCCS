/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TEST_EMEDataGather.cpp
 * Author: lenovo
 *
 * Created on 2017-6-23, 16:22:43
 */

#include "TEST_EMEDataGather.h"
#include "EMEDataGather.h"
#include "atccs_public_define.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TEST_EMEDataGather);

TEST_EMEDataGather::TEST_EMEDataGather()
{
}

TEST_EMEDataGather::~TEST_EMEDataGather()
{
}

void TEST_EMEDataGather::setUp()
{
    dataGather = std::make_shared<EMEDataGather>(ASC);
}

void TEST_EMEDataGather::tearDown()
{
}

void TEST_EMEDataGather::testEMEDataGather()
{
    CPPUNIT_ASSERT(dataGather->type() == ASC);
}

void TEST_EMEDataGather::testType()
{

}

void TEST_EMEDataGather::testRun()
{

}

