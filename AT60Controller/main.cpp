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
    while (input != "q")
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
    bindtextdomain("AT60Controller", "/usr/share/locale");
    textdomain("AT60Controller");
    std::cout << "----------------------" << gettext("AT60 Controller V3.00.00") << "----------------------" << std::endl;
    std::cout << gettext("If want to quit, Please enter \'q\' to quit!") << std::endl;

    //声明控制线程实例.
    //在系统设计中,为了最大程度的简化控制逻辑,将每种独立功能设计在一个独立线程中运行.
    //在60cm望远镜控制软件中,存在以下11个线程
    //1. 异常信息打印线程
    //2. 数据接收线程
    //3. 数据分派线程
    //4. 上行数据处理线程(用于处理设备上报的各种数据)
    //5. 观测计划指令处理线程
    //6. 观测计划数据处理线程
    //7. Gimbal控制线程
    //8. CCD控制线程
    //9. Filter控制线程
    //10. Focus控制线程
    //11. SlaveDome控制线程
    std::shared_ptr<ATCCSExceptionPrinter> exceptionPrinter = nullptr;
    std::shared_ptr<ATCCSDataReceiver> dataReceiver = nullptr;
    std::shared_ptr<ATCCSDataDispatcher> dataDispatcher = nullptr;
//    std::shared_ptr<ATCCSUpgoingController> upgoingController = nullptr;
    std::shared_ptr<ATCCSPlanController> at60PlanController = nullptr;
    std::shared_ptr<ATCCSPlanPerformer> at60PlanPerformer = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60GimbalController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60CCDController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60FilterController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60FocusController = nullptr;
    std::shared_ptr<ATCCSDeviceController> at60SlaveDomeController = nullptr;

    try
    {
        //初始化并启动异常信息打印线程.
        exceptionPrinter = std::make_shared<ATCCSExceptionPrinter>();
        exceptionPrinter->start();


        //加载配置文件
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
        //连接数据库
        std::shared_ptr<ATCCSDBAddress> dbAddress = set->dbAddress();
        if (dbAddress)
        {
            ORMHelper::initDB(dbAddress->type(), dbAddress->user(), dbAddress->password(),
                              dbAddress->db(), dbAddress->ip(), dbAddress->port());
        }
        
                //启动一系列具体设备控制线程
        //并将其以[设备类型]分别注册到数据分派器, 上行数据处理线程, 观测计划执行线程

        //初始化并启动Gimbal控制线程
        at60GimbalController = std::make_shared<AT60GimbalController>();
        if (at60GimbalController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(GIMBAL);
            at60GimbalController->setDeviceAddress(address);            
//            at60PlanPerformer->registerDeviceController(GIMBAL, at60GimbalController);
//            dataDispatcher->registerDeviceController(GIMBAL, at60GimbalController);
            at60GimbalController->start();
        }

        //初始化并启动CCD控制线程
        at60CCDController = std::make_shared<AT60CCDController>();
        if (at60CCDController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(CCD);
            at60CCDController->setDeviceAddress(address);
            
//            at60PlanPerformer->registerDeviceController(CCD, at60CCDController);
//            dataDispatcher->registerDeviceController(CCD, at60CCDController);
            at60CCDController->start();
        }

        //初始化并启动Focus控制线程
        at60FocusController = std::make_shared<AT60FocusController>();
        if (at60FocusController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(FOCUS);
            at60FocusController->setDeviceAddress(address);
//            upgoingController->registerDeviceController(FOCUS, at60FocusController);
//            at60PlanPerformer->registerDeviceController(FOCUS, at60FocusController);
//            dataDispatcher->registerDeviceController(FOCUS, at60FocusController);
            at60FocusController->start();
        }

        //初始化并启动Filter控制线程
        at60FilterController = std::make_shared<AT60FilterController>();
        if (at60FilterController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(FILTER);
            at60FilterController->setDeviceAddress(address);
//            upgoingController->registerDeviceController(FILTER, at60FilterController);
//            at60PlanPerformer->registerDeviceController(FILTER, at60FilterController);
//            dataDispatcher->registerDeviceController(FILTER, at60FilterController);
            at60FilterController->start();
        }

        //初始化并启动SlaveDome控制线程
        at60SlaveDomeController = std::make_shared<AT60SlaveDomeController>();
        if (at60SlaveDomeController)
        {
            std::shared_ptr<ATCCSAddress> address = set->deviceAddress(SLAVEDOME);
            at60SlaveDomeController->setDeviceAddress(address);
//            upgoingController->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
//            at60PlanPerformer->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
//            dataDispatcher->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
            at60SlaveDomeController->start();
        }
        
        //初始化并启动观测计划数据处理线程
        //将线程以 ATPLANDATA 类型注册到数据分派器 
        at60PlanPerformer = std::make_shared<AT60PlanController>();
        if (at60PlanPerformer)
        {
            at60PlanPerformer->registerDeviceController(GIMBAL, at60GimbalController);
            at60PlanPerformer->registerDeviceController(CCD, at60CCDController);
            at60PlanPerformer->registerDeviceController(FILTER, at60FilterController);
            at60PlanPerformer->registerDeviceController(FOCUS, at60FocusController);
            at60PlanPerformer->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
            at60PlanPerformer->start();
        }

        //初始化并启动观测计划指令处理线程
        //将线程以 ATPLANINSTRUCTION 类型注册到数据分派器
        //并将观测计划数据处理线程注册到本线程
        at60PlanController = std::make_shared<ATCCSPlanController>();
        if (at60PlanController)
        {            
            at60PlanController->setPlanPerformer(at60PlanPerformer);
            at60PlanController->start();
        }

        //初始化并启动数据分派线程
        dataDispatcher = std::make_shared<ATCCSDataDispatcher>();
        if (dataDispatcher)
        {
            std::shared_ptr<ATCCSDataProcessor> processor(new ATCCSDataDispatcherProcessor(dataDispatcher));
            dataDispatcher->setDataProcessor(processor);
            dataDispatcher->registerDeviceController(GIMBAL, at60GimbalController);
            dataDispatcher->registerDeviceController(CCD, at60CCDController);
            dataDispatcher->registerDeviceController(FOCUS, at60GimbalController);
            dataDispatcher->registerDeviceController(FILTER, at60FilterController);
            dataDispatcher->registerDeviceController(SLAVEDOME, at60SlaveDomeController);
            dataDispatcher->registerDeviceController(ATPLANDATA, at60PlanPerformer);
            dataDispatcher->registerDeviceController(ATPLANINSTRCTION, at60PlanController);            
            dataDispatcher->start();
        }

        //初始化并启动数据接收线程
        dataReceiver = std::make_shared<ATCCSDataReceiver>();
        if (dataReceiver)
        {
            std::shared_ptr<ATCCSAddress> recvAddress = set->hostAddress();
            dataReceiver->setRecvAddress(recvAddress);
            dataReceiver->start();
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
        if (at60PlanController)
        {
            at60PlanController->setStop(true);
            at60PlanController->waitToQuit();
        }
        if (at60PlanPerformer)
        {
            at60PlanPerformer->setStop(true);
            at60PlanPerformer->waitToQuit();
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

