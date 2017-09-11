/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on September 7, 2017, 5:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <locale>
#include <memory>
using namespace std;
#include "atccsdatareceiver.h"
#include "atccsdatadispatcher.h"
#include "emedatagather.h"
#include "emsetting.h"
#include "emedatadispatcherprocessor.h"
#include "ORMHelper.h"
#include "atccsdbaddress.h"
#include "ATCCSExceptionPrinter.h"


void quit()
{
    cout << gettext("Please enter \'q\' to quit!") << endl;
    std::string input;
    std::cin >> input;
    while(input != "q")
    {
        cout << gettext("unknown command!") << endl;
        std::cin >> input;  
    }
}


/*
 * 
 */
int main(int argc, char** argv)
{
    cout << gettext("--------------------------------------EM Data Gather--------------------------------------") << endl;
    try
    {

        shared_ptr<ATCCSDataReceiver> _dataReceiver(nullptr);
        shared_ptr<ATCCSDataDispatcher> _dataDispatcher(nullptr);
        shared_ptr<EMEDataGather> _emeDataGather[6]{nullptr};

        //initialize system settings.
        //here, we have 6 EM Gathers:
        //ASC, WS, CS, SQM, DUST, DIMM
        std::shared_ptr<EMSetting> set = std::make_shared<EMSetting>(6);
        
        //initialize database
        std::shared_ptr<ATCCSDBAddress> dbAddress = set->dbAddress();
        if(dbAddress)
        {
             ORMHelper::initDB(dbAddress->type(), dbAddress->user(), dbAddress->password(),
                              dbAddress->db(), dbAddress->ip(), dbAddress->port());
        }
        
        //initialize and start ATCCSExceptionPrinter. 
        std::shared_ptr<ATCCSExceptionPrinter> printer = std::make_shared<ATCCSExceptionPrinter>();
        printer->start();
        
        //initialize and start ATCCSDataReceiver.
        _dataReceiver = std::make_shared<ATCCSDataReceiver>();
        _dataReceiver->setRecvAddress(set->hostAddress());
        _dataReceiver->start();
        
        //initialize and start ATCCSDataDispatcher.
        _dataDispatcher = std::make_shared<ATCCSDataDispatcher>();
        std::shared_ptr<EMEDataDispatcherProcessor> processor = std::make_shared<EMEDataDispatcherProcessor>(_dataDispatcher);
        _dataDispatcher->setDataProcessor(processor);
        _dataDispatcher->start();
        
        //initialize and start EM Data Gathers.
        for(int i=0; i < set->emCount(); i++)
        {
            _emeDataGather[i] = std::make_shared<EMEDataGather>(ASC+i);
            _dataDispatcher->registerDeviceController(ASC+i, _emeDataGather[i]);
            _emeDataGather[i]->start();
        }
        quit();
        _dataReceiver->setStop(true);
        _dataReceiver->waitToQuit();
        _dataDispatcher->setStop(true);
        _dataDispatcher->waitToQuit();
        for(int i=0; i<6; i++)
        {
            _emeDataGather[i]->setStop(true);
            _emeDataGather[i]->waitToQuit();
        }
        printer->setStop(true);
        printer->waitToQuit();
//        for(int i=0; i < 8; i++)
//        {
//            _threadController[i]->join();
//        }
    }
    catch(std::exception &e)
    {
        cerr << e.what() << " @" << __FILE__
                << " @" << __func__ 
                << " @" << __LINE__ << endl;
    }
        
    return 0;
}

