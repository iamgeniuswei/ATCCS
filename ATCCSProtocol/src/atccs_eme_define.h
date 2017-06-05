#ifndef ATCCS_EME_DEFINE_H
#define ATCCS_EME_DEFINE_H
/*
 * This file defines the structure of the data acquired by environmental monitoring equipments,
 * the equipments include, but are not limited to,
 * 1)   ASC
 * 2)   WS
 * 3)   CS
 * 4)   SQM
 * 5)   DUST
 * 6)   DIMM
 * ---------------------------------------------------------------------------------------------------
 * verion:              1.00.00
 * struct defined by:   Xinglong station of NAOC.
 * file created by:     UKC.
 * modified date:       2016-10-18.
 * CPP version:         C++11/14.
 * compiler:            gcc 4.8.5.
 * IDE:                 Qt 5.6.0.
 * debugger:            gdb 7.6.1.
 * OS:                  CentOS 7.0 64bit.
 * kernel:              3.10.0.
 * ---------------------------------------------------------------------------------------------------
 * version:             1.00.01
 * modified date:       2016-11-18
 * desciption:          change a portion of variables' type into float
 * ---------------------------------------------------------------------------------------------------
 * version:             1.00.02
 * modified date:       2016-12-22
 * desciption:          use ATCCS_GLOBAL_H to redefine the data type
 */
#pragma once
#include "atccs_global.h"

//data structure of ASC.
//sizeof(ASC_STRUCT) = 24bytes.
#pragma pack(1)
typedef struct asc_struct{
    UINT32 envDeviceType;
    UINT32 timestamp;
    FLOAT32 shutterspeed;
    FLOAT32 aperture;
    unsigned short iso;
    unsigned short jpeg;
    unsigned short raw;
    unsigned short fits;
}_AT_ASC_STATUS;
#pragma pack()

//data structure of WS.
//sizeof(WS_STRUCT) = 52bytes;
#pragma pack(1)
typedef struct ws_struct{
    UINT32 envDeviceType;
    UINT32 timestamp;
    FLOAT32 temperature;
    FLOAT32 humidity;
    FLOAT32 dewpoint;
    FLOAT32 pressure;
    FLOAT32 windspeed;
    FLOAT32 windspeed2;
    FLOAT32 windspeed10;
    UINT32 windderection;
    FLOAT32 rainfall;
    FLOAT32 raidation;
    FLOAT32 illumination;
}_AT_WS_STATUS;
#pragma pack()
//data structure of CS.
//sizeof(CS_STRUCT) = 42bytes.
#pragma pack(1)
typedef struct cs_struct{
    UINT32 envDeviceType;
    UINT32 timestamp;
    FLOAT32 RelSkyT;
    FLOAT32 AmbientT;
    FLOAT32 SensorT;
    unsigned short RainF;
    unsigned short RainThreshV;
    FLOAT32 wind;
    unsigned short WindUnits;
    FLOAT32 HumidityPercent;
    FLOAT32 DewPointT;
    UINT32 DayLightV;
}_AT_CS_STATUS;
#pragma pack()
//data structure of SQM.
//sizeof(SQM_STRUCT) = 12bytes;
#pragma pack(1)
typedef struct sqm_struct{
    UINT32 envDeviceType;
    UINT32 timestamp;
    FLOAT32 sqmdata;
}_AT_SQM_STATUS;
#pragma pack()
//data structure of dust.
//sizeof(DUST_STRUCT) = 12bytes;
#pragma pack(1)
typedef struct dust_struct{
    UINT32 envDeviceType;
    UINT32 timestamp;
    FLOAT32 dust_data;
}_AT_DUST_STATUS;
#pragma pack()
//data structure of dimm.
//sizeof(DUST_STRUCT) = 12bytes;
#pragma pack(1)
typedef struct dimm_struct{
    UINT32 envDeviceType;
    UINT32 timestamp;
    FLOAT32 dimm_data;
}_AT_DIMM_STATUS;
#pragma pack()
#endif // ATCCS_EME_DEFINE_H
