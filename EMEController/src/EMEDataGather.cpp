/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMEDataGather.cpp
 * Author: lenovo
 * 
 * Created on 2017年6月23日, 下午4:08
 */

#include "EMEDataGather.h"
#include "atccs_public_define.h"

EMEDataGather::EMEDataGather(unsigned int type)
    :_type(type)
{
}

EMEDataGather::~EMEDataGather()
{
}

//std::shared_ptr<emerealtimedata> EMEDataGather::realtimeData()
//{
//    switch(_type)
//    {
//        case ASC:
//        {
//            break;
//        }
//        case WS:
//        {
//            break;
//        }
//        case CS:
//        {
//            break;
//        }
//        case SQM:
//        {
//            break;
//        }
//        case DUST:
//        {
//            break;
//        }
//        case DIMM:
//        {
//            break;
//        }
//        default:
//        {
//            break;
//        }
//    }
//}

void EMEDataGather::run()
{

}
