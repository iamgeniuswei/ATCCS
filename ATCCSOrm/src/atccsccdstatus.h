#ifndef CCDSTATUS_H
#define CCDSTATUS_H
#include <odb/core.hxx>
#include "atccspublicstatus.h"
#include <iostream>
#pragma db object
class atccsccdstatus : public atccspublicstatus
{
public:
    atccsccdstatus();
    ~atccsccdstatus()
    {
        std::cout << "~atccsccdstatus" << std::endl;
    }
    void setStatus(std::shared_ptr<ATCCSData> data = nullptr);
    unsigned short indexOfGain() const;
    unsigned short indexOfGainMode() const;
    unsigned short indexOfTSMode() const;
    unsigned short indexOfRSMode() const;
    unsigned int binY() const;
    unsigned int binX() const;
    unsigned int imageHeight() const;
    unsigned int imageWidth() const;
    unsigned int startY() const;
    unsigned int startX() const;
    unsigned short shutterMode() const;
    unsigned short isFullFrame() const;
    unsigned short isNoiseFilter() const;
    unsigned short isEM() const;
    unsigned int baseline() const;
    unsigned int EM() const;
    unsigned short isBaseline() const;
    double coolerT() const;
    unsigned short epoch() const;
    unsigned short observeType() const;
    std::string observeName() const;
    double J2000Declination() const;
    double J2000RightAscension() const;
    std::string band() const;

protected:
    friend class odb::access;

    std::string _observeName;
    std::string _band;
    std::string _lastTargetName;

    unsigned short _observeType = 0;
    unsigned short _epoch = 0;
    unsigned short _indexOfRSMode = 0;
    unsigned short _indexOfTSMode = 0;
    unsigned short _indexOfGainMode = 0;
    unsigned short _indexOfGain = 0;
    unsigned short _readMode = 0;
    unsigned short _exposureTriggerMode = 0;
    unsigned short _fanOn = 0;
    unsigned short _shutterMode = 0;
    unsigned short _isFullFrame = 0;
    unsigned short _isEM = 0;
    unsigned short _isNoiseFilter = 0;
    unsigned short _isBaseline = 0;

    unsigned int _binX = 0;
    unsigned int _binY = 0;
    unsigned int _startX = 0;
    unsigned int _startY = 0;
    unsigned int _imageWidth = 0;
    unsigned int _imageHeight = 0;
    unsigned int _frameSequence = 0;
    unsigned int _frameTotal = 0;
    unsigned int _lastExposureTime = 0;
    unsigned int _EM = 0;
    unsigned int _baseline = 0;

    double _J2000RightAscension = 0;
    double _J2000Declination = 0;
    double _exposureTime = 0;
    double _delayTime = 0;
    double _coolerT = 0;
    double _targetCoolerT = 0;
    double _lastExposureDuration = 0;
    double _bitsOfPixel = 0;
    double _exposurePercent = 0;
    double _pixelScaleX = 0;
    double _pixelScaleY = 0;
};

#endif // CCDSTATUS_H
