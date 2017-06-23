/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月22日, 下午4:29
 */

#ifndef CSREALTIMEDATA_H
#define CSREALTIMEDATA_H
#include "emerealtimedata.h"

#pragma db object
class csrealtimedata : public emerealtimedata
{
public:
    csrealtimedata();
    csrealtimedata(const csrealtimedata& orig) = delete;
    csrealtimedata(const csrealtimedata&& orig) = delete;
    csrealtimedata& operator=(const csrealtimedata& orig) = delete;
    csrealtimedata& operator=(const csrealtimedata&& orig) = delete;
    virtual ~csrealtimedata();
    unsigned long long persistRealtimeData() override;
    unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data) override;



protected:

public:
    friend class odb::access;
    double _RelSkyT = 0;
    double _AmbientT = 0;
    double _SensorT = 0;
    unsigned short _RainF = 0;
    unsigned short _RainThreshV = 0;
    double _wind = 0;
    unsigned short _WindUnits = 0;
    double _HumidityPercent = 0;
    double _DewPointT = 0;
    double _DayLightV = 0;
};

#endif /* CSREALTIMEDATA_H */

