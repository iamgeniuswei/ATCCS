/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60plan.h
 * Author: lenovo
 *
 * Created on May 15, 2017, 5:06 PM
 */

#ifndef AT60PLAN_H
#define AT60PLAN_H
#include "atccsplan.h"
#pragma db object
class at60plan : public atccsplan
{
public:
    at60plan();
    at60plan(const at60plan& orig);
    ~at60plan(){}
    unsigned int persistPlan() override;
};

#endif /* AT60PLAN_H */

