/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testclass_ascrealtimedata.cpp
 * Author: lenovo
 *
 * Created on 2017-6-22, 15:28:55
 */

#include "testclass_ascrealtimedata.h"
#include "ascrealtimedata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include "atccsdata.h"
#include <string.h>
#include "ORMHelper.h"
#include <iostream>
using namespace std;
CPPUNIT_TEST_SUITE_REGISTRATION(testclass_ascrealtimedata);

testclass_ascrealtimedata::testclass_ascrealtimedata()
{
}

testclass_ascrealtimedata::~testclass_ascrealtimedata()
{
}

void testclass_ascrealtimedata::setUp()
{
    asc = new ascrealtimedata();
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
}

void testclass_ascrealtimedata::tearDown()
{
    delete asc;
}

void testclass_ascrealtimedata::testAscrealtimedata()
{
    CPPUNIT_ASSERT(asc->_aperture == 0);
    CPPUNIT_ASSERT(asc->_fits == 0);
    CPPUNIT_ASSERT(asc->_iso == 0);
    CPPUNIT_ASSERT(asc->_jpeg == 0);
    CPPUNIT_ASSERT(asc->_raw == 0);
    CPPUNIT_ASSERT(asc->_shutterspeed == 0);
}

void testclass_ascrealtimedata::testPersistRealtimeData()
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

    CPPUNIT_ASSERT(asc->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(asc->_aperture == 10.1);
    CPPUNIT_ASSERT(asc->_fits == 0);
    CPPUNIT_ASSERT(asc->_iso == 1);
    CPPUNIT_ASSERT(asc->_jpeg == 0);
    CPPUNIT_ASSERT(asc->_raw == 0);
    CPPUNIT_ASSERT(asc->_shutterspeed == 23.333);
    unsigned long long id = 0;
    try
    {
        id = asc->persistRealtimeData();
    }
    catch(std::exception &e)
    {
        cout << e.what() << endl;
    }
    CPPUNIT_ASSERT(id != 0);
}

void testclass_ascrealtimedata::testSetRealtimeData()
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

    CPPUNIT_ASSERT(asc->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(asc->_aperture == 10.1);
    CPPUNIT_ASSERT(asc->_fits == 0);
    CPPUNIT_ASSERT(asc->_iso == 1);
    CPPUNIT_ASSERT(asc->_jpeg == 0);
    CPPUNIT_ASSERT(asc->_raw == 0);
    CPPUNIT_ASSERT(asc->_shutterspeed == 23.333);

}

