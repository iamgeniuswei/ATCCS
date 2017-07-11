/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMESetting.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月27日, 下午2:35
 */

#include "emesetting.h"
#include "atccsaddress.h"
#include "atccsdbaddress.h"
#include <iostream>
#include "atccs_global.h"
#include "atccsexceptionhandler.h"


EMESetting::EMESetting(unsigned int emeNum)
    :_emeNum(emeNum)
{
}

EMESetting::~EMESetting()
{
}

bool EMESetting::initSysSetting()
{
    std::string xml = settingFilePath();
    std::shared_ptr<XMLDocument> doc = std::make_shared<XMLDocument>();
    if (doc)
    {
        if (doc->LoadFile(xml.c_str()) != XML_SUCCESS)
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::CUSTOMERROR, "%s%s",
                                                gettext("Fails to load setting file. The file is : "), xml.c_str());
#endif
            return false;
        }
            
        XMLElement *titleElement = doc->FirstChildElement("SETTING");
        if (titleElement)
        {
            return (initDBAddress(titleElement) && initHostAddress(titleElement));
        }
    }
    return false;
}

bool EMESetting::initDBAddress(XMLElement* element)
{
    if (element)
    {
        if (!_dbAddress)
        {
            try
            {
                _dbAddress = std::make_shared<ATCCSDBAddress>();
            }
            catch(std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                    gettext("Fails to create database address instance."), e.what());
#endif
                return false;
            }
        }

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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                                    gettext("The database's type is error."));
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                                    gettext("The database's ip is error."));
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                                    gettext("The database's port is error."));
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                                    gettext("The database's name is error."));
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                                    gettext("The database's username is error."));
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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                                    gettext("The database's password is error."));
#endif
                ret &= false;
            }
            return ret;
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                                gettext("Fails to initialize database address, The database's setting is error."));
#endif
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                            gettext("Fails to initialize database address, The system setting is error."));
#endif           
    }

    return false;
}

bool EMESetting::initHostAddress(XMLElement* element)
{
    if (element)
    {
        if (!_hostAddress)
        {
            try
            {
                _hostAddress = std::make_shared<ATCCSAddress>();
            }
            catch(std::exception &e)
            {
#ifdef OUTERRORINFO
                ATCCSExceptionHandler::addException(ATCCSException::STDEXCEPTION, "%s%s",
                                                    gettext("Fails to create host address instance.\n"), e.what());
#endif
                return false;                
            }
        }

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
                ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                                    gettext("The host's ip and port is error."));
#endif                    
            }
        }
        else
        {
#ifdef OUTERRORINFO
            ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL,"%s",
                                                gettext("Fails to initialize host address, the host's setting is error."));
#endif        
        }
    }
    else
    {
#ifdef OUTERRORINFO
        ATCCSExceptionHandler::addException(ATCCSException::POINTERISNULL, "%s",
                                            gettext("Fails to initialize host address, The system setting is error."));
#endif
    }

    return false;
}

unsigned int EMESetting::emeNum() const
{
    return _emeNum;
}




std::shared_ptr<ATCCSAddress> EMESetting::hostAddress() const
{
    return _hostAddress;
}

std::shared_ptr<ATCCSDBAddress> EMESetting::dbAddress() const
{
    return _dbAddress;
}

std::string EMESetting::settingFilePath()
{
    std::string xml = ATCCSSetting::settingFilePath();
    if(!xml.empty())
    {
        xml.append("/");
        xml.append("emecontroller.xml");
    }
    std::cout << xml << std::endl;
    return xml;
}




