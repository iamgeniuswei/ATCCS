/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dustrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午10:39
 */

#ifndef DUSTREALTIMEDATA_H
#define DUSTREALTIMEDATA_H
#include <odb/exceptions.hxx>

#include "emerealtimedata.h"
#pragma db object
class dustrealtimedata : public emerealtimedata
{
public:
    dustrealtimedata();
    dustrealtimedata(const dustrealtimedata& orig) = delete;
    dustrealtimedata(const dustrealtimedata&& orig) = delete;
    dustrealtimedata& operator=(const dustrealtimedata& orig) = delete;
    dustrealtimedata& operator=(const dustrealtimedata&& orig) = delete;
    virtual ~dustrealtimedata();
    unsigned long long persistRealtimeData() override;
    unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data) override;



protected:

public:
    friend class odb::access;
    double _dustdata = 0;

};

#endif /* DUSTREALTIMEDATA_H */

