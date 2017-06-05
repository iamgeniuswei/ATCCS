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
//#include <atutilization.h>
//#include <atutilization-odb.hxx>
#include "atccsutilization.h"
#include "atccsutilization-odb.hxx"
#include "ORMHelper.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    std::cout << "-----------------ATCCS Database Manager-------------------------\n";
    
    try
    {
        ORMHelper::initDB("pgsql", "lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        t.tracer(stderr_tracer);
        odb::schema_catalog::create_schema(*db);        
        t.commit();
        std::shared_ptr<atccsutilization> at216(new atccsutilization(AT216));
        std::shared_ptr<atccsutilization> at126(new atccsutilization(AT126));
        std::shared_ptr<atccsutilization> at100(new atccsutilization(AT100));
        std::shared_ptr<atccsutilization> at85(new atccsutilization(AT85));
        std::shared_ptr<atccsutilization> at80(new atccsutilization(AT80));
        std::shared_ptr<atccsutilization> at60(new atccsutilization(AT60));
        std::shared_ptr<atccsutilization> at50(new atccsutilization(AT50));
        std::shared_ptr<atccsutilization> atAE(new atccsutilization(ATAE));
        ORMHelper::persist<atccsutilization>(at216);
        ORMHelper::persist<atccsutilization>(at126);
        ORMHelper::persist<atccsutilization>(at100);
        ORMHelper::persist<atccsutilization>(at85);
        ORMHelper::persist<atccsutilization>(at80);
        ORMHelper::persist<atccsutilization>(at60);
        ORMHelper::persist<atccsutilization>(at50);
        ORMHelper::persist<atccsutilization>(atAE);
        
        
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}

