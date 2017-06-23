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
#include <math.h>

#include "atccs_global.h"

/**
 * ASC realtime data structure.
 * The programmer have to guarantee that:
 * sizeof(double) == 8
 * sizeof(unsigned short) == 2 
 * sizeof(_EME_ASC_REALTIME_DATA) == 24
 */
#pragma pack(1)
struct _EME_ASC_REALTIME_DATA
{
    double shutterspeed;
    double aperture;
    unsigned short iso;
    unsigned short jpeg;
    unsigned short raw;
    unsigned short fits;
};
#pragma pack()

/**
 * WS realtime data structure.
 * The programmer have to guarantee that:
 * sizeof(double) == 8
 * sizeof(unsigned int) == 4 
 * sizeof(_EME_WS_REALTIME_DATA) == 84
 */
#pragma pack(1)
struct _EME_WS_REALTIME_DATA
{
    double temperature;
    double humidity;
    double dewpoint;
    double pressure;
    double windspeed;
    double windspeed2;
    double windspeed10;
    unsigned int windderection;
    double rainfall;
    double raidation;
    double illumination;
};
#pragma pack()

/**
 * WS realtime data structure.
 * The programmer have to guarantee that:
 * sizeof(double) == 8
 * sizeof(unsigned short) == 2 
 * sizeof(_EME_WS_REALTIME_DATA) == 62
 */
#pragma pack(1)
struct _EME_CS_REALTIME_DATA
{
    double RelSkyT;
    double AmbientT;
    double SensorT;
    unsigned short RainF;
    unsigned short RainThreshV;
    double wind;
    unsigned short WindUnits;
    double HumidityPercent;
    double DewPointT;
    double DayLightV;
};
#pragma pack()


/**
 * WS realtime data structure.
 * The programmer have to guarantee that:
 * sizeof(double) == 8
 * sizeof(_EME_SQM_REALTIME_DATA) == 8
 */
#pragma pack(1)
struct _EME_SQM_REALTIME_DATA
{
    double sqmdata;
};
#pragma pack()


/**
 * WS realtime data structure.
 * The programmer have to guarantee that:
 * sizeof(double) == 8
 * sizeof(_EME_DUST_REALTIME_DATA) == 8
 */
#pragma pack(1)
struct _EME_DUST_REALTIME_DATA
{
    double dust_data;
};
#pragma pack()

/**
 * WS realtime data structure.
 * The programmer have to guarantee that:
 * sizeof(double) == 8
 * sizeof(_EME_DIMM_REALTIME_DATA) == 8
 */
#pragma pack(1)
struct _EME_DIMM_REALTIME_DATA
{
    double dimm_data;
};
#pragma pack()
#endif // ATCCS_EME_DEFINE_H
