/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at80gimbalstatus.h
 * Author: lenovo
 *
 * Created on September 12, 2017, 1:44 PM
 */

#ifndef AT80GIMBALSTATUS_H
#define AT80GIMBALSTATUS_H
#include "atccsgimbalstatus.h"

#pragma db object
class at80gimbalstatus : public atccsgimbalstatus
{
public:
    at80gimbalstatus();
    at80gimbalstatus(const at80gimbalstatus& orig) = delete;
    at80gimbalstatus(const at80gimbalstatus&& orig) = delete;
    at80gimbalstatus& operator=(const at80gimbalstatus& orig) = delete;
    at80gimbalstatus& operator=(const at80gimbalstatus&& orig) = delete;
    virtual ~at80gimbalstatus();
    unsigned long long persistStatus() override;


protected:

private:

};

#endif /* AT80GIMBALSTATUS_H */

