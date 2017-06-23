/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Testclass_dustrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 上午10:44
 */

#include "Testclass_dustrealtimedata.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include <string.h>
#include "ORMHelper.h"
#include <iostream>
using namespace std;
CPPUNIT_TEST_SUITE_REGISTRATION(Testclass_dustrealtimedata);

Testclass_dustrealtimedata::Testclass_dustrealtimedata()
{
}

Testclass_dustrealtimedata::~Testclass_dustrealtimedata()
{
}

void Testclass_dustrealtimedata::setUp()
{
    dust = new dustrealtimedata();
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
}

void Testclass_dustrealtimedata::tearDown()
{
    delete dust;
}

void Testclass_dustrealtimedata::testDustrealtimedata()
{
    CPPUNIT_ASSERT(dust->id() == 0);
    CPPUNIT_ASSERT(dust->sec() == 0);
    CPPUNIT_ASSERT(dust->msec() == 0);
    CPPUNIT_ASSERT(dust->_dustdata == 0);
}

void Testclass_dustrealtimedata::testSetrealtimedata()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_DUST_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_DUST_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 200;
    header.tv_usec = 600;
    _EME_DUST_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_DUST_REALTIME_DATA));
    tws.dust_data = 454577.3434343;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_DUST_REALTIME_DATA));

    CPPUNIT_ASSERT(dust->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(dust->_dustdata == 454577.3434343);

    CPPUNIT_ASSERT(dust->id() == 0);
    CPPUNIT_ASSERT(dust->sec() == 200);
    CPPUNIT_ASSERT(dust->msec() == 600);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
}

void Testclass_dustrealtimedata::testPersist()
{
        std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_DUST_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_DUST_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 200;
    header.tv_usec = 600;
    _EME_DUST_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_DUST_REALTIME_DATA));
    tws.dust_data = 454577.3434343;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_DUST_REALTIME_DATA));

    CPPUNIT_ASSERT(dust->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(dust->_dustdata == 454577.3434343);

    CPPUNIT_ASSERT(dust->id() == 0);
    CPPUNIT_ASSERT(dust->sec() == 200);
    CPPUNIT_ASSERT(dust->msec() == 600);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
    unsigned long long id = 0;
    try
    {
        id = dust->persistRealtimeData();
    }
    catch(std::exception &e)
    {
        cout << e.what() << endl;
    }
    CPPUNIT_ASSERT(id != 0);
}
