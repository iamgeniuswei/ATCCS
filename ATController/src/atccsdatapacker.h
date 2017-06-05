/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDataPacker.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 10:24 AM
 */

#ifndef ATCCSDATAPACKER_H
#define ATCCSDATAPACKER_H
#include <memory>
#include "atccs_public_define.h"

class ATCCSData;
class atccsplan;
class ATCCSDataPacker {
private:
    ATCCSDataPacker();
    ATCCSDataPacker(const ATCCSDataPacker& orig) = delete;
    virtual ~ATCCSDataPacker();    
public:
    static unsigned int seq;
    static std::shared_ptr<ATCCSData> packGimbalInstruction_SetObjectName(std::shared_ptr<atccsplan> plan = nullptr);
    static std::shared_ptr<ATCCSData> packGimbalInstruction_TrackStar(std::shared_ptr<atccsplan> plan = nullptr);
    static std::shared_ptr<ATCCSData> packCCDInstruction_SetExposureTactic(std::shared_ptr<atccsplan> plan = nullptr);
    static std::shared_ptr<ATCCSData> packCCDInstruction_StartExposure(std::shared_ptr<atccsplan> plan = nullptr);
    static void packATCCSHeader(_ATCCSPHeader& header, unsigned int size, unsigned short at, unsigned short device);
    static void packInstructionHeader(_AT_INSTRUCTION_HEADER &in, unsigned short at, unsigned short device, unsigned int instruction);

};

#endif /* ATCCSDATAPACKER_H */

