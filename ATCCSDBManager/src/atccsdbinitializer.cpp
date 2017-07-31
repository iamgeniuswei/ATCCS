/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDBInitializer.cpp
 * Author: lenovo
 * 
 * Created on July 27, 2017, 11:04 AM
 */

#include "atccsdbinitializer.h"
#include "atccs_public_define.h"
#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb;
using namespace odb::core;
#include <odb/pgsql/database.hxx>
#include "ORMHelper.h"
#include <iostream>

ATCCSDBInitializer::ATCCSDBInitializer()
{
}

ATCCSDBInitializer::~ATCCSDBInitializer()
{
}

void ATCCSDBInitializer::initializeATTable(unsigned int at)
{
    switch (at)
    {
        case AT216:
        {
            break;
        }

        case AT126:
        {
            break;
        }

        case AT100:
        {
            break;
        }
        case AT85:
        {
            break;
        }

        case AT80:
        {
            //            initializeAT80Table();
            break;
        }

        case AT60:
        {
            initializeAT60Table();
            break;
        }

        case AT50:
        {
            break;
        }

        case ATAE:
        {
            break;
        }
    }
}

void ATCCSDBInitializer::initializeAT60Table()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        t.tracer(stderr_tracer);
        odb::schema_catalog::create_schema(*db, "at60gimbalstatus");
        odb::schema_catalog::create_schema(*db, "at60ccdstatus");
        odb::schema_catalog::create_schema(*db, "at60filterstatus");
        odb::schema_catalog::create_schema(*db, "at60focusstatus");
        odb::schema_catalog::create_schema(*db, "at60slavedomestatus");
        odb::schema_catalog::create_schema(*db, "at60plan");
        odb::schema_catalog::create_schema(*db, "at60instruction");
        t.commit();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ATCCSDBInitializer::initializeSystemTable()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        t.tracer(stderr_tracer);
        odb::schema_catalog::create_schema(*db, "atccsuser");
        odb::schema_catalog::create_schema(*db, "atccsat");
        odb::schema_catalog::create_schema(*db, "atccsdevice");
        odb::schema_catalog::create_schema(*db, "atccseme");
        odb::schema_catalog::create_schema(*db, "atccsutilization");
        t.commit();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ATCCSDBInitializer::initializeEMETable()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        t.tracer(stderr_tracer);
        odb::schema_catalog::create_schema(*db, "wsrealtimedata");
        odb::schema_catalog::create_schema(*db, "csrealtimedata");
        odb::schema_catalog::create_schema(*db, "ascrealtimedata");
        odb::schema_catalog::create_schema(*db, "sqmrealtimedata");
        odb::schema_catalog::create_schema(*db, "dustrealtimedata");
        odb::schema_catalog::create_schema(*db, "dimmrealtimedata");
        t.commit();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ATCCSDBInitializer::initializeTable(const std::string& tableName)
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db();
        transaction t(db->begin());
        t.tracer(stderr_tracer);
        odb::schema_catalog::create_schema(*db, tableName);
        t.commit();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }            
}




