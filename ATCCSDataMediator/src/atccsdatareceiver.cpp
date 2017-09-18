#include "atccsdatareceiver.h"
#include "atccsdataqueue.h"
#include "atccsdata.h"
#include "qpudpsocket.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <locale>
#include "atccsaddress.h"
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
ATCCSDataReceiver::ATCCSDataReceiver()
{    
  
}


ATCCSDataReceiver::~ATCCSDataReceiver()
{
  
}

/**
 * Thread function.
 * This function will be executed in a new thread.
 * @access public
 */
void ATCCSDataReceiver::run()
{
    _dataQueue = ATCCSDataQueue::instance();
    if(_dataQueue == nullptr)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The MSG Queue is fail to create, fails to execute data receiver thread."));
#endif  
        return;
    }
    if(!_isReadyToRecv)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR,"%s",
                                            gettext("Can not bind the IP and port, fails to execute data receiver thread."));
#endif
        return;
    }
    if(_recvSocket == nullptr)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The socket is fail to create, fails to execute data receiver thread."));
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
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,"%s%s",
                                            gettext("The receiver buffer is fail to create, fails to execute data receiver thread."), e.what());
#endif
        return;
    }
    
    if(data)
    {
        while (!stop())
        {
            try
            {
                ssize_t size = _recvSocket->recvData(data, BUFFER_SIZE);
                if (size > 0) 
                {
//                    std::cout << "recv data\n";
                    std::shared_ptr<ATCCSData> newdata(new ATCCSData(size));
                    if (newdata != nullptr && newdata->data() != nullptr) 
                    {
                        memcpy(newdata->data(), data, size);
                        _dataQueue->push(newdata);
                    }
                }                
            }
            catch(std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                    gettext("Fails to receive data and push it into MSG Queue."), e.what());
#endif                
            }
        }
        delete [] data;
        data = nullptr;
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                            gettext("The receiver buffer fails to create, fails to execute data receiver thread."));
#endif
    }
}

/**
 * set the receive address.
 * @param address
 * @return SUCCESS(0) if success, FAIL(-1) if fails.
 * @access public
 */
int ATCCSDataReceiver::setRecvAddress(std::shared_ptr<ATCCSAddress> address)
{
    if(address != nullptr)
    {
        return setRecvAddress(address->ip(), address->port());
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                            gettext("The address is null, fails to set receive address."));
#endif        
    }
    return FAIL;
}

/**
 * set the receive address.
 * @param ip
 * @param port
 * @return SUCCESS(0) if success, FAIL(-1) if fails.
 * @access public
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
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                gettext("The socket is fails to create, fails to set receive address."), e.what());
#endif
            return ret;
        }        
    }

    ret = _recvSocket->setHostAddress(ip, port);
    _recvSocket->setRecvTimeout(10);

    if(ret == QPUdpSocket::SUCCESS)
        _isReadyToRecv = true;
    return ret;
}