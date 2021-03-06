#ifndef GUIDESCOPESTATUS_H
#define GUIDESCOPESTATUS_H


#include <odb/core.hxx>
#include "atccspublicstatus.h"
#pragma db object
class GuideScopeStatus : public atccspublicstatus
{
public:
    GuideScopeStatus();

private:
    friend class odb::access;
    unsigned short _indexOfCover = 0;
    unsigned short _targetIndexeOfCover = 0;
    double _positionOfCover = 0;
};

#endif // GUIDESCOPESTATUS_H
