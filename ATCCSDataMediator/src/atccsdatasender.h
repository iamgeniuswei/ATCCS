#ifndef ATCCSDATASENDER_H
#define ATCCSDATASENDER_H

/*!
*-----------------------------------------------------
* @file         atccsdatasender.h
* @author       Geniuswei
* @brief        This file define interface of ATCCSDataSender.
* @date         2017-04-13
* @compiler:    gcc/g++ 4.8.5
* @gdb:         GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
* @kernel:      3.10.0-327.28.2.el7.x86_64
* @OS:          CentOS 7.0
* @IDE:         Qt Creator 3.6.1/Qt 5.6.0
* ----------------------------------------------------
*/

#include <string>
#include <memory>
class QPUdpSocket;
class ATCCSData;
class ATCCSAddress;

/*
 * -----------------------------------------------------------------------------
 * ATCCSDataSender is used to send ATCCSData to the appointed ip add port.
 * -----------------------------------------------------------------------------
 * @author: Geniuswei
 * @date:   2017-05-24
 * -----------------------------------------------------------------------------
 */
class ATCCSDataSender
{
public:    
    ATCCSDataSender();
    virtual ~ATCCSDataSender();
    virtual int sendData(std::shared_ptr<ATCCSData> data = nullptr);
    void setTargetAddress(const std::string &ip , unsigned short port = 0);
    void setTargetAddress(std::shared_ptr<ATCCSAddress> address = nullptr);
protected:
    std::shared_ptr<QPUdpSocket> _udpSocket = nullptr;
};

#endif // ATCCSDATASENDER_H
