#ifndef FILTERSTATUS_H
#define FILTERSTATUS_H
#include "atccspublicstatus.h"
#include <odb/core.hxx>

#pragma db object
class atccsfilterstatus : public atccspublicstatus
{
public:
    atccsfilterstatus();
private:
    friend class odb::access;
    unsigned short _filterPosition = 0;
    unsigned short _targetFilterPosition = 0;
    unsigned short _isHomed = 0;

    // ATCCSPublicStatus interface
public:
    virtual void setStatus(std::shared_ptr<ATCCSData> data) override;
    unsigned short isHomed() const;
    unsigned short targetFilterPosition() const;
    unsigned short filterPosition() const;
};

#endif // FILTERSTATUS_H
