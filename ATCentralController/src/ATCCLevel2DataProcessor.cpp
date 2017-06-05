/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCLevel2DataProcessor.cpp
 * Author: lenovo
 * 
 * Created on May 12, 2017, 8:41 PM
 */

#include "ATCCLevel2DataProcessor.h"
#include "ATCCATController.h"
#include "atccsdata.h"
#include "atccs_global.h"
#include "atccs_public_define.h"
#include <iostream>
ATCCLevel2DataProcessor::ATCCLevel2DataProcessor(ATCCATController *controller)
    :_controller(controller)
{
}

ATCCLevel2DataProcessor::ATCCLevel2DataProcessor(const ATCCLevel2DataProcessor& orig) {
}

ATCCLevel2DataProcessor::~ATCCLevel2DataProcessor() 
{
    
}

void ATCCLevel2DataProcessor::processData(std::shared_ptr<ATCCSData> data) 
{
    if(data == nullptr || (!data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(_controller && header)
    {
        if(header->AT.at != _controller->type())
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error: The data is not AT." << _controller->type() 
                << " @" << __func__ 
                << " @" << __FILE__ 
                << " @" << __LINE__ << std::endl;
#endif
            return;
        }
            
        if(header->msg == ATTAKEOVER)
        {
            if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_OCCUPATION)))
                return;
            _AT_OCCUPATION *occu = (_AT_OCCUPATION*)(data->data()+sizeof(_ATCCSPHeader));
            _controller->setATOccupation(occu->_user, occu->_at, occu->_occupation, occu->_start, occu->_end, occu->_priority);
        }
        else
        {
            _controller->sendControlData(data);

        }
    }
}
