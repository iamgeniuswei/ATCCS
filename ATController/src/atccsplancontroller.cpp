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
#include "at60plan-odb.hxx"
#include "ORMHelper.h"

ATCCSPlanController::ATCCSPlanController(unsigned short at)
: _at(at)
{

}

ATCCSPlanController::~ATCCSPlanController()
{

}

void ATCCSPlanController::run()
{
    while(!stop())
    {
        try
        {
            std::shared_ptr<ATCCSData> data = popControlData();
            if (data == nullptr)
                continue;

            while (!stop() && !canExecutePlan())
            {
                std::chrono::milliseconds dura(2000);
                std::this_thread::sleep_for(dura);
            }
            if (!stop() && canExecutePlan())
            {
                executePlan(data);
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, 0, e.what());
#endif
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





/**
 * control a plan's procedure.
 * @param data, the raw plan encapsulated in ATCCSData.
 */
void ATCCSPlanController::executePlan(std::shared_ptr<ATCCSData> data)
{
    if (data == nullptr)
        return;
    if (!(data->validate()))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCS Plan's raw data is error and can not be resolved, the plan is canceled.");
#endif
        return;
    }

    if (!_executoryPlan)
    {
        _executoryPlan = executoryPlanInstance();
    }

    if (_executoryPlan)
    {
        if (_executoryPlan->setPlan(data) == atccsplan::RESULT_EXECUTED)
        {
#ifdef OUTDEBUGINFO
            std::cout << "---------------------------Start to execute plan--------------------------" << std::endl;
#endif

            try
            {
#ifdef DATAPERSISTENCE
                _executoryPlan->persistPlan();
#endif
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                    __FILE__, __func__, __LINE__, _at, 0,
                                                    e.what());
#endif
            }
            
            try
            {
                //reset ATCCSDeviceController's instruction queue.
                resetDeviceInstruction(GIMBAL);
                resetDeviceInstruction(CCD);

                //Send GImbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
                //check all the related devices' status, if they are ready?
                //if ready, go on;
                //else, abandon this plan.
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0,
                                                        "Gimbal's _GIMBAL_INSTRUCTION_SETOBJECTNAME fails to dispatch, plan is canceled.");
#endif
//                    return;
                }
                if (!waitInstructionOK(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0, 
                                                        "Gimbal's _GIMBAL_INSTRUCTION_SETOBJECTNAME fails to execute, plan is canceled.");
#endif
//                    return;
                }

                //Send GImbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0,
                                                        "Gimbal's _GIMBAL_INSTRUCTION_TRACKSTAR fails to dispatch, plan is canceled.");
#endif
//                    return;
                }

                if (!waitInstructionOK(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0,
                                                        "Gimbal's _GIMBAL_INSTRUCTION_TRACKSTAR fails to execute, plan is canceled.");
#endif
//                    return;
                }

                //Send CCD's instruction: _CCD_INSTRUCTION_SETGAIN
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETGAIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0, 
                                                        "CCD's _CCD_INSTRUCTION_SETGAIN fails to dispatch, plan is canceled.");
#endif
//                    return;
                }
                if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_SETGAIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0, 
                                                        "CCD's _CCD_INSTRUCTION_SETGAIN fails to execute, plan is canceled.");
#endif
//                    return;
                }

                //Send CCD's instruction: _CCD_INSTRUCTION_SETRSMODE
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETRSMODE))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0,
                                                        "CCD's _CCD_INSTRUCTION_SETRSMODE fails to dispatch, plan is canceled.");
#endif
//                    return;
                }
                if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_SETRSMODE))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0,
                                                        "CCD's _CCD_INSTRUCTION_SETRSMODE fails to execute, plan is canceled.");
#endif
//                    return;
                }

                //Send CCD's instruction: _CCD_INSTRUCTION_SETBIN
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETBIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0,
                                                        "CCD's _CCD_INSTRUCTION_SETBIN fails to dispatch, plan is canceled.");
#endif
//                    return;
                }
                if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_SETBIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                        __FILE__, __func__, __LINE__, _at, 0, 
                                                        "CCD's _CCD_INSTRUCTION_SETBIN fails to execute, plan is canceled.");
#endif
//                    return;
                }  

                for (int i = 0; i < _executoryPlan->exposureCount(); i++)
                {
                    //Send CCD's instruction: _CCD_INSTRUCTION_SETEXPOSURETACTIC
                    if (!isRelatedDevicesReady())
                        break;
                    if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                            __FILE__, __func__, __LINE__, _at, 0, 
                                                            "CCD's _CCD_INSTRUCTION_SETEXPOSURETACTIC fails to dispatch, plan is canceled.");
#endif
//                        break;
                    }
                    if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                            __FILE__, __func__, __LINE__, _at, 0, 
                                                            "CCD's _CCD_INSTRUCTION_SETEXPOSURETACTIC fails to execute, plan is canceled.");
#endif                    
//                        break;
                    }
                    //Send CCD's instruction: _CCD_INSTRUCTION_STARTEXPOSURE
                    if (!isRelatedDevicesReady())
                        break;
                    if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                            __FILE__, __func__, __LINE__, _at, 0,
                                                            "CCD's _CCD_INSTRUCTION_STARTEXPOSURE fails to dispatch, plan is canceled.");
#endif
//                        break;
                    }
                    if (!waitInstructionOK(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                            __FILE__, __func__, __LINE__, _at, 0,
                                                            "CCD's _CCD_INSTRUCTION_STARTEXPOSURE fails to execute, plan is canceled.");
#endif                    
//                        break;
                    }
                    std::cout << "i=" << i<< std::endl;
                }                
            }
            catch(std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                    __FILE__, __func__, __LINE__, _at, 0,
                                                    e.what());
#endif                
            }  
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, 0,
                                                "Plan's raw data is error and can not be resolved, the plan is canceled.");
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, 0,
                                            "atccsplan instance is null, the plan is canceled.");
#endif
    }
}

void ATCCSPlanController::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller)
{
    if (_controllers == nullptr)
    {
        try
        {
            _controllers = std::make_shared<ATCCSMapManager < ATCCSDeviceController >> ();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, 0, e.what());
#endif
            return;
        }        
    }
    
    try
    {
        _controllers->registerController(id, controller);
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, _at, 0, e.what());
#endif        
    }
}

void ATCCSPlanController::resetDeviceInstruction(unsigned int device)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
            if (temp)
            {
                temp->clearControlData();
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                    __FILE__, __func__, __LINE__, _at, device,
                                                    "There is no such ATCCSDeviceController, fails to resetDeviceInstruction.");
#endif        
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, device, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, 0,
                                            "ATCCSMapManager<ATCCSDeviceController> is null, fails to resetDeviceInstruction.");
#endif        
    }
}

unsigned short ATCCSPlanController::at() const
{
    return _at;
}

bool ATCCSPlanController::setGimbalInstruction(unsigned int instruction)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(GIMBAL);
            if (temp)
            {
                std::shared_ptr<ATCCSData> pendingData = nullptr;
                if (instruction == _GIMBAL_INSTRUCTION_SETOBJECTNAME)
                {
                    pendingData = ATCCSDataPacker::packGimbalInstruction_SetObjectName(_executoryPlan);
                }
                else if (instruction == _GIMBAL_INSTRUCTION_TRACKSTAR)
                {
                    pendingData = ATCCSDataPacker::packGimbalInstruction_TrackStar(_executoryPlan);
                }
                temp->pushControlData(pendingData);
                return true;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                    __FILE__, __func__, __LINE__, _at, GIMBAL,
                                                    "There is no such ATCCSDeviceController, fails to dispatch plan's instruction to GIMBAL.");
#endif            
            }
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, GIMBAL, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, GIMBAL,
                                            "ATCCSMapManager<ATCCSDeviceController> is null, fails to dispatch plan's instruction to GIMBAL.");
#endif
    }
    return false;
}

bool ATCCSPlanController::setCCDInstruction(unsigned int instruction)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(CCD);
            if (temp)
            {
                std::shared_ptr<ATCCSData> pendingData = nullptr;

                if (instruction == _CCD_INSTRUCTION_SETEXPOSURETACTIC)
                {
                    pendingData = ATCCSDataPacker::packCCDInstruction_SetExposureTactic(_executoryPlan);
                }
                else if (instruction == _CCD_INSTRUCTION_STARTEXPOSURE)
                {
                    pendingData = ATCCSDataPacker::packCCDInstruction_StartExposure(_executoryPlan);
                }
                else if (instruction == _CCD_INSTRUCTION_SETBIN)
                {
                    pendingData = ATCCSDataPacker::packCCDInstruction_SetBIN(_executoryPlan);
                }
                else if (instruction == _CCD_INSTRUCTION_SETGAIN)
                {
                    pendingData = ATCCSDataPacker::packCCDInstruction_SetGain(_executoryPlan);
                }
                else if (instruction == _CCD_INSTRUCTION_SETRSMODE)
                {
                    pendingData = ATCCSDataPacker::packCCDInstruction_SetReadSpeedMode(_executoryPlan);
                }
                temp->pushControlData(pendingData);
                return true;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                    __FILE__, __func__, __LINE__, _at, CCD,
                                                    "There is no such ATCCSDeviceController, fails to dispatch plan's instruction to CCD.");
#endif                
            }
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, CCD, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, CCD,
                                            "ATCCSMapManager<ATCCSDeviceController> is null, fails to dispatch plan's instruction to CCD.");
#endif
    }
    return false;
}

bool ATCCSPlanController::setDeviceInstruction(unsigned int device, unsigned int instruction)
{
    switch (device)
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

bool ATCCSPlanController::waitInstructionOK(unsigned int device, unsigned int instruction)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);            
            if (temp)
            {
                auto base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                while (!temp->isExecutoryInstructionFinished(instruction))
                {
//                    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//                    if ((now - base) > temp->timeout())
//                        break;
                    std::chrono::milliseconds dura(1000);
                    std::this_thread::sleep_for(dura);
                }
                if (temp->isExecutoryInstructionSuccess(instruction))
                    return true;
                else
                    return false;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                    __FILE__, __func__, __LINE__, _at, device,
                                                    "There is no such ATCCSDeviceController, fails to check the result of device's instruction.");
#endif                
            }
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, _at, device, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, _at, device,
                                            "ATCCSMapManager<ATCCSDeviceController> is null, fails to check the result of device's instruction.");
#endif
    }
    return false;
}

bool ATCCSPlanController::isRelatedDevicesReady()
{
    return true;
}


std::shared_ptr<atccsplan> ATCCSPlanController::executoryPlanInstance()
{
    return nullptr;
}
