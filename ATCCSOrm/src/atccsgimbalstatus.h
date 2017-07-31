#ifndef GIMBALSTATUS_H
#define GIMBALSTATUS_H
#include <odb/core.hxx>
#include "atccspublicstatus.h"
#include "atccs_public_define.h"

/**
 * atccsgimbalstatus is the base class of the gimbal's real-time status.
 */
#pragma db object
class atccsgimbalstatus : public atccspublicstatus
{
public:
    explicit atccsgimbalstatus();
    ~atccsgimbalstatus(){}
    void setStatus(std::shared_ptr<ATCCSData> data = nullptr);
    double targetJ2000Declination() const;
    double targetJ2000RightAscension() const;
    unsigned short trackType() const;
    std::string trackObjectName() const;
    double axis3Encoder() const;
    unsigned short axis3Mode() const;
    double axis1Speed() const;
    unsigned short coverIndex() const;
    unsigned short focusTypeIndex() const;

protected:
    friend class odb::access;
    std::string _trackObjectName;
    double _siderealTime = INIT_VALUE;
    double _hourAngle = INIT_VALUE;
    double _rightAscension = INIT_VALUE;
    double _declination = INIT_VALUE;
    double _J2000RightAscension = INIT_VALUE;
    double _J2000Declination = INIT_VALUE;
    double _azmiuth = INIT_VALUE;
    double _elevation = INIT_VALUE;
    double _derotatorPositon = INIT_VALUE;
    double _targetRightAscension = INIT_VALUE;
    double _targetDeclination = INIT_VALUE;
    double _targetJ2000RightAscension = INIT_VALUE;
    double _targetJ2000Declination = INIT_VALUE;
    double _targetAzmiuth = INIT_VALUE;
    double _targetElevation = INIT_VALUE;
    double _targetDerotatorPosition = INIT_VALUE;
    double _axis1TrackError = INIT_VALUE;
    double _axis2TrackError = INIT_VALUE;
    double _axis3TrackError = INIT_VALUE;
    double _axis4Angle = INIT_VALUE;
    double _coverPosition = INIT_VALUE;
    double _targetAxis4Angle = INIT_VALUE;
    double _axis1Speed = INIT_VALUE;
    double _axis2Speed = INIT_VALUE;
    double _axis3Speed = INIT_VALUE;
    double _refractionCorrection = INIT_VALUE;
    double _axis1Encoder = INIT_VALUE;
    double _axis2Encoder = INIT_VALUE;
    double _axis3Encoder = INIT_VALUE;
    double _axis1PMCorrection = INIT_VALUE;
    double _axis2PMCorrection = INIT_VALUE;
    double _axis3PMCorrection = INIT_VALUE;
    double _axis1ManualCorrection = INIT_VALUE;
    double _axis2ManualCorrection = INIT_VALUE;
    double _axis3ManualCorrection = INIT_VALUE;
    double _temperature1 = INIT_VALUE;
    double _temperature2 = INIT_VALUE;
    double _temperature3 = INIT_VALUE;
    double _temperature4 = INIT_VALUE;
    double _temperature5 = INIT_VALUE;
    double _temperature6 = INIT_VALUE;
    double _temperature7 = INIT_VALUE;
    double _temperature8 = INIT_VALUE;
    double _temperature9 = INIT_VALUE;
    double _temperature10 = INIT_VALUE;
    double _temperature11 = INIT_VALUE;
    double _temperature12 = INIT_VALUE;
    double _humidity1 = INIT_VALUE;
    double _humidity2 = INIT_VALUE;
    double _humidity3 = INIT_VALUE;
    double _humidity4 = INIT_VALUE;
    double _humidity5 = INIT_VALUE;
    double _humidity6 = INIT_VALUE;
    double _humidity7 = INIT_VALUE;
    double _humidity8 = INIT_VALUE;
    double _humidity9 = INIT_VALUE;
    double _humidity10 = INIT_VALUE;
    double _humidity11 = INIT_VALUE;
    double _humidity12 = INIT_VALUE;
    unsigned short _focusTypeIndex = INIT_VALUE;
    unsigned short _coverIndex = INIT_VALUE;
    unsigned short _targetFocusTypeIndex = INIT_VALUE;
    unsigned short _targetCoverIndex = INIT_VALUE;
    unsigned short _trackType = INIT_VALUE;
    unsigned short _axis3Mode = INIT_VALUE;
    unsigned short _pieSide = INIT_VALUE;
    unsigned short _targetPieSide = INIT_VALUE;
    unsigned short _isAxis1FindHome = INIT_VALUE;
    unsigned short _isAxis2FindHome = INIT_VALUE;
    unsigned short _isAxis3FindHome = INIT_VALUE;
};

#endif // GIMBALSTATUS_H
