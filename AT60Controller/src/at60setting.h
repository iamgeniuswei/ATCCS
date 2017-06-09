/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60Setting.h
 * Author: lenovo
 *
 * Created on May 6, 2017, 4:58 PM
 */

#ifndef AT60SETTING_H
#define AT60SETTING_H
#include <map>
#include <memory>
#include <limits.h>
#include "atccsmapmanager.h"
#include "atccs_global.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class ATCCSAddress;
class ATCCSDBAddress;

class AT60Setting {
private:
    explicit AT60Setting();
    AT60Setting(const AT60Setting& orig) = delete;
    AT60Setting& operator=(const AT60Setting&) = delete;
    AT60Setting(AT60Setting &&) = delete;   
    static AT60Setting *_instance;
    class AT60SettingGarbo
    {
    public:
        ~AT60SettingGarbo()
        {
            if(_instance != nullptr)
            {
                delete _instance;
                _instance = nullptr;
            }
        }
    };
    static AT60SettingGarbo _Garbo;
    
private:
    std::shared_ptr<ATCCSAddress> _hostAddress = nullptr;
    std::shared_ptr<ATCCSDBAddress> _dbAddress = nullptr;
    std::shared_ptr<ATCCSMapManager<ATCCSAddress>> _deviceAddresses = nullptr;
    
    std::shared_ptr<ATCCSMapManager<ATCCSAddress>> deviceAddressesInstance();
    std::shared_ptr<ATCCSAddress> hostAddressInstance();
    std::shared_ptr<ATCCSDBAddress> dbAddressInstance();
    
    bool initDBAddress(XMLElement *element = nullptr);
    bool initHostAddress(XMLElement *element = nullptr);    
    bool initDeviceAddresses(XMLElement *element = nullptr);
    std::string xmlPath();
    
public:
    virtual ~AT60Setting();
    static AT60Setting *instance();
    
    bool initSystemSetting();    
    void setHostAddress(std::shared_ptr<ATCCSAddress> _hostAddress);
    
    std::shared_ptr<ATCCSAddress> hostAddress() const;
    std::shared_ptr<ATCCSDBAddress> dbAddress() const;
    std::shared_ptr<ATCCSAddress> deviceAddress(unsigned int device) const;
};

#endif /* AT60SETTING_H */

