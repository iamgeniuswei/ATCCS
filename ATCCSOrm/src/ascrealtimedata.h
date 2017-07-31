/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ascrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月22日, 下午3:15
 */

#ifndef ASCREALTIMEDATA_H
#define ASCREALTIMEDATA_H
#include "emerealtimedata.h"

/**
 * @brief ascrealtimedata is a persistence class which encapsulates the 
 * ASC real-time data.
 * @modified 2017-07-27
 * @description 
 * 1) recompile the header file by odb complier with the --schema-name ascrealtimedata
 * 
 */
#pragma db object
class ascrealtimedata : public emerealtimedata
{
public:
    ascrealtimedata();
    ascrealtimedata(const ascrealtimedata& orig) = delete;
    ascrealtimedata(const ascrealtimedata&& orig) = delete;
    ascrealtimedata& operator=(const ascrealtimedata& orig) = delete;
    ascrealtimedata& operator=(const ascrealtimedata&& orig) = delete;
    virtual ~ascrealtimedata();
    unsigned long long persistRealtimeData() override;
    unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data) override;


public:
    friend class odb::access;
    double _shutterspeed = 0;
    double _aperture = 0;
    unsigned short _iso = 0;
    unsigned short _jpeg = 0;
    unsigned short _raw = 0;
    unsigned short _fits = 0;
};

#endif /* ASCREALTIMEDATA_H */

