#include "atccsplanperformer.h"
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
#include "ORMHelper.h"

ATCCSPlanPerformer::ATCCSPlanPerformer(unsigned short at)
: _at(at)
{

}

ATCCSPlanPerformer::~ATCCSPlanPerformer()
{

}

void ATCCSPlanPerformer::updateInstruction(std::shared_ptr<ATCCSData> data)
{
    try
    {
        _instruction = std::make_shared<atccsplaninstruction>();
        _instruction->setPlanInstruction(data);
        if (_instruction->instruction() == STOP)
        {
            clearControlData();
            resetDeviceInstruction(GIMBAL);
            resetDeviceInstruction(CCD);
            resetDeviceInstruction(FILTER);
            //直接向设备发送带外停止指令
            sendStopInstruction(GIMBAL);
            std::cerr << "Gimbal's Emergency stop has sent." << std::endl;
            sendStopInstruction(CCD);
            std::cerr << "CCD's Emergency stop has sent." << std::endl;
        }
    }
    catch (std::exception &e)
    {
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s",
                                            gettext("ATCCSPlanPeroformer fails to update plan's instruction. AT: "), _at, e.what());
    }
}

void ATCCSPlanPerformer::run()
{
    _executoryPlan = executoryPlanInstance();
    while (!stop())
    {
        if (_instruction == nullptr)
        {
            std::chrono::milliseconds dura(2000);
            std::this_thread::sleep_for(dura);
            continue;
        }
        try
        {
            switch (_instruction->instruction())
            {
                case START:
                {
                    setDevicePlanning(true);
                    if (_instruction->strategy() == SINGLE)
                    {
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Single Mode Plans Start------------------------------"));
                        executeSinglePlan();
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Single Mode Plans End------------------------------"));
                    }
                    else if (_instruction->strategy() == SINGLELOOP)
                    {
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Single Loop Mode Plans Start------------------------------"));
                        executeSingleLoopPlan();
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Single Loop Mode Plans End------------------------------"));
                    }
                    else if (_instruction->strategy() == SEQUENCE)
                    {
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Sequence Mode Plans Start------------------------------"));
                        executeSequencePlan();
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Sequence Mode Plans End------------------------------"));

                    }
                    else if (_instruction->strategy() == SEQUENCELOOP)
                    {
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Sequence Loop Mode Plans Start------------------------------"));
                        executeSequenceLoopPlan();
                        ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                                            gettext("------------------------------Sequence Loop Mode Plans End------------------------------"));
                    }
                    //重置指令
                    setDevicePlanning(false);
                    _instruction->unsetPlanInstruction();
                    break;
                }
                case STOP:
                {
                    clearControlData();
                    resetDeviceInstruction(GIMBAL);
                    resetDeviceInstruction(CCD);
                    break;
                }
                case NEXT:
                {
                    break;
                }
                default:
                {
                    std::chrono::milliseconds dura(2000);
                    std::this_thread::sleep_for(dura);
                    break;
                }
            }
        }
        catch (std::exception &e)
        {

        }
    }
}

/**
 * 判断是否可以执行计划,判断标准为所有设备状态正常,无错误.
 * @return true,各设备状态正常; false,有设备不正常
 */
bool ATCCSPlanPerformer::canExecutePlan() const
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(SLAVEDOME);
            if (temp)
                return temp->canExecutePlan();
        }
        catch (std::exception &e)
        {

        }
    }
    return true;
}

/**
 * 更新待执行的计划参数
 * @param data
 * @return 
 */
bool ATCCSPlanPerformer::updatePlanData(std::shared_ptr<ATCCSData> data)
{
    if (data)
    {
        if (_executoryPlan)
        {
            if (_executoryPlan->setPlan(data) == atccsplan::RESULT_EXECUTING)
            {
                std::cerr << "type is : " << _executoryPlan->type() << std::endl;
                return true;
            }
        }
    }
    return false;
}

/**
 * 执行Single模式观测计划
 */
void ATCCSPlanPerformer::executeSinglePlan()
{
    try
    {
        while (queueSize() > 0)
        {
            std::shared_ptr<ATCCSData> data = popControlData();
            if (data == nullptr)
                continue;
            if (!updatePlanData(data))
                continue;
            if (_instruction->start() == _executoryPlan->tag())
            {
                break;
            }
            else
                continue;
        }
        if (_instruction->start() == _executoryPlan->tag())
        {
            executeAPlanWithDebug();
        }
    }
    catch (std::exception &e)
    {

    }
}

void ATCCSPlanPerformer::executeAPlanWithDebug()
{
    ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                        gettext("------------------------------A Plan Start------------------------------"));
    executeAPlan();
    ATCCSExceptionHandler::addException(ATCCSException::DEBUGINFO, "%s",
                                        gettext("------------------------------The Plan End------------------------------"));
}

/**
 * 执行Single Loop模式观测计划
 */
void ATCCSPlanPerformer::executeSingleLoopPlan()
{
    while (queueSize() > 0)
    {
        std::shared_ptr<ATCCSData> data = popControlData();
        if (data == nullptr)
            continue;
        if (!updatePlanData(data))
            continue;
        if (_instruction->start() == _executoryPlan->tag())
        {
            break;
        }
        else
            continue;
    }
    if (_instruction->start() == _executoryPlan->tag())
    {
        while (!stop() && _instruction->instruction() != STOP)
        {
            executeAPlanWithDebug();
        }
    }
}

/**
 * 执行Sequence模式观测计划
 */
void ATCCSPlanPerformer::executeSequencePlan()
{
    while (!stop() && _instruction->instruction() != STOP)
    {
        std::shared_ptr<ATCCSData> data = popControlData();
        if (data == nullptr)
            continue;
        if (!updatePlanData(data))
            continue;
        if (_instruction->start() != _executoryPlan->tag())
        {

            pushControlData(data);
            continue;
        }
        else
            break;
    }

    executeAPlanWithDebug();


    while (queueSize() > 0 && _instruction->instruction() != STOP)
    {
        std::shared_ptr<ATCCSData> data = popControlData();
        if (data == nullptr)
            continue;
        if (!updatePlanData(data))
            continue;
        executeAPlanWithDebug();
    }
}

void ATCCSPlanPerformer::executeSequenceLoopPlan()
{
    while (!stop() && _instruction->instruction() != STOP)
    {
        //        std::cout << "queue size: " << queueSize() << std::endl;
        std::shared_ptr<ATCCSData> data = popControlData();
        //        std::cout << "start is : " << _instruction-> start() << std::endl;
        //        std::cout << "queue size: " << queueSize() << std::endl;
        if (data == nullptr)
            continue;
        if (!updatePlanData(data))
            continue;
        if (_instruction->start() != _executoryPlan->tag())
        {
            pushControlData(data);
            continue;
        }
        else
        {
            pushControlData(data);
            break;
        }
    }

    executeAPlanWithDebug();

    while (!stop() && _instruction->instruction() != STOP)
    {
        std::shared_ptr<ATCCSData> data = popControlData();
        if (data == nullptr)
            continue;
        if (!updatePlanData(data))
            continue;
        executeAPlanWithDebug();
        //        std::cout << "-------------A Plan start------------" << std::endl;
        //        executeAPlan();
        //        std::cout << "-------------A Plan end------------" << std::endl;
        pushControlData(data);
    }
}

void ATCCSPlanPerformer::executeAPlan()
{
    std::cout << "Current Plan" << _executoryPlan->tag() << std::endl;
    if (_instruction->instruction() == STOP)
        return;
    //持久化计划数据
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

    if (_instruction->instruction() == STOP)
        return;

    //清空Filter指令队列
    resetDeviceInstruction(FILTER);
    //清空转台指令队列.
    resetDeviceInstruction(GIMBAL);
    //清空CCD指令队列
    resetDeviceInstruction(CCD);

    if (_executoryPlan->type() != BIAS && _executoryPlan->type() != DARK)
    {
        if (!isRelatedDevicesReady())
            return;
        if (_instruction->instruction() == STOP)
            return;
        if (!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), GIMBAL,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif
            return;
        }

        if (_instruction->instruction() == STOP)
            return;
        if (!waitInstructionFinish(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), GIMBAL,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif
            return;
        }

        //Send GImbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
        if (!isRelatedDevicesReady())
            return;
        if (_instruction->instruction() == STOP)
            return;
        if (!setDeviceInstruction(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), GIMBAL,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif
            return;
        }
        if (_instruction->instruction() == STOP)
            return;
        if (!waitInstructionFinish(GIMBAL, _GIMBAL_INSTRUCTION_TRACKSTAR))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), GIMBAL,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif
            return;
        }
    }



    //Send CCD's instruction: _CCD_INSTRUCTION_SETGAIN
    if (!isRelatedDevicesReady())
        return;
    if (_instruction->instruction() == STOP)
        return;
    if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETGAIN))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), CCD,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif
        return;
    }
    if (_instruction->instruction() == STOP)
        return;
    if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETGAIN))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), CCD,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif
        return;
    }

    //Send CCD's instruction: _CCD_INSTRUCTION_SETRSMODE
    if (!isRelatedDevicesReady())
        return;
    if (_instruction->instruction() == STOP)
        return;
    if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETRSMODE))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), CCD,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif
        return;
    }
    if (_instruction->instruction() == STOP)
        return;
    if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETRSMODE))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), CCD,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif
        return;
    }

    //Send CCD's instruction: _CCD_INSTRUCTION_SETBIN
    if (!isRelatedDevicesReady())
        return;
    if (_instruction->instruction() == STOP)
        return;
    if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETBIN))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), CCD,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
#endif
        return;
    }
    if (_instruction->instruction() == STOP)
        return;
    if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETBIN))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), CCD,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
#endif
        return;
    }


    if (!isRelatedDevicesReady())
        return;
    if (_instruction->instruction() == STOP)
        return;
    if (!setDeviceInstruction(FILTER, _FILTER_INSTRUCTION_SETPOSITION))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), FILTER,
                                            gettext(" Instruction: "), _FILTER_INSTRUCTION_SETPOSITION);
#endif
        return;
    }

    if (_instruction->instruction() == STOP)
        return;
    if (!waitInstructionFinish(FILTER, _FILTER_INSTRUCTION_SETPOSITION))
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                            gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                            gettext(" Device: "), FILTER,
                                            gettext(" Instruction: "), _FILTER_INSTRUCTION_SETPOSITION);
#endif
        return;
    }



    if (_instruction->instruction() == STOP)
        return;
    for (int i = 0; i < _executoryPlan->exposureCount(); i++)
    {
        //Send CCD's instruction: _CCD_INSTRUCTION_SETEXPOSURETACTIC
        if (!isRelatedDevicesReady())
            break;
        if (_instruction->instruction() == STOP)
            break;
        bool statusOk = false;
        auto base = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        while (!canExecutePlan())
        {
            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            if(now-base > 30)
                break;
            std::chrono::milliseconds dura(2000);
            std::this_thread::sleep_for(dura);

        }
        if(!canExecutePlan())
            break;

        if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), CCD,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif
            break;
        }
        if (_instruction->instruction() == STOP)
            return;
        if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_SETEXPOSURETACTIC))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), CCD,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif                    
            break;
        }
        //Send CCD's instruction: _CCD_INSTRUCTION_STARTEXPOSURE
        if (!isRelatedDevicesReady())
            break;
        if (_instruction->instruction() == STOP)
            return;
        if (!setDeviceInstruction(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to set the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), CCD,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_STARTEXPOSURE);
#endif
            break;
        }
        if (_instruction->instruction() == STOP)
            return;
        if (!waitInstructionFinish(CCD, _CCD_INSTRUCTION_STARTEXPOSURE))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("Fails to execute the instruction and the plan is neglected. AT: "), _at,
                                                gettext(" Device: "), CCD,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_STARTEXPOSURE);
#endif                    
            break;
        }
    }
}

/**
 * control a plan's procedure.
 * @param data, the raw plan encapsulated in ATCCSData.
 */
void ATCCSPlanPerformer::executePlan(std::shared_ptr<ATCCSData> data)
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

void ATCCSPlanPerformer::registerDeviceController(unsigned int id, std::shared_ptr<ATCCSDeviceController> controller)
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

void ATCCSPlanPerformer::setDevicePlanning(bool planning)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(GIMBAL);
            if (temp)
            {
                temp->setPlanning(planning);
            }
            temp = _controllers->controller(CCD);
            if (temp)
            {
                temp->setPlanning(planning);
            }
            temp = _controllers->controller(FILTER);
            if (temp)
            {
                temp->setPlanning(planning);
            }
        }
        catch (std::exception &e)
        {

        }
    }
}

void ATCCSPlanPerformer::resetDeviceInstruction(unsigned int device)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
            if (temp)
            {
                temp->clearControlData();
                temp->setPlanningStop(true);
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

unsigned short ATCCSPlanPerformer::at() const
{
    return _at;
}

bool ATCCSPlanPerformer::setGimbalInstruction(unsigned int instruction)
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

bool ATCCSPlanPerformer::setCCDInstruction(unsigned int instruction)
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

bool ATCCSPlanPerformer::setFilterInstruction(unsigned int instruction)
{
    if (_controllers)
    {
        try
        {
            std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(FILTER);
            if (temp)
            {
                std::shared_ptr<ATCCSData> pendingData = nullptr;
                if (instruction == _FILTER_INSTRUCTION_SETPOSITION)
                {
                    pendingData = ATCCSDataPacker::packFilterInstruction_SetPosition(_executoryPlan);
                }
                temp->pushControlData(pendingData);
                return true;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                    gettext(" Fails to find AT Controller and  set AT Controller's instruction. AT: "), _at,
                                                    gettext(" Device: "), FILTER,
                                                    gettext(" Instruction: "), instruction);
#endif            
            }
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("Fails to set AT Controller's instruction. AT: "), _at,
                                                gettext(" Device: "), FILTER,
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

bool ATCCSPlanPerformer::sendStopInstruction(unsigned int device)
{
    if (_controllers)
    {
        std::shared_ptr<ATCCSDeviceController> temp = _controllers->controller(device);
        if (temp)
        {
            switch (device)
            {
                case GIMBAL:
                {
                    std::shared_ptr<ATCCSData> stopInstruction = ATCCSDataPacker::packGimbalInstruction_Stop(_at);
                    if (stopInstruction)
                    {
                        int size = temp->sendInstruction(stopInstruction);
                        if (size != stopInstruction->size())
                        {
#ifdef OUTERRORINFO
                            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d",
                                                                gettext("ATCCSPlanPerformer fails to send GIMBAL's stop instruction. AT: "), _at);
#endif                    
                        }
                    }
                    else
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d",
                                                            gettext("ATCCSPlanPerformer fails to construct GIMBAL's stop instruction. AT: "), _at);
#endif                
                    }
                    break;
                }
                case CCD:
                {
                    std::shared_ptr<ATCCSData> stopInstruction = ATCCSDataPacker::packCCDInstruction_Stop(_at);
                    if (stopInstruction)
                    {
                        int size = temp->sendInstruction(stopInstruction);
                        if (size != stopInstruction->size())
                        {
#ifdef OUTERRORINFO
                            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d",
                                                                gettext("ATCCSPlanPerformer fails to send CCD's abort instruction. AT: "), _at);
#endif                    
                        }
                    }
                    else
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d",
                                                            gettext("ATCCSPlanPerformer fails to construct CCD's abort instruction. AT: "), _at);
#endif                
                    }
                    break;
                }
            }
        }
    }
}

bool ATCCSPlanPerformer::setDeviceInstruction(unsigned int device, unsigned int instruction)
{
    switch (device)
    {
        case GIMBAL:
            return setGimbalInstruction(instruction);
            break;
        case CCD:
            return setCCDInstruction(instruction);
            break;
        case FILTER:
            return setFilterInstruction(instruction);
            break;
        default:
            return false;
    }
}

bool ATCCSPlanPerformer::waitInstructionFinish(unsigned int device, unsigned int instruction)
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

bool ATCCSPlanPerformer::isRelatedDevicesReady()
{
    return true;
}

std::shared_ptr<atccsplan> ATCCSPlanPerformer::executoryPlanInstance()
{
    return nullptr;
}

void ATCCSPlanPerformer::executePlanParell()
{
    bool Filter1Send, Gimbal1Send, Gimbal2Send, CCD1Send, CCD2Send, CCD3Send = false;
    bool Filter1OK, Gimbal1OK, Gimbal2OK, CCD1OK, CCD2OK, CCD3OK = false;
    while (!(Filter1Send && Gimbal1Send && Gimbal2Send && CCD1Send && CCD2Send && CCD3Send))
    {
        if (!Filter1Send)
        {
            if (!setFilterInstruction(_FILTER_INSTRUCTION_SETPOSITION))
                break;
            Filter1Send = true;
        }
        if (!Gimbal1Send)
        {
            if (!setGimbalInstruction(_GIMBAL_INSTRUCTION_SETOBJECTNAME))
                break;
            Gimbal1Send = true;
        }
        if (!Gimbal1Send && !Gimbal2Send && waitInstructionFinishNew(GIMBAL, _GIMBAL_INSTRUCTION_SETOBJECTNAME))
        {
            if (!setGimbalInstruction(_GIMBAL_INSTRUCTION_TRACKSTAR))
                break;
            Gimbal2Send = true;
        }
        if (!CCD1Send)
        {
            if (!setCCDInstruction(_CCD_INSTRUCTION_SETGAIN))
                break;
            CCD1Send = true;
        }

    }

}

bool ATCCSPlanPerformer::waitInstructionFinishNew(unsigned int device, unsigned int instruction)
{
    return true;
}
