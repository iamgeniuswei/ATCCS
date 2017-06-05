#ifndef ATCCS_GUIDESCOPE_DEFINE
#define ATCCS_GUIDESCOPE_DEFINE

/*
 * ---------------------------------------------------------------------------------------------------
 * ��ͷ�ļ�����ATCCSЭ����Guidescope (���Ǿ�) ��������Ϣ
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
* ----------------------------------------------------------------------------------------------------
* _AT_GUIDESCOPE_INSTRUCTION ö������, ö��GuideScope (���Ǿ�) ������ָ�����
* ----------------------------------------------------------------------------------------------------
*/
enum _AT_GUIDESCOPE_INSTRUCTION
{
    _AT_GUIDESCOPE_CONNECT,
    _AT_GUIDESCOPE_COVEROPERATION,
    _AT_GUIDESCOPE_ENABLEAUTOFOCUS
};


/*!
*-----------------------------------------------------------------------------------------------------
* �ýṹ�嶨��GuideScope��������Ϣ
*-----------------------------------------------------------------------------------------------------
* @author			Geniuswei
* @date				2016-12-28
* @modified-date	2017-03-31
* @size				88B
*-----------------------------------------------------------------------------------------------------
*/
#pragma pack(1)
typedef struct GuideScopeAttributes{
    _AT_PUBLIC_PROPERTY header;
    double aperture;
    unsigned short focusType;
    double foucsLength;
    unsigned short hasAxis5;
    unsigned short isAutoFocus;
    unsigned short canConnect;
    unsigned short canCoverOperation;
    unsigned short canEnableAutoFocus;
}_AT_GUIDESCOPE_ATTRIBUTES;
#pragma pack()

/*!
*-----------------------------------------------------------------------------------------------------
* �ýṹ�嶨��GuideScope��״̬��Ϣ
*-----------------------------------------------------------------------------------------------------
* @author			Geniuswei
* @date				2016-12-28
* @modified-date	2017-03-31
* @size				76 B
*-----------------------------------------------------------------------------------------------------
* @modified-date    2017-04-10
* @description      relayout the data members, put _AT_PUBLIC_STATUS in the first position.
*-----------------------------------------------------------------------------------------------------
*/
#pragma pack(1)
typedef struct GuideScopeStatus{
    _AT_PUBLIC_STATUS status;
    unsigned short indexOfCover;
    unsigned short targetIndexeOfCover;
    double positionOfCover;	
}_AT_GUIDESCOPE_STATUS;
#pragma pack()
/*!
*-----------------------------------------------------------------------------------------------------
* �ýṹ�嶨��GuideScope (EnableAutoFocus) ָ��Ĳ�����Ϣ
*-----------------------------------------------------------------------------------------------------
* @author			Geniuswei
* @date				2016-12-28
* @modified-date	2017-03-31
* @size				4B
*-----------------------------------------------------------------------------------------------------
*/
#pragma pack(1)
typedef struct GuideScopeEnableAutoFocusParam{
    unsigned short enable;
}_AT_GUIDESCOPE_EAF_PARAM;
#pragma pack()
#endif
