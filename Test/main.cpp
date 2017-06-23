/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on 2017年6月22日, 上午11:02
 */

#include <cstdlib>
#include <iostream>
#include <memory>
using namespace std;
#include "QString.h"

class Test
{
    int i = 10;
    int j = 10;
};

QString ret()
{
    QString temp;
    return temp;
}

/*
 * 
 */
int main(int argc, char** argv)
{
    QString ret;
    QString str(std::move(ret));
    
    return 0;
}

