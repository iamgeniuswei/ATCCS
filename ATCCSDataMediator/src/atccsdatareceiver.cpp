#include "atccsdatareceiver.h"
#include "atccsdataqueue.h"
#include "atccsdata.h"
#include "qpudpsocket.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "atccsaddress.h"
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
ATCCSDataReceiver::ATCCSDataReceiver()
{    
    try
    {
        _recvSocket = std::make_shared<QPUdpSocket>();
        _dataQueue = ATCCSDataQueue::instance();
    }
    catch(std::exception &e)
    {
        _recvSocket = nullptr;
#ifdef OUTERRORINFO
        std::string debug_info;
        debug_info += e.what();
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new (std::nothrow) ATCCSException(ATCCSException::STDEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
    }    
}


ATCCSDataReceiver::~ATCCSDataReceiver()
{
#ifdef OUTERRORINFO
    std::cout << "~ATCCSDataReceiver" << std::endl;
#endif    
}

/**
 * -----------------------------------------------------------------------------
 * @brief       Thread function, This function will be executed in a new thread.
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 */
void ATCCSDataReceiver::run()
{
    char *data = nullptr;
    try
    {
        data = new char[4096];
        
    }
    catch(std::exception &e)
    {
        data = nullptr;
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
    }
    
    if(data)
    {
        try 
        {
            while (!stop() && _recvSocket && isReadyToRecv) 
            {
                ssize_t size = _recvSocket->recvData(data, 4096);
                if (size > 0) 
                {
                    std::shared_ptr<ATCCSData> newdata(new ATCCSData(size));
                    if (newdata != nullptr && newdata->data() != nullptr) 
                    {
                        memcpy(newdata->data(), data, size);
                        _dataQueue->push(newdata);
                    }
                }
            }
            
        } 
        catch (std::exception &e) 
        {
#ifdef OUTERRORINFO
        std::string debug_info;
        debug_info += e.what();
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::STDEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
        }
        delete [] data;
        data = nullptr;
    }
    else
    {
#ifdef OUTERRORINFO
        std::string debug_info;
        debug_info += "can not allocate ATCCSDataReceiver receive buffer. ";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
    }
}

/**
 * -----------------------------------------------------------------------------
 * @brief       set the address of ATCCSDataReceiver
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 * @param address   a shared_ptr of ATCCSAddress
 * -----------------------------------------------------------------------------
 */
int ATCCSDataReceiver::setRecvAddress(std::shared_ptr<ATCCSAddress> address)
{
    if(address != nullptr)
        return setRecvAddress(address->ip(), address->port());
    return -1;
}

/**
 * -----------------------------------------------------------------------------
 * @brief       set the address of ATCCSDataReceiver
 * -----------------------------------------------------------------------------
 * @access      public
 * -----------------------------------------------------------------------------
 * @param ip    ip v4 address, std::string
 * @param port  4000-65535, unsigned short
 * -----------------------------------------------------------------------------
 */
int ATCCSDataReceiver::setRecvAddress(const std::string &ip, unsigned short port)
{
    int ret = -1;
    if(_recvSocket == nullptr)
        _recvSocket = recvSocketInstance();
    if(_recvSocket)
    {
        ret = _recvSocket->setHostAddress(ip, port);
        _recvSocket->setRecvTimeout(10);
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, 
                                            __FILE__, __func__, __LINE__,
                                            "QPUdpSocket instance is null, can not bind address.");
#endif
    }
    if(ret == 0)
        isReadyToRecv = true;
    return ret;
}

std::shared_ptr<QPUdpSocket> ATCCSDataReceiver::recvSocketInstance()
{
    if(_recvSocket == nullptr)
    {
        try
        {
            _recvSocket = std::shared_ptr<QPUdpSocket>();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }
    }
    return _recvSocket;
}
