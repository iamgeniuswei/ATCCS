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
#include "atccspublicstatus.h"
#include "atccsexceptionhandler.h"
#include "atccsccdstatus.h"

ATCCSCCDController::ATCCSCCDController(unsigned short at, unsigned short device)
: ATCCSDeviceController(at, device)
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
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
            return _realtimeStatus->error() == _CCD_ERROR_NORMAL;

        }
        catch (std::exception &e)
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

bool ATCCSCCDController::isInstructionSuccess(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    bool ret = false;
    if (_planInstruction)
    {
        switch (_planInstruction->instruction())
        {
            case _CCD_INSTRUCTION_CONNECT:
            {
                ret = checkResult_Connect(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETCOOLERT:
            {
                ret = checkResult_SetCoolerT(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETEXPOSURETACTIC:
            {
                ret = checkResult_SetExposureTactics(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_STARTEXPOSURE:
            {
                ret = checkResult_StartExposure(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_STOPEXPOSURE:
            {
                ret = checkResult_StopExposure(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_ABORTEXPOSURE:
            {
                ret = checkResult_AbortExposure(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETGAIN:
            {
                ret = checkResult_SetGain(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETBIN:
            {
                ret = checkResult_SetBIN(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETRSMODE:
            {
                ret = checkResult_SetReadSpeedMode(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETTSMODE:
            {
                ret = checkResult_SetTransferSpeed(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETROI:
            {
                ret = checkResult_SetROI(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETSHUTTER:
            {
                ret = checkResult_SetShutter(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETFULLFRAME:
            {
                ret = checkResult_SetFullFrame(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETEM:
            {
                ret = checkResult_SetEM(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETNOISEFILTER:
            {
                ret = checkResult_SetCMOSNF(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETBASELINE:
            {
                ret = checkResult_SetBaseline(instruction, rawData);
                break;
            }
            case _CCD_INSTRUCTION_SETOVERSCAN:
            {
                ret = checkResult_SetOverScan(instruction, rawData);
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


/**
 * query the AT's CCD's executory instruction's result,
 * and judge the progress it has executed.
 * @return true if has done, false if in progress.
 */
//bool ATCCSCCDController::isExecutoryInstructionOK()
//{
//    bool ret = false;
//    if (_executoryInstruction)
//    {
//        switch (_executoryInstruction->instruction())
//        {
//            case _CCD_INSTRUCTION_CONNECT:
//            {
//                ret = checkResult_Connect();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETCOOLERT:
//            {
//                ret = checkResult_SetCoolerT();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETEXPOSURETACTIC:
//            {
//                ret = checkResult_SetExposureTactics();
//                break;
//            }
//            case _CCD_INSTRUCTION_STARTEXPOSURE:
//            {
//                ret = checkResult_StartExposure();
//                break;
//            }
//            case _CCD_INSTRUCTION_STOPEXPOSURE:
//            {
//                ret = checkResult_StopExposure();
//                break;
//            }
//            case _CCD_INSTRUCTION_ABORTEXPOSURE:
//            {
//                ret = checkResult_AbortExposure();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETGAIN:
//            {
//                ret = checkResult_SetGain();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETBIN:
//            {
//                ret = checkResult_SetBIN();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETRSMODE:
//            {
//                ret = checkResult_SetReadSpeedMode();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETTSMODE:
//            {
//                ret = checkResult_SetTransferSpeed();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETROI:
//            {
//                ret = checkResult_SetROI();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETSHUTTER:
//            {
//                ret = checkResult_SetShutter();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETFULLFRAME:
//            {
//                ret = checkResult_SetFullFrame();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETEM:
//            {
//                ret = checkResult_SetEM();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETNOISEFILTER:
//            {
//                ret = checkResult_SetCMOSNF();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETBASELINE:
//            {
//                ret = checkResult_SetBaseline();
//                break;
//            }
//            case _CCD_INSTRUCTION_SETOVERSCAN:
//            {
//                ret = checkResult_SetOverScan();
//                break;
//            }
//            default:
//                break;
//        }
//    }
//    else
//    {
//#ifdef OUTERRORINFO
//        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d",
//                                            gettext("The instruction is fail to be created, fails to check instruction's result: AT: "), _at,
//                                            gettext(" Device: "), _device);
//#endif        
//    }
//    return ret;
//}

bool ATCCSCCDController::canExecutePlan()
{
    try
    {
        std::lock_guard<std::mutex> lk(_statusLock);
        if (_realtimeStatus)
        {
            unsigned int temp = _realtimeStatus->curstatus();
            return _realtimeStatus->error() == _CCD_ERROR_NORMAL &&
                    temp != _CCD_STATUS_DISCONNECT &&
                    temp != _CCD_STATUS_CONNECTING &&
                    temp != _CCD_STATUS_DISCONNECTING;
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
 * check the result of Gimbal's instruction: _CCD_INSTRUCTION_CONNECT
 * @return true if success, false if fails. 
 */
bool ATCCSCCDController::checkResult_Connect(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if(instruction == nullptr || rawData == nullptr)
        return false;
    
    if (_realtimeStatus)
    {
        if (!(rawData->validate()))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_CONNECT);
#endif            
            return false;
        }
        if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_CONNECT)))
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_CONNECT);
#endif            
            return false;
        }
        _AT_CCD_PARAM_CONNECT *param = (_AT_CCD_PARAM_CONNECT*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_CONNECT,
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
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_CONNECT);
#endif
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetCoolerT(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if(instruction == nullptr || rawData == nullptr)
        return false;
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (!(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETCOOLERT);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETCOOLERT)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETCOOLERT);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETCOOLERT *param = (_AT_CCD_PARAM_SETCOOLERT*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return ((temp->warning() == _CCD_WARN_NORMAL) && (cmpDouble(temp->coolerT(), param->temperature, 5)));
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETCOOLERT);
#endif
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETCOOLERT,
                                            e.what());
#endif
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetExposureTactics(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    if(instruction == nullptr || rawData == nullptr)
        return false;
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETEXPOSURETACTIC)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif                 
                return false;
            }
            _AT_CCD_PARAM_SETEXPOSURETACTIC *param = (_AT_CCD_PARAM_SETEXPOSURETACTIC*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            std::string name = std::string(param->objectName);
            std::string band = std::string(param->objectBand);
//            std::cout << temp->curstatus() << "-" << _CCD_STATUS_WAITINGEXPOSURE << std::endl;
//            std::cout << temp->epoch() << "-" << param->objectEpoch << std::endl;
//            std::cout << temp->observeType() << "-" << param->objectType << std::endl;
//            std::cout << temp->observeName() << "-" << name << std::endl;
//            std::cout << temp->band() << "-" << band << std::endl;
//            std::cout << temp->J2000RightAscension() << "-" << param->objectRightAscension << std::endl;
//            std::cout << temp->J2000Declination() << "-" << param->objectDeclination << std::endl;

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
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
#endif
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETEXPOSURETACTIC,
                                            e.what());
#endif
    }
    return false;
}

bool ATCCSCCDController::checkResult_StartExposure(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    
    if (_realtimeStatus)
    {
        try
        {
            std::lock_guard<std::mutex> lk(_statusLock);
//            std::cout << _realtimeStatus ->laststatus() << "--" << _realtimeStatus->curstatus() << std::endl;
            return (_realtimeStatus->laststatus() == _CCD_STATUS_SAVING)&&
                    (_realtimeStatus->curstatus() == _CCD_STATUS_IDLE);
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_STARTEXPOSURE,
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
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_STARTEXPOSURE);
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_StopExposure(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_STOPEXPOSURE,
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
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_STOPEXPOSURE);
#endif
    }
    return false;
}

bool ATCCSCCDController::checkResult_AbortExposure(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                                gettext("Fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_ABORTEXPOSURE,
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
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_ABORTEXPOSURE);
#endif
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetGain(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETGAIN)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETGAIN *param = (_AT_CCD_PARAM_SETGAIN*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
//            std::cout << temp->indexOfGain() << "--" << param->gear << std::endl;
//            std::cout << temp->indexOfGainMode() << "--" << param->mode << std::endl;
            return (temp->indexOfGain() == param->gear && temp->indexOfGainMode() == param->mode);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETGAIN,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetReadSpeedMode(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETRSMODE)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETRSMODE *param = (_AT_CCD_PARAM_SETRSMODE*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
//            std::cout << temp->indexOfRSMode() << "--" << param->mode << std::endl;
            return temp->indexOfRSMode() == param->mode;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETRSMODE,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetBIN(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETBIN)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETBIN *param = (_AT_CCD_PARAM_SETBIN*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
//            std::cout << temp->binX() << "--" << param->binX << std::endl;
//            std::cout << temp->binY() << "--" << param->binY << std::endl;
            return (temp->binX() == param->binX) && (temp->binY() == param->binY);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETBIN,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetBaseline(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETBASELINE);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETBASELINE)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETBASELINE);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETBASELINE *param = (_AT_CCD_PARAM_SETBASELINE*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->isBaseline() == param->isBaseline) && (temp->baseline() == param->baseline);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETBASELINE);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETBASELINE,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetCMOSNF(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETNOISEFILTER);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETNOISEFILTER)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETNOISEFILTER);
#endif                 
                return false;
            }
            _AT_CCD_PARAM_SETNOISEFILTER *param = (_AT_CCD_PARAM_SETNOISEFILTER*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->isNoiseFilter() == param->isNoiseFilter;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETNOISEFILTER);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETNOISEFILTER,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetEM(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETEM);
#endif                 
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETEM)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETEM);
#endif
                return false;
            }
            _AT_CCD_PARAM_SETEM *param = (_AT_CCD_PARAM_SETEM*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->isEM() == param->isEM) && (temp->EM() == param->EM);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETEM);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETEM,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetFullFrame(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETFULLFRAME);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETFULLFRAME)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETFULLFRAME);
#endif 
                return false;
            }
            _AT_CCD_PARAM_SETFULLFRAME *param = (_AT_CCD_PARAM_SETFULLFRAME*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->isFullFrame() == param->fullFrame;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETFULLFRAME);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETFULLFRAME,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetOverScan(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    return true;
}

bool ATCCSCCDController::checkResult_SetROI(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETROI);
#endif                 
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETROI)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETROI);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETROI *param = (_AT_CCD_PARAM_SETROI*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return (temp->startX() == param->startX) &&
                    (temp->startY() == param->startY) &&
                    (temp->imageHeight() == param->imageHeight) &&
                    (temp->imageWidth() == param->imageWidth);
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETROI);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETROI,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetShutter(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETSHUTTER);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETSHUTTER)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETSHUTTER);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETSHUTTER *param = (_AT_CCD_PARAM_SETSHUTTER*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->shutterMode() == param->shutter;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETSHUTTER);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETSHUTTER,
                                            e.what());
#endif        
    }
    return false;
}

bool ATCCSCCDController::checkResult_SetTransferSpeed(std::shared_ptr<atccsinstruction> instruction, std::shared_ptr<ATCCSData> rawData)
{
    try
    {
        std::shared_ptr<atccsccdstatus> temp = std::dynamic_pointer_cast<atccsccdstatus>(_realtimeStatus);
        if (temp)
        {
            if (rawData == nullptr || !(rawData->validate()))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETTSMODE);
#endif                
                return false;
            }
            if (rawData->size() != (sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER) + sizeof (_AT_CCD_PARAM_SETTSMODE)))
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%d%s%d%s%d",
                                                    gettext("The Instruction's raw data is error, fails to check instruction's result: AT: "), _at,
                                                    gettext(" Device: "), _device,
                                                    gettext(" Instruction: "), _CCD_INSTRUCTION_SETTSMODE);
#endif                
                return false;
            }
            _AT_CCD_PARAM_SETTSMODE *param = (_AT_CCD_PARAM_SETTSMODE*) (rawData->data() + sizeof (_ATCCSPHeader) + sizeof (_AT_INSTRUCTION_HEADER));

            std::lock_guard<std::mutex> lk(_statusLock);
            return temp->indexOfTSMode() == param->mode;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s%d%s%d%s%d",
                                                gettext("The status is fail to be created, fails to check instruction's result: AT: "), _at,
                                                gettext(" Device: "), _device,
                                                gettext(" Instruction: "), _CCD_INSTRUCTION_SETTSMODE);
#endif            
        }
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%d%s%d%s%d%s",
                                            gettext("Fails to check instruction's result: AT: "), _at,
                                            gettext(" Device: "), _device,
                                            gettext(" Instruction: "), _CCD_INSTRUCTION_SETTSMODE,
                                            e.what());
#endif        
    }
    return false;
}








