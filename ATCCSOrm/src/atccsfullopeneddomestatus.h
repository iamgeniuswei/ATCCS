#ifndef FULLOPENEDDOMESTATUS_H
#define FULLOPENEDDOMESTATUS_H

#include "atccspublicstatus.h"
#include <odb/core.hxx>

#pragma db object
class ATCCSFullOpenedDomeStatus : public atccspublicstatus
{
public:
    ATCCSFullOpenedDomeStatus();
private:
    friend class odb::access;
    double _domePosition = 0;

    // ATCCSPublicStatus interface
public:
    virtual void setStatus(std::shared_ptr<ATCCSData> data) override;
};

#endif // FULLOPENEDDOMESTATUS_H
