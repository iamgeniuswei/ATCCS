#ifndef ATCCS_PLAN_DEFINE_H
#define ATCCS_PLAN_DEFINE_H
/*
 * -----------------------------------------------------------------------------
 * atccs_plan_define.h define plan's data structure.
 * -----------------------------------------------------------------------------
 * verion:              1.00.00
 * struct defined by:   Xinglong station of NAOC.
 * file created by:     UKC.
 * modified date:       2017-04-17.
 * CPP version:         C++11/14.
 * compiler:            gcc 4.8.5.
 * IDE:                 Qt 5.6.0.
 * debugger:		gdb 7.6.1.
 * OS:                  CentOS 7.0 64bit.
 * kernel:              3.10.0.
 * -----------------------------------------------------------------------------
 */

#include "atccs_global.h"
#include "atccsaddress.h"
#pragma once

/*!
*------------------------------------------------------------
* _AT_PLAN defines plan's struct.
*------------------------------------------------------------
* @author Geniuswei
* @date 2016-12-26 11:25
* @modified 2017-06-07 10:35
* @size 160 Bytes
*------------------------------------------------------------
*/

enum ENUM_OBJECT_TYPE
{
    STELLAR = 0,
    SUN,
    MOON,
    COMET,
    PLANET,
    SATELITE,
    FIXED,
    BIAS,
    DARK,
    FLAT    
};



#pragma pack(1)
struct _AT_PLAN
{
    unsigned int _tag;
    unsigned short at;
    char user[48];
    char project[48];
    char target[48];
    unsigned int type;
    double rightAscension;
    double declination;
    unsigned int epoch;
    double  exposureTime;
    double delayTime;
    unsigned int exposureCount;
    char filter[8];
    unsigned short gain;
    unsigned short bin;
    unsigned short readout;
};
#pragma pack()

/**
 * 定义计划观测操作
 */

enum ENUM_AT_PLAN_STRATEGY
{
    SINGLE = 0x01,
    SINGLELOOP,
    SEQUENCE,
    SEQUENCELOOP
};

enum ENUM_AT_PLAN_INSTRUCTION
{
    START = 0x01,
    STOP,
    NEXT
};

#pragma pack(1)
struct _AT_PLAN_INSTRUCTION
{
    unsigned int instruction;
    unsigned int strategy;
    unsigned int start;
    unsigned int end;
};
#pragma pack()



#endif // ATCCS_PLAN_DEFINE_H
