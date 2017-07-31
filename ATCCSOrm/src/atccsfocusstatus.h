#ifndef FOCUSSTATUS_H
#define FOCUSSTATUS_H

#include "atccspublicstatus.h"
#include <odb/core.hxx>
#include <iostream>

/**
 * @brief atccsfocusstatus is the base class of focus' real-time status.
 */
#pragma db object
class atccsfocusstatus : public atccspublicstatus
{
public:
    atccsfocusstatus();
    void setStatus(std::shared_ptr<ATCCSData> data);

private:
    friend class odb::access;
    unsigned short _isHomed = 0;
    unsigned short _isTCompensation = 0;
    double _position = 0;
    double _targetPosition = 0;    
    double _temperature = 0;    
    double _TCompenensation = 0;
};

#endif // FOCUSSTATUS_H
