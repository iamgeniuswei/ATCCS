/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60slavedomestatus.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 10:05 AM
 */

#ifndef AT60SLAVEDOMESTATUS_H
#define AT60SLAVEDOMESTATUS_H

#include "atccsslavedomestatus.h"
/**
 * @brief at60slavedomestatus is AT60 slavedome's real-time status.
 * @modified 2017-07-27
 * @description 
 * 1) recompile the header file by odb complier with the --schema-name at60slavedomestatus
 */
#pragma db object
class at60slavedomestatus : public atccsslavedomestatus
{
public:
    at60slavedomestatus();
    at60slavedomestatus(const at60slavedomestatus& orig);
    virtual ~at60slavedomestatus();
    unsigned long long persistStatus() override;

private:

};

#endif /* AT60SLAVEDOMESTATUS_H */

