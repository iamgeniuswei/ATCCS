/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMSingleDataPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:39 AM
 */

#include "EMSingleDataPanel.h"

EMSingleDataPanel::EMSingleDataPanel()
{
    widget.setupUi(this);
    initializeUI();
    initializeSignal();
    setObjectName("atccs_em_displaypanel");
    setAttribute(Qt::WA_StyledBackground);
}

EMSingleDataPanel::~EMSingleDataPanel()
{
}

void EMSingleDataPanel::initializeUI()
{
    if(widget._emNameTag)
        widget._emNameTag->setObjectName("atccs_em_name");
    if(widget._valueTag)
        widget._valueTag->setObjectName("atccs_em_value");
    if(widget._timeTag)
        widget._timeTag->setObjectName("atccs_em_tag");           
}

void EMSingleDataPanel::initializeSignal()
{

}




void EMSingleDataPanel::setEMName(const QString& name)
{
    if(widget._emNameTag)
        widget._emNameTag->setText(name);            
}

void EMSingleDataPanel::updateData(int value, unsigned int time)
{
    if(widget._valueTag)
        widget._valueTag->setText(QString::number(value));
    if(widget._timeTag)
        widget._timeTag->setText(QString::number(value));
}


