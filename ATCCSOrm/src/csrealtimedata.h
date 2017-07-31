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

/**
 * @brief csrealtimedata is a persistence class which encapsulates the 
 * cloud sensor real-time data.
 * @modified 2017-07-26
 * @description 
 * 1) recompile the header file by odb complier with the --schema-name csrealtimedata
 * 
 */
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
    double _relskytemperature = 0;
    double _ambienttemperature = 0;
    double _sensortemperature = 0;
    unsigned short _rainfall = 0;
    unsigned short _rainthresh = 0;
    double _wind = 0;
    unsigned short _windunits = 0;
    double _humiditypercent = 0;
    double _dewpoint = 0;
    double _daylight = 0;
};

#endif /* CSREALTIMEDATA_H */

