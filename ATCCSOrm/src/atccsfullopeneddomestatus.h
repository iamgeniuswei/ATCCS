#ifndef FULLOPENEDDOMESTATUS_H
#define FULLOPENEDDOMESTATUS_H

#include "atccspublicstatus.h"
#include <odb/core.hxx>

/**
 * @brief atccsfullopeneddomestatus is the base class of fullopeneddome's 
 * real-time status.
 */
#pragma db object
class atccsfullopeneddomestatus : public atccspublicstatus
{
public:
    atccsfullopeneddomestatus();
private:
    friend class odb::access;
    double _domePosition = 0;

    // ATCCSPublicStatus interface
public:
    virtual void setStatus(std::shared_ptr<ATCCSData> data) override;
};

#endif // FULLOPENEDDOMESTATUS_H
