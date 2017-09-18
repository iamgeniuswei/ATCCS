/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60GimbalController.cpp
 * Author: lenovo
 * 
 * Created on May 9, 2017, 11:00 AM
 */

#include "atccsgimbalcontroller.h"
#include "atccspublicstatus.h"
#include "atccspublicstatus-odb.hxx"
#include "atccsgimbalstatus.h"
#include "atccsgimbalstatus-odb.hxx"
#ifdef DATAPERSISTENCE
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
using namespace odb::core;
#endif
#include "atccssetting.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_gimbal_define.h"
#include "atccsinstruction.h"
#include "ORMHelper.h"
#include <memory>
#include <stdbool.h>
#include <iomanip>
#include "atccsexceptionhandler.h"

ATCCSGimbalController::ATCCSGimbalController(unsigned short at, unsigned short device)
: ATCCSDeviceController(at,device)
{

}

ATCCSGimbalController::~ATCCSGimbalController()
{
}


/**
 * query the concrete AT's gimbal's real-time status, 
 * and judge whether it is normal. Generally speaking, 
 * that its error equals to _GIMBAL_ERROR_NORMAL means 
 * status is normal.
 * @return true if ok, false if not.
 */
bool ATCCSGimbalController::isStatusOK() const
{
    if(_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            //FIXME: What's the GImbal's normal status.
            return _realtimeStatus->error() == _GIMBAL_ERROR_NORMAL;
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s",
                                                gettext("Fails to query whether status is ok. AT: "), _at,
                                                gettext(" Device: "), _device,
                                                e.what());
#endif  
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The status is fail to be created, fails to query whether status is ok. AT: "), _at,
                                            gettext(" Device: "), _device);
#endif
    }
    return false;
}


/**
 * query the AT's Gimbal's executory instruction's result,
 * and judge the progress it has executed.
 * @return true if has done, false if in progress.
 */
bool ATCCSGimbalController::isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    bool ret = false;
    if (instruction)
    {
        switch (instruction->instruction())
        {
            case _GIMBAL_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_FINDHOME:
            {
                ret = checkResult_FindHome(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_TRACKSTAR:
            {
                ret = checkResult_TrackStar(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_SETOBJECTNAME:
            {
                ret = checkResult_SetObjectName(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_SLEWAZEL:
            {
                ret = checkResult_SlewAzEl(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_SLEWDEROTATOR:
            {
                ret = checkResult_SlewDerotator(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_CONFIGDEROTATOR:
            {
                ret = checkResult_ConfigDerotator(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_STOP:
            {
                ret = checkResult_Stop(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_SPEEDCORRECT:
            {
                ret = checkResult_SpeedCorrect(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_PARK:
            {
                ret = checkResult_Park(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_FIXEDMOVE:
            {
                ret = checkResult_FixedMove(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_POSITIONCORRECT:
            {
                ret = checkResult_PositionCorrect(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_COVERACTION:
            {
                ret = checkResult_CoverAction(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_FOCUSACTION:
            {
                ret = checkResult_FocusAction(instruction, rawData);
                break;
            }
            case _GIMBAL_INSTRUCTION_EMERGENCYSTOP:
            {
                ret = checkResult_Emergence(instruction, rawData);
                break;
            }
            default:
                break;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
                                            gettext("The instruction is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device);
#endif        
    }
    return ret;
}

//bool ATCCSGimbalController::isExecutoryInstructionOK(unsigned int instruction)
//{
//    if(instruction)
//    {
//        if(instruction->instruction() == instruction)
//            return isExecutoryInstructionOK();
//        return false;
//    }
//    else
//    {
//        return false;
//    }
//}


bool ATCCSGimbalController::canExecutePlan()
{
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        if (_realtimeStatus)
        {
            unsigned int temp = _realtimeStatus->curstatus();
            return _realtimeStatus->error() == _GIMBAL_ERROR_NORMAL &&
                    temp != _GIMBAL_STATUS_DISCONNECT &&
                    temp != _GIMBAL_STATUS_CONNECTING &&
                    temp != _GIMBAL_STATUS_DISCONNECTING &&
                    temp != _GIMBAL_STATUS_NOTFINDHOME &&
                    temp != _GIMBAL_STATUS_HOMING &&
                    temp != _GIMBAL_STATUS_EMERGENCYING &&
                    temp != _GIMBAL_STATUS_EMERGENCY &&
                    temp != _GIMBAL_STATUS_ERROR;
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        std::cerr << "error#" << ERROR_STDEXCEPTRION << ": Device " << at() << " " << e.what()
                << " @" << __func__
                << " @" << __FILE__
                << " @" << __LINE__ << std::endl;
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_CONNECT
 * @return true if success, false if fails. 
 */
bool ATCCSGimbalController::checkResult_Connect(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        if (rawData == nullptr || !(rawData->validate()))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONNECT);
#endif            
            return false;
        }
        if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_CONNECT)))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONNECT);
#endif            
            return false;
        }
        _AT_GIMBAL_PARAM_CONNECT *param = (_AT_GIMBAL_PARAM_CONNECT*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            unsigned int curStatus = _realtimeStatus->curstatus();
            if (param->connect == CONNECT)
            {
                return (curStatus != _GIMBAL_STATUS_DISCONNECT)&&
                        (curStatus != _GIMBAL_STATUS_CONNECTING)&&
                        (curStatus != _GIMBAL_STATUS_DISCONNECTING);
            }
            else if (param->connect == DISCONNECT)
            {
                return curStatus == _GIMBAL_STATUS_DISCONNECT;
            }

        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONNECT,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONNECT);
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_FINDHOME
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_FindHome(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_FREEZED;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FINDHOME,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FINDHOME);
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_TRACKSTAR
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_TrackStar(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsgimbalstatus> temp = std::dynamic_pointer_cast<atccsgimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif                 
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_TRACKSTAR)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif                
                return false;
            }
            _AT_GIMBAL_PARAM_TRACKSTAR *param = (_AT_GIMBAL_PARAM_TRACKSTAR*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            std::cout << std::fixed << std::setprecision(8) << param->rightAscension <<"---" << temp->targetJ2000RightAscension() << std::endl;
            std::cout << std::fixed << std::setprecision(8) << param->declination << "---" << temp->targetJ2000Declination() << std::endl;
            return (temp->curstatus() == _GIMBAL_STATUS_TRACKING)&&
                    (cmpDouble(param->rightAscension, temp->targetJ2000RightAscension(), 0.0001))&&
                    (cmpDouble(param->declination, temp->targetJ2000Declination(), 0.0001));
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR);
#endif
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_TRACKSTAR,
                                                e.what());
#endif
    }    
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SetObjectName(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsgimbalstatus> temp = std::dynamic_pointer_cast<atccsgimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_SETOBJECTNAME)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif                
                return false;
            }
            _AT_GIMBAL_PARAM_SETOBJECTNAME *param = (_AT_GIMBAL_PARAM_SETOBJECTNAME*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            std::string tempObjectName(param->objectName);
            std::cout << tempObjectName << "--" << temp->trackObjectName() << "--" << temp->trackType() << "-" << param->objectType << std::endl;
            return (temp->trackType() == param->objectType)&&
                    (temp->trackObjectName() == tempObjectName);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
#endif
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SETOBJECTNAME,
                                                e.what());
#endif        
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SLEWAZEL
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SlewAzEl(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_SLEWED;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SLEWAZEL,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SLEWAZEL);
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SLEWDEORTATOR
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SlewDerotator(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsgimbalstatus> temp = std::dynamic_pointer_cast<atccsgimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SLEWDEROTATOR);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_SLEWDEROTATOR)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SLEWDEROTATOR);
#endif                
                return false;
            }
            _AT_GIMBAL_PARAM_SLEWDEROTATOR *param = (_AT_GIMBAL_PARAM_SLEWDEROTATOR*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return cmpDouble(param->position, temp->axis3Encoder(), 1 / 360);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SLEWDEROTATOR);
#endif
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SLEWDEROTATOR,
                                                e.what());
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_CONFIGDEORTATOR
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_ConfigDerotator(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsgimbalstatus> temp = std::dynamic_pointer_cast<atccsgimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONFIGDEROTATOR);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_CONFIGDEROTATOR)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONFIGDEROTATOR);
#endif                
                return false;
            }
            _AT_GIMBAL_PARAM_CONFIGDEROTATOR *param = (_AT_GIMBAL_PARAM_CONFIGDEROTATOR*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
           
            std::lock_guard<std::mutex> lk(_statusLock);
            return param->mode == temp->axis3Mode();
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONFIGDEROTATOR);
#endif
        }        
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_CONFIGDEROTATOR,
                                                e.what());
#endif
    }    
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_STOP
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_Stop(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_FREEZED;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_STOP,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_STOP);
#endif       
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SPEEDCORRECT
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SpeedCorrect(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_TRACKING;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SPEEDCORRECT,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_SPEEDCORRECT);
#endif      
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_PARK
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_Park(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_PARKED;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_PARK,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_PARK);
#endif       
    }
    return false; 
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_FIXEDMOVE
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_FixedMove(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_MOVING;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FIXEDMOVE,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FIXEDMOVE);
#endif        
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_POSITIONCORRECT
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_PositionCorrect(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_TRACKING;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_POSITIONCORRECT,
                                                e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_POSITIONCORRECT);
#endif        
    }
    return false;
}


/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_COVERACTION
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_CoverAction(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsgimbalstatus> temp = std::dynamic_pointer_cast<atccsgimbalstatus>(_realtimeStatus);
        if(temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_COVERACTION);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_COVERACTION)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_COVERACTION);
#endif                
                return false;
            }
            _AT_GIMBAL_PARAM_COVERACTION *param = (_AT_GIMBAL_PARAM_COVERACTION*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->coverIndex() == param->action;
        }
        else
        {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_COVERACTION);
#endif 
        }            
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_COVERACTION,
                                                e.what());
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_FOCUSACTION
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_FocusAction(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsgimbalstatus> temp = std::dynamic_pointer_cast<atccsgimbalstatus>(_realtimeStatus);
        if(temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FOCUSACTION);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_FOCUSACTION)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FOCUSACTION);
#endif                
                return false;
            }
            _AT_GIMBAL_PARAM_FOCUSACTION *param = (_AT_GIMBAL_PARAM_FOCUSACTION*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->focusTypeIndex() == param->action;
        }
        else
        {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FOCUSACTION);
#endif
        }            
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_FOCUSACTION,
                                                e.what());
#endif
    }
    return false;
}
/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_EMERGENCE
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_Emergence(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if(_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _GIMBAL_STATUS_EMERGENCY;
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _GIMBAL_INSTRUCTION_EMERGENCYSTOP,
                                                e.what());
#endif        
        }    
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                            gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _GIMBAL_INSTRUCTION_EMERGENCYSTOP);
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_CONFIGPROPERTY
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_ConfigProperty(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    return true;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SAVESYNCDATA
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SaveSyncData(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    return true;

}







