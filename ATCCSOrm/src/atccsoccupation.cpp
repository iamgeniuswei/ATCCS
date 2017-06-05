#include "atccsoccupation.h"
#include "atccsdata.h"
#include "atccs_public_define.h"
atccsoccupation::atccsoccupation()
{

}

bool atccsoccupation::setValue(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || data->validate())
        return false;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(!header || (header->msg != ATTAKEOVER))
        return false;
    _AT_OCCUPATION *occu = (_AT_OCCUPATION*)(data->data()+sizeof(_ATCCSPHeader));
    if(occu)
    {
        _user = occu->_user;
        _at = occu->_at;
        _occupation = occu->_occupation;
        _start = occu->_start;
        _end = occu->_end;
        _priority = occu->_priority;
    }
}

unsigned int atccsoccupation::user() const
{
    return _user;
}

unsigned short atccsoccupation::at() const
{
    return _at;
}

unsigned short atccsoccupation::occupation() const
{
    return _occupation;
}

unsigned int atccsoccupation::start() const
{
    return _start;
}

unsigned int atccsoccupation::end() const
{
    return _end;
}

unsigned int atccsoccupation::priority() const
{
    return _priority;
}

void atccsoccupation::setUser(unsigned int _user) {
    this->_user = _user;
}

void atccsoccupation::setAt(unsigned short _at) {
    this->_at = _at;
}

void atccsoccupation::setOccupation(unsigned short _occupation) {
    this->_occupation = _occupation;
}

void atccsoccupation::setStart(unsigned int _start) {
    this->_start = _start;
}

void atccsoccupation::setEnd(unsigned int _end) {
    this->_end = _end;
}

void atccsoccupation::setPriority(unsigned int _priority) {
    this->_priority = _priority;
}
