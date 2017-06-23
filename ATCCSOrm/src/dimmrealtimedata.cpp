/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dimmrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 上午10:51
 */

#include "dimmrealtimedata.h"
#include "dimmrealtimedata-odb.hxx"
#include "ORMHelper.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
dimmrealtimedata::dimmrealtimedata()
{
}

dimmrealtimedata::~dimmrealtimedata()
{
}

unsigned long long dimmrealtimedata::persistRealtimeData()
{
    return ORMHelper::persist<dimmrealtimedata*>(this);
}

unsigned int dimmrealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = emerealtimedata::setRealtimeData(data);
    
    if(ret == SUCCESS)
    {
        if(data->size() != sizeof(_ATCCSPHeader) + sizeof(_EME_DIMM_REALTIME_DATA))
            return RAWDATAERROR;
        _EME_DIMM_REALTIME_DATA *dimm = (_EME_DIMM_REALTIME_DATA*)(data->data() + sizeof(_ATCCSPHeader));
        
        _dimmdata = dimm->dimm_data;
        
        return SUCCESS;
    }
    
    return ret;
}


