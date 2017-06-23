/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: lenovo
 *
 * Created on 2017-6-22, 11:20:34
 */

#include <cstring>

#include "newtestclass.h"
#include "emerealtimedata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
#include "atccsdata.h"

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass()
{
}

newtestclass::~newtestclass()
{
}

void newtestclass::setUp()
{
    eme = new emerealtimedata();
}

void newtestclass::tearDown()
{
    delete eme;
}

void newtestclass::testSetRealtimeDataRetNULL()
{
    std::shared_ptr<ATCCSData> data;
    emerealtimedata _emerealtimedata;
    CPPUNIT_ASSERT(_emerealtimedata.setRealtimeData(data) == emerealtimedata::RAWDATAISNULL);
}

void newtestclass::testSetRealtimeDataRetERROR()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof(_ATCCSPHeader)+sizeof(_EME_ASC_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof(_ATCCSPHeader));
    header.msg = EMEREALDATA;
    _EME_ASC_REALTIME_DATA asc;
    memset(&asc, 0, sizeof(_EME_ASC_REALTIME_DATA));
    memcpy(data->data(), &header, sizeof(_ATCCSPHeader));
    memcpy(data->data()+sizeof(_ATCCSPHeader) , &asc, sizeof(_EME_ASC_REALTIME_DATA));
    CPPUNIT_ASSERT(eme->setRealtimeData(data) == emerealtimedata::RAWDATAERROR);    
}

void newtestclass::testSetRealtimeDataRetSUCCESS()
{
    std::shared_ptr<ATCCSData> data = std::make_shared<ATCCSData>(sizeof(_ATCCSPHeader)+sizeof(_EME_ASC_REALTIME_DATA));
    _ATCCSPHeader header;
    memset(&header, 0, sizeof(_ATCCSPHeader));
    header.length = sizeof(_ATCCSPHeader)+sizeof(_EME_ASC_REALTIME_DATA);
    header.msg = EMEREALDATA;
    _EME_ASC_REALTIME_DATA asc;
    memset(&asc, 0, sizeof(_EME_ASC_REALTIME_DATA));
    memcpy(data->data(), &header, sizeof(_ATCCSPHeader));
    memcpy(data->data()+sizeof(_ATCCSPHeader) , &asc, sizeof(_EME_ASC_REALTIME_DATA));
    CPPUNIT_ASSERT(eme->setRealtimeData(data) == emerealtimedata::SUCCESS);  
}



void newtestclass::testDefaultConstructor()
{
    CPPUNIT_ASSERT(eme->id() == 0);
    CPPUNIT_ASSERT(eme->sec() == 0);
    CPPUNIT_ASSERT(eme->msec() == 0);
}
