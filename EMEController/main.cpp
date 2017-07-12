/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on 2017年6月21日, 上午10:05
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <memory>
using namespace std;
#include "atccsdatareceiver.h"
#include "atccsdatadispatcher.h"
#include "src/emedatagather.h"
#include "src/emesetting.h"
#include "atccs_public_define.h"
#include "src/emedatadispatcherprocessor.h"
/*
 * 
 */
int main(int argc, char** argv)
{
    //declare the thread controller
    shared_ptr<thread> _threadController[8]{nullptr};
    //declare the thread function 
    shared_ptr<ATCCSDataReceiver> _dataReceiver(nullptr);
    shared_ptr<ATCCSDataDispatcher> _dataDispatcher(nullptr);
    shared_ptr<EMEDataGather> _emeDataGather[6]{nullptr};
    try
    {
        std::shared_ptr<EMESetting> set = std::make_shared<EMESetting>(6);
        set->initSysSetting();
        
        //data receiver
        _dataReceiver = std::make_shared<ATCCSDataReceiver>();
        _dataReceiver->setRecvAddress(set->hostAddress());
        _threadController[0] = std::make_shared<thread>(&ATCCSDataReceiver::run, _dataReceiver);
        
        //data dispatcher
        _dataDispatcher = std::make_shared<ATCCSDataDispatcher>();
        std::shared_ptr<EMEDataDispatcherProcessor> processor = std::make_shared<EMEDataDispatcherProcessor>(_dataDispatcher);
        _dataDispatcher->setDataProcessor(processor);
        _threadController[1] = std::make_shared<thread>(&ATCCSDataDispatcher::run, _dataDispatcher);
        
        //asc data gather
        for(int i=0; i < set->emeNum(); i++)
        {
            _emeDataGather[i] = std::make_shared<EMEDataGather>(ASC+i);
            _dataDispatcher->registerDeviceController(ASC+i, _emeDataGather[i]);
            _threadController[i+2] = std::make_shared<thread>(&EMEDataGather::run, _emeDataGather[i]);
        }
        cin.get();
        _dataReceiver->setStop(true);
        _dataDispatcher->setStop(true);
        for(int i=0; i<6; i++)
        {
            _emeDataGather[i]->setStop(true);
        }
        for(int i=0; i < 8; i++)
        {
            _threadController[i]->join();
        }
    }
    catch(std::exception &e)
    {
        cerr << e.what() << " @" << __FILE__
                << " @" << __func__ 
                << " @" << __LINE__ << endl;
    }
    
    return 0;
}

