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
#include "at60gimbalstatus.h"
#include "at60gimbalstatus-odb.hxx"
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
#include "at60instruction.h"
#include "ORMHelper.h"
#include <memory>
#include <stdbool.h>

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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif  
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
    return false;
}


/**
 * query the AT's Gimbal's executory instruction's result,
 * and judge the progress it has executed.
 * @return true if has done, false if in progress.
 */
bool ATCCSGimbalController::isExecutoryInstructionOK()
{
    bool ret = false;
    if (_executoryInstruction)
    {
        switch (_executoryInstruction->instruction())
        {
            case _GIMBAL_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect();
                break;
            }
            case _GIMBAL_INSTRUCTION_FINDHOME:
            {
                ret = checkResult_FindHome();
                break;
            }
            case _GIMBAL_INSTRUCTION_TRACKSTAR:
            {
                ret = checkResult_TrackStar();
                break;
            }
            case _GIMBAL_INSTRUCTION_SETOBJECTNAME:
            {
                ret = checkResult_SetObjectName();
                break;
            }
            case _GIMBAL_INSTRUCTION_SLEWAZEL:
            {
                ret = checkResult_SlewAzEl();
                break;
            }
            case _GIMBAL_INSTRUCTION_SLEWDEROTATOR:
            {
                ret = checkResult_SlewDerotator();
                break;
            }
            case _GIMBAL_INSTRUCTION_CONFIGDEROTATOR:
            {
                ret = checkResult_ConfigDerotator();
                break;
            }
            case _GIMBAL_INSTRUCTION_STOP:
            {
                ret = checkResult_Stop();
                break;
            }
            case _GIMBAL_INSTRUCTION_SPEEDCORRECT:
            {
                ret = checkResult_SpeedCorrect();
                break;
            }
            case _GIMBAL_INSTRUCTION_PARK:
            {
                ret = checkResult_Park();
                break;
            }
            case _GIMBAL_INSTRUCTION_FIXEDMOVE:
            {
                ret = checkResult_FixedMove();
                break;
            }
            case _GIMBAL_INSTRUCTION_POSITIONCORRECT:
            {
                ret = checkResult_PositionCorrect();
                break;
            }
            case _GIMBAL_INSTRUCTION_COVERACTION:
            {
                ret = checkResult_CoverAction();
                break;
            }
            case _GIMBAL_INSTRUCTION_FOCUSACTION:
            {
                ret = checkResult_FocusAction();
                break;
            }
            case _GIMBAL_INSTRUCTION_EMERGENCYSTOP:
            {
                ret = checkResult_Emergence();
                break;
            }
            default:
                break;
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif        
    }
    return ret;
}

bool ATCCSGimbalController::isExecutoryInstructionOK(unsigned int instruction)
{
    if(_executoryInstruction)
    {
        if(_executoryInstruction->instruction() == instruction)
            return isExecutoryInstructionOK();
        return false;
    }
    else
    {
        return false;
    }
}


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
bool ATCCSGimbalController::checkResult_Connect()
{
    if (_realtimeStatus)
    {
        if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
            return false;
        if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_CONNECT)))
            return false;
        _AT_GIMBAL_PARAM_CONNECT *param = (_AT_GIMBAL_PARAM_CONNECT*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, 
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_FINDHOME
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_FindHome()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_TRACKSTAR
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_TrackStar()
{
    try
    {
        std::shared_ptr<at60gimbalstatus> temp = std::dynamic_pointer_cast<at60gimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_TRACKSTAR)))
                return false;
            _AT_GIMBAL_PARAM_TRACKSTAR *param = (_AT_GIMBAL_PARAM_TRACKSTAR*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            std::cout << param->rightAscension <<"---" << temp->targetJ2000RightAscension() << std::endl;
            std::cout << param->declination << "---" << temp->targetJ2000Declination() << std::endl;
            return (temp->curstatus() == _GIMBAL_STATUS_TRACKING)&&
                    (cmpDouble(param->rightAscension, temp->targetJ2000RightAscension(), 0.0001))&&
                    (cmpDouble(param->declination, temp->targetJ2000Declination(), 0.0001));
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
                
#endif
    }    
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SETOBJECTNAME
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SetObjectName()
{
    try
    {
        std::shared_ptr<at60gimbalstatus> temp = std::dynamic_pointer_cast<at60gimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_SETOBJECTNAME)))
                return false;
            _AT_GIMBAL_PARAM_SETOBJECTNAME *param = (_AT_GIMBAL_PARAM_SETOBJECTNAME*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            std::string tempObjectName(param->objectName);
            std::cout << tempObjectName << "--" << temp->trackObjectName() << "--" << temp->trackType() << "-" << param->objectType << std::endl;
            return (temp->trackType() == param->objectType)&&
                    (temp->trackObjectName() == tempObjectName);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, 
                                                "Gimbal has no real-time status instance. Can not check the instruction's result, may be the device doesn't report any real-time status.");
#endif
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
                
#endif        
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SLEWAZEL
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SlewAzEl()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SLEWDEORTATOR
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SlewDerotator()
{
    try
    {
        std::shared_ptr<at60gimbalstatus> temp = std::dynamic_pointer_cast<at60gimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_SLEWDEROTATOR)))
                return false;
            _AT_GIMBAL_PARAM_SLEWDEROTATOR *param = (_AT_GIMBAL_PARAM_SLEWDEROTATOR*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return cmpDouble(param->position, temp->axis3Encoder(), 1 / 360);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());                
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_CONFIGDEORTATOR
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_ConfigDerotator()
{
    try
    {
        std::shared_ptr<at60gimbalstatus> temp = std::dynamic_pointer_cast<at60gimbalstatus>(_realtimeStatus);
        if (temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_CONFIGDEROTATOR)))
                return false;
            _AT_GIMBAL_PARAM_CONFIGDEROTATOR *param = (_AT_GIMBAL_PARAM_CONFIGDEROTATOR*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
           
            std::lock_guard<std::mutex> lk(_statusLock);
            return param->mode == temp->axis3Mode();
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }        
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }    
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_STOP
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_Stop()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif       
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SPEEDCORRECT
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SpeedCorrect()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif       
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_PARK
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_Park()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif       
    }
    return false; 
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_FIXEDMOVE
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_FixedMove()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif        
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_POSITIONCORRECT
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_PositionCorrect()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");
#endif        
    }
    return false;
}


/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_COVERACTION
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_CoverAction()
{
    try
    {
        std::shared_ptr<at60gimbalstatus> temp = std::dynamic_pointer_cast<at60gimbalstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_COVERACTION)))
                return false;
            _AT_GIMBAL_PARAM_COVERACTION *param = (_AT_GIMBAL_PARAM_COVERACTION*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->coverIndex() == param->action;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }            
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, 
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_FOCUSACTION
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_FocusAction()
{
    try
    {
        std::shared_ptr<at60gimbalstatus> temp = std::dynamic_pointer_cast<at60gimbalstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_GIMBAL_PARAM_FOCUSACTION)))
                return false;
            _AT_GIMBAL_PARAM_FOCUSACTION *param = (_AT_GIMBAL_PARAM_FOCUSACTION*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->focusTypeIndex() == param->action;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                                __FILE__, __func__, __LINE__, "");
#endif
        }            
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return false;
}
/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_EMERGENCE
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_Emergence()
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif        
        }    
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__, "");        
#endif
    }
    return false;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_CONFIGPROPERTY
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_ConfigProperty()
{
    return true;
}

/**
 * check the result of Gimbal's instruction: _GIMBAL_INSTRUCTION_SAVESYNCDATA
 * @return true if success, false if fails
 */
bool ATCCSGimbalController::checkResult_SaveSyncData()
{
    return true;

}







