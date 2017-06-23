/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月22日, 下午4:29
 */

#include "csrealtimedata.h"
#include "csrealtimedata-odb.hxx"
#include "ORMHelper.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
csrealtimedata::csrealtimedata()
{
}

csrealtimedata::~csrealtimedata()
{
}

unsigned long long csrealtimedata::persistRealtimeData()
{

    return ORMHelper::persist<csrealtimedata*>(this);

}

unsigned int csrealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = emerealtimedata::setRealtimeData(data);
    
    if(ret == SUCCESS)
    {
        if(data->size() != sizeof(_ATCCSPHeader) + sizeof(_EME_CS_REALTIME_DATA))
            return RAWDATAERROR;
        _EME_CS_REALTIME_DATA *cs = (_EME_CS_REALTIME_DATA*)(data->data() + sizeof(_ATCCSPHeader));
        
        _RelSkyT = cs->RelSkyT;
        _AmbientT = cs->AmbientT;
        _SensorT = cs->SensorT;
        _RainF = cs->RainF;
        _RainThreshV = cs->RainThreshV;
        _wind = cs->wind;
        _WindUnits = cs->WindUnits;
        _HumidityPercent = cs->HumidityPercent;
        _DewPointT = cs->DewPointT;
        _DayLightV = cs->DayLightV;
        
        return SUCCESS;
    }
    
    return ret;
}


