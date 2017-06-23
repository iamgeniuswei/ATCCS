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
//class emerealtimedata;
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
    
    void run() override;


protected:
//    std::shared_ptr<emerealtimedata> realtimeData();

private:
    unsigned int _type = 0;
//    std::shared_ptr<emerealtimedata> _realtimeData = nullptr;

};

#endif /* EMEDATAGATHER_H */

