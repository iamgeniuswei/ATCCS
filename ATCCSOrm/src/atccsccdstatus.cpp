#include "atccsccdstatus.h"
#include "atccs_ccd_define.h"
#include "atccsdata.h"
atccsccdstatus::atccsccdstatus()
{

}

void atccsccdstatus::setStatus(std::shared_ptr<ATCCSData> data)
{
    if(data == nullptr || !(data->validate()))
        return;
    atccspublicstatus::setStatus(data);

    _AT_CCD_STATUS *status = (_AT_CCD_STATUS*)(data->data()+sizeof(_ATCCSPHeader));
    if(status)
    {
        _band.assign(status->band);
        _observeName.assign(status->observeName);
        _lastTargetName.assign(status->lastTargetName);
        _J2000RightAscension = status->J2000RightAscension;
        _J2000Declination = status->J2000Declination;
        _epoch = status->epoch;
        _binX = status->binX;
        _binY = status->binY;
        _startX = status->startX;
        _startY = status->startY;
        _imageWidth = status->imageWidth;
        _imageHeight = status->imageHeight;
        _exposureTime = status->exposureTime;
        _delayTime = status->delayTime;
        _frameSequence = status->frameSequence;
        _frameTotal = status->frameTotal;
        _indexOfRSMode = status->indexOfRSMode;
        _indexOfTSMode = status->indexOfTSMode;
        _indexOfGainMode = status->indexOfGainMode;
        _indexOfGain = status->indexOfGain;
        _coolerT = status->coolerT;
        _targetCoolerT = status->targetCoolerT;
        _lastExposureTime = status->lastExposureTime;
        _lastExposureDuration = status->lastExposureDuration;
        _readMode = status->readMode;
        _bitsOfPixel = status->bitsOfPixel;
        _exposurePercent = status->exposurePercent;
        _exposureTriggerMode = status->exposureTriggerMode;
        _fanOn = status->fanOn;
        _shutterMode = status->shutterMode;
        _isFullFrame = status->isFullFrame;
        _isEM = status->isEM;
        _EM = status->EM;
        _isNoiseFilter = status->isNoiseFilter;
        _isBaseline = status->isBaseline;
        _baseline = status->baseline;
        _pixelScaleX = status->pixelScaleX;
        _pixelScaleY = status->pixelScaleY;
    }

}

unsigned short atccsccdstatus::indexOfGain() const {
    return _indexOfGain;
}

unsigned short atccsccdstatus::indexOfGainMode() const {
    return _indexOfGainMode;
}

unsigned short atccsccdstatus::indexOfTSMode() const {
    return _indexOfTSMode;
}

unsigned short atccsccdstatus::indexOfRSMode() const {
    return _indexOfRSMode;
}

unsigned int atccsccdstatus::binY() const {
    return _binY;
}

unsigned int atccsccdstatus::binX() const {
    return _binX;
}

unsigned int atccsccdstatus::imageHeight() const {
    return _imageHeight;
}

unsigned int atccsccdstatus::imageWidth() const {
    return _imageWidth;
}

unsigned int atccsccdstatus::startY() const {
    return _startY;
}

unsigned int atccsccdstatus::startX() const {
    return _startX;
}

unsigned short atccsccdstatus::shutterMode() const {
    return _shutterMode;
}

unsigned short atccsccdstatus::isFullFrame() const {
    return _isFullFrame;
}

unsigned short atccsccdstatus::isNoiseFilter() const {
    return _isNoiseFilter;
}

unsigned short atccsccdstatus::isEM() const {
    return _isEM;
}

unsigned int atccsccdstatus::baseline() const {
    return _baseline;
}

unsigned int atccsccdstatus::EM() const {
    return _EM;
}

unsigned short atccsccdstatus::isBaseline() const {
    return _isBaseline;
}

double atccsccdstatus::coolerT() const {
    return _coolerT;
}

unsigned short atccsccdstatus::epoch() const {
    return _epoch;
}

unsigned short atccsccdstatus::observeType() const {
    return _observeType;
}

std::string atccsccdstatus::observeName() const {
    return _observeName;
}

double atccsccdstatus::J2000Declination() const {
    return _J2000Declination;
}

double atccsccdstatus::J2000RightAscension() const {
    return _J2000RightAscension;
}

std::string atccsccdstatus::band() const {
    return _band;
}
