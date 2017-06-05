/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSCCATController.cpp
 * Author: lenovo
 * 
 * Created on May 12, 2017, 8:20 PM
 */

#include "ATCCATController.h"
#include "atccs_global.h"
#include "atccsdatasender.h"
#include "atccsoccupation.h"
#include "atccsdata.h"
#include "ATCCLevel2DataProcessor.h"
#include <iostream>
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb;
using namespace odb::core;
#include <odb/pgsql/database.hxx>
#include "atccsoccupation.h"
#include "atccsoccupation-odb.hxx"
ATCCATController::ATCCATController(unsigned int type)
    :_type(type)
{
    try
    {
        _sender = std::make_shared<ATCCSDataSender>();
        _dataProcessor = std::make_shared<ATCCLevel2DataProcessor>(this);
        _atOccupation = new (std::nothrow) atccsoccupation;
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSDebugInfo(e);
#endif
    }
}

ATCCATController::ATCCATController(const ATCCATController& orig) {
}

ATCCATController::~ATCCATController() {
}

void ATCCATController::handleControlData() 
{
    while(!stop())
    {
        std::shared_ptr<ATCCSData> data = _fifoQueue.wait_and_pop();
        if(data == nullptr)
            continue;
        if(_dataProcessor)
            _dataProcessor->processData(data);
        else
        {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCLevel2DataProcessor is null."
                << " @" << __func__ 
                << " @" << __FILE__ 
                << " @" << __LINE__ << std::endl;
#endif
        }
    }
}

unsigned int ATCCATController::type() const 
{
    return _type;
}

int ATCCATController::sendControlData(std::shared_ptr<ATCCSData> data) 
{
    int ret = 0;
    int i = 0;
    for(i; i<3; i++)
    {
        if(_sender && data)
            ret = _sender->sendData(data);
        if(ret == data->size())
            break;
        else
            continue;
    }
    std::cout << "ret --" << ret << std::endl;
    return ret;
}

void ATCCATController::setATControllerAddress(const std::string& ip, unsigned short port) 
{
    if(_sender)
        _sender->setTargetAddress(ip, port);
    else
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCSDataSender is null."
                << " @" << __func__ 
                << " @" << __FILE__ 
                << " @" << __LINE__ << std::endl;
#endif
    }
}


void ATCCATController::setATOccupation(std::shared_ptr<ATCCSData> data) 
{
//    if(_atOccupation && )
//    {
//        _atOccupation->setValue(data);
//    }
//    else
//    {
//#ifdef OUTDEBUGINFO
//        std::cerr << "error: ATCCSOccupation is null."
//                << " @" << __func__ 
//                << " @" << __FILE__ 
//                << " @" << __LINE__ << std::endl;
//#endif
//    }
}

void ATCCATController::setATOccupation(UINT32 user, unsigned short at, unsigned short occupation, UINT32 start, UINT32 end, UINT32 priority) 
{
    if(_atOccupation)
    {
        if(_atOccupation->user() == 0)
        {
            _atOccupation->setUser(user);
            _atOccupation->setOccupation(occupation);
            _atOccupation->setAt(at);
            _atOccupation->setStart(start);
            _atOccupation->setEnd(end);
            _atOccupation->setPriority(priority);  
        }
        else if(_atOccupation->user() == user)
        {
            _atOccupation->setOccupation(occupation);
            _atOccupation->setAt(at);
            _atOccupation->setStart(start);
            _atOccupation->setEnd(end);
            _atOccupation->setPriority(priority);                   
        }
        else if(canPreempt())
        {
            _atOccupation->setUser(user);
            _atOccupation->setOccupation(occupation);
            _atOccupation->setAt(at);
            _atOccupation->setStart(start);
            _atOccupation->setEnd(end);
            _atOccupation->setPriority(priority);  
        }
        
        try
        {
            std::shared_ptr<database> db(new odb::pgsql::database("lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432));
            
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
    else
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error: ATCCSOccupation is null."
                << " @" << __func__ 
                << " @" << __FILE__ 
                << " @" << __LINE__ << std::endl;
#endif
    }
}

bool ATCCATController::canPreempt() const 
{
    return false;
}




bool ATCCATController::canSendControlData(UINT32 user) const 
{
    if(_atOccupation)
    {
        return (user == _atOccupation->user() && _atOccupation->occupation() != 0);
    }
    else
        return false;
}

unsigned int ATCCATController::persistOcuupation() 
{
    
}
