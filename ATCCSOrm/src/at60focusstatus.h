/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60focusstatus.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 9:56 AM
 */

#ifndef AT60FOCUSSTATUS_H
#define AT60FOCUSSTATUS_H
#include "atccsfocusstatus.h"

#pragma db object
class at60focusstatus : public atccsfocusstatus
{
public:
    at60focusstatus();
    at60focusstatus(const at60focusstatus& orig);
    virtual ~at60focusstatus();
    unsigned long long persistStatus() override;

private:

};

#endif /* AT60FOCUSSTATUS_H */

