/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMASCDataPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:22 AM
 */

#include "EMASCDataPanel.h"

EMASCDataPanel::EMASCDataPanel()
{
    widget.setupUi(this);
    setObjectName("atccs_em_displaypanel");
    setAttribute(Qt::WA_StyledBackground);
    widget._emNameTag->setObjectName("atccs_em_name");
    widget._apertureTag->setObjectName("atccs_em_tag");
    widget._fitsTag->setObjectName("atccs_em_tag");
    widget._isoTag->setObjectName("atccs_em_tag");
    widget._jpegTag->setObjectName("atccs_em_tag");
    widget._rawTag->setObjectName("atccs_em_tag");
    widget._shutterspeedTag->setObjectName("atccs_em_tag");
    widget._shutterSpeedValue->setObjectName("atccs_em_value");
    widget._apertureValue->setObjectName("atccs_em_value");
    widget._fitsValue->setObjectName("atccs_em_value");
    widget._isoValue->setObjectName("atccs_em_value");
    widget._jpegValue->setObjectName("atccs_em_value");
    widget._rawValue->setObjectName("atccs_em_value");
    widget._timeTag->setObjectName("atccs_em_tag");
    
}

EMASCDataPanel::~EMASCDataPanel()
{
}
