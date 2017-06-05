#ifndef _ATCCS_GLOBAL
#define _ATCCS_GLOBAL
#pragma once
/*---------------------------------------------------------------
* Description:  global definition
* Author:	Geniuswei
* Date:		2017-03-30
* IDE:		VS2010
* OS:		windows xp sp3
*--------------------------------------------------------------*/

#ifndef C11
#define C11 0
#endif

#ifndef QT
#define QT 1
#endif

#ifndef OUTDEBUGINFO
#define OUTDEBUGINFO
#endif

#ifndef DATAPERSISTENCE
#define DATAPERSISTENCE
#endif

enum ERROR_TYPE
{
    ERROR_STDEXCEPTRION = 1,
    ERROR_POINTERISNULL,
    ERROR_CUSTOM
};

enum
{
    INIT_VALUE = 10000
};

#endif