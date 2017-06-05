#ifndef ATCCS_DPM_DEFINE
#define ATCCS_DPM_DEFINE
/*
 * ---------------------------------------------------------------------------------------------------
 * ��ͷ�ļ�����ATCCSЭ����DPM (���ݴ���ģ��) ��������Ϣ
 * ---------------------------------------------------------------------------------------------------
 * verion:              1.00.00
 * struct defined by:   Xinglong station of NAOC.
 * file created by:     UKC.
 * modified date:       2016-10-18.
 * CPP version:         C++11/14.
 * compiler:            gcc 4.8.5.
 * IDE:                 Qt 5.6.0.
 * debugger:			gdb 7.6.1.
 * OS:                  CentOS 7.0 64bit.
 * kernel:              3.10.0.
 * ---------------------------------------------------------------------------------------------------
 * ���ļ������� (version 1.00.00)
 * ---------------------------------------------------------------------------------------------------
 * version:				1.00.1
 * modified data:		2017-04-06
 * IDE:					VS2010
 * OS:					windows xp sp3
 *
 */
#include "atccs_global.h"
#include "atccs_public_define.h"
#pragma once

/*!
*-----------------------------------------------------------------------------------------------------
* �ýṹ�嶨��DPM��������Ϣ
*-----------------------------------------------------------------------------------------------------
* @author			Geniuswei
* @date				2016-12-28
* @modified-date	2017-03-31
* @size				68B
*-----------------------------------------------------------------------------------------------------
*/
#pragma pack(1)
typedef struct DPMAttributes{
    _AT_PUBLIC_PROPERTY header;
    char detector[8];
}_AT_DPM_ATTRIBUTES;
#pragma pack()

/*!
*-----------------------------------------------------------------------------------------------------
* �ýṹ�嶨��DPM��״̬��Ϣ
*-----------------------------------------------------------------------------------------------------
* @author			Geniuswei
* @date				2016-12-28
* @modified-date	2017-03-31
* @size				330B
*-----------------------------------------------------------------------------------------------------
*/
#pragma pack(1)
typedef struct DPMStatus{
    char imagePath[48];
    char objectName[48];
    unsigned short objectType;
    double rightAscension;
    double declination;
    unsigned short epoch;
    char band[8];
    unsigned short observeStatus;
    unsigned int binX;
    unsigned int binY;
    unsigned int startX;
    unsigned int startY;
    unsigned int imageWidth;
    unsigned int imageHeight;
    double exposureTime;
    unsigned short indexOfGainMode;
    unsigned short indexOfRSMode;
    unsigned short indexOfTSMode;
    unsigned short indexOfGainGear;
    unsigned short indexOfRMode;
    unsigned short gain;
    double noise;
    double coolerT;
    double targetCoolerT;
    double bitsOfPixel;
    unsigned short exposureTriggerMode;
    unsigned short indexOfCoolerMode;
    unsigned short fanStatus;
    double imageMeanValue;
    double imageRMS;
    double astrologyHHFW;
    double imageCenterRightAscension;
    double imageCenterDeclination;
    double missX;
    double missY;
    double missAxis1;
    double missAxis2;
    double atmosphericTransparency;
    unsigned short shutterMode;
    unsigned short isFullFrame;
    unsigned short isEM;
    unsigned int EM;
    unsigned short isNoiseFilter;
    unsigned short isBaseline;
    unsigned short isOverScan;
    double pixelScaleX;
    double pixelScaleY;
    double temperature;
    unsigned short fitsHead;
}_AT_DPM_STATUS;
#pragma pack()

#endif
