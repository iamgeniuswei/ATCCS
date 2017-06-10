/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60CCDController.cpp
 * Author: lenovo
 * 
 * Created on May 14, 2017, 11:05 AM
 */

#include "atccsccdcontroller.h"
#include "atccsinstruction.h"
#include "atccsdata.h"
#include "atccs_ccd_define.h"
#include "at60instruction.h"
#include "atccspublicstatus.h"
#include "at60ccdstatus.h"
#include "atccsexceptionhandler.h"
ATCCSCCDController::ATCCSCCDController() 
    :ATCCSDeviceController(CCD)
{

}


ATCCSCCDController::~ATCCSCCDController() 
{
}

/**
 * query the concrete AT's CCD's real-time status, 
 * and judge whether it is normal. Generally speaking, 
 * that its error equals to _CCD_ERROR_NORMAL means that
 * status is normal.
 * @return true if ok, false if not.
 */
bool ATCCSCCDController::isStatusOK() const 
{
    if(_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->error() == _CCD_ERROR_NORMAL;
            
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
 * query the AT's CCD's executory instruction's result,
 * and judge the progress it has executed.
 * @return true if has done, false if in progress.
 */
bool ATCCSCCDController::isExecutoryInstructionOK() 
{
    bool ret = false;
    if(_executoryInstruction)
    {
        switch(_executoryInstruction->instruction())
        {
            case _CCD_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect();
                break;
            }
            case _CCD_INSTRUCTION_SETCOOLERT:
            {
                ret = checkResult_SetCoolerT();
                break;
            }
            case _CCD_INSTRUCTION_SETEXPOSURETACTIC:
            {
                ret = checkResult_SetExposureTactics();
                break;
            }
            case _CCD_INSTRUCTION_STARTEXPOSURE:
            {
                ret = checkResult_StartExposure();
                break;
            }
            case _CCD_INSTRUCTION_STOPEXPOSURE:
            {
                ret = checkResult_StopExposure();
                break;
            }
            case _CCD_INSTRUCTION_ABORTEXPOSURE:
            {
                ret = checkResult_AbortExposure();
                break;
            }
            case _CCD_INSTRUCTION_SETGAIN:
            {
                ret = checkResult_SetGain();
                break;
            }            
            case _CCD_INSTRUCTION_SETBIN:
            {
                ret = checkResult_SetBIN();
                break;
            }
            case _CCD_INSTRUCTION_SETRSMODE:
            {
                ret = checkResult_SetReadSpeedMode();
                break;
            }
            case _CCD_INSTRUCTION_SETTSMODE:
            {
                ret = checkResult_SetTransferSpeed();
                break;
            }
            case _CCD_INSTRUCTION_SETROI:
            {
                ret = checkResult_SetROI();
                break;
            }
            case _CCD_INSTRUCTION_SETSHUTTER:
            {
                ret = checkResult_SetShutter();
                break;
            }
            case _CCD_INSTRUCTION_SETFULLFRAME:
            {
                ret = checkResult_SetFullFrame();
                break;
            }
            case _CCD_INSTRUCTION_SETEM:
            {
                ret = checkResult_SetEM();
                break;
            }
            case _CCD_INSTRUCTION_SETNOISEFILTER:
            {
                ret = checkResult_SetCMOSNF();
                break;
            }
            case _CCD_INSTRUCTION_SETBASELINE:
            {
                ret = checkResult_SetBaseline();
                break;
            }
            case _CCD_INSTRUCTION_SETOVERSCAN:
            {
                ret = checkResult_SetOverScan();
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

bool ATCCSCCDController::canExecutePlan() 
{
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        if(_realtimeStatus)
        {
            unsigned int temp = _realtimeStatus->curstatus();
            return _realtimeStatus->error() == _CCD_ERROR_NORMAL && 
                    temp != _CCD_STATUS_DISCONNECT &&
                    temp != _CCD_STATUS_CONNECTING &&
                    temp != _CCD_STATUS_DISCONNECTING;
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        std::cerr << "error#"<< ERROR_STDEXCEPTRION << ": Device "<< id() << " " << e.what()
                << " @" << __func__
                << " @" << __FILE__
                << " @" << __LINE__ << std::endl;
#endif
    }
    return false;
}


/**
 * check the result of Gimbal's instruction: _CCD_INSTRUCTION_CONNECT
 * @return true if success, false if fails. 
 */
bool ATCCSCCDController::checkResult_Connect() 
{
    if (_realtimeStatus)
    {
        if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
            return false;
        if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_CONNECT)))
            return false;
        _AT_CCD_PARAM_CONNECT *param = (_AT_CCD_PARAM_CONNECT*) (_executoryInstructionRawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            unsigned int curStatus = _realtimeStatus->curstatus();
            if (param->connect == CONNECT)
            {
                return (curStatus != _CCD_STATUS_DISCONNECT)&&
                        (curStatus != _CCD_STATUS_CONNECTING)&&
                        (curStatus != _CCD_STATUS_DISCONNECTING);
            }
            else if (param->connect == DISCONNECT)
            {
                return curStatus == _CCD_STATUS_DISCONNECT;
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

bool ATCCSCCDController::checkResult_SetCoolerT() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETCOOLERT)))
                return false;
            _AT_CCD_PARAM_SETCOOLERT *param = (_AT_CCD_PARAM_SETCOOLERT*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);
            std::cout << param->temperature << "--" << temp->coolerT() << std::endl;
            return ((temp->warning() == _CCD_WARN_NORMAL) && (cmpDouble(temp->coolerT(), param->temperature, 5)));
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

bool ATCCSCCDController::checkResult_SetExposureTactics() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETEXPOSURETACTIC)))
                return false;
            _AT_CCD_PARAM_SETEXPOSURETACTIC *param = (_AT_CCD_PARAM_SETEXPOSURETACTIC*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));
            
            std::lock_guard<std::mutex> lk(_statusLock);            
            std::string name = std::string(param->objectName);
            std::string band = std::string(param->objectBand);
            std::cout << temp->curstatus() << "-" << _CCD_STATUS_WAITINGEXPOSURE << std::endl;
            std::cout << temp->epoch() << "-" << param->objectEpoch << std::endl;
            std::cout << temp->observeType() << "-" << param->objectType << std::endl;
            std::cout << temp->observeName() << "-" << name << std::endl;
            std::cout << temp->band() << "-" << band << std::endl;
            std::cout << temp->J2000RightAscension() << "-" << param->objectRightAscension << std::endl;
            std::cout << temp->J2000Declination() << "-" << param->objectDeclination << std::endl;
            
            return (temp->curstatus() == _CCD_STATUS_WAITINGEXPOSURE)&&
                    (temp->epoch() == param->objectEpoch) &&
                    (temp->observeType() == param->objectType) &&
                    (temp->observeName() == name) &&
                    (temp->band() == band)&&
                    (cmpDouble(temp->J2000RightAscension(), param->objectRightAscension, 0.0001))&&
                    (cmpDouble(temp->J2000Declination(), param->objectDeclination, 0.0001));
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

bool ATCCSCCDController::checkResult_StartExposure() 
{
    if(_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            std::cout << _realtimeStatus ->laststatus() << "--" << _realtimeStatus->curstatus() << std::endl;
            return (_realtimeStatus->laststatus() == _CCD_STATUS_SAVING)&&
                    (_realtimeStatus->curstatus() == _CCD_STATUS_IDLE);
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

bool ATCCSCCDController::checkResult_StopExposure() 
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _CCD_STATUS_IDLE &&
                    _realtimeStatus->laststatus() == _CCD_STATUS_ABORTING;
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

bool ATCCSCCDController::checkResult_AbortExposure() 
{
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->curstatus() == _CCD_STATUS_ABORTING;
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

bool ATCCSCCDController::checkResult_SetGain() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETGAIN)))
                return false;
            _AT_CCD_PARAM_SETGAIN *param = (_AT_CCD_PARAM_SETGAIN*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->indexOfGain() == param->gear && temp->indexOfGainMode() == param->mode);
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

bool ATCCSCCDController::checkResult_SetReadSpeedMode() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETRSMODE)))
                return false;
            _AT_CCD_PARAM_SETRSMODE *param = (_AT_CCD_PARAM_SETRSMODE*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->indexOfRSMode() == param->mode;
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

bool ATCCSCCDController::checkResult_SetBIN() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETBIN)))
                return false;
            _AT_CCD_PARAM_SETBIN *param = (_AT_CCD_PARAM_SETBIN*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->binX() == param->binX) && (temp->binY() == param->binY);
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

bool ATCCSCCDController::checkResult_SetBaseline() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETBASELINE)))
                return false;
            _AT_CCD_PARAM_SETBASELINE *param = (_AT_CCD_PARAM_SETBASELINE*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->isBaseline() == param->isBaseline) && (temp->baseline() == param->baseline);
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

bool ATCCSCCDController::checkResult_SetCMOSNF() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETNOISEFILTER)))
                return false;
            _AT_CCD_PARAM_SETNOISEFILTER *param = (_AT_CCD_PARAM_SETNOISEFILTER*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->isNoiseFilter() == param->isNoiseFilter;
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

bool ATCCSCCDController::checkResult_SetEM() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETEM)))
                return false;
            _AT_CCD_PARAM_SETEM *param = (_AT_CCD_PARAM_SETEM*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->isEM() == param->isEM) && (temp->EM() == param->EM);
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

bool ATCCSCCDController::checkResult_SetFullFrame() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETFULLFRAME)))
                return false;
            _AT_CCD_PARAM_SETFULLFRAME *param = (_AT_CCD_PARAM_SETFULLFRAME*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->isFullFrame() == param->fullFrame;
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

bool ATCCSCCDController::checkResult_SetOverScan() 
{
    return true;
}

bool ATCCSCCDController::checkResult_SetROI() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETROI)))
                return false;
            _AT_CCD_PARAM_SETROI *param = (_AT_CCD_PARAM_SETROI*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->startX() == param->startX) &&
                        (temp->startY() == param->startY) &&
                        (temp->imageHeight() == param->imageHeight) &&
                        (temp->imageWidth() == param->imageWidth);
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

bool ATCCSCCDController::checkResult_SetShutter() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETSHUTTER)))
                return false;
            _AT_CCD_PARAM_SETSHUTTER *param = (_AT_CCD_PARAM_SETSHUTTER*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->shutterMode() == param->shutter;
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

bool ATCCSCCDController::checkResult_SetTransferSpeed() 
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if(temp)
        {
            if (_executoryInstructionRawData == nullptr || !(_executoryInstructionRawData->validate()))
                return false;
            if (_executoryInstructionRawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETTSMODE)))
                return false;
            _AT_CCD_PARAM_SETTSMODE *param = (_AT_CCD_PARAM_SETTSMODE*)(_executoryInstructionRawData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER));    
            
            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->indexOfTSMode() == param->mode;
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








