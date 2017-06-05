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
ATCCSPlanController::ATCCSPlanController():
    _controllers(new ATCCSMapManager<ATCCSDeviceController>())
{
    _curPlan = std::make_shared<atccsplan>();
}

void ATCCSPlanController::handleControlData()
{
    while (!stop())
    {
        std::shared_ptr<ATCCSData> data = _fifoQueue.wait_and_pop();
        if(data == nullptr)
            continue;
        
        while(!stop() && !nextOK())
        {
            std::chrono::milliseconds dura(2000);
            std::this_thread::sleep_for(dura);
        }
        if(!stop() && nextOK())
        {
            controlPlan(data);
        }
    }
}

bool ATCCSPlanController::nextOK() const
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

void ATCCSPlanController::controlPlan(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || (!data->validate()))
        return;
    if(_curPlan)
    {
        if(_curPlan->setPlan(data) != atccsplan::RESULT_EXECUTED)
        {
#ifdef OUTDEBUGINFO
            std::cout << "error#" << ERROR_CUSTOM << ": Plan is error, cannot execute."
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
        //reset ATCCSDeviceController's instruction
        resetDeviceInstruction(GIMBAL);
        resetDeviceInstruction(CCD);
        
        //set ATCCSDeviceController's instruction
        if(!isDeviceReady())
            return;
        setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME);
        if(!waitInstructionOK(GIMBAL))
        {
            std::cout << "plan canceled!" << std::endl;
        }
        if(!isDeviceReady())
            return;
        setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR);
        if(!waitInstructionOK(GIMBAL))
        {
            std::cout << "plan canceled!" << std::endl;
        } 

        for(int i=0; i<_curPlan->exposureCount(); i++)
        {
            if(!isDeviceReady())
                break;
            setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC);
            if(!waitInstructionOK(CCD))
                break;
            if(!isDeviceReady())
                break;
            setDeviceInstruction(CCD, _CCD_INSTRUCTION_STARTEXPOSURE);
            if(!waitInstructionOK(CCD))
                break;
        }
    }
}

void ATCCSPlanController::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller)
{
    if(_controllers)
        _controllers->registerController(id, controller);
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
        
    }
}

void ATCCSPlanController::setDeviceInstruction(unsigned int device, unsigned int instruction) 
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
        if(temp)
        {
            std::shared_ptr<ATCCSData> pendingData = nullptr;
            if(instruction == _GIMBAL_INSTRUCTION_SETOBJECTNAME)
            {
                pendingData = ATCCSDataPacker::packGimbalInstruction_SetObjectName(_curPlan);
            }
            else if(instruction == _GIMBAL_INSTRUCTION_TRACKSTAR)
            {
                pendingData = ATCCSDataPacker::packGimbalInstruction_TrackStar(_curPlan);
            }
            else if(instruction == _CCD_INSTRUCTION_SETEXPOSURETACTIC)
            {
                pendingData = ATCCSDataPacker::packCCDInstruction_SetExposureTactic(_curPlan);
            }
            else if(instruction == _CCD_INSTRUCTION_STARTEXPOSURE)
            {
                pendingData = ATCCSDataPacker::packCCDInstruction_StartExposure(_curPlan);
            }
            temp->pushControlData(pendingData);
        }
    }
    else
    {
        
    }
}

bool ATCCSPlanController::waitInstructionOK(unsigned int device) 
{
    if(_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
        auto base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        if(temp)
        {
            while (!temp->isExecutoryInstructionOK()) 
            {
                auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                if ((now - base) > 60)
                    break;
                std::chrono::milliseconds dura(1000);
                std::this_thread::sleep_for(dura);
            }
            if(temp->isExecutoryInstructionOK())
                return true;
            else return false;
        }
    }
    else
    {
        
    }
    return false;
}

bool ATCCSPlanController::isDeviceReady() 
{
    if(_controllers)
    {
        bool isGimbalOK = false;
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(GIMBAL);
        if(temp)
        {
            isGimbalOK = temp->canExecutePlan();
        }
        bool isCCDOK = false;
        std::shared_ptr<ATCCSDeviceController> temp1 = _controllers->controller(CCD);
        if(temp1)
        {
            isCCDOK = temp1->canExecutePlan();
        }
        bool isFilterOK = false;
        std::shared_ptr<ATCCSDeviceController> temp2 = _controllers->controller(FILTER);
        if(temp2)
        {
            isFilterOK = temp2->canExecutePlan();
        }
        bool isFocusOK = false;
        std::shared_ptr<ATCCSDeviceController> temp3 = _controllers->controller(FOCUS);
        if(temp3)
        {
            isFocusOK = temp3->canExecutePlan();
        }
        bool isDomeOK = false;
        std::shared_ptr<ATCCSDeviceController> temp4 = _controllers->controller(SLAVEDOME);
        if(temp4)
        {
            isDomeOK = temp4->canExecutePlan();
        }
    }
    return false;
}


