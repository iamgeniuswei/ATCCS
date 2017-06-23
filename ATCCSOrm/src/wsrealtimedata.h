/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wsrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月22日, 下午4:00
 */

#ifndef WSREALTIMEDATA_H
#define WSREALTIMEDATA_H
#include "emerealtimedata.h"

#pragma db object
class wsrealtimedata : public emerealtimedata
{
public:
    wsrealtimedata();
    wsrealtimedata(const wsrealtimedata& orig) = delete;
    wsrealtimedata(const wsrealtimedata&& orig) = delete;
    wsrealtimedata& operator=(const wsrealtimedata& orig) = delete;
    wsrealtimedata& operator=(const wsrealtimedata&& orig) = delete;
    virtual ~wsrealtimedata();
    unsigned long long persistRealtimeData() override;
    unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data) override;   

protected:

public:
    friend class odb::access;
    double _temperature = 0;
    double _humidity = 0;
    double _dewpoint = 0;
    double _pressure = 0;
    double _windspeed = 0;
    double _windspeed2 = 0;
    double _windspeed10 = 0;
    unsigned int _windderection = 0;
    double _rainfall = 0;
    double _raidation = 0;
    double _illumination = 0;

};

#endif /* WSREALTIMEDATA_H */

