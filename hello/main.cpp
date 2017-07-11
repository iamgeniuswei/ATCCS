/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on 2017年6月16日, 上午11:18
 */

#include <cstdlib>
#include <iostream>
#include <locale>
#include <libintl.h>
#include <functional>
using namespace std;
#include <string>
/*
 * 
 */
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "zh_CN.UTF8");
    bindtextdomain( "hello", "/usr/share/locale" );
    textdomain( "hello" );
    std::string msg;
    msg += gettext("what");
    msg += gettext("funk");
            
    cout << msg.c_str() << endl;
    return 0;
}

