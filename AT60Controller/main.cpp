/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on May 6, 2017, 4:51 PM
 */

#include "atccs_global.h"
#include "atccsdatareceiver.h"
#include "atccsdatadispatcher.h"
#include "atccsupgoingcontroller.h"
#include <thread>
#include "atccs_public_define.h"
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
using namespace odb::core;
#include <odb/pgsql/database.hxx>
#include "ORMHelper.h"
#include <memory>
#include <future>
#include "atclevel1dataprocessor.h"
#include "src/at60ccdcontroller.h"
#include "src/at60filtercontroller.h"
#include "src/at60focuscontroller.h"
#include "src/at60gimbalcontroller.h"
#include "src/at60slavedomecontroller.h"

#include "atccsexception.h"
#include "atccsexceptionhandler.h"
#include "atccscontroller.h"
#include "src/at60exceptiondisplayer.h"
#include "src/at60setting.h"
/**
 * @brief main function, system entry.
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) 
{
    std::cout << "----------------------AT60 Controller V1.00.00----------------------\n"; 
    
    AT60Setting *set = AT60Setting::instance();
    set->initSystemSetting("/home/lenovo/at60setting.xml");
    ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);

      
    
    try
    {   
        std::shared_ptr<ATCCSDeviceController> t1 = std::make_shared<ATCCSDeviceController>(GIMBAL);
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, __FILE__, __func__, __LINE__, "my fault");
        
        //start a data receiver thread.
        //you should use following 3 lines.
        //but you don't modify anything, except "setRecvAddress".
//        std::shared_ptr<ATCCSDataReceiver> receiver(new ATCCSDataReceiver);
//        receiver->setRecvAddress("192.168.0.115", 4747);
//        std::thread th(&ATCCSDataReceiver::run, receiver);
//        
//        //start a data dispatcher thread.
//        //first, you should use the following line to create a "ATCCSDataDispatcher".
//        std::shared_ptr<ATCCSDataDispatcher> dispatcher(new ATCCSDataDispatcher);
////        std::shared_ptr<ATCCSDataProcessor> processor (new ATCLevel1DataProcessor(dispatcher));
////        dispatcher->setDataProcessor(processor);
//        
        std::shared_ptr<AT60ExceptionDisplayer> displayer(new AT60ExceptionDisplayer);
        std::thread the(&AT60ExceptionDisplayer::run, displayer);
//        
//        //then, you should create a series of subclasses of "ATCCSController"
//        //and register them to the instance of "ATCCSDataDispatcher".
//        
//        //start a upgoing processor thread.
//        //"ATCCSUpgoingController" is used to process upgoing-data from Device Controller;
//        //such as: ATHEARTBEAT, ATINSTRUCTIONACK, ATSTATUSREPORT
//        std::shared_ptr<ATCCSUpgoingController> upgoing(new ATCCSUpgoingController);
//        dispatcher->registerDeviceController(ATINSTRUCTIONACK, upgoing);
//        dispatcher->registerDeviceController(ATHEARTBEAT, upgoing);
//        dispatcher->registerDeviceController(ATSTATUSREPORT, upgoing);        
//
//        
//        //start a series of concrete variable device controller.
//        //and register them to the instance of "ATCCSDataDispatcher" and "ATCCSUpgoingController"
//        //"ATCCSDataDispatcher" dispatch control data to device controller.
//        //"ATCCSUpgoingController" modify device controller's status according to upgoing-data.
//        
//        //start a AT60 gimbal controller.
//        std::shared_ptr<AT60GimbalController> at60Gimbal(new AT60GimbalController);    
//        at60Gimbal->setDeviceAddress("192.168.0.184", 6500);
//        upgoing->registerDeviceController(GIMBAL, at60Gimbal);
//        dispatcher->registerDeviceController(GIMBAL, at60Gimbal);
//        
//        std::shared_ptr<AT60CCDController> at60CCD(new AT60CCDController);   
//        at60CCD->setDeviceAddress("192.168.0.130",4646);
//        upgoing->registerDeviceController(CCD, at60CCD);
//        dispatcher->registerDeviceController(CCD, at60CCD);
//        
//        std::shared_ptr<AT60FocusController> at60Focus(new AT60FocusController);        
//        upgoing->registerDeviceController(FOCUS, at60Focus);
//        dispatcher->registerDeviceController(FOCUS, at60Focus);
//        
//        std::shared_ptr<AT60FilterController> at60Filter(new AT60FilterController);  
//        at60Filter->setDeviceAddress("192.168.0.130",4646);
//        upgoing->registerDeviceController(FILTER, at60Filter);
//        dispatcher->registerDeviceController(FILTER, at60Filter);
//        
//        std::shared_ptr<AT60SlaveDomeController> at60SlaveDome(new AT60SlaveDomeController);        
//        upgoing->registerDeviceController(SLAVEDOME, at60SlaveDome);
//        dispatcher->registerDeviceController(SLAVEDOME, at60SlaveDome);
//        
//
//        
//        std::thread th1(&ATCCSDataDispatcher::run, dispatcher);
//        std::thread th2(&ATCCSUpgoingController::run, upgoing);
//        std::thread th3(&AT60GimbalController::run, at60Gimbal);
//        std::thread th4(&AT60CCDController::run, at60CCD);
//        std::thread th5(&AT60FilterController::run, at60Filter);
//        std::thread th6(&AT60FocusController::run, at60Focus);
//        std::thread th7(&AT60SlaveDomeController::run, at60SlaveDome);
        std::cin.get();
        displayer->setStop(true);
        the.join();
//        receiver->setStop(true);
//        dispatcher->setStop(true);
//        upgoing->setStop(true);
//        at60Gimbal->setStop(true);
//        at60CCD->setStop(true);
//        at60Filter->setStop(true);
//        at60Focus->setStop(true);
//        at60SlaveDome->setStop(true);
//        th.join();
//        th1.join();
//        th2.join();
//        th3.join();
//        th4.join();
//        th5.join();
//        th6.join();
//        th7.join();      
        
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        std::cerr << "error#1: " << e.what()
                << " @" << __func__
                << " @" << __FILE__
                << " @" << __LINE__ << std::endl;
#endif   
    }
    return 0;
}

