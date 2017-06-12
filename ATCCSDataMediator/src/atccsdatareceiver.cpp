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
    _dataQueue = ATCCSDataQueue::instance();
    if(_dataQueue == nullptr)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSDataQueue instance is null,fails to execute data receiver thread.");
#endif          
    }
    if(!isReadyToRecv)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__,
                                            "There is error in socket setting, fails to execute data receiver thread.");
#endif
        return;
    }
    if(_recvSocket == nullptr)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "QPUdpSocket instance is null, fails to execute data receiver thread.");
#endif
        return;
    }
    char *data = nullptr;
    try
    {
        data = new char[BUFFER_SIZE];
        
    }
    catch(std::exception &e)
    {
        data = nullptr;
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                            __FILE__, __func__, __LINE__, e.what());
#endif
        return;
    }
    
    if(data)
    {
        try 
        {
            while (!stop() && isReadyToRecv) 
            {
                ssize_t size = _recvSocket->recvData(data, BUFFER_SIZE);
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
        }
        delete [] data;
        data = nullptr;
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "fails to allocate temporary receive buffer, fails to execute data receiver thread.");
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
    return FAIL;
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
    int ret = QPUdpSocket::FAIL;
    if(_recvSocket == nullptr)
    {
        try
        {
            _recvSocket = std::make_shared<QPUdpSocket>();
        }
        catch(std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
            return ret;
        }        
    }
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
    if(ret == QPUdpSocket::SUCCESS)
        isReadyToRecv = true;
    return ret;
}