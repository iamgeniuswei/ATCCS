/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60GimbalController.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 11:00 AM
 */

#ifndef AT60GIMBALCONTROLLER_H
#define AT60GIMBALCONTROLLER_H
#include "atccsgimbalcontroller.h"
#include "atccs_global.h"
class ATCCSData;
class AT60GimbalController : public ATCCSGimbalController
{
public:
    AT60GimbalController();
    virtual ~AT60GimbalController();    
protected:
    std::shared_ptr<atccspublicstatus> statusInstance() override;
    std::shared_ptr<atccsinstruction> instructionInstance() override;
};

#endif /* AT60GIMBALCONTROLLER_H */

