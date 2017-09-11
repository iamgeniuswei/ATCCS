/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMESetting.h
 * Author: lenovo
 *
 * Created on 2017年6月27日, 下午2:35
 */

#ifndef EMESETTING_H
#define EMESETTING_H
#include <memory>
#include <mutex>
#include "atccssetting.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class ATCCSDBAddress;
class ATCCSAddress;

class EMSetting : public ATCCSSetting
{
public:
    EMSetting(unsigned int emeNum = 0);
    EMSetting(const EMSetting& orig) = delete;
    EMSetting(const EMSetting&& orig) = delete;
    EMSetting& operator=(const EMSetting& orig) = delete;
    EMSetting& operator=(const EMSetting&& orig) = delete;
    virtual ~EMSetting();
    void setEMCount(unsigned int _emCount);
    unsigned int emCount() const;
    static EMSetting* instance();
    bool initSysSetting() override;
    void setHostAddress(const std::string& ip, unsigned short port);
    void setHostIP(const std::string& ip);
    void setHostPort(unsigned short port);
    void setDBAddress(const std::string& type, 
                        const std::string& user,
                        const std::string& password,
                        const std::string& db,
                        const std::string& ip,
                        unsigned short port);
    std::shared_ptr<ATCCSAddress> hostAddress() const;
    std::shared_ptr<ATCCSDBAddress> dbAddress() const;
    

protected:
    bool initDBAddress(XMLElement* element = nullptr);
    bool initHostAddress(XMLElement* element = nullptr);
    


private:
    static EMSetting *_instance;
    static std::mutex _instanceLock;
    std::shared_ptr<ATCCSDBAddress> _dbAddress = nullptr;
    std::shared_ptr<ATCCSAddress> _hostAddress = nullptr;
    unsigned int _emCount = 0;
};

#endif /* EMESETTING_H */

