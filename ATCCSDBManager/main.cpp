/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on May 13, 2017, 8:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <exception>
#include <memory>
#include "atccs_public_define.h"
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb;
using namespace odb::core;
#include <odb/pgsql/database.hxx>
#include <locale>
//#include <atutilization.h>
//#include <atutilization-odb.hxx>
#include "atccsutilization.h"
#include "atccsutilization-odb.hxx"
#include "ORMHelper.h"

//TEST
#include "at60plan.h"
#include <string>
#include "src/atccsdbinitializer.h"

void printDBSettingInfo()
{
    std::cout << "Please enter an id to initialize database: \n";
    std::cout << "Enter 1 to initialize ATCCS public tables;\n";
    std::cout << "Enter 2 to initialize ATCCS EME tables;\n";
    std::cout << "Enter 3 to initialize AT 60 tables;\n";
    std::cout << "Enter q to quit.\n";
}
/*
 * 
 */
int main(int argc, char** argv) 
{
    std::cout << "-----------------ATCCS Database Manager-------------------------\n";
    
    try
    {     
        ORMHelper::initDB("pgsql", "lenovo", "1234567", "ATCCSDB", "192.168.0.200", 5432);
        std::shared_ptr<database> db = ORMHelper::db();
        std::cout << db << std::endl;
        std::cout << db->connection() << std::endl;
        printDBSettingInfo();

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }    
    return 0;
}

