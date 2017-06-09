/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60Setting.cpp
 * Author: lenovo
 * 
 * Created on May 6, 2017, 4:58 PM
 */

#include <stdbool.h>

#include "at60setting.h"
#include "atccsaddress.h"
#include "atccsdbaddress.h"
#include "atccs_public_define.h"
#include "atccsexceptionhandler.h"
#ifdef WIN32
#else
#include <unistd.h>
#endif
AT60Setting *AT60Setting::_instance = nullptr;
AT60Setting::AT60SettingGarbo AT60Setting::_Garbo;

AT60Setting::AT60Setting()
{

}

AT60Setting::~AT60Setting()
{
}

AT60Setting* AT60Setting::instance()
{
    if (_instance == nullptr)
        _instance = new AT60Setting;
    return _instance;
}

bool AT60Setting::initDBAddress(XMLElement * element)
{
    if (element)
    {
        if (_dbAddress == nullptr)
            _dbAddress = dbAddressInstance();
        if (_dbAddress)
        {
            XMLElement *dbElement = element->FirstChildElement("DATABASE");
            if (dbElement)
            {
                bool ret = true;
                const char *attr = dbElement->Attribute("type");
                if (attr)
                {
                    _dbAddress->setType(attr);
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                            __FILE__, __func__, __LINE__, "");
#endif
                    ret &= false;
                }

                XMLElement *ip = dbElement->FirstChildElement("ip");
                if (ip)
                {
                    _dbAddress->setIp(ip->GetText());
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                            __FILE__, __func__, __LINE__, "");
#endif
                    ret &= false;
                }

                XMLElement *port = dbElement->FirstChildElement("port");
                if (port)
                {
                    _dbAddress->setPort(atoi(port->GetText()));
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                            __FILE__, __func__, __LINE__, "");
#endif
                    ret &= false;
                }

                XMLElement *db = dbElement->FirstChildElement("db");
                if (db)
                {
                    _dbAddress->setDb(db->GetText());
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                            __FILE__, __func__, __LINE__, "");
#endif
                    ret &= false;
                }

                XMLElement *user = dbElement->FirstChildElement("user");
                if (user)
                {
                    _dbAddress->setUser(user->GetText());
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                            __FILE__, __func__, __LINE__, "");
#endif
                    ret &= false;
                }

                XMLElement *pwd = dbElement->FirstChildElement("password");
                if (pwd)
                {
                    _dbAddress->setPassword(pwd->GetText());
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                            __FILE__, __func__, __LINE__, "");
#endif
                    ret &= false;
                }
                return ret;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                        __FILE__, __func__, __LINE__, "");
#endif
            }
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                    __FILE__, __func__, __LINE__, "");
#endif           
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                __FILE__, __func__, __LINE__, "");
#endif        
    }
    return false;
}

bool AT60Setting::initHostAddress(XMLElement * element /* = nullptr */)
{
    if (element)
    {
        if (_hostAddress == nullptr)
            _hostAddress = hostAddressInstance();
        if (_hostAddress)
        {
            XMLElement *drElement = element->FirstChildElement("DATARECEIVER");

            if (drElement)
            {                
                XMLElement *ip = drElement->FirstChildElement("ip");
                XMLElement *port = drElement->FirstChildElement("port");
                if (ip && port)
                {
                    _hostAddress->setAddress(ip->GetText(), atoi(port->GetText()));
                    return true;
                }
                else
                {
#ifdef OUTERRORINFO
                    ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                        __FILE__, __func__, __LINE__, "");
#endif                    
                }                
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                        __FILE__, __func__, __LINE__, "");
#endif        
            }
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                        __FILE__, __func__, __LINE__, "");
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                    __FILE__, __func__, __LINE__, "");
#endif
    }
    return false;
}

bool AT60Setting::initDeviceAddresses(XMLElement* element)
{
    if (element)
    {
        if (_deviceAddresses == nullptr)
            _deviceAddresses = deviceAddressesInstance();
        if (_deviceAddresses)
        {
            XMLElement *dcElement = element->FirstChildElement("DEVICECONTROLLER");
            if (dcElement)
            {
                bool ret = true;
                XMLElement *deviceElement = dcElement->FirstChildElement("device");
                while (deviceElement)
                {
                    const char *attr = deviceElement->Attribute("type");
                    XMLElement *ip = deviceElement->FirstChildElement("ip");
                    XMLElement *port = deviceElement->FirstChildElement("port");
                    if (attr && ip && port)
                    {
                        std::shared_ptr<ATCCSAddress> address(new ATCCSAddress(ip->GetText(), atoi(port->GetText())));
                        if (strcmp(attr, "GIMBAL") == 0)
                            _deviceAddresses->registerController(GIMBAL, address);
                        else if (strcmp(attr, "CCD") == 0)
                            _deviceAddresses->registerController(CCD, address);
                        else if (strcmp(attr, "FILTER") == 0)
                            _deviceAddresses->registerController(FILTER, address);
                        else if (strcmp(attr, "FOCUS") == 0)
                            _deviceAddresses->registerController(FOCUS, address);
                        else if (strcmp(attr, "SLAVEDOME") == 0)
                            _deviceAddresses->registerController(SLAVEDOME, address);
                        else if (strcmp(attr, "FULLOPENEDDOME") == 0)
                            _deviceAddresses->registerController(FULLOPENEDDOME, address);
                    }
                    else
                    {
#ifdef OUTERRORINFO
                        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                                __FILE__, __func__, __LINE__, "");
#endif                        
                        ret &= false;
                    }
                    deviceElement = deviceElement->NextSiblingElement("device");
                }
                return ret;
            }
            else
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                        __FILE__, __func__, __LINE__, "");
#endif                
            }
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                    __FILE__, __func__, __LINE__, "");
#endif
        }        
    }
    else
    {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                        __FILE__, __func__, __LINE__, "");
#endif        
    }
    return false;
}

std::string AT60Setting::xmlPath()
{
    std::string xml;
    char pwd[2048];
    memset(pwd, 0, 2048);
#ifdef WIN32
#else
    if(getcwd(pwd, 1024))
    {
        xml.assign(pwd);
        xml.append("/");
        xml.append("at60setting.xml");        
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                            __FILE__, __func__, __LINE__,
                                            "Can not get configuration file's path");
#endif
    }
#endif
    return xml;
}



bool AT60Setting::initSystemSetting()
{
    std::string xml(xmlPath());
    std::shared_ptr<XMLDocument> doc = std::make_shared<XMLDocument>();
    if (doc)
    {
        if (doc->LoadFile(xml.c_str()) != XML_SUCCESS)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMEXCEPTION,
                                                __FILE__, __func__, __LINE__, "");
#endif
            return false;
        }
            
        XMLElement *titleElement = doc->FirstChildElement("SETTING");
        if (titleElement)
        {
            initDBAddress(titleElement);
            initHostAddress(titleElement);
            initDeviceAddresses(titleElement);
        }
    }
    return true;
}

void AT60Setting::setHostAddress(std::shared_ptr<ATCCSAddress> _hostAddress)
{
    this->_hostAddress = _hostAddress;
}

std::shared_ptr<ATCCSAddress> AT60Setting::hostAddress() const
{
    return _hostAddress;
}

std::shared_ptr<ATCCSDBAddress> AT60Setting::dbAddress() const
{
    return _dbAddress;
}


std::shared_ptr<ATCCSMapManager<ATCCSAddress> > AT60Setting::deviceAddressesInstance()
{
    try
    {
        _deviceAddresses = std::make_shared<ATCCSMapManager < ATCCSAddress >> ();
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return _deviceAddresses;
}

std::shared_ptr<ATCCSAddress> AT60Setting::hostAddressInstance()
{
    try
    {
        _hostAddress = std::make_shared<ATCCSAddress>();
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                __FILE__, __func__, __LINE__, e.what());
#endif        
    }
    return _hostAddress;
}

std::shared_ptr<ATCCSDBAddress> AT60Setting::dbAddressInstance()
{
    try
    {
        _dbAddress = std::make_shared<ATCCSDBAddress>();
    }
    catch (std::exception &e)
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION,
                __FILE__, __func__, __LINE__, e.what());
#endif
    }
    return _dbAddress;
}

std::shared_ptr<ATCCSAddress> AT60Setting::deviceAddress(unsigned int device) const
{
    if (_deviceAddresses)
    {
        return _deviceAddresses->controller(device);
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,
                __FILE__, __func__, __LINE__, "");
#endif 
    }
    return nullptr;
}