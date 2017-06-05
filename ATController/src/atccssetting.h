#ifndef ATCSETTING_H
#define ATCSETTING_H
#include "atccs_global.h"
#ifdef DATAPERSISTENCE
#include <odb/core.hxx>
#include <odb/database.hxx>
using namespace odb::core;
#endif


class ATCCSSetting
{
private:
    explicit ATCCSSetting();
    ATCCSSetting(const ATCCSSetting&) = delete;
    ATCCSSetting& operator=(const ATCCSSetting&) = delete;
    static ATCCSSetting *_instance;
    class ATCCSSettingGarbo
    {
    public:
        ~ATCCSSettingGarbo()
        {
            if(_instance != nullptr)
            {
                delete _instance;
                _instance = nullptr;
            }
        }
    };
    static ATCCSSettingGarbo _Garbo;
    
private:
#ifdef DATAPERSISTENCE
    std::shared_ptr<database> _db = nullptr;
#endif

public:
    static ATCCSSetting *instance();
    virtual ~ATCCSSetting();
#ifdef DATAPERSISTENCE
    std::shared_ptr<database> db() const;
#endif
};

#endif // ATCSETTING_H