/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60FilterController.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 7:06 PM
 */

#ifndef AT60FILTERCONTROLLER_H
#define AT60FILTERCONTROLLER_H
#include "atccsfiltercontroller.h"

class AT60FilterController : public ATCCSFilterController
{
public:
    AT60FilterController();
    virtual ~AT60FilterController();

protected:
    std::shared_ptr<atccsinstruction> instructionInstance() override;
    std::shared_ptr<atccspublicstatus> statusInstance() override;
};

#endif /* AT60FILTERCONTROLLER_H */

