/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDataPacker.cpp
 * Author: lenovo
 * 
 * Created on May 16, 2017, 10:24 AM
 */

#include "atccsdatapacker.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
#include "atccs_gimbal_define.h"
#include "atccs_ccd_define.h"
#include <chrono>
#include <string.h>
#include "atccsplan.h"

unsigned int ATCCSDataPacker::seq = 1;
ATCCSDataPacker::ATCCSDataPacker() {
}

ATCCSDataPacker::~ATCCSDataPacker() {
}



std::shared_ptr<ATCCSData> ATCCSDataPacker::packGimbalInstruction_SetObjectName(std::shared_ptr<atccsplan> plan) 
{
    if(plan == nullptr)
        return nullptr;
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_GIMBAL_PARAM_SETOBJECTNAME);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), GIMBAL);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), GIMBAL, plan->id(), _GIMBAL_INSTRUCTION_SETOBJECTNAME);
        
        _AT_GIMBAL_PARAM_SETOBJECTNAME param;
        memcpy(&param.objectName, plan->target().c_str(), 48);
        param.objectType = plan->type();

        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_GIMBAL_PARAM_SETOBJECTNAME));
    }
    return pendingData;
}

std::shared_ptr<ATCCSData> ATCCSDataPacker::packGimbalInstruction_TrackStar(std::shared_ptr<atccsplan> plan) 
{
    if(plan == nullptr)
        return nullptr;
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_GIMBAL_PARAM_TRACKSTAR);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), GIMBAL);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), GIMBAL, plan->id(), _GIMBAL_INSTRUCTION_TRACKSTAR);
        
        _AT_GIMBAL_PARAM_TRACKSTAR param;
        param.epoch = plan->epoch();
        param.speed = plan->type();
        param.rightAscension = plan->rightAscension();
        param.declination = plan->declination();

        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_GIMBAL_PARAM_TRACKSTAR));
    }
    return pendingData;
}

std::shared_ptr<ATCCSData> ATCCSDataPacker::packCCDInstruction_SetBIN(std::shared_ptr<atccsplan> plan)
{
    if(plan == nullptr)
        return nullptr;
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_CCD_PARAM_SETBIN);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), CCD);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), CCD, plan->id(), _CCD_INSTRUCTION_SETBIN);
        _AT_CCD_PARAM_SETBIN param;
        param.binX = param.binY = plan->bin();
        
        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_CCD_PARAM_SETBIN));
    }
    return pendingData;
}

std::shared_ptr<ATCCSData> ATCCSDataPacker::packCCDInstruction_SetGain(std::shared_ptr<atccsplan> plan)
{
    if(plan == nullptr)
        return nullptr;
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_CCD_PARAM_SETGAIN);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), CCD);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), CCD, plan->id(), _CCD_INSTRUCTION_SETGAIN);
        _AT_CCD_PARAM_SETGAIN param;
        param.mode = 0;
        param.gear = plan->gain();
        
        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_CCD_PARAM_SETGAIN));
    }
    return pendingData;
}

std::shared_ptr<ATCCSData> ATCCSDataPacker::packCCDInstruction_SetReadSpeedMode(std::shared_ptr<atccsplan> plan)
{
    if(plan == nullptr)
        return nullptr;
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_CCD_PARAM_SETRSMODE);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), CCD);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), CCD, plan->id(), _CCD_INSTRUCTION_SETRSMODE);
        _AT_CCD_PARAM_SETRSMODE param;
        param.mode = plan->readout();
        
        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_CCD_PARAM_SETRSMODE));
    }
    return pendingData;
}




std::shared_ptr<ATCCSData> ATCCSDataPacker::packCCDInstruction_SetExposureTactic(std::shared_ptr<atccsplan> plan) 
{
    if(plan == nullptr)
        return nullptr;
    
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_CCD_PARAM_SETEXPOSURETACTIC);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), CCD);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), CCD, plan->id(), _CCD_INSTRUCTION_SETEXPOSURETACTIC);
        
        _AT_CCD_PARAM_SETEXPOSURETACTIC param;
        memset(&param, 0, sizeof(_AT_CCD_PARAM_SETEXPOSURETACTIC));
        param.duration  = plan->exposureTime();
        param.delay = plan->delayTime();
        memcpy(&param.objectName, plan->target().c_str(), 48);
        param.objectType = plan->type();
        param.objectRightAscension = plan->rightAscension();
        param.objectDeclination = plan->declination();
        param.objectEpoch = plan->epoch();
        param.frameNum = 1;
        
        memcpy(&param.objectBand, plan->filter().c_str(), 8);
        

        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_CCD_PARAM_SETEXPOSURETACTIC));
    }
    return pendingData;
}

std::shared_ptr<ATCCSData> ATCCSDataPacker::packCCDInstruction_StartExposure(std::shared_ptr<atccsplan> plan) 
{
    if(plan == nullptr)
        return nullptr;
    unsigned int size = sizeof(_ATCCSPHeader) + sizeof(_AT_INSTRUCTION_HEADER) + sizeof(_AT_CCD_PARAM_STARTEXPOSURE);
    std::shared_ptr<ATCCSData> pendingData(new (std::nothrow) ATCCSData(size));
    if(pendingData)
    {
        _ATCCSPHeader header;
        packATCCSHeader(header, size, plan->at(), CCD);
        _AT_INSTRUCTION_HEADER in;
        packInstructionHeader(in, plan->at(), CCD, plan->id(), _CCD_INSTRUCTION_STARTEXPOSURE);
        
        _AT_CCD_PARAM_STARTEXPOSURE param;
        memset(&param, 0, sizeof(_AT_CCD_PARAM_STARTEXPOSURE));
        

        memcpy(pendingData->data(), &header, sizeof(_ATCCSPHeader));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader), &in, sizeof(_AT_INSTRUCTION_HEADER));
        memcpy(pendingData->data()+sizeof(_ATCCSPHeader)+sizeof(_AT_INSTRUCTION_HEADER), &param, sizeof(_AT_CCD_PARAM_STARTEXPOSURE));
    }
    return pendingData;
}



void ATCCSDataPacker::packATCCSHeader(_ATCCSPHeader& header, unsigned int size, unsigned short at, unsigned short device) 
{
    memset(&header, 0, sizeof(_ATCCSPHeader));
    header.magic = MAGIC;
    header.version = VERSION;    
    header.msg = ATINSTRUCTION;
    header.length = size;
    header.sequence = seq;
    header.tv_sec = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());;
    header.AT.at = at;
    header.AT.device = device;
}

void ATCCSDataPacker::packInstructionHeader(_AT_INSTRUCTION_HEADER& in, unsigned short at, unsigned short device, unsigned int plan, unsigned int instruction) 
{
    memset(&in, 0, sizeof(_AT_INSTRUCTION_HEADER));
    in.at = at;
    in.device = device;
    in.plan = plan;
    in.sequence = seq++;
    in.operation = instruction;
}



