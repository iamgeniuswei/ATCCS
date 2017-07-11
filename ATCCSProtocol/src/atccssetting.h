/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSSetting.h
 * Author: lenovo
 *
 * Created on 2017年6月27日, 下午2:44
 */

#ifndef ATCCSSETTING_H
#define ATCCSSETTING_H

#include <string>


class ATCCSSetting
{
public:
    ATCCSSetting();
    ATCCSSetting(const ATCCSSetting& orig) = delete;
    ATCCSSetting(const ATCCSSetting&& orig) = delete;
    ATCCSSetting& operator=(const ATCCSSetting& orig) = delete;
    ATCCSSetting& operator=(const ATCCSSetting&& orig) = delete;
    virtual ~ATCCSSetting(){};
    virtual std::string settingFilePath();
    virtual bool initSysSetting() = 0;

protected:

private:

};

#endif /* ATCCSSETTING_H */

