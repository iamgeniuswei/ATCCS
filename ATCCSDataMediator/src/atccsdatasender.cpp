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
#ifdef OUTDEBUGINFO
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
    if (_udpSocket)
        return _udpSocket->sendData(data->data(), data->size());
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "QPUdpSocket instance is null, send data fails.");
#endif
    }
    return -1;
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
    if (_udpSocket == nullptr)
    {
        try
        {
            _udpSocket = std::make_shared<QPUdpSocket>();
        }
        catch (std::exception &e)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                                                __FILE__, __func__, __LINE__, e.what());
#endif
            return;
        }
    }
    if (_udpSocket)
        _udpSocket->setTargetAddress(ip, port);
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "QPUdpSocket instance is null, set Target Address fails.");
#endif        
    }
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
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                            __FILE__, __func__, __LINE__,
                                            "ATCCSAddress instance is null, set Target Address fails.");        
#endif
    }
}
