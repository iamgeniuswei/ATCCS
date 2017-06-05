/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60SlaveDomeController.h
 * Author: lenovo
 *
 * Created on May 16, 2017, 7:13 PM
 */

#ifndef AT60SLAVEDOMECONTROLLER_H
#define AT60SLAVEDOMECONTROLLER_H

#include "atccsslavedomecontroller.h"

class AT60SlaveDomeController : public ATCCSSlaveDomeController
{
public:
    AT60SlaveDomeController();
    virtual ~AT60SlaveDomeController();

protected:
    std::shared_ptr<atccsinstruction> instructionInstance() override;
    std::shared_ptr<atccspublicstatus> statusInstance() override;
};

#endif /* AT60SLAVEDOMECONTROLLER_H */

