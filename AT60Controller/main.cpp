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
#include "atccsdbaddress.h"
#include "atccsaddress.h"
#include "src/at60plancontroller.h"

/**
 * @brief main function, system entry.
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv)
{
    std::cout << "----------------------AT60 Controller V1.00.00----------------------\n";

    //declare the thread controllers.
    std::shared_ptr<std::thread> exceptionThread = nullptr;
    std::shared_ptr<std::thread> receiverThread = nullptr;
    std::shared_ptr<std::thread> dispatcherThread = nullptr;
    std::shared_ptr<std::thread> upgoingThread = nullptr;
    std::shared_ptr<std::thread> at60PlanThread = nullptr;
    std::shared_ptr<std::thread> at60GimbalThread = nullptr;
    std::shared_ptr<std::thread> at60CCDThread = nullptr;
    std::shared_ptr<std::thread> at60FilterThread = nullptr;
    std::shared_ptr<std::thread> at60FocusThread = nullptr;
    std::shared_ptr<std::thread> at60SlaveDomeThread = nullptr;

    //declare the thread class instances.
    std::shared_ptr<AT60ExceptionDisplayer> exceptionDisplayer = nullptr;
    std::shared_ptr<ATCCSDataReceiver> dataReceiver = nullptr;
    std::shared_ptr<ATCCSDataDispatcher> dataDispatcher = nullptr;
    std::shared_ptr<ATCCSUpgoingController> upgoingController = nullptr;
    std::shared_ptr<ATCCSPlanController> at60PlanController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60GimbalController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60CCDController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60FilterController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60FocusController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60SlaveDomeController = nullptr;

    try
    {
        //initialize Exception Displayer Thread
        exceptionDisplayer = std::make_shared<AT60ExceptionDisplayer>();
        if (exceptionDisplayer)
        {
            exceptionThread = std::make_shared<std::thread>(&AT60ExceptionDisplayer::run, exceptionDisplayer);
        }

        AT60Setting *set = AT60Setting::instance();
        if (!(set->initSystemSetting("/home/lenovo/at60setting.xml")))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, "");
#endif
            exceptionDisplayer->setStop(true);
            exceptionThread->join();
            return 0;
        }
        //initialize database
        std::shared_ptr<ATCCSDBAddress> dbAddress = set->dbAddress();
        if (dbAddress)
        {
            ORMHelper::initDB(dbAddress->type(), dbAddress->user(), dbAddress->password(),
                              dbAddress->db(), dbAddress->ip(), dbAddress->port());
        }

        //start a data receiver thread.
        //generally speaking, the following 5 lines is enough.
        dataReceiver = std::make_shared<ATCCSDataReceiver>();
        if (dataReceiver)
        {
            std::shared_ptr<ATCCSAddress> recvAddress = set->hostAddress();
            dataReceiver->setRecvAddress(recvAddress);
            receiverThread = std::make_shared<std::thread>(&ATCCSDataReceiver::run, dataReceiver);
        }


        //start a data dispatcher thread.
        //generally speaking, the following 5 lines is enough.
        dataDispatcher = std::make_shared<ATCCSDataDispatcher>();
        if (dataDispatcher)
        {
            std::shared_ptr<ATCCSDataProcessor> processor(new ATCLevel1DataProcessor(dataDispatcher));
            dataDispatcher->setDataProcessor(processor);
            dispatcherThread = std::make_shared<std::thread>(&ATCCSDataDispatcher::run, dataDispatcher);
        }


        //then, you should create a series of subclasses of "ATCCSController"
        //and register them to the instance of "ATCCSDataDispatcher".

        //start a upgoing processor thread.
        //"ATCCSUpgoingController" is used to process upgoing-data from Device Controller;
        //such as: ATHEARTBEAT, ATINSTRUCTIONACK, ATSTATUSREPORT
        upgoingController = std::make_shared<ATCCSUpgoingController>();
        if (upgoingController)
        {
            dataDispatcher->registerDeviceController(ATINSTRUCTIONACK, upgoingController);
            dataDispatcher->registerDeviceController(ATHEARTBEAT, upgoingController);
            dataDispatcher->registerDeviceController(ATSTATUSREPORT, upgoingController);
            upgoingThread = std::make_shared<std::thread>(&ATCCSUpgoingController::run, upgoingController);
        }
        
        at60PlanController = std::make_shared<AT60PlanController>();
        if(at60PlanController)
        {
            dataDispatcher->registerDeviceController(ATPLAN, at60PlanController);
            at60PlanThread = std::make_shared<std::thread>(&ATCCSPlanController::run, at60PlanController);
        }
        
        //start a series of concrete variable device controller.
        //and register them to the instance of "ATCCSDataDispatcher" and "ATCCSUpgoingController"
        //"ATCCSDataDispatcher" dispatch control data to device controller.
        //"ATCCSUpgoingController" modify device controller's status according to upgoing-data.

        //start a AT60 gimbal controller.
        at60GimbalController = std::make_shared<AT60GimbalController>();
        if (at60GimbalController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(GIMBAL);
            at60GimbalController->setDeviceAddress(address);
            upgoingController->registerDeviceController(GIMBAL, at60GimbalController);
            at60PlanController->registerDeviceController(GIMBAL, at60GimbalController);
            dataDispatcher->registerDeviceController(GIMBAL, at60GimbalController);
            at60GimbalThread = std::make_shared<std::thread>(&ATCCSDeviceController::run, at60GimbalController);
        }

        at60CCDController = std::make_shared<AT60CCDController>();
        if (at60CCDController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(CCD);
            at60CCDController->setDeviceAddress(address);
            upgoingController->registerDeviceController(CCD, at60CCDController);
            at60PlanController->registerDeviceController(CCD, at60CCDController);
            dataDispatcher->registerDeviceController(CCD, at60CCDController);
            at60CCDThread = std::make_shared<std::thread>(&ATCCSDeviceController::run, at60CCDController);
        }

        at60FocusController = std::make_shared<AT60FocusController>();
        if (at60FocusController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(FOCUS);
            at60FocusController->setDeviceAddress(address);
            upgoingController->registerDeviceController(FOCUS, at60FocusController);
            at60PlanController->registerDeviceController(FOCUS, at60FocusController);
            dataDispatcher->registerDeviceController(FOCUS, at60FocusController);
            at60FocusThread = std::make_shared<std::thread>(&ATCCSDeviceController::run, at60FocusController);
        }

        at60FilterController = std::make_shared<AT60FilterController>();
        if (at60FilterController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(FILTER);
            at60FilterController->setDeviceAddress(address);
            upgoingController->registerDeviceController(FOCUS, at60FilterController);
            at60PlanController->registerDeviceController(FOCUS, at60FilterController);
            dataDispatcher->registerDeviceController(FOCUS, at60FilterController);
            at60FilterThread = std::make_shared<std::thread>(&ATCCSDeviceController::run, at60FilterController);
        }

        at60SlaveDomeController = std::make_shared<AT60SlaveDomeController>();
        if (at60SlaveDomeController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(SLAVEDOME);
            at60SlaveDomeController->setDeviceAddress(address);
            upgoingController->registerDeviceController(FOCUS, at60SlaveDomeController);
            at60PlanController->registerDeviceController(FOCUS, at60SlaveDomeController);
            dataDispatcher->registerDeviceController(FOCUS, at60SlaveDomeController);
            at60SlaveDomeThread = std::make_shared<std::thread>(&ATCCSDeviceController::run, at60SlaveDomeController);
        }

        std::cin.get();
        if (dataReceiver && receiverThread)
        {
            dataReceiver->setStop(true);
            receiverThread->join();
        }
        if (dataDispatcher && dispatcherThread)
        {
            dataDispatcher->setStop(true);
            dispatcherThread->join();
        }
        if (upgoingController && upgoingThread)
        {
            upgoingController->setStop(true);
            upgoingThread->join();
        }
        if(at60PlanThread && at60PlanController)
        {
            at60PlanController->setStop(true);
            at60PlanThread->join();
        }
        if (at60GimbalController && at60GimbalThread)
        {
            at60GimbalController->setStop(true);
            at60GimbalThread->join();
        }
        if (at60CCDController && at60CCDThread)
        {
            at60CCDController->setStop(true);
            at60CCDThread->join();
        }
        if (at60FocusController && at60FocusThread)
        {
            at60FocusController->setStop(true);
            at60FocusThread->join();
        }
        if (at60FilterController && at60FilterThread)
        {
            at60FilterController->setStop(true);
            at60FilterThread->join();
        }
        if (at60SlaveDomeController && at60SlaveDomeThread)
        {
            at60SlaveDomeController->setStop(true);
            at60SlaveDomeThread->join();
        }
        if (exceptionDisplayer && exceptionThread)
        {
            exceptionDisplayer->setStop(true);
            exceptionThread->join();
        }

    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        std::cerr << "error#1: " << e.what()
                << " @" << __func__
                << " @" << __FILE__
                << " @" << __LINE__ << std::endl;
#endif   
    }
    return 0;
}

