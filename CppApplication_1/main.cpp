/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on June 16, 2017, 10:38 AM
 */

#include <cstdlib>
#include <iostream>
#include <locale>
#include <libintl.h>
#include <functional>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    bindtextdomain( "hello", "/usr/share/locale" );
    textdomain( "hello" );
    cout << gettext("test") << endl;
    return 0;
}

