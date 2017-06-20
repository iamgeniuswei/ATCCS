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
}

ATCCSDataSender::~ATCCSDataSender()
{
}


/**
 * send ATCCSData to the targetDevice
 * @param data
 * @return the size has been sent
 * @access public
 */
int ATCCSDataSender::sendData(std::shared_ptr<ATCCSData> data)
{
    if (_udpSocket)
        return _udpSocket->sendData(data->data(), data->size());
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                            gettext("The socket is fail to create, fails to send data."));
#endif
    }
    return FAIL;
}

/**
 * set the target address
 * @param ip
 * @param port
 * @return void
 */
void ATCCSDataSender::setTargetAddress(const std::string &ip, unsigned short port)
{
    if (_udpSocket == nullptr)
    {
        try
        {
            _udpSocket = std::make_shared<QPUdpSocket>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                gettext("The socket is fail to create, fails to set target address."), e.what());
#endif
            return;
        }
    }
    
    _udpSocket->setTargetAddress(ip, port);

}

void ATCCSDataSender::setTargetAddress(std::shared_ptr<ATCCSAddress> address)
{
    if (address)
    {
        setTargetAddress(address->ip(), address->port());
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("The address is null, fails to set target address."));        
#endif
    }
}
