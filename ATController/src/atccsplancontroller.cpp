#include "atccsplancontroller.h"
#include "atccsmapmanager.h"
#include "atccsdevicecontroller.h"
#include "atccsdata.h"
#include "atccsplan.h"
#include "atccs_gimbal_define.h"
#include "atccs_plan_define.h"
#include "atccs_filter_define.h"
#include "atccs_ccd_define.h"
#include <ctime>
#include <string.h>
#include <thread>
#include "atccsdatapacker.h"
#include "atccsexceptionhandler.h"
#include "at60plan.h"
ATCCSPlanController::ATCCSPlanController(unsigned short at)
    : _at(at)
{
    
}

ATCCSPlanController::~ATCCSPlanController()
{

}

void ATCCSPlanController::run()
{
    while (!stop())
    {
        std::shared_ptr<ATCCSData> data = popControlData();
        if(data == nullptr)
            continue;
        
        while(!stop() && !canExecutePlan())
        {
            std::chrono::milliseconds dura(2000);
            std::this_thread::sleep_for(dura);
        }
        if(!stop() && canExecutePlan())
        {
            controlPlan(data);
        }
    }
}


/**
 * judge whether can execute plan, the standard is 
 * all devices' status are normal.
 * @return true if can, false if can not.
 */
bool ATCCSPlanController::canExecutePlan() const
{
    return true;
}

bool ATCCSPlanController::exposureOK() const
{

}

void ATCCSPlanController::dispatchControlData(unsigned int id, std::shared_ptr<ATCCSData> data)
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> controller = _controllers->controller(id);
        if(controller)
            controller->pushControlData(data);
    }
}

/**
 * control a plan's procedure.
 * @param data, the raw plan encapsulated in ATCCSData.
 */
void ATCCSPlanController::controlPlan(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
        return;
    if(!(data->validate()))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__, 
                                            "Plan's raw data is error and can not be resolved, the plan is canceled.");
#endif
        return;
    }
    
    if(!_executoryPlan)
    {
        _executoryPlan = executoryPlanInstance();
    }
    
    if(_executoryPlan)
    {
        if(_executoryPlan->setPlan(data) == atccsplan::RESULT_EXECUTED)
        {
#ifdef OUTDEBUGINFO
            std::cout << "-------------------Start to execute plan------------------" << std::endl;
#endif
            
#ifdef DATAPERSISTENCE
            _executoryPlan->persistPlan();
#endif
            //reset ATCCSDeviceController's instruction queue.
            resetDeviceInstruction(GIMBAL);
            resetDeviceInstruction(CCD);

            //Send GImbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
            //check all the related devices' status, if they are ready?
            //if ready, go on;
            //else, abandon this plan.
            if (!isRelatedDevicesReady())
                return;
            if(!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
            {
#ifdef OUTDEBUGINFO
                std::cout << "ERROR: fails to set Gimbal's _GIMBAL_INSTRUCTION_SETOBJECTNAME, plan is canceled." << std::endl;
#endif
                return;
            }
            if(!waitInstructionOK(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                    __FILE__, __func__, __LINE__, 
                                                    "Gimbal's _GIMBAL_INSTRUCTION_SETOBJECTNAME fails to execute, plan is canceled.");
#endif
                return;
            }

            //Send GImbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
            if (!isRelatedDevicesReady())
                return;
            if(!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
            {
#ifdef OUTDEBUGINFO
                std::cout << "ERROR: fails to set Gimbal's _GIMBAL_INSTRUCTION_TRACKSTAR, plan is canceled." << std::endl;
#endif
                return;
            }
            
            if (!waitInstructionOK(GIMBAL,_GIMBAL_INSTRUCTION_TRACKSTAR))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                    __FILE__, __func__, __LINE__, 
                                                    "Gimbal's _GIMBAL_INSTRUCTION_TRACKSTAR fails to execute, plan is canceled.");
#endif
                return;
            }
            std::cout << "track star ok!----\n";
            for (int i = 0; i < _executoryPlan->exposureCount(); i++)
            {
                //Send CCD's instruction: _CCD_INSTRUCTION_SETEXPOSURETACTIC
                if (!isRelatedDevicesReady())
                    break;
                if(!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
                {
#ifdef OUTDEBUGINFO
                    std::cout << "ERROR: fails to set CCD's _CCD_INSTRUCTION_SETEXPOSURETACTIC, plan is canceled." << std::endl;
#endif
                    return;                    
                }
                if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
                {
#ifdef OUTDEBUGINFO
                    std::cout << "ERROR: CCD's _CCD_INSTRUCTION_SETEXPOSURETACTIC fails to execute, plan is canceled." << std::endl;
#endif                    
                    break;
                }
                //Send CCD's instruction: _CCD_INSTRUCTION_STARTEXPOSURE
                if (!isRelatedDevicesReady())
                    break;
                if(!setDeviceInstruction(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
                {
#ifdef OUTDEBUGINFO
                    std::cout << "ERROR: fails to set CCD's _CCD_INSTRUCTION_STARTEXPOSURE, plan is canceled." << std::endl;
#endif
                    return;                     
                }
                if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
                {
#ifdef OUTDEBUGINFO
                    std::cout << "ERROR: CCD's _CCD_INSTRUCTION_STARTEXPOSUREni fails to execute, plan is canceled." << std::endl;
#endif                    
                    break;
                }
            }            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
}

void ATCCSPlanController::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller)
{
    if(!_controllers)
        _controllers = controllersInstance();
    if(_controllers)
        _controllers->registerController(id, controller);
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
}

void ATCCSPlanController::resetDeviceInstruction(unsigned int device) 
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
        if(temp)
        {
            temp->clearControlData();
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif        
    }
}

unsigned short ATCCSPlanController::at() const
{
    return _at;
}

bool ATCCSPlanController::setGimbalInstruction(unsigned int instruction)
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(GIMBAL);
        if(temp)
        {
            std::shared_ptr<ATCCSData> pendingData = nullptr;
            if(instruction == _GIMBAL_INSTRUCTION_SETOBJECTNAME)
            {
                pendingData = ATCCSDataPacker::packGimbalInstruction_SetObjectName(_executoryPlan);
            }
            else if(instruction == _GIMBAL_INSTRUCTION_TRACKSTAR)
            {
                pendingData = ATCCSDataPacker::packGimbalInstruction_TrackStar(_executoryPlan);
            }
            temp->pushControlData(pendingData);
            return true;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager instance is null, can not send plan's sub-instruction.");
#endif
    }
    return false;
}

bool ATCCSPlanController::setCCDInstruction(unsigned int instruction)
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(CCD);
        if(temp)
        {
            std::shared_ptr<ATCCSData> pendingData = nullptr;
            if(instruction == _CCD_INSTRUCTION_SETEXPOSURETACTIC)
            {
                pendingData = ATCCSDataPacker::packCCDInstruction_SetExposureTactic(_executoryPlan);
            }
            else if(instruction == _CCD_INSTRUCTION_STARTEXPOSURE)
            {
                pendingData = ATCCSDataPacker::packCCDInstruction_StartExposure(_executoryPlan);
            }
            temp->pushControlData(pendingData);
            return true;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSMapManager instance is null, can not send plan's sub-instruction.");
#endif
    }
    return false;
}



bool ATCCSPlanController::setDeviceInstruction(unsigned int device, unsigned int instruction) 
{
    switch(device)
    {
        case GIMBAL:
            return setGimbalInstruction(instruction);
            break;
        case CCD:
            return setCCDInstruction(instruction);
            break;
        default:
            return false;
    }
}

bool ATCCSPlanController::waitInstructionOK(unsigned int device, unsigned int instruction /* = 0 */) 
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
        auto base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        if(temp)
        {
            while (!temp->executoryInstructionSuccess(instruction)) 
            {
                auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                if ((now - base) > temp->timeout())
                    break;
                std::chrono::milliseconds dura(1000);
                std::this_thread::sleep_for(dura);
            }
            if(temp->executoryInstructionSuccess(instruction))
                return true;
            else 
                return false;
        }
    }
    else
    {
        
    }
    return false;
}

bool ATCCSPlanController::isRelatedDevicesReady()
{
    return true;
}


std::shared_ptr<ATCCSMapManager<ATCCSDeviceController> > ATCCSPlanController::controllersInstance()
{
    if(_controllers == nullptr)
    {
        try
        {
            _controllers = std::make_shared<ATCCSMapManager<ATCCSDeviceController>>();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }
    }
    return _controllers;
}

std::shared_ptr<atccsplan> ATCCSPlanController::executoryPlanInstance()
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
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }
    }
    return _executoryPlan;
}
