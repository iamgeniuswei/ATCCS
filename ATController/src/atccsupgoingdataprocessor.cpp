/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSUpgoingDataProcessor.cpp
 * Author: lenovo
 * 
 * Created on May 5, 2017, 10:34 PM
 */

#include "atccsupgoingdataprocessor.h"
#include "atccsdata.h"
#include "atccs_public_define.h"

ATCCSUpgoingDataProcessor::ATCCSUpgoingDataProcessor(ATCCSUpgoingController *controller)
    :_controller(controller)
{
}

void ATCCSUpgoingDataProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header && _controller)
    {
        _controller->processUpgoingData(header->msg, data);
    }
}

