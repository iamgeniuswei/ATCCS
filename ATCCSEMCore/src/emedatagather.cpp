/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMEDataGather.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 下午4:08
 */

#include "emedatagather.h"
#include "atccs_public_define.h"
#include "ascrealtimedata.h"
#include "wsrealtimedata.h"
#include "csrealtimedata.h"
#include "sqmrealtimedata.h"
#include "dustrealtimedata.h"
#include "dimmrealtimedata.h"
#include "atccsexceptionhandler.h"

EMEDataGather::EMEDataGather(unsigned int type)
    :_type(type)
{
}

EMEDataGather::~EMEDataGather()
{
}

std::shared_ptr<emerealtimedata> EMEDataGather::realtimeData()
{    
    switch(_type)
    {
        case ASC:
        {
            _realtimeData = std::make_shared<ascrealtimedata>();
            break;
        }
        case WS:
        {
            _realtimeData = std::make_shared<wsrealtimedata>();
            break;
        }
        case CS:
        {
            _realtimeData = std::make_shared<csrealtimedata>();
            break;
        }
        case SQM:
        {
            _realtimeData = std::make_shared<sqmrealtimedata>();
            break;
        }
        case DUST:
        {
            _realtimeData = std::make_shared<dustrealtimedata>();
            break;
        }
        case DIMM:
        {
            _realtimeData = std::make_shared<dimmrealtimedata>();
            break;
        }
        default:
        {
            break;
        }
    }
    return _realtimeData;
}

void EMEDataGather::run()
{
    while (!stop())
    {
        try
        {
            std::shared_ptr<ATCCSData> data = popControlData();
            if(!data)
                continue;
            resolveRealtimeData(data);
        }
        catch(std::exception &e)
        {
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s%s",
                                                gettext("Fails to resolve realtimedata. device: "), device().c_str(), e.what());
        }
    }
}

unsigned long long EMEDataGather::resolveRealtimeData(std::shared_ptr<ATCCSData> data)
{
    unsigned long long id = 0;
    if(!_realtimeData)
    {
        try
        {
            realtimeData();
        }
        catch(std::exception &e)
        {
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s%s",
                                                gettext("Fails to create realtimedata. device: "), device().c_str(), e.what());
            return id;
        }
    }   
        
#ifdef DATAPERSISTENCE
    try
    {
        _realtimeData->setRealtimeData(data);
        id = _realtimeData->persistRealtimeData();        
    }
    catch(std::exception &e)
    {
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s%s",
                                                gettext("Fails to persist realtimedata, device: "), device().c_str(), e.what());
    }
#endif
    return id;
}
