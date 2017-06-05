#include "atccssetting.h"
#include <new>
#ifdef DATAPERSISTENCE
#include <odb/pgsql/database.hxx>
#endif

ATCCSSetting *ATCCSSetting::_instance = nullptr;
ATCCSSetting::ATCCSSettingGarbo ATCCSSetting::_Garbo;
ATCCSSetting::ATCCSSetting()
{
    try
    {
        _db = std::make_shared<odb::pgsql::database>("lenovo", "123456", "ATCCSDB", "192.168.0.200", 5432);
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
#endif
    }
}

ATCCSSetting *ATCCSSetting::instance()
{
    if(_instance == nullptr)
    {
        if(_instance == nullptr)
        {
            _instance = new (std::nothrow) ATCCSSetting;
        }
    }
    return _instance;
}

ATCCSSetting::~ATCCSSetting()
{
    
}


#ifdef DATAPERSISTENCE
std::shared_ptr<database> ATCCSSetting::db() const {
    return _db;
}
#endif
