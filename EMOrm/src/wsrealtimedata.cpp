/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wsrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月22日, 下午4:00
 */

#include "wsrealtimedata.h"
#include "wsrealtimedata-odb.hxx"
#include "ORMHelper.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
wsrealtimedata::wsrealtimedata()
{
}

wsrealtimedata::~wsrealtimedata()
{
    
}

unsigned int wsrealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = emerealtimedata::setRealtimeData(data);
    
    if(ret == SUCCESS)
    {
        if(data->size() != sizeof(_ATCCSPHeader) + sizeof(_EME_WS_REALTIME_DATA))
            return RAWDATAERROR;
        _EME_WS_REALTIME_DATA *ws = (_EME_WS_REALTIME_DATA*)(data->data() + sizeof(_ATCCSPHeader));
        
        _temperature = ws->temperature;
        _humidity = ws->humidity;
        _dewpoint = ws->dewpoint;
        _pressure = ws->pressure;
        _windspeed = ws->windspeed;
        _windspeed2 = ws->windspeed2;
        _windspeed10 = ws->windspeed10;
        _winddirection = ws->windderection;
        _rainfall = ws->rainfall;
        _radiation = ws->raidation;
        _illumination = ws->illumination;
        
        return SUCCESS;
    }
    
    return ret;
}


unsigned long long wsrealtimedata::persistRealtimeData()
{

    return ORMHelper::persist<wsrealtimedata*>(this);

}


