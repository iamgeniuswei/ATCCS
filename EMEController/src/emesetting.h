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
#include "atccssetting.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class ATCCSDBAddress;
class ATCCSAddress;

class EMESetting : public ATCCSSetting
{
public:
    EMESetting(unsigned int emeNum = 0);
    EMESetting(const EMESetting& orig) = delete;
    EMESetting(const EMESetting&& orig) = delete;
    EMESetting& operator=(const EMESetting& orig) = delete;
    EMESetting& operator=(const EMESetting&& orig) = delete;
    virtual ~EMESetting();
    
    bool initSysSetting() override;
    std::shared_ptr<ATCCSAddress> hostAddress() const;
    std::shared_ptr<ATCCSDBAddress> dbAddress() const;
    unsigned int emeNum() const;

protected:
    std::string settingFilePath() override;
    bool initDBAddress(XMLElement* element = nullptr);
    bool initHostAddress(XMLElement* element = nullptr);
    


private:
    std::shared_ptr<ATCCSDBAddress> _dbAddress = nullptr;
    std::shared_ptr<ATCCSAddress> _hostAddress = nullptr;
    unsigned int _emeNum = 0;
};

#endif /* EMESETTING_H */

