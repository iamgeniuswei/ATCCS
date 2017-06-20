#ifndef ATCADATA_H
#define ATCADATA_H

/*!
*-----------------------------------------------------
* @file         atccsdata.h/c.pp
* @author       Geniuswei
* @brief        This file define Class ATCCSData while encapsulates the raw data.
* @date         2017-04-13
* @compiler:    gcc/g++ 4.8.5
* @gdb:         GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
* @kernel:      3.10.0-327.28.2.el7.x86_64
* @OS:          CentOS 7.0
* @IDE:         Qt Creator 3.6.1/Qt 5.6.0
* ----------------------------------------------------
*/
#include <iostream>
#pragma once



/**
 * -----------------------------------------------------------------------------
 * The exchange data in the system. 
 * -----------------------------------------------------------------------------
 */
class ATCCSData
{
public:
    ATCCSData(unsigned int size) noexcept;
    ~ATCCSData()
    {        
        if(nullptr != _data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }
    char* data();
    unsigned int size() const
    {
        return _size;
    }
    bool validate() const;

private:
    char *_data = nullptr;
    unsigned int _size = 0;
};

#endif // ATCADATA_H
