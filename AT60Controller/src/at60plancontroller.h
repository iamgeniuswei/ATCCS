/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AT60PlanController.h
 * Author: lenovo
 *
 * Created on June 8, 2017, 3:09 PM
 */

#ifndef AT60PLANCONTROLLER_H
#define AT60PLANCONTROLLER_H

#include "atccsplanperformer.h"

class AT60PlanController : public ATCCSPlanPerformer
{
public:
    AT60PlanController();
    virtual ~AT60PlanController();
protected:
    std::shared_ptr<atccsplan> executoryPlanInstance() override;
    bool isRelatedDevicesReady() override;
};

#endif /* AT60PLANCONTROLLER_H */

