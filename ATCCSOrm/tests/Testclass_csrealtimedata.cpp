/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Testclass_csrealtimedata.cpp
 * Author: lenovo
 *
 * Created on 2017-6-22, 16:38:31
 */

#include "Testclass_csrealtimedata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include "atccsdata.h"
#include <string.h>
#include "ORMHelper.h"
#include <iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(Testclass_csrealtimedata);

Testclass_csrealtimedata::Testclass_csrealtimedata()
{
}

Testclass_csrealtimedata::~Testclass_csrealtimedata()
{
}

void Testclass_csrealtimedata::setUp()
{
    cs = new csrealtimedata;
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
}

void Testclass_csrealtimedata::tearDown()
{
    delete cs;
}

void Testclass_csrealtimedata::testCsrealtimedata()
{
    CPPUNIT_ASSERT(cs->_AmbientT == 0);
    CPPUNIT_ASSERT(cs->_DayLightV == 0);
    CPPUNIT_ASSERT(cs->_DewPointT == 0);
    CPPUNIT_ASSERT(cs->_HumidityPercent == 0);
    CPPUNIT_ASSERT(cs->_RainF == 0);
    CPPUNIT_ASSERT(cs->_RainThreshV == 0);
    CPPUNIT_ASSERT(cs->_RelSkyT == 0);
    CPPUNIT_ASSERT(cs->_SensorT == 0);
    CPPUNIT_ASSERT(cs->_WindUnits == 0);
    CPPUNIT_ASSERT(cs->_wind == 0);
    CPPUNIT_ASSERT(cs->id() == 0);
    CPPUNIT_ASSERT(cs->sec() == 0);
    CPPUNIT_ASSERT(cs->msec() == 0);

}

void Testclass_csrealtimedata::testPersistRealtimeData()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_CS_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_CS_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 100;
    header.tv_usec = 200;
    _EME_CS_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_CS_REALTIME_DATA));
    tws.AmbientT = 22.22;
    tws.DayLightV = 33.33;
    tws.DewPointT = 44.44;
    tws.HumidityPercent = 55.55;
    tws.RainF = 6;
    tws.RainThreshV = 7;
    tws.RelSkyT = 88.88;
    tws.SensorT = 99.899;
    tws.WindUnits = 9;
    tws.wind = 111.111;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_CS_REALTIME_DATA));

    CPPUNIT_ASSERT(cs->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(cs->_AmbientT == 22.22);
    CPPUNIT_ASSERT(cs->_DayLightV == 33.33);
    CPPUNIT_ASSERT(cs->_DewPointT == 44.44);
    CPPUNIT_ASSERT(cs->_HumidityPercent == 55.55);
    CPPUNIT_ASSERT(cs->_RainF == 6);
    CPPUNIT_ASSERT(cs->_RainThreshV == 7);
    CPPUNIT_ASSERT(cs->_RelSkyT == 88.88);
    CPPUNIT_ASSERT(cs->_SensorT == 99.899);
    CPPUNIT_ASSERT(cs->_WindUnits == 9);
    CPPUNIT_ASSERT(cs->_wind == 111.111);
    CPPUNIT_ASSERT(cs->id() == 0);
    CPPUNIT_ASSERT(cs->sec() == 100);
    CPPUNIT_ASSERT(cs->msec() == 200);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
    unsigned long long id = 0;
    try
    {
        id = cs->persistRealtimeData();
    }
    catch(std::exception &e)
    {
        cout << e.what() << endl;
    }
    CPPUNIT_ASSERT(id != 0);
}

void Testclass_csrealtimedata::testSetRealtimeData()
{
std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_CS_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_CS_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 100;
    header.tv_usec = 200;
    _EME_CS_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_CS_REALTIME_DATA));
    tws.AmbientT = 22.22;
    tws.DayLightV = 33.33;
    tws.DewPointT = 44.44;
    tws.HumidityPercent = 55.55;
    tws.RainF = 6;
    tws.RainThreshV = 7;
    tws.RelSkyT = 88.88;
    tws.SensorT = 99.899;
    tws.WindUnits = 9;
    tws.wind = 111.111;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_CS_REALTIME_DATA));

    CPPUNIT_ASSERT(cs->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(cs->_AmbientT == 22.22);
    CPPUNIT_ASSERT(cs->_DayLightV == 33.33);
    CPPUNIT_ASSERT(cs->_DewPointT == 44.44);
    CPPUNIT_ASSERT(cs->_HumidityPercent == 55.55);
    CPPUNIT_ASSERT(cs->_RainF == 6);
    CPPUNIT_ASSERT(cs->_RainThreshV == 7);
    CPPUNIT_ASSERT(cs->_RelSkyT == 88.88);
    CPPUNIT_ASSERT(cs->_SensorT == 99.899);
    CPPUNIT_ASSERT(cs->_WindUnits == 9);
    CPPUNIT_ASSERT(cs->_wind == 111.111);
    CPPUNIT_ASSERT(cs->id() == 0);
    CPPUNIT_ASSERT(cs->sec() == 100);
    CPPUNIT_ASSERT(cs->msec() == 200);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
}

