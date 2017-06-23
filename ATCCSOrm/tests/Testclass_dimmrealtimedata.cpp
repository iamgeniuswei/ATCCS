/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Testclass_dimmrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 上午10:55
 */

#include "Testclass_dimmrealtimedata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include "atccsdata.h"
#include <string.h>
#include "ORMHelper.h"
#include <iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(Testclass_dimmrealtimedata);

Testclass_dimmrealtimedata::Testclass_dimmrealtimedata()
{
}

Testclass_dimmrealtimedata::~Testclass_dimmrealtimedata()
{
}

void Testclass_dimmrealtimedata::setUp()
{
    dimm = new dimmrealtimedata();
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
}

void Testclass_dimmrealtimedata::tearDown()
{
    delete dimm;
}

void Testclass_dimmrealtimedata::testDimmrealtimedata()
{
    CPPUNIT_ASSERT(dimm->id() == 0);
    CPPUNIT_ASSERT(dimm->sec() == 0);
    CPPUNIT_ASSERT(dimm->msec() == 0);
    CPPUNIT_ASSERT(dimm->_dimmdata == 0);
}

void Testclass_dimmrealtimedata::testSetrealtimedata()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_DIMM_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_DIMM_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 300;
    header.tv_usec = 400;
    _EME_DIMM_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_DIMM_REALTIME_DATA));
    tws.dimm_data = 34343.3434343;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_DIMM_REALTIME_DATA));

    CPPUNIT_ASSERT(dimm->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(dimm->_dimmdata == 34343.3434343);

    CPPUNIT_ASSERT(dimm->id() == 0);
    CPPUNIT_ASSERT(dimm->sec() == 300);
    CPPUNIT_ASSERT(dimm->msec() == 400);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
}

void Testclass_dimmrealtimedata::testPersist()
{
        std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof (_ATCCSPHeader) + sizeof (_EME_DIMM_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof (_ATCCSPHeader));
    header.length = sizeof (_ATCCSPHeader) + sizeof (_EME_DIMM_REALTIME_DATA);
    header.msg = EMEREALDATA;
    header.tv_sec = 300;
    header.tv_usec = 400;
    _EME_DIMM_REALTIME_DATA tws;
    memset(&tws, 0, sizeof (_EME_DIMM_REALTIME_DATA));
    tws.dimm_data = 34343.3434343;
            
            
    memcpy(data->data(), &header, sizeof (_ATCCSPHeader));
    memcpy(data->data() + sizeof (_ATCCSPHeader), &tws, sizeof (_EME_DIMM_REALTIME_DATA));

    CPPUNIT_ASSERT(dimm->setRealtimeData(data) == emerealtimedata::SUCCESS);
    CPPUNIT_ASSERT(dimm->_dimmdata == 34343.3434343);

    CPPUNIT_ASSERT(dimm->id() == 0);
    CPPUNIT_ASSERT(dimm->sec() == 300);
    CPPUNIT_ASSERT(dimm->msec() == 400);
    CPPUNIT_ASSERT(header.msg == EMEREALDATA);
    unsigned long long id = 0;
    try
    {
        id = dimm->persistRealtimeData();
    }
    catch(std::exception &e)
    {
        cout << e.what() << endl;
    }
    CPPUNIT_ASSERT(id != 0);
}

