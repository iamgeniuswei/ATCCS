#ifndef SLAVEDOMESTATUS_H
#define SLAVEDOMESTATUS_H
#include <odb/core.hxx>
#include "atccspublicstatus.h"

#pragma db object
class atccsslavedomestatus : public atccspublicstatus
{
public:
    atccsslavedomestatus();
private:
    friend class odb::access;
    unsigned short _scuttleStatus = 0;
    unsigned short _shadeStatus = 0;
    double _domePosition = 0;
    double _scuttlePercent = 0;
    double _shadePosition = 0;
    double _targetDomePosition = 0;
    double _targetScuttlePosition = 0;
    double _targetShadePosition = 0;

    // ATCCSPublicStatus interface
public:
    virtual void setStatus(std::shared_ptr<ATCCSData> data) override;
};

#endif // SLAVEDOMESTATUS_H
