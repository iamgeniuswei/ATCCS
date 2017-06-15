#include "atccsinstruction.h"
#include "atccsdata.h"
#include <iostream>
#include "atccs_public_define.h"
#include "atccs_gimbal_define.h"
#include "atccs_ccd_define.h"
#include "atccs_filter_define.h"
#include "atccs_focus_define.h"
#include "atccs_dome_define.h"
#include "atccs_global.h"
atccsinstruction::atccsinstruction()
{

}

atccsinstruction::~atccsinstruction()
{
    std::cout << "~ATCCSInstruction" << std::endl;
}

unsigned int atccsinstruction::validateParam(unsigned int device, unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    switch (device) 
    {
        case GIMBAL:
        {
            ret = validateGimbalParam(instruction, data);
            break;
        }

        case CCD:
        {
            ret = validateCCDParam(instruction, data);
            break;
        }

        case FILTER:
        {
            ret = validateFilterParam(instruction, data);
            break;
        }

        case FOCUS:
        {
            ret = validateFocusParam(instruction, data);
            break;
        }
        case SLAVEDOME:
        {
            ret = validateSlaveDomeParam(instruction, data);
            break;
        }
        case FULLOPENEDDOME:
        {
            ret = validateFullOpenedDomeParam(instruction, data);
            break;
        }
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;
        }
    } 

    return ret;
}

unsigned int  atccsinstruction::validateGimbalParam(unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    switch(instruction)
    {
        case _GIMBAL_INSTRUCTION_CONNECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_CONNECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        
        case _GIMBAL_INSTRUCTION_FINDHOME:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_FINDHOME)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        
        case _GIMBAL_INSTRUCTION_TRACKSTAR:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_TRACKSTAR)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_SETOBJECTNAME:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_SETOBJECTNAME)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_SLEWAZEL:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_SLEWAZEL)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_SLEWDEROTATOR:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_SLEWDEROTATOR)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_CONFIGDEROTATOR:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_CONFIGDEROTATOR)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_PARK:
        case _GIMBAL_INSTRUCTION_STOP:
        case _GIMBAL_INSTRUCTION_EMERGENCYSTOP:
        case _GIMBAL_INSTRUCTION_SAVESYNCDATA:
        case _GIMBAL_INSTRUCTION_CONFIGPROPERTIES:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_SPEEDCORRECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_SPEEDCORRECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        
        case _GIMBAL_INSTRUCTION_FIXEDMOVE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_FIXEDMOVE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }        

        case _GIMBAL_INSTRUCTION_POSITIONCORRECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_POSITIONCORRECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_COVERACTION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_COVERACTION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _GIMBAL_INSTRUCTION_FOCUSACTION:
        {            
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_GIMBAL_PARAM_FOCUSACTION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        
        case _GIMBAL_INSTRUCTION_TRACKSATELLITE:
        {
            break;
        }
        
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;
        }
    }
    
    return ret;
}

unsigned int atccsinstruction::validateCCDParam(unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    
    switch(instruction)
    {
        case _CCD_INSTRUCTION_CONNECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_CONNECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETCOOLERT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETCOOLERT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETEXPOSURETACTIC:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETEXPOSURETACTIC)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_STARTEXPOSURE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_STARTEXPOSURE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_STOPEXPOSURE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_ABORTEXPOSURE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }    
        case _CCD_INSTRUCTION_SETGAIN:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETGAIN)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETRSMODE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETRSMODE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETTSMODE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETTSMODE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETBIN:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETBIN)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETROI:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETROI)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETSHUTTER:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETSHUTTER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }            
        case _CCD_INSTRUCTION_SETFULLFRAME:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETFULLFRAME)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETEM:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETEM)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETBASELINE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETBASELINE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETNOISEFILTER:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETNOISEFILTER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _CCD_INSTRUCTION_SETOVERSCAN:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_CCD_PARAM_SETOVERSCAN)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;
        }
    }
    
    return ret;
}

unsigned int atccsinstruction::validateFilterParam(unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    switch(instruction)
    {
        case _FILTER_INSTRUCTION_CONNECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FILTER_PARAM_CONNECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FILTER_INSTRUCTION_SETPOSITION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FILTER_PARAM_SETPOSITION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FILTER_INSTRUCTION_FINDHOME:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;
        }       
    }
    return ret;
}

unsigned int atccsinstruction::validateFocusParam(unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    
    switch (instruction)
    {
        case _FOCUS_INSTRUCTION_CONNECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FOCUS_PARAM_CONNECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FOCUS_INSTRUCTION_SETPOSITION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FOCUS_PARAM_SETPOSITION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FOCUS_INSTRUCTION_SETFIXEDSPEED:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FOCUS_PARAM_SETFIXEDSPEED)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        
        case _FOCUS_INSTRUCTION_STOP:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FOCUS_INSTRUCTION_FINDHOME:           
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FOCUS_INSTRUCTION_ENABLETCOMPENSATE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FOCUS_PARAM_ENABLETCOMPENSATE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }        
        case _FOCUS_INSTRUCTION_SETTCOMPENSATE:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FOCUS_PARAM_SETTCOMPENSATE)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;
        }
    }
    
    return ret;
}

unsigned int atccsinstruction::validateSlaveDomeParam(unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    
    switch(instruction)
    {
        case _SLAVEDOME_INSTRUCTION_CONNECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_SLAVEDOME_PARAM_CONNECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _SLAVEDOME_INSTRUCTION_SETDOMEPOSITION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_SLAVEDOME_PARAM_SETDOMEPOSITION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _SLAVEDOME_INSTRUCTION_SETSHADEPOSITION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_SLAVEDOME_PARAM_SETSHADEPOSITION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _SLAVEDOME_INSTRUCTION_SETROTATESPEED:            
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_SLAVEDOME_PARAM_SETROTATESPEED)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _SLAVEDOME_INSTRUCTION_STOP:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _SLAVEDOME_INSTRUCTION_SCUTTLEACTION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_SLAVEDOME_PARAM_SHUTTERACTION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _SLAVEDOME_INSTRUCTION_SHADEACTION:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_SLAVEDOME_PARAM_SHADEACTION)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;
        }
    }
    
    return ret;
}

unsigned int atccsinstruction::validateFullOpenedDomeParam(unsigned int instruction, std::shared_ptr<ATCCSData> data) 
{
    unsigned int ret = INSTRUCTION_PASS;
    
    switch(instruction)
    {
        case _FULLOPENEDDOME_INSTRUCTION_CONNECT:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FULLOPENEDDOME_PARAM_CONNECT)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        case _FULLOPENEDDOME_INSTRUCTION_OPENDOME:
        {
            if(data)
            {
                if(data->size() != (sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER)+sizeof(_AT_FULLOPENEDDOME_PARAM_OPENDOME)))
                    ret = INSTRUCTION_SIZEERROR;
            }
            break;
        }
        default:
        {
            ret = INSTRUCTION_UNKOWNN;
            break;            
        }
    }
    
    return ret;
}

unsigned int atccsinstruction::setInstructionValue(std::shared_ptr<ATCCSData> data)
{
    //Level 1 validation.
    if(data == nullptr)
        return INSTRUCTION_NULL;
    if(!data->validate())
        return INSTRUCTION_SIZEERROR;
    if(data->size() < (sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER)))
        return INSTRUCTION_SIZEERROR;
    
    //Level 2 validation.
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    _AT_INSTRUCTION_HEADER *instruction = (_AT_INSTRUCTION_HEADER*)(data->data()+sizeof(_ATCCSPHeader));
    unsigned int ret = validateParam(instruction->device, instruction->instruction, data);
    if(ret != INSTRUCTION_PASS && ret != INSTRUCTION_PARAMOUTOFRANGE)
        return ret;
    
    //resolve ATCCSData to set atccsinstruction.
    if(header)
    {
        _sec = header->tv_sec;
        _msec = header->tv_usec;
    }
    
    if(instruction)
    {
        _user = instruction->user;
        _at = instruction->at;
        _device = instruction->device;
        _sequence = instruction->sequence;
        _plan = instruction->plan;
        _timeout = 30;
        _instruction = instruction->instruction;
        if(ret == INSTRUCTION_PASS)
            _result = RESULT_WAITINGTOEXECUTE;
        else
            _result = RESULT_PARAMOUTOFRANGE;                
    }
    return ret;
}

unsigned int atccsinstruction::setInstructionResult(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr)
        return RESULT_SIZEERROR;
    if(!data->validate())
        return RESULT_SIZEERROR;
    if(data->size() != (sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_RESULT)))
        return RESULT_SIZEERROR;
    _AT_INSTRUCTION_RESULT *result = (_AT_INSTRUCTION_RESULT*)(data->data() + sizeof(_ATCCSPHeader));
    if(result->user == _user &&
            result->plan == _plan &&
            result->at == _at &&
            result->device == _device &&
            result->sequence == _sequence &&
            result->instruction == _instruction)
    {
        _timeout = result->timeout;
        _result = result->result;
        return RESULT_EXECUTING;
    }
    else
    {
        return RESULT_WAITINGTOEXECUTE;
    }

}

void atccsinstruction::reset()
{
    _id = _sec = _msec = _user = _at = _device = _sequence = _timeout = _plan = _instruction = _result = 0;
}


unsigned int atccsinstruction::sec() const
{
    return _sec;
}

void atccsinstruction::setSec(const unsigned int sec)
{
    _sec = sec;
}

unsigned int atccsinstruction::msec() const
{
    return _msec;
}

void atccsinstruction::setMsec(const unsigned int msec)
{
    _msec = msec;
}

unsigned int atccsinstruction::user() const
{
    return _user;
}

void atccsinstruction::setUser(const unsigned int user)
{
    _user = user;
}

unsigned short atccsinstruction::device() const
{
    return _device;
}

void atccsinstruction::setDevice(const unsigned short device)
{
    _device = device;
}

unsigned int atccsinstruction::sequence() const
{
    return _sequence;
}

void atccsinstruction::setSequence(const unsigned int sequence)
{
    _sequence = sequence;
}

unsigned int atccsinstruction::plan() const
{
    return _plan;
}

void atccsinstruction::setPlan(const unsigned int plan)
{
    _plan = plan;
}

unsigned int atccsinstruction::instruction() const
{
    return _instruction;
}

std::string atccsinstruction::param() const
{
    return _param;
}

void atccsinstruction::setParam(const std::string &param)
{
    _param = param;
}

unsigned int atccsinstruction::result() const
{
    return _result;
}

void atccsinstruction::setResult(const unsigned int result)
{
    _result = result;
}

void atccsinstruction::setAT(unsigned short _at) {
    this->_at = _at;
}

unsigned short atccsinstruction::at() const {
    return _at;
}

unsigned int atccsinstruction::timeout() const {
    return _timeout;
}
