/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sqmrealtimedata.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午10:14
 */

#ifndef SQMREALTIMEDATA_H
#define SQMREALTIMEDATA_H
#include "emerealtimedata.h"

/**
 * @brief sqmrealtimedata is a persistence class which encapsulates the 
 * sqm real-time data.
 * @modified 2017-07-26
 * @description 
 * 1) recompile the header file by odb complier with the --schema-name sqmrealtimedata
 * 
 */
#pragma db object
class sqmrealtimedata : public emerealtimedata
{
public:
    sqmrealtimedata();
    sqmrealtimedata(const sqmrealtimedata& orig) = delete;
    sqmrealtimedata(const sqmrealtimedata&& orig) = delete;
    sqmrealtimedata& operator=(const sqmrealtimedata& orig) = delete;
    sqmrealtimedata& operator=(const sqmrealtimedata&& orig) = delete;
    virtual ~sqmrealtimedata();
    unsigned long long persistRealtimeData() override;
    unsigned int setRealtimeData(std::shared_ptr<ATCCSData> data) override;



protected:

public:
    friend class odb::access;
    double _sqmdata = 0;

};

#endif /* SQMREALTIMEDATA_H */

