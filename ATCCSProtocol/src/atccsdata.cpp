#include "atccsdata.h"
#include <new>
#include <exception>
#include "atccs_public_define.h"
#include <iostream>
#include "atccs_global.h"
#include "atccsexception.h"
#include "atccsexceptionhandler.h"
ATCCSData::ATCCSData()
{

}

ATCCSData::ATCCSData(unsigned int size):_size(size)
{
    try
    {
        _data = new char[size];
    }
    catch(std::exception &e)
    {
        _data = nullptr;
        _size = 0;
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += e.what();
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::STDEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
    }
}

char *ATCCSData::data()
{
    return _data;
}




/**
 * @name            validate()
 * @description     validate the ATCCSData, if(_data == nullptr)&&
 *                                              (_size < sizeof(_ATCCSPHeader))&&
 *                                              (_size < _ATCCSPHeader::length)
 * @return          true(_data is right) false(_data is error)
 * @author          Geniuswei
 * @create-date     
 * @modify-date     2017-05-10
 * @modify-reason   print debug infomation
 */
bool ATCCSData::validate() const
{
    if(_data == nullptr)
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += "ATCCSData's _data is null";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::POINTERISNULL, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif
        return false;
    }

    if(_size < sizeof(_ATCCSPHeader))
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += "ATCCSData's _size is less than sizeof(_ATCCSPHeader)";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif        
        return false;
    }
    _ATCCSPHeader *header = (_ATCCSPHeader*)(_data);
    if(header->length != _size)
    {
#ifdef OUTDEBUGINFO
        std::string debug_info;
        debug_info += "ATCCSData's _size is not equal to _ATCCSPHeader's length field";
        debug_info += " @";
        debug_info += __func__;
        debug_info += " @";
        debug_info += __FILE__;
        std::shared_ptr<ATCCSException> e1(new ATCCSException(ATCCSException::CUSTOMEXCEPTION, debug_info));
        ATCCSExceptionHandler::addException(e1);
#endif         
        return false;
    }
    return true;
}
