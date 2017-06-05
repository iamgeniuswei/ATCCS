/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60FocusController.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 7:08 PM
 */

#ifndef AT60FOCUSCONTROLLER_H
#define AT60FOCUSCONTROLLER_H
#include "atccsfocuscontroller.h"
class AT60FocusController : public ATCCSFocusController
{
public:
    AT60FocusController();
    virtual ~AT60FocusController();

protected:
    std::shared_ptr<atccsinstruction> instructionInstance() override;
    std::shared_ptr<atccspublicstatus> statusInstance() override;


};

#endif /* AT60FOCUSCONTROLLER_H */

