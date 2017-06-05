/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSCCATController.h
 * Author: lenovo
 *
 * Created on May 12, 2017, 8:20 PM
 */

#ifndef ATCCSCCATCONTROLLER_H
#define ATCCSCCATCONTROLLER_H
#include "atccscontroller.h"
#include "ATCCLevel2DataProcessor.h"
class ATCCSDataSender;
class atccsoccupation;
class ATCCLevel2DataProcessor;
class ATCCATController : public ATCCSController
{
public:
    ATCCATController(unsigned int type);
    ATCCATController(const ATCCATController& orig);
    virtual ~ATCCATController();
    void handleControlData() override;
    unsigned int type() const;
    
public:
    int sendControlData(std::shared_ptr<ATCCSData> data = nullptr);
    void setATControllerAddress(const std::string &ip, unsigned short port);
    void setATOccupation(std::shared_ptr<ATCCSData> data = nullptr);
    void setATOccupation(UINT32 user = 0,
                            unsigned short at = 0,
                            unsigned short occupation = 0,
                            UINT32 start = 0,
                            UINT32 end = 0,
                            UINT32 priority = 0);
    bool canSendControlData(UINT32 user) const;
    
private:
    unsigned int persistOcuupation();
    bool canPreempt() const;

private:
    unsigned int _type = 0;
    std::shared_ptr<ATCCSDataSender> _sender = nullptr;
    std::shared_ptr<ATCCLevel2DataProcessor> _dataProcessor = nullptr;
    atccsoccupation *_atOccupation = nullptr;
};

#endif /* ATCCSCCATCONTROLLER_H */

