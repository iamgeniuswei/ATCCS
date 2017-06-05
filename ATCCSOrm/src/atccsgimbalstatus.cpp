#include "atccsgimbalstatus.h"
#include "atccs_gimbal_define.h"
#include "atccsdata.h"
atccsgimbalstatus::atccsgimbalstatus()
{

}

void atccsgimbalstatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    atccspublicstatus::setStatus(data);
    if(data == nullptr || !(data->validate()))
        return;
    _ATCCSPHeader *header = (_ATCCSPHeader*)(data->data());
    if(header)
    {
        _sec = header->tv_sec;
        _msec = header->tv_usec;
    }
    _AT_GIMBAL_STATUS *status = (_AT_GIMBAL_STATUS*)(data->data() + sizeof(_ATCCSPHeader));
    if(status)
    {
        _siderealTime = status->siderealTime;
        _hourAngle = status->hourAngle;
        _rightAscension = status->rightAscension;
        _declination = status->declination;
        _J2000RightAscension = status->J2000RightAscension;
        _J2000Declination = status->J2000Declination;
        _azmiuth = status->azmiuth;
        _elevation = status->elevation;
        _derotatorPositon = status->derotatorPositon;
        _targetRightAscension = status->targetRightAscension;
        _targetDeclination = status->targetDeclination;
        _targetJ2000RightAscension = status->targetJ2000RightAscension;
        _targetJ2000Declination = status->targetJ2000Declination;
        _targetAzmiuth = status->targetAzmiuth;
        _targetElevation = status->targetElevation;
        _targetDerotatorPosition = status->targetDerotatorPosition;
        _axis1TrackError = status->axis1TrackError;
        _axis2TrackError = status->axis2TrackError;
        _axis3TrackError = status->axis1TrackError;
        _focusTypeIndex = status->focusTypeIndex;
        _axis4Angle = status->axis4Angle;
        _coverIndex = status->coverIndex;
        _coverPosition = status->coverPosition;
        _targetFocusTypeIndex = status->targetFocusTypeIndex;
        _targetAxis4Angle = status->targetAxis4Angle;
        _targetCoverIndex = status->targetCoverIndex;
        _axis1Speed = status->axis1Speed;
        _axis2Speed = status->axis2Speed;
        _axis3Speed = status->axis3Speed;
        _trackType = status->trackType;
        _trackObjectName.assign(status->trackObjectName);
        _refractionCorrection = status->refractionCorrection;
        _axis1Encoder = status->axis1Encoder;
        _axis2Encoder = status->axis2Encoder;
        _axis3Encoder = status->axis3Encoder;
        _axis3Mode = status->axis3Mode;
        _axis1PMCorrection = status->axis1PMCorrection;
        _axis2PMCorrection = status->axis2PMCorrection;
        _axis3PMCorrection = status->axis3PMCorrection;
        _axis1ManualCorrection = status->axis1ManualCorrection;
        _axis2ManualCorrection = status->axis2ManualCorrection;
        _axis3ManualCorrection = status->axis3ManualCorrection;
        _pieSide = status->pieSide;
        _targetPieSide = status->targetPieSide;
        _isAxis1FindHome = status->isAxis1FindHome;
        _isAxis2FindHome = status->isAxis2FindHome;
        _isAxis3FindHome = status->isAxis3FindHome;
        _temperature1 = status->temperature[0];
        _temperature2 = status->temperature[1];
        _temperature3 = status->temperature[2];
        _temperature4 = status->temperature[3];
        _temperature5 = status->temperature[4];
        _temperature6 = status->temperature[5];
        _temperature7 = status->temperature[6];
        _temperature8 = status->temperature[7];
        _temperature9 = status->temperature[8];
        _temperature10 = status->temperature[9];
        _temperature11 = status->temperature[10];
        _temperature12 = status->temperature[11];
        _humidity1 = status->humidity[0];
        _humidity2 = status->humidity[1];
        _humidity3 = status->humidity[2];
        _humidity4 = status->humidity[3];
        _humidity5 = status->humidity[4];
        _humidity6 = status->humidity[5];
        _humidity7 = status->humidity[6];
        _humidity8 = status->humidity[7];
        _humidity9 = status->humidity[8];
        _humidity10 = status->humidity[9];
        _humidity11 = status->humidity[10];
        _humidity12 = status->humidity[11];
    }
}

double atccsgimbalstatus::targetJ2000Declination() const {
    return _targetJ2000Declination;
}

double atccsgimbalstatus::targetJ2000RightAscension() const {
    return _targetJ2000RightAscension;
}

unsigned short atccsgimbalstatus::trackType() const {
    return _trackType;
}

std::string atccsgimbalstatus::trackObjectName() const {
    return _trackObjectName;
}

double atccsgimbalstatus::axis3Encoder() const {
    return _axis3Encoder;
}

unsigned short atccsgimbalstatus::axis3Mode() const {
    return _axis3Mode;
}

double atccsgimbalstatus::axis1Speed() const {
    return _axis1Speed;
}

unsigned short atccsgimbalstatus::coverIndex() const {
    return _coverIndex;
}

unsigned short atccsgimbalstatus::focusTypeIndex() const {
    return _focusTypeIndex;
}

