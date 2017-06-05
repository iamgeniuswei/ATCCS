/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ORMHelper.h
 * Author: lenovo
 *
 * Created on May 14, 2017, 2:45 PM
 */

#ifndef ORMHELPER_H
#define ORMHELPER_H

#include <memory>
#include <string>
#include "atccs_global.h"
#include <iostream>
#ifdef DATAPERSISTENCE
#include <odb/core.hxx>
#include <odb/database.hxx>
using namespace odb::core;
#endif

class ORMHelper {
private:
    ORMHelper();
    ORMHelper(const ORMHelper& orig) = delete;
public:
    virtual ~ORMHelper();
    static void initDB(const std::string& type,
                const std::string& user,
                const std::string& password,
                const std::string& db,
                const std::string& host = "",
                unsigned int port = 0);
#ifdef DATAPERSISTENCE
    static std::shared_ptr<database> db();

    template<typename T>
    static unsigned int persist(std::shared_ptr<T> value) 
    {
        if(value == nullptr)
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#2: The object to persist is null." 
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
            return 0;
        }
        try 
        {
            transaction t(_db->begin());
            _db->persist(*value);
            t.commit();
        } 
        catch (std::exception &e) 
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#1: " << e.what()
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
    }
    
    template<typename T>
    static unsigned long long persist(T value) 
    {        
        unsigned long long id = 0;
        if(value == nullptr)
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#2: The object to persist is null." 
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
            return 0;
        }
        try 
        {
            transaction t(_db->begin());
            _db->persist(value);
            t.commit();
        } 
        catch (std::exception &e) 
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#1: " << e.what()
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
        return id;
    }
    
//    template<typename T>
//    static unsigned int persist(T value) 
//    {        
//        unsigned int id = 0;
//        if(value == nullptr)
//        {
//#ifdef OUTDEBUGINFO
//            std::cerr << "error#2: The object to persist is null." 
//                    << " @" << __func__
//                    << " @" << __FILE__
//                    << " @" << __LINE__ << std::endl;
//#endif
//            return 0;
//        }
//        try 
//        {
//            transaction t(_db->begin());
//            id = _db->persist(value);
//            t.commit();
//        } 
//        catch (std::exception &e) 
//        {
//#ifdef OUTDEBUGINFO
//            std::cerr << "error#1: " << e.what()
//                    << " @" << __func__
//                    << " @" << __FILE__
//                    << " @" << __LINE__ << std::endl;
//#endif
//        }
//        return id;
//    }

    
    template<typename T>
    static void update(std::shared_ptr<T> value)
    {
        if(value == nullptr)
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#2: The object to persist is null." 
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
        try 
        {
            transaction t(_db->begin());
            _db->update(*value);
            t.commit();
        } 
        catch (std::exception &e) 
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#1: " << e.what()
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
    }
    
    template<typename T>
    static void update(T value)
    {
        if(value == nullptr)
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#2: The object to persist is null." 
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
        try 
        {
            transaction t(_db->begin());
            _db->update(value);
            t.commit();
        } 
        catch (std::exception &e) 
        {
#ifdef OUTDEBUGINFO
            std::cerr << "error#1: " << e.what()
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
        }
    }
    
#endif
private:
#ifdef DATAPERSISTENCE
    static std::shared_ptr<database> _db;
#endif
};

#endif /* ORMHELPER_H */

