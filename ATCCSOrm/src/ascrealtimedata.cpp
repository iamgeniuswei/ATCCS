/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ascrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月22日, 下午3:15
 */

#include "ascrealtimedata.h"
#include "ascrealtimedata-odb.hxx"
#include "ORMHelper.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
ascrealtimedata::ascrealtimedata()
{
}

ascrealtimedata::~ascrealtimedata()
{
}

unsigned int ascrealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = emerealtimedata::setRealtimeData(data);
    
    if(ret == SUCCESS)
    {
        if(data->size() != sizeof(_ATCCSPHeader) + sizeof(_EME_ASC_REALTIME_DATA))
            return RAWDATAERROR;
        _EME_ASC_REALTIME_DATA *asc = (_EME_ASC_REALTIME_DATA*)(data->data() + sizeof(_ATCCSPHeader));
        _shutterspeed = asc->shutterspeed;
        _aperture = asc->aperture;
        _jpeg = asc->jpeg;
        _iso = asc->iso;
        _fits = asc->fits;
        _raw = asc->raw;
        return SUCCESS;
    }
    
    return ret;
}

unsigned long long ascrealtimedata::persistRealtimeData()
{
    return ORMHelper::persist<ascrealtimedata*>(this);
}

