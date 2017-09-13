/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dustrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 上午10:39
 */

#include "dustrealtimedata.h"
#include "dustrealtimedata-odb.hxx"
#include "ORMHelper.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
dustrealtimedata::dustrealtimedata()
{
}

dustrealtimedata::~dustrealtimedata()
{
}

unsigned long long dustrealtimedata::persistRealtimeData()
{
    return ORMHelper::persist<dustrealtimedata*>(this);
}

unsigned int dustrealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = emerealtimedata::setRealtimeData(data);
    
    if(ret == SUCCESS)
    {
        if(data->size() != sizeof(_ATCCSPHeader) + sizeof(_EME_DUST_REALTIME_DATA))
            return RAWDATAERROR;
        _EME_DUST_REALTIME_DATA *dust = (_EME_DUST_REALTIME_DATA*)(data->data() + sizeof(_ATCCSPHeader));
        
        _dustdata = dust->dust_data;
        
        return SUCCESS;
    }
    
    return ret;
}


