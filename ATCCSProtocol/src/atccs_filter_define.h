#ifndef ATCCS_FILTER_DEFINE
#define ATCCS_FILTER_DEFINE

/*
 * ---------------------------------------------------------------------------------------------------
 * atccs_filter_define.h defines Filter's data structrue.
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
* @brief    ENUM_AT_FILTER_INSTRUCTION enumerates Filter's instruction.
* ----------------------------------------------------------------------------------------------------
*/
enum ENUM_AT_FILTER_INSTRUCTION
{
    _FILTER_INSTRUCTION_CONNECT = 1,    // =1
    _FILTER_INSTRUCTION_SETPOSITION,    // =2    
    _FILTER_INSTRUCTION_FINDHOME        // =3
};

/**
 * -----------------------------------------------------------------------------
 * @brief ENUM_AT_FILTER_ENUM_STATUS enumerates the Filter's status
 * -----------------------------------------------------------------------------
 */
enum ENUM__AT_FILTER_STATUS
{
    _FILTER_STATUS_DISCONNECT = 0x01,   // =1
    _FILTER_STATUS_CONNECTING,          // =2
    _FILTER_STATUS_DISCONNECTING,       // =3
    _FILTER_STATUS_FREEZING,            // =4
    _FILTER_STATUS_FREEZED,             // =5
    _FILTER_STATUS_SLEWING,             // =6
    _FILTER_STATUS_SLEWED,              // =7
    _FILTER_STATUS_NOTFINDHOME,         // =8
    _FILTER_STATUS_HOMING,              // =9    
    _FILTER_STATUS_EMERGENCYING,        // =10
    _FILTER_STATUS_EMERGENCY            // =11
};



#pragma pack(1)
struct _AT_FILTER_PROPERTY{
    _AT_PUBLIC_PROPERTY header;
    unsigned int filterSize[3];
    unsigned short numFilter;    
    unsigned short filterShape;
    unsigned short canSetFilterPosition;
    unsigned short canConnect;
    unsigned short canFindHome;
};
#pragma pack()


/**
 * -----------------------------------------------------------------------------
 * @brief:  _AT_FILTER_STATUS defines Filter's real time status.
 * -----------------------------------------------------------------------------
 * @version:2.00.00 
 * @size:   78 bytes.
 * @date:   2017-05-15
 * @author: Geniuswei
 * -----------------------------------------------------------------------------
 * @type-info:  char: 1 bytes.
 *              double: 8 bytes.
 *              unsigned short: 2 bytes.
 *              unsigned int: 4 bytes.
 * -----------------------------------------------------------------------------
 */
#pragma pack(1)
struct _AT_FILTER_STATUS{
    _AT_PUBLIC_STATUS status;
    unsigned short filterPosition;
    unsigned short targetFilterPosition;
    unsigned short isHomed;	
};
#pragma pack()



/**
 * -----------------------------------------------------------------------------
 * @brief:  _AT_FILTER_PARAM_CONNECT defines Filter's
 *          [_FILTER_INSTRUCTION_CONNECT] parameter.
 * -----------------------------------------------------------------------------
 * @version:2.00.00 
 * @size:   2 bytes.
 * @date:   2017-05-15
 * @author: Geniuswei
 * -----------------------------------------------------------------------------
 * @type-info:  unsigned short: 2 bytes.
 * -----------------------------------------------------------------------------
 */
#pragma pack(1)
struct _AT_FILTER_PARAM_CONNECT{
    //1:connect, 2:disconnect
    //according to ENUM_CONNECT
    unsigned short connect;
};
#pragma pack()


/**
 * -----------------------------------------------------------------------------
 * @brief:  _AT_FILTER_PARAM_SETPOSITION defines Filter's
 *          [_FILTER_INSTRUCTION_SETPOSITION] parameter.
 * -----------------------------------------------------------------------------
 * @version:2.00.00 
 * @size:   2 bytes.
 * @date:   2017-05-15
 * @author: Geniuswei
 * -----------------------------------------------------------------------------
 * @type-info:  unsigned short: 2 bytes.
 * -----------------------------------------------------------------------------
 */
#pragma pack(1)
struct _AT_FILTER_PARAM_SETPOSITION{
    unsigned short position;
};
#pragma pack()

#endif
