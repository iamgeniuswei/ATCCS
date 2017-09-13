#ifndef ATCCSCONTROLLER_H
#define ATCCSCONTROLLER_H

/*!
* ----------------------------------------------------
* @file         atccscontroller.h/.cpp
* @author       Geniuswei
* @brief        This file define interface of ATCCSController.
*               ATCCSController is the base class of all the device controller.
* @date         2017-04-13
* @compiler:    gcc/g++ 4.8.5
* @gdb:         GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
* @kernel:      3.10.0-327.28.2.el7.x86_64
* @OS:          CentOS 7.0
* @IDE:         Qt Creator 3.6.1/Qt 5.6.0
* ----------------------------------------------------
*/


#include "atccsqueue.h"
#include "atccsdata.h"
#include <memory>
#include <mutex>
class ATCCSData;

/**
 * -----------------------------------------------------------------------------
 * The base class of all the device controllers that have a first in first 
 * out queue.
 * -----------------------------------------------------------------------------
 */
class ATCCSController
{
public:
    explicit ATCCSController();
    virtual ~ATCCSController();
    void pushControlData(std::shared_ptr<ATCCSData> data = nullptr);
    void clearControlData();
    size_t queueSize();
protected:
    ATCCSQueue<std::shared_ptr<ATCCSData>> _fifoQueue;
    std::shared_ptr<ATCCSData> popControlData();
};

#endif // ATCCSCONTROLLER_H
