/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMEDataDispatcherProcessor.h
 * Author: lenovo
 *
 * Created on June 27, 2017, 4:21 PM
 */

#ifndef EMEDATADISPATCHERPROCESSOR_H
#define EMEDATADISPATCHERPROCESSOR_H
#include "atccsdataprocessor.h"
class ATCCSData;
class ATCCSDataDispatcher;
class EMEDataDispatcherProcessor : public ATCCSDataProcessor
{
public:
    EMEDataDispatcherProcessor(std::shared_ptr<ATCCSDataDispatcher> dispatcher = nullptr);
    EMEDataDispatcherProcessor(const EMEDataDispatcherProcessor& orig) = delete;
    EMEDataDispatcherProcessor(const EMEDataDispatcherProcessor&& orig) = delete;
    EMEDataDispatcherProcessor& operator=(const EMEDataDispatcherProcessor& orig) = delete;
    EMEDataDispatcherProcessor& operator=(const EMEDataDispatcherProcessor&& orig) = delete;
    void processData(std::shared_ptr<ATCCSData> data = nullptr) override;
private:
    ATCCSDataDispatcher *_dispatcher = nullptr;

};

#endif /* EMEDATADISPATCHERPROCESSOR_H */

