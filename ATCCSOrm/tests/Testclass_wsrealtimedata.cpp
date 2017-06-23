/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Testclass_wsrealtimedata.cpp
 * Author: lenovo
 *
 * Created on 2017-6-22, 16:08:31
 */

#include "Testclass_wsrealtimedata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include "atccsdata.h"
#include <string.h>
#include <iostream>
using namespace std;
#include "ORMHelper.h"


CPPUNIT_TEST_SUITE_REGISTRATION(Testclass_wsrealtimedata);

Testclass_wsrealtimedata::Testclass_wsrealtimedata()
{
}

Testclass_wsrealtimedata::~Testclass_wsrealtimedata()
{
}

void Testclass_wsrealtimedata::setUp()
{
    ws = new wsrealtimedata();
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
}

void Testclass_wsrealtimedata::tearDown()
{
    delete ws;
}

void Testclass_wsrealtimedata::testWsrealtimedata()
{
    CPPUNIT_ASSERT(ws->_dewpoint == 0);
    CPPUNIT_ASSERT(ws->_humidity == 0);
    CPPUNIT_ASSERT(ws->_illumination == 0);
    CPPUNIT_ASSERT(ws->_pressure == 0);
    CPPUNIT_ASSERT(ws->_raidation == 0);
    CPPUNIT_ASSERT(ws->_rainfall == 0);
    CPPUNIT_ASSERT(ws->_temperature == 0);
    CPPUNIT_ASSERT(ws->_windspeed == 0);
    CPPUNIT_ASSERT(ws->_windderection == 0);
    CPPUNIT_ASSERT(ws->_windspeed10 == 0);
    CPPUNIT_ASSERT(ws->_windspeed2 == 0);
}

void Testclass_wsrealtimedata::testPersistRealtimeData()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_WS_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_WS_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 100;
    header.tv_usec = 200;
    _EME_WS_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_WS_REALTIME_DATA));
    tws.dewpoint = 22.22;
    tws.humidity = 33.33;
    tws.illumination = 44.44;
    tws.pressure = 55.55;
    tws.raidation = 66.66;
    tws.rainfall = 77.77;
    tws.temperature = 88.88;
    tws.windderection = 4;
    tws.windspeed = 99.99;
    tws.windspeed2 = 111.111;
    tws.windspeed10 = 122.122;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_WS_REALTIME_DATA));

    CPPUNIT_ASSERT(ws->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(ws->_dewpoint == 22.22);
    CPPUNIT_ASSERT(ws->_humidity == 33.33);
    CPPUNIT_ASSERT(ws->_illumination == 44.44);
    CPPUNIT_ASSERT(ws->_pressure == 55.55);
    CPPUNIT_ASSERT(ws->_raidation == 66.66);
    CPPUNIT_ASSERT(ws->_rainfall == 77.77);
    CPPUNIT_ASSERT(ws->_temperature == 88.88);
    CPPUNIT_ASSERT(ws->_windderection == 4);
    CPPUNIT_ASSERT(ws->_windspeed == 99.99);
    CPPUNIT_ASSERT(ws->_windspeed2 == 111.111);
    CPPUNIT_ASSERT(ws->_windspeed10 == 122.122);
    CPPUNIT_ASSERT(ws->id() == 0);
    CPPUNIT_ASSERT(ws->sec() == 100);
    CPPUNIT_ASSERT(ws->sec() == 100);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
    
    unsigned long long id = 0;
    try
    {
        id = ws->persistRealtimeData();
    }
    catch(std::exception &e)
    {
        cout << e.what() << endl;
    }
    CPPUNIT_ASSERT(id != 0);
}

void Testclass_wsrealtimedata::testSetRealtimeData()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_WS_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_WS_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 100;
    header.tv_usec = 200;
    _EME_WS_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_WS_REALTIME_DATA));
    tws.dewpoint = 22.22;
    tws.humidity = 33.33;
    tws.illumination = 44.44;
    tws.pressure = 55.55;
    tws.raidation = 66.66;
    tws.rainfall = 77.77;
    tws.temperature = 88.88;
    tws.windderection = 4;
    tws.windspeed = 99.99;
    tws.windspeed2 = 111.111;
    tws.windspeed10 = 122.122;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_WS_REALTIME_DATA));

    CPPUNIT_ASSERT(ws->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(ws->_dewpoint == 22.22);
    CPPUNIT_ASSERT(ws->_humidity == 33.33);
    CPPUNIT_ASSERT(ws->_illumination == 44.44);
    CPPUNIT_ASSERT(ws->_pressure == 55.55);
    CPPUNIT_ASSERT(ws->_raidation == 66.66);
    CPPUNIT_ASSERT(ws->_rainfall == 77.77);
    CPPUNIT_ASSERT(ws->_temperature == 88.88);
    CPPUNIT_ASSERT(ws->_windderection == 4);
    CPPUNIT_ASSERT(ws->_windspeed == 99.99);
    CPPUNIT_ASSERT(ws->_windspeed2 == 111.111);
    CPPUNIT_ASSERT(ws->_windspeed10 == 122.122);
    CPPUNIT_ASSERT(ws->id() == 0);
    CPPUNIT_ASSERT(ws->sec() == 100);
    CPPUNIT_ASSERT(ws->sec() == 100);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
}

