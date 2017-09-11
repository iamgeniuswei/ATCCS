/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCCSEMDisplayArea.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 3:57 PM
 */

#include "ATCCSEMDisplayArea.h"
#include <QGridLayout>
ATCCSEMDisplayArea::ATCCSEMDisplayArea(QWidget *parent)
:QWidget(parent)
{
    initializeUI();
}

ATCCSEMDisplayArea::~ATCCSEMDisplayArea()
{
}

void ATCCSEMDisplayArea::initializeUI()
{
    _mainLayout = new QGridLayout(this);
    setLayout(_mainLayout);
}

void ATCCSEMDisplayArea::addEMDisplayPanel(QWidget* panel)
{
    if(panel)
    {        
        _panelCount++ < 4 ? 
            _mainLayout->addWidget(panel, 0, _panelCount, 1, 1):
            _mainLayout->addWidget(panel, 1, _panelCount-4, 1, 1);            
    }
}
