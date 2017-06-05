/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60CCDController.h
 * Author: lenovo
 *
 * Created on May 14, 2017, 11:05 AM
 */

#ifndef AT60CCDCONTROLLER_H
#define AT60CCDCONTROLLER_H
#include "atccsccdcontroller.h"

class AT60CCDController : public ATCCSCCDController
{
public:
    AT60CCDController();
    virtual ~AT60CCDController();
protected:
    std::shared_ptr<atccsinstruction> instructionInstance() override;
    std::shared_ptr<atccspublicstatus> statusInstance() override;
};

#endif /* AT60CCDCONTROLLER_H */

