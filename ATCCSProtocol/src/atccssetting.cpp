/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSSetting.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月27日, 下午2:44
 */

#include "atccssetting.h"
#include <string.h>
#ifdef WIN32
#else
#include <unistd.h>
#endif

ATCCSSetting::ATCCSSetting()
{
}

std::string ATCCSSetting::settingFilePath()
{
    std::string xml;
    char pwd[2048];
    memset(pwd, 0, 2048);
#ifdef WIN32
#else
    if(getcwd(pwd, 1024))
    {
        xml.assign(pwd);     
    }
#endif
    return xml;
}


