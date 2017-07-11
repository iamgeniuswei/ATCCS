/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMEDataDispatcherProcessor.cpp
 * Author: lenovo
 * 
 * Created on June 27, 2017, 4:21 PM
 */

#include "emedatadispatcherprocessor.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccsdatadispatcher.h"
EMEDataDispatcherProcessor::EMEDataDispatcherProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher)
        :_dispatcher(dispatcher.get())
{
}

void EMEDataDispatcherProcessor::processData(std::shared_ptr<ATCCSData> data)
{
    if (_dispatcher)
    {
        if (data)
        {
            if (data->validate())
            {
                _ATCCSPHeader *header = (_ATCCSPHeader*) (data->data());
                _dispatcher->dispatchControlData(header->env, data);
            }
        }
    }
}



