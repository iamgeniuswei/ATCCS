/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSUpgoingDataProcessor.h
 * Author: lenovo
 *
 * Created on May 5, 2017, 10:34 PM
 */

#ifndef ATCCSUPGOINGDATAPROCESSOR_H
#define ATCCSUPGOINGDATAPROCESSOR_H
#include "atccsdataprocessor.h"
#include "atccsupgoingcontroller.h"
class ATCCSUpgoingController;
class ATCCSUpgoingDataProcessor : public ATCCSDataProcessor
{
public:
    ATCCSUpgoingDataProcessor(ATCCSUpgoingController *controller = nullptr);
    void processData(std::shared_ptr<ATCCSData> data) override;

private:
    ATCCSUpgoingController *_controller = nullptr;;

};

#endif /* ATCCSUPGOINGDATAPROCESSOR_H */

