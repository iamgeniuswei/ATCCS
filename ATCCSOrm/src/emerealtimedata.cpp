/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   emerealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月21日, 上午10:31
 */

#include "emerealtimedata.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
emerealtimedata::emerealtimedata()
{
}

emerealtimedata::~emerealtimedata()
{
}

unsigned int emerealtimedata::msec() const
{
    return _msec;
}

unsigned int emerealtimedata::sec() const
{
    return _sec;
}

unsigned int emerealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
        return RAWDATAISNULL;
    if(!data->validate())
        return RAWDATAERROR;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    _sec = header->tv_sec;
    _msec = header->tv_usec;
    return SUCCESS;
}

unsigned long long emerealtimedata::id() const
{
    return _id;
}

