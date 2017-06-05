/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60GimbalStatus.h
 * Author: lenovo
 *
 * Created on May 8, 2017, 4:16 PM
 */

#ifndef AT60GIMBALSTATUS_H
#define AT60GIMBALSTATUS_H
#include "atccsgimbalstatus.h"
#pragma db object
class at60gimbalstatus : public atccsgimbalstatus
{
public:
    at60gimbalstatus();
    at60gimbalstatus(const at60gimbalstatus& orig);
    virtual ~at60gimbalstatus();
    unsigned long long persistStatus() override;

};

#endif /* AT60GIMBALSTATUS_H */

