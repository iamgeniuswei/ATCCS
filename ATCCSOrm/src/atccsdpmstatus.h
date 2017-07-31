#ifndef DPMSTATUS_H
#define DPMSTATUS_H

#include <odb/core.hxx>
#include "atccspublicstatus.h"
#pragma db object
class atccsdpmstatus : public atccspublicstatus
{
public:
    atccsdpmstatus();
private:
    friend class odb::access;
    std::string _imagePath;
    std::string _objectName;
    unsigned short _objectType = 0;
    double _rightAscension = 0;
    double _declination = 0;
    unsigned short _epoch = 0;
    std::string _band;
    unsigned short _observeStatus = 0;
    unsigned int _binX = 0;
    unsigned int _binY = 0;
    unsigned int _startX = 0;
    unsigned int _startY = 0;
    unsigned int _imageWidth = 0;
    unsigned int _imageHeight = 0;
    double _exposureTime = 0;
    unsigned short _indexOfGainMode = 0;
    unsigned short _indexOfRSMode = 0;
    unsigned short _indexOfTSMode = 0;
    unsigned short _indexOfGainGear = 0;
    unsigned short _indexOfRMode = 0;
    unsigned short _gain = 0;
    double _noise = 0;
    double _coolerT = 0;
    double _targetCoolerT = 0;
    double _bitsOfPixel = 0;
    unsigned short _exposureTriggerMode = 0;
    unsigned short _indexOfCoolerMode = 0;
    unsigned short _fanStatus = 0;
    double _imageMeanValue = 0;
    double _imageRMS = 0;
    double _astrologyHHFW = 0;
    double _imageCenterRightAscension = 0;
    double _imageCenterDeclination = 0;
    double _missX = 0;
    double _missY = 0;
    double _missAxis1 = 0;
    double _missAxis2 = 0;
    double _atmosphericTransparency = 0;
    unsigned short _shutterMode = 0;
    unsigned short _isFullFrame = 0;
    unsigned short _isEM = 0;
    unsigned int _EM = 0;
    unsigned short _isNoiseFilter = 0;
    unsigned short _isBaseline = 0;
    unsigned short _isOverScan = 0;
    double _pixelScaleX = 0;
    double _pixelScaleY = 0;
    double _temperature = 0;
    unsigned short _fitsHead = 0;
};

#endif // DPMSTATUS_H
