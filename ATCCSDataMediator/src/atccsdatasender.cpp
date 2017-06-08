#include "atccsdatasender.h"
#include "qpudpsocket.h"
#include <exception>
#include "atccsdata.h"
#include "atccsaddress.h"
#include <iostream>
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
ATCCSDataSender::ATCCSDataSender()
{
    try
    {
        _udpSocket = std::make_shared<QPUdpSocket>();
    }
    catch(std::exception &e)
    {
        _udpSocket = nullptr;
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
}

ATCCSDataSender::~ATCCSDataSender()
{
#ifdef OUTERRORINFO
    std::cout << "~ATCCSDataSender\n";
#endif
}

/**
 * -----------------------------------------------------------------------------
 * @brief       send ATCCSData to The Target
 * -----------------------------------------------------------------------------
 * @param data  the pending data
 * @return size actually send
 * -----------------------------------------------------------------------------
 */
int ATCCSDataSender::sendData(std::shared_ptr<ATCCSData> data)
{
    if(_udpSocket)
        return _udpSocket->sendData(data->data(), data->size());
    else
    {
#ifdef OUTERRORINFO
        std::string debug_info;
        debug_info += "QPUdpSocket is null, can not send data.";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
        return 0;
    }
}

/**
 * -----------------------------------------------------------------------------
 * @brief       set The Target Address
 * -----------------------------------------------------------------------------
 * @param ip    ip v4 address, std::string, 
 * @param port  4000-65535, unsigned short, 
 * -----------------------------------------------------------------------------
 */
void ATCCSDataSender::setTargetAddress(const std::string &ip, unsigned short port)
{
    if(_udpSocket)
        _udpSocket->setTargetAddress(ip, port);
    else
    {
#ifdef OUTERRORINFO
        std::string debug_info;
        debug_info += "QPUdpSocket is null, can not set Address. ";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif        
    }
}

void ATCCSDataSender::setTargetAddress(std::shared_ptr<ATCCSAddress> address) 
{
    if(address)
    {
        setTargetAddress(address->ip(), address->port());
    }
    else
    {
#ifdef OUTERRORINFO
        std::string debug_info;
        debug_info += "ATCCSAddress is null. ";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
    }    
}
