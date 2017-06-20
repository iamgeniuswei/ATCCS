#include "atccsdata.h"
#include <new>
#include <exception>
#include "atccs_public_define.h"
#include <iostream>
#include <locale>
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"

/**
 * ATCCSData's constructor.
 * allocate a buffer whose size is 'size'
 * @param size
 */
ATCCSData::ATCCSData(unsigned int size) noexcept
{
    try
    {
        _data = new char[size];
        _size = size;
    }
    catch(std::exception &e)
    {
        _data = nullptr;
        _size = 0;
    }
}

/**
 * get the raw data's pointer
 * @return char*
 */
char *ATCCSData::data()
{
    return _data;
}


/**
 * validate the ATCCSData.
 * @return true if success, false if fails.
 */
bool ATCCSData::validate() const
{
    if(_data == nullptr)
    {
        return false;
    }

    if(_size < sizeof(_ATCCSPHeader))
    {     
        return false;
    }
    _ATCCSPHeader *header = (_ATCCSPHeader*)(_data);
    if(header->length != _size)
    {   
        return false;
    }
    
    return true;
}
