/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSLevel1DataProcessor.cpp
 * Author: lenovo
 * 
 * Created on May 12, 2017, 7:59 PM
 */

#include <stddef.h>

#include "ATCCLevel1DataProcessor.h"
#include "atccsdatadispatcher.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
ATCCSCCLevel1DataProcessor::ATCCSCCLevel1DataProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher)
        :_dispathcer(dispatcher)
{
    
}


ATCCSCCLevel1DataProcessor::~ATCCSCCLevel1DataProcessor() 
{
}

void ATCCSCCLevel1DataProcessor::processData(std::shared_ptr<ATCCSData> data) 
{
    if(data == nullptr || !(data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header && _dispathcer)
    {
        _dispathcer->dispatchControlData(header->AT.at, data);
    }
}


