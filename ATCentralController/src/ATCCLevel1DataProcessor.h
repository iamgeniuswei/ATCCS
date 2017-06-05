/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSLevel1DataProcessor.h
 * Author: lenovo
 *
 * Created on May 12, 2017, 7:59 PM
 */

#ifndef ATCCSLEVEL1DATAPROCESSOR_H
#define ATCCSLEVEL1DATAPROCESSOR_H
#include "atccsdataprocessor.h"
class ATCCSDataDispatcher;
class ATCCSCCLevel1DataProcessor : public ATCCSDataProcessor
{
public:
    ATCCSCCLevel1DataProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher = nullptr);
    ATCCSCCLevel1DataProcessor(const ATCCSCCLevel1DataProcessor& orig) = delete;
    ATCCSCCLevel1DataProcessor& operator=(const ATCCSCCLevel1DataProcessor& orit) = delete;
    virtual ~ATCCSCCLevel1DataProcessor();
    virtual void processData(std::shared_ptr<ATCCSData> data);

private:
    std::shared_ptr<ATCCSDataDispatcher> _dispathcer = nullptr;

};

#endif /* ATCCSLEVEL1DATAPROCESSOR_H */

