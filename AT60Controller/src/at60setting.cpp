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

#include "at60setting.h"
#include "atccsaddress.h"
#include "atccsdbaddress.h"
#include "atccs_public_define.h"
#include "tinyxml2.h"
using namespace tinyxml2;
AT60Setting *AT60Setting::_instance = nullptr;
AT60Setting::AT60SettingGarbo AT60Setting::_Garbo;
AT60Setting::AT60Setting()
{
    _dbAddress = std::make_shared<ATCCSDBAddress>();
    _hostAddress = std::make_shared<ATCCSAddress>();
}


AT60Setting::~AT60Setting() 
{
}

AT60Setting* AT60Setting::instance() 
{
    if(_instance == nullptr)
        _instance = new AT60Setting;
    return _instance;
}


bool AT60Setting::initSystemSetting(const std::string &xmlpath) 
{
    std::shared_ptr<XMLDocument> doc(new XMLDocument);
    if(doc)
    {
        if(doc->LoadFile(xmlpath.c_str()) != XML_SUCCESS)
            return false;
        XMLElement *titleElement = doc->FirstChildElement("SETTING");
        if(titleElement)
        {
            XMLElement *dbElement = titleElement->FirstChildElement("DATABASE");
            if(dbElement)
            {
                const char *attr = dbElement->Attribute("type");
                if(attr)
                {
                    _dbAddress->setType(attr);
                }
                XMLElement *ip = dbElement->FirstChildElement("ip");
                if(ip)
                {
                    _dbAddress->setIp(ip->GetText());
                }
                XMLElement *port = dbElement->FirstChildElement("port");
                if(port)
                {
                    _dbAddress->setPort(atoi(port->GetText()));
                }
                XMLElement *db = dbElement->FirstChildElement("db");
                if(db)
                {
                    _dbAddress->setDb(db->GetText());
                }
                XMLElement *user = dbElement->FirstChildElement("user");
                if(user)
                {
                    _dbAddress->setUser(user->GetText());
                }
                XMLElement *pwd = dbElement->FirstChildElement("password1");
                if(pwd)
                {
                    _dbAddress->setPassword(pwd->GetText());
                }
            }
            XMLElement *drElement = titleElement->FirstChildElement("DATARECEIVER");
            if(drElement)
            {
                
                XMLElement *ip = drElement->FirstChildElement("ip");
                XMLElement *port = drElement->FirstChildElement("port");
                if(ip && port)
                {
                    _hostAddress->setAddress(ip->GetText(), atoi(port->GetText()));
                }                    
            }
            XMLElement *dcElement = titleElement->FirstChildElement("DEVICECONTROLLER");
            if(dcElement)
            {
                XMLElement *deviceElement = dcElement->FirstChildElement("device");
                while(deviceElement)
                {
                    const char *attr = deviceElement->Attribute("type");
                    XMLElement *ip = drElement->FirstChildElement("ip");
                    XMLElement *port = drElement->FirstChildElement("port");
                    if(ip && port)
                    {
                        std::shared_ptr<ATCCSAddress> address(new ATCCSAddress(ip->GetText(), atoi(port->GetText())));
                        if(strcmp(attr,"GIMBAL") == 0)
                            _deviceAddresses.registerController(GIMBAL, address);
                        else if(strcmp(attr,"CCD") == 0)
                            _deviceAddresses.registerController(CCD, address);
                        else if(strcmp(attr,"FILTER") == 0)
                            _deviceAddresses.registerController(FILTER, address);
                        else if(strcmp(attr,"FOCUS") == 0)
                            _deviceAddresses.registerController(FOCUS, address);
                        else if(strcmp(attr,"SLAVEDOME") == 0)
                            _deviceAddresses.registerController(SLAVEDOME, address);
                        else if(strcmp(attr,"FULLOPENEDDOME") == 0)
                            _deviceAddresses.registerController(FULLOPENEDDOME, address);
                    }
                    deviceElement = deviceElement->NextSiblingElement("device");
                }
            }
        }
    }
    
    return true;
}


void AT60Setting::setHostAddress(std::shared_ptr<ATCCSAddress> _hostAddress) {
    this->_hostAddress = _hostAddress;
}

std::shared_ptr<ATCCSAddress> AT60Setting::hostAddress() const {
    return _hostAddress;
}

void AT60Setting::setDeviceAddress(unsigned int device, std::shared_ptr<ATCCSAddress> deviceAddress)
{
//    if(deviceAddress == nullptr)
//        return;
//    auto search = _deviceAddresses.find(device);
//    if(search != _deviceAddresses.end())
//        return;
//    _deviceAddresses.insert(std::pair<unsigned int, std::shared_ptr<ATCCSAddress>>(device, deviceAddress));
}

void AT60Setting::setDeviceAddress(unsigned int device, const std::string& ip, unsigned short port)
{
//    if(ip.size() == 0 || port == 0)
//        return;
//    auto search = _deviceAddresses.find(device);
//    if(search != _deviceAddresses.end())
//        return;
//    std::shared_ptr<ATCCSAddress> deviceAddress(new ATCCSAddress(ip, port));    
//    _deviceAddresses.insert(std::pair<unsigned int, std::shared_ptr<ATCCSAddress>>(device, deviceAddress));
}

std::shared_ptr<ATCCSAddress> AT60Setting::deviceAddress(unsigned int device) const
{
    return nullptr;
//    auto search = _deviceAddresses.find(device);
//    if(search == _deviceAddresses.end())
//        return nullptr;
//    std::shared_ptr<ATCCSAddress> temp = search->second;
//    return temp;            
}