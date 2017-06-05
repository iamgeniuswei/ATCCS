#ifndef ATCCS_PLAN_DEFINE_H
#define ATCCS_PLAN_DEFINE_H
/*
 * ---------------------------------------------------------------------------------------------------
 * 该头文件定义ATCCS协议计划信息
 * ---------------------------------------------------------------------------------------------------
 * verion:              1.00.00
 * struct defined by:   Xinglong station of NAOC.
 * file created by:     UKC.
 * modified date:       2017-04-17.
 * CPP version:         C++11/14.
 * compiler:            gcc 4.8.5.
 * IDE:                 Qt 5.6.0.
 * debugger:			gdb 7.6.1.
 * OS:                  CentOS 7.0 64bit.
 * kernel:              3.10.0.
 * ---------------------------------------------------------------------------------------------------
 */

#include "atccs_global.h"
#pragma once

/*!
*-----------------------------------------------------------------------------------------------------
* 该结构体定义观测计划的指令信息
*-----------------------------------------------------------------------------------------------------
* @author Geniuswei
* @date 2016-12-26 11:25
* @size 204 Bytes
*-----------------------------------------------------------------------------------------------------
*/
#pragma pack(1)
typedef struct _atPlan{
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
}_AT_PLAN;
#pragma pack()



#endif // ATCCS_PLAN_DEFINE_H
