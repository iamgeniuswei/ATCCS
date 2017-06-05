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
#include "atccsmapmanager.h"
#include "atccs_global.h"
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
    ATCCSMapManager<ATCCSAddress> _deviceAddresses;
    
public:
    static AT60Setting *instance();
    bool initSystemSetting(const std::string &xmlpath);
    virtual ~AT60Setting();
    void setHostAddress(std::shared_ptr<ATCCSAddress> _hostAddress);
    std::shared_ptr<ATCCSAddress> hostAddress() const;
    void setDeviceAddress(unsigned int device, std::shared_ptr<ATCCSAddress> dveiceAddress);
    void setDeviceAddress(unsigned int device, const std::string& ip, unsigned short port);
    std::shared_ptr<ATCCSAddress> deviceAddress(unsigned int device) const;
};

#endif /* AT60SETTING_H */

