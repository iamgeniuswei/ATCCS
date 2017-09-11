/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMCSDataPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:46 AM
 */

#include "EMCSDataPanel.h"

EMCSDataPanel::EMCSDataPanel()
{
    widget.setupUi(this);
    setObjectName("atccs_em_displaypanel");
    setAttribute(Qt::WA_StyledBackground);
    widget._emNameTag->setObjectName("atccs_em_name");
    widget._ambientTag->setObjectName("atccs_em_tag");
    widget._daylightTag->setObjectName("atccs_em_tag");
    widget._dewpointTag->setObjectName("atccs_em_tag");
    widget._humidityTag->setObjectName("atccs_em_tag");
    widget._rainTag->setObjectName("atccs_em_tag");
    widget._rainthreshTag->setObjectName("atccs_em_tag");
    widget._relskyTag->setObjectName("atccs_em_tag");
    widget._sensorTag->setObjectName("atccs_em_tag");
    widget._timeTag->setObjectName("atccs_em_tag");
    widget._windTag->setObjectName("atccs_em_tag");
    widget._windunitTag->setObjectName("atccs_em_tag");
    widget._ambientValue->setObjectName("atccs_em_value");
    widget._daylightValue->setObjectName("atccs_em_value");
    widget._dewpointValue->setObjectName("atccs_em_value");
    widget._humidityValue->setObjectName("atccs_em_value");
    widget._rainValue->setObjectName("atccs_em_value");
    widget._rainthreshValue->setObjectName("atccs_em_value");
    widget._relskyValue->setObjectName("atccs_em_value");
    widget._sensorValue->setObjectName("atccs_em_value");
    widget._windValue->setObjectName("atccs_em_value");
    widget._windunitValue->setObjectName("atccs_em_value");
    
}

EMCSDataPanel::~EMCSDataPanel()
{
}
