#ifndef ATCCSDATAPROCESSOR_H
#define ATCCSDATAPROCESSOR_H

/*!
* ----------------------------------------------------
* @file         atccsdataprocessor.h/.cpp
* @author       Geniuswei
* @brief        This file define interface of ATCCSDataProcessor.
* @date         2017-04-13
* @compiler:    gcc/g++ 4.8.5
* @gdb:         GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
* @kernel:      3.10.0-327.28.2.el7.x86_64
* @OS:          CentOS 7.0
* @IDE:         Qt Creator 3.6.1/Qt 5.6.0
* ----------------------------------------------------
*/


#include <memory>
class ATCCSData;
class ATCCSDataProcessor
{
public:
    virtual void processData(std::shared_ptr<ATCCSData> data = nullptr) = 0;
};

#endif // ATCCSDATAPROCESSOR_H
