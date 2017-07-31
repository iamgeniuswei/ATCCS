#ifndef ATCCSTAKEOVER_H
#define ATCCSTAKEOVER_H

#include <odb/core.hxx>
#include "atccs_global.h"
#include <memory>
class ATCCSData;

/**
 * @brief atccsoccupation is a persistence class which encapsulates the AT's 
 * occupation.
 */
#pragma db object
class atccsoccupation
{
public:
    enum {NOTOCCUPATION, OCCUPATION};
    atccsoccupation();
    bool setValue(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned int user() const;
    unsigned short at() const;
    unsigned short occupation() const;
    unsigned int start() const;
    unsigned int end() const;
    unsigned int priority() const;
    void setUser(unsigned int _user);
    void setAt(unsigned short _at);
    void setOccupation(unsigned short _occupation);
    void setStart(unsigned int _start);
    void setEnd(unsigned int _end);
    void setPriority(unsigned int _priority);

private:
    friend class odb::access;

#pragma db id auto
    unsigned int _id;
    unsigned int _user = 0;
    unsigned short _at = 0;
    unsigned short _occupation = 0;
    unsigned int _start = 0;
    unsigned int _end = 0;
    unsigned int _priority = 0;
};

#endif // ATCCSTAKEOVER_H
