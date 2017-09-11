/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCDisplayArea.cpp
 * Author: lenovo
 *
 * Created on August 3, 2017, 5:38 PM
 */

#include "ATCDisplayArea.h"

ATCDisplayArea::ATCDisplayArea()
{
    _mainLayout = new QGridLayout(this);
    setLayout(_mainLayout);
}

ATCDisplayArea::~ATCDisplayArea()
{
}

void ATCDisplayArea::addDevicePanel(unsigned int type, const QString& name)
{
    auto it = _panelMap.find(type);
    if(it == _panelMap.end())
    {
        ATCDevicePanel *newPanel = new ATCDevicePanel();
        
        newPanel->setDeviceProperty(type, name);
        _panelMap.insert(type, newPanel);
        _panelMap.size() >= 4 ?
            _mainLayout->addWidget(newPanel, 1, _panelMap.size()-4):
            _mainLayout->addWidget(newPanel, 0, _panelMap.size()-1);        
    }
}
