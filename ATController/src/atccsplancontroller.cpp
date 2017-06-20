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
    while (!stop())
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("Fails to execute the plan. AT: "), _at,
                                                e.what());
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
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                            gettext("The plan's raw data is error and the plan is neglected. AT: "), _at);
#endif
        return;
    }

    if (!_executoryPlan)
    {
        _executoryPlan = executoryPlanInstance();
    }

    if (_executoryPlan)
    {
        if (_executoryPlan->setPlan(data) == atccsplan::RESULT_EXECUTING)
        {
#ifdef OUTDEBUGINFO
            ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s%s%s",
                                                "--------------------------",
                                                gettext("Start execute a plan"),
                                                "--------------------------");
#endif
            //persist the plan.
#ifdef DATAPERSISTENCE
            try
            {
                _executoryPlan->persistPlan();
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                    gettext("Fails to persist the plan. AT: "), _at,
                                                    e.what());
#endif
            }
#endif

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
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), GIMBAL,
                                                        gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif
                    //                    return;
                }
                if (!waitInstructionFinish(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), GIMBAL,
                                                        gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif
                    //                    return;
                }

                //Send GImbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), GIMBAL,
                                                        gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif
                    //                    return;
                }

                if (!waitInstructionFinish(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), GIMBAL,
                                                        gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif
                    //                    return;
                }

                //Send CCD's instruction: _CCD_INSTRUCTION_SETGAIN
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETGAIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), CCD,
                                                        gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif
                    //                    return;
                }
                if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETGAIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), CCD,
                                                        gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif
                    //                    return;
                }

                //Send CCD's instruction: _CCD_INSTRUCTION_SETRSMODE
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETRSMODE))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), CCD,
                                                        gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif
                    //                    return;
                }
                if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETRSMODE))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), CCD,
                                                        gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif
                    //                    return;
                }

                //Send CCD's instruction: _CCD_INSTRUCTION_SETBIN
                if (!isRelatedDevicesReady())
                    return;
                if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETBIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), CCD,
                                                        gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
#endif
                    //                    return;
                }
                if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETBIN))
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                        gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                        gettext(" Device: "), CCD,
                                                        gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
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
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                            gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                            gettext(" Device: "), CCD,
                                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif
                        //                        break;
                    }
                    if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                            gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                            gettext(" Device: "), CCD,
                                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif                    
                        //                        break;
                    }
                    //Send CCD's instruction: _CCD_INSTRUCTION_STARTEXPOSURE
                    if (!isRelatedDevicesReady())
                        break;
                    if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                            gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                            gettext(" Device: "), CCD,
                                                            gettext(" Instruction: "), _CCD_INSTRUCTION_STARTEXPOSURE);
#endif
                        //                        break;
                    }
                    if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                            gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                            gettext(" Device: "), CCD,
                                                            gettext(" Instruction: "), _CCD_INSTRUCTION_STARTEXPOSURE);
#endif                    
                        //                        break;
                    }

                }
            }
            catch (std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                    gettext("Fails to execute the plan and the plan is neglected. AT: "), _at,
                                                    e.what());
#endif                
            }
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                                gettext("The plan is fail to be set and neglected. AT: "), _at);
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d",
                                            gettext("The plan is fail to be created and neglected. AT: "), _at);
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("The AT Controllers' manager is fail to be created, fails to register AT Controller. The id is: "), id, e.what());
#endif
            return;
        }
    }

    try
    {
        _controllers->registerController(id, controller);
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                                gettext("Fails to register AT Controller. The id is: "), id, e.what());
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
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                                gettext("Fails to find AT Controller and AT Controller's instruction queue. AT: "), _at,
                                                gettext(" Device: "), device);
#endif        
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s",
                                                gettext("Fails to clear the AT Controller's instruction queue. AT: "), _at, 
                                                gettext(" Device: "), device, e.what());
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                                gettext("The AT Controllers' manager is fail to be created, fails to clear AT Controller's instruction queue. AT: "), _at,
                                                gettext(" Device: "), device);
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                    gettext(" Fails to find AT Controller and  set AT Controller's instruction. AT: "), _at,
                                                    gettext(" Device: "), GIMBAL,
                                                    gettext(" Instruction: "), instruction);
#endif            
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("Fails to set AT Controller's instruction. AT: "), _at,
                                                gettext(" Device: "), GIMBAL,
                                                gettext(" Instruction: "), instruction);
#endif           
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The AT Controllers' manager is fail to be created, fails to set AT Controller's instruction. AT: "), _at,
                                                gettext(" Device: "), GIMBAL,
                                                gettext(" Instruction: "), instruction);
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                    gettext(" Fails to find AT Controller and  set AT Controller's instruction. AT: "), _at,
                                                    gettext(" Device: "), CCD,
                                                    gettext(" Instruction: "), instruction);
#endif                
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("Fails to set AT Controller's instruction. AT: "), _at,
                                                gettext(" Device: "), CCD,
                                                gettext(" Instruction: "), instruction);
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The AT Controllers' manager is fail to be created, fails to set AT Controller's instruction. AT: "), _at,
                                                gettext(" Device: "), CCD,
                                                gettext(" Instruction: "), instruction);
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

bool ATCCSPlanController::waitInstructionFinish(unsigned int device, unsigned int instruction)
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                    gettext("Fails to find AT Controller and wait AT Controller's instruction result. AT: "), _at,
                                                    gettext(" Device: "), device,
                                                    gettext(" Instruction: "), instruction);
#endif                
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("Fails to wait AT Controller's instruction result. AT: "), _at,
                                                gettext(" Device: "), device,
                                                gettext(" Instruction: "), instruction);
#endif            
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The AT Controllers' manager is fail to be created, fails to wait AT Controller's instruction result. AT: "), _at,
                                            gettext(" Device: "), device,
                                            gettext(" Instruction: "), instruction);
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
