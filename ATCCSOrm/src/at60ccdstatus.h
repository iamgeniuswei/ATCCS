/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60ccdstatus.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 9:19 AM
 */

#ifndef AT60CCDSTATUS_H
#define AT60CCDSTATUS_H
#include "atccsccdstatus.h"
#pragma db object
class at60ccdstatus : public atccsccdstatus
{
public:
    at60ccdstatus();
    at60ccdstatus(const at60ccdstatus& orig);
    virtual ~at60ccdstatus();
    unsigned long long persistStatus() override;

private:
    

};

#endif /* AT60CCDSTATUS_H */

