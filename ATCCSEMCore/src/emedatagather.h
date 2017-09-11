/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMEDataGather.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 下午4:08
 */

#ifndef EMEDATAGATHER_H
#define EMEDATAGATHER_H
#include "atccscontroller.h"
#include "atccsthread.h"
#include <memory>
#include "atccs_public_define.h"
class emerealtimedata;
class EMEDataGather : public ATCCSController, public ATCCSThread
{
public:
    EMEDataGather(unsigned int type);
    EMEDataGather(const EMEDataGather& orig) = delete;
    EMEDataGather(const EMEDataGather&& orig) = delete;
    EMEDataGather& operator=(const EMEDataGather& orig) = delete;
    EMEDataGather& operator=(const EMEDataGather&& orig) = delete;
    virtual ~EMEDataGather();

    unsigned int type() const
    {
        return _type;
    }
    
    std::string device() 
    {
        switch(_type)
        {
            case ASC:
                return "ASC.\n";                
            case WS:
                return "WS.\n";
            case CS:
                return "CS.\n";
            case SQM:
                return "SQM.\n";
            case DUST:
                return "DUST.\n";
            case DIMM:
                return "DIMM.\n";
            default:
                return "unknown.\n";
        }
    }
    
    void run() override;


    
    
private:
    std::shared_ptr<emerealtimedata> realtimeData();
    unsigned long long resolveRealtimeData(std::shared_ptr<ATCCSData> data = nullptr);

private:
    unsigned int _type = 0;
    std::shared_ptr<emerealtimedata> _realtimeData = nullptr;
};

#endif /* EMEDATAGATHER_H */

