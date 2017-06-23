/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sqmrealtimedata.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 上午10:14
 */

#include "sqmrealtimedata.h"
#include "sqmrealtimedata-odb.hxx"
#include "ORMHelper.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_eme_define.h"
sqmrealtimedata::sqmrealtimedata()
{
}

sqmrealtimedata::~sqmrealtimedata()
{
}

unsigned long long sqmrealtimedata::persistRealtimeData()
{
    return ORMHelper::persist<sqmrealtimedata*>(this);
}

unsigned int sqmrealtimedata::setRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned int ret = emerealtimedata::setRealtimeData(data);
    
    if(ret == SUCCESS)
    {
        if(data->size() != sizeof(_ATCCSPHeader) + sizeof(_EME_SQM_REALTIME_DATA))
            return RAWDATAERROR;
        _EME_SQM_REALTIME_DATA *sqm = (_EME_SQM_REALTIME_DATA*)(data->data() + sizeof(_ATCCSPHeader));
        
        _sqmdata = sqm->sqmdata;
        
        return SUCCESS;
    }
    
    return ret;
            
}


