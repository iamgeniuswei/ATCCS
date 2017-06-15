/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60PlanController.cpp
 * Author: lenovo
 * 
 * Created on June 8, 2017, 3:09 PM
 */

#include "at60plancontroller.h"
#include "atccs_public_define.h"
#include "atccsexceptionhandler.h"
#include "at60plan.h"
AT60PlanController::AT60PlanController()
    :ATCCSPlanController(AT60)
{
}

AT60PlanController::~AT60PlanController()
{
}

std::shared_ptr<atccsplan> AT60PlanController::executoryPlanInstance()
{
    if (_executoryPlan == nullptr)
    {
        try
        {
            _executoryPlan = std::make_shared<at60plan>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, 0, e.what());
#endif
        }
    }
    return _executoryPlan;
}

bool AT60PlanController::isRelatedDevicesReady()
{
//    if(_controllers)
//    {
//        bool isGimbalOK = false;
//        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(GIMBAL);
//        if(temp)
//        {
//            isGimbalOK = temp->canExecutePlan();
//        }
//        bool isCCDOK = false;
//        std::shared_ptr<ATCCSDeviceController> temp1 = _controllers->controller(CCD);
//        if(temp1)
//        {
//            isCCDOK = temp1->canExecutePlan();
//        }
//        bool isFilterOK = false;
//        std::shared_ptr<ATCCSDeviceController> temp2 = _controllers->controller(FILTER);
//        if(temp2)
//        {
//            isFilterOK = temp2->canExecutePlan();
//        }
//        bool isFocusOK = false;
//        std::shared_ptr<ATCCSDeviceController> temp3 = _controllers->controller(FOCUS);
//        if(temp3)
//        {
//            isFocusOK = temp3->canExecutePlan();
//        }
//        bool isDomeOK = false;
//        std::shared_ptr<ATCCSDeviceController> temp4 = _controllers->controller(SLAVEDOME);
//        if(temp4)
//        {
//            isDomeOK = temp4->canExecutePlan();
//        }
//    }
//    else
//    {
//#ifdef OUTERRORINFO
//        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
//                                            __FILE__, __func__, __LINE__, "");
//#endif
//    }
    return true;
}


