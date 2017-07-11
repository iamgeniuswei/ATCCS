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
#include "emedatagather.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include "atccsdata.h"
#include <string.h>
#include "ascrealtimedata.h"
#include "wsrealtimedata.h"
#include "emerealtimedata.h"
#include "ORMHelper.h"


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
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
}

void TEST_EMEDataGather::tearDown()
{
}

void TEST_EMEDataGather::testASCEMEDataGather()
{
    CPPUNIT_ASSERT(dataGather->type() == ASC);
}

void TEST_EMEDataGather::testRealtimeInstance()
{
    std::shared_ptr<emerealtimedata> temp = dataGather->realtimeData();
    CPPUNIT_ASSERT(std::dynamic_pointer_cast<ascrealtimedata>(temp) != nullptr);
}

void TEST_EMEDataGather::testASCResolveData()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_ASC_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_ASC_REALTIME_DATA);
    header.msg = EMEREALDATA;
    _EME_ASC_REALTIME_DATA tasc;
    memset(&tasc, 0, sizeof (_EME_ASC_REALTIME_DATA));
    tasc.aperture = 10.1;
    tasc.fits = 0;
    tasc.iso = 1;
    tasc.jpeg = 0;
    tasc.raw = 0;
    tasc.shutterspeed = 23.333;
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tasc, sizeof (_EME_ASC_REALTIME_DATA));
    CPPUNIT_ASSERT(dataGather->resolveRealtimeData(data) != 0);

}




void TEST_EMEDataGather::testType()
{

}

void TEST_EMEDataGather::testRun()
{

}

