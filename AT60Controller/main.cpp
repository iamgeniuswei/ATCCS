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
#include "atccsdatadispatcherprocessor.h"
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
#include "ATCCSExceptionPrinter.h"
#include "ATCCSPlanController.h"


void quit()
{    
    std::string input;
    std::cin >> input;
    while(input != "q")
    {
        std::cout << gettext("unknown command!") << std::endl;
        std::cin >> input;  
    }
}

/**
 * @brief 系统程序入口,.
 * @param argc
 * @param argv
 * @return 
 */
#include "atccs_plan_define.h"
#include <unistd.h>
#include <locale>
int main(int argc, char** argv)
{

    setlocale(LC_ALL, "zh_CN.UTF8");
    bindtextdomain( "AT60Controller", "/usr/share/locale" );
    textdomain( "AT60Controller" );
    std::cout << "----------------------" <<gettext("AT60 Controller V3.00.00") << "----------------------" <<std::endl;
    std::cout << gettext("If want to quit, Please enter \'q\' to quit!") << std::endl;

    //declare the thread class instances.
    std::shared_ptr<ATCCSExceptionPrinter> exceptionPrinter = nullptr;
    std::shared_ptr<ATCCSDataReceiver> dataReceiver = nullptr;
    std::shared_ptr<ATCCSDataDispatcher> dataDispatcher = nullptr;
    std::shared_ptr<ATCCSUpgoingController> upgoingController = nullptr;
    std::shared_ptr<ATCCSPlanPerformer> at60PlanController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60GimbalController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60CCDController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60FilterController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60FocusController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60SlaveDomeController = nullptr;

    try
    {
        //initialize and start Exception Printer.
        exceptionPrinter = std::make_shared<ATCCSExceptionPrinter>();
        exceptionPrinter->start();


        AT60Setting *set = AT60Setting::instance();
        if (!(set->initSystemSetting()))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR,
                                                __FILE__, __func__, __LINE__, "");
#endif
            exceptionPrinter->setStop(true);
            exceptionPrinter->waitToQuit();
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
            dataReceiver->start();
        }


        //start a data dispatcher thread.
        //generally speaking, the following 5 lines is enough.
        dataDispatcher = std::make_shared<ATCCSDataDispatcher>();
        if (dataDispatcher)
        {
            std::shared_ptr<ATCCSDataProcessor> processor(new ATCCSDataDispatcherProcessor(dataDispatcher));
            dataDispatcher->setDataProcessor(processor);
            dataDispatcher->start();
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
            upgoingController->start();
       }
        
        
        
        at60PlanController = std::make_shared<AT60PlanController>();
        if(at60PlanController)
        {
            dataDispatcher->registerDeviceController(ATPLANDATA, at60PlanController);
            at60PlanController->start();
        }
        
        std::shared_ptr<ATCCSPlanController> planController = std::make_shared<ATCCSPlanController>();
        dataDispatcher->registerDeviceController(ATPLANINSTRCTION, planController);
        planController->setPlanPerformer(at60PlanController);
        planController->start();
        
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
            at60GimbalController->start();
        }

        at60CCDController = std::make_shared<AT60CCDController>();
        if (at60CCDController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(CCD);
            at60CCDController->setDeviceAddress(address);
            upgoingController->registerDeviceController(CCD, at60CCDController);
            at60PlanController->registerDeviceController(CCD, at60CCDController);
            dataDispatcher->registerDeviceController(CCD, at60CCDController);
            at60CCDController->start();
      }

        at60FocusController = std::make_shared<AT60FocusController>();
        if (at60FocusController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(FOCUS);
            at60FocusController->setDeviceAddress(address);
            upgoingController->registerDeviceController(FOCUS, at60FocusController);
            at60PlanController->registerDeviceController(FOCUS, at60FocusController);
            dataDispatcher->registerDeviceController(FOCUS, at60FocusController);
            at60FocusController->start();
       }

        at60FilterController = std::make_shared<AT60FilterController>();
        if (at60FilterController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(FILTER);
            at60FilterController->setDeviceAddress(address);
            upgoingController->registerDeviceController(FILTER, at60FilterController);
            at60PlanController->registerDeviceController(FILTER, at60FilterController);
            dataDispatcher->registerDeviceController(FILTER, at60FilterController);
            at60FilterController->start();
        }

        at60SlaveDomeController = std::make_shared<AT60SlaveDomeController>();
        if (at60SlaveDomeController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(SLAVEDOME);
            at60SlaveDomeController->setDeviceAddress(address);
            upgoingController->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
            at60PlanController->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
            dataDispatcher->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
            at60SlaveDomeController->start();
       }

        quit();
        if (dataReceiver)
        {
            dataReceiver->setStop(true);
            dataReceiver->waitToQuit();
        }
        if (dataDispatcher)
        {
            dataDispatcher->setStop(true);
            dataDispatcher->waitToQuit();
        }
        if (upgoingController)
        {
            upgoingController->setStop(true);
            upgoingController->waitToQuit();
        }
        if(planController)
        {
            planController->setStop(true);
            planController->waitToQuit();
        }
        if(at60PlanController)
        {
            at60PlanController->setStop(true);
            at60PlanController->waitToQuit();
        }
        if (at60GimbalController)
        {
            at60GimbalController->setStop(true);
            at60GimbalController->waitToQuit();
        }
        if (at60CCDController)
        {
            at60CCDController->setStop(true);
            at60CCDController->waitToQuit();
        }
        if (at60FocusController)
        {
            at60FocusController->setStop(true);
            at60FocusController->waitToQuit();
        }
        if (at60FilterController)
        {
            at60FilterController->setStop(true);
            at60FilterController->waitToQuit();
        }
        if (at60SlaveDomeController)
        {
            at60SlaveDomeController->setStop(true);
            at60SlaveDomeController->waitToQuit();
        }
        if (exceptionPrinter)
        {
            exceptionPrinter->setStop(true);
            exceptionPrinter->waitToQuit();
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

