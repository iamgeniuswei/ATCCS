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


/**
 * @brief wsrealtimedata is a persistence class which encapsulates the 
 * weather station real-time data.
 * @modified 2017-07-26
 * @description 
 * 1) two member-data's name is modified.
 * 2) recompile the header file by odb complier with --schema-name wsrealtimedata
 * 
 */
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
    unsigned int _winddirection = 0;
    double _rainfall = 0;
    double _radiation = 0;
    double _illumination = 0;

};

#endif /* WSREALTIMEDATA_H */

