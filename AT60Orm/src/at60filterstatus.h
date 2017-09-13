/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   at60filterstatus.h
 * Author: lenovo
 *
 * Created on May 9, 2017, 9:43 AM
 */

#ifndef AT60FILTERSTATUS_H
#define AT60FILTERSTATUS_H
#include "atccsfilterstatus.h"

/**
 * @brief at60filterstatus is AT60 filter's real-time status.
 * @modified 2017-07-27
 * @description 
 * 1) recompile the header file by odb complier with the --schema-name at60filterstatus
 */
#pragma db object
class at60filterstatus : public atccsfilterstatus
{
public:
    at60filterstatus();
    at60filterstatus(const at60filterstatus& orig);
    virtual ~at60filterstatus();
    unsigned long long persistStatus() override;

private:

};

#endif /* AT60FILTERSTATUS_H */

