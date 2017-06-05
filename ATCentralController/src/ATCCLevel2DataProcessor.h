/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCLevel2DataProcessor.h
 * Author: lenovo
 *
 * Created on May 12, 2017, 8:41 PM
 */

#ifndef ATCCLEVEL2DATAPROCESSOR_H
#define ATCCLEVEL2DATAPROCESSOR_H
#include "atccsdataprocessor.h"
#include "ATCCATController.h"
class ATCCATController;
class ATCCLevel2DataProcessor : public ATCCSDataProcessor
{
public:
    ATCCLevel2DataProcessor(ATCCATController *controller = nullptr);
    ATCCLevel2DataProcessor(const ATCCLevel2DataProcessor& orig);
    virtual ~ATCCLevel2DataProcessor();
    void processData(std::shared_ptr<ATCCSData> data) override;

private:
    ATCCATController *_controller;
};

#endif /* ATCCLEVEL2DATAPROCESSOR_H */

