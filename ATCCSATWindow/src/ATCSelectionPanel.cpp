/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ATCSelectionPanel.cpp
 * Author: lenovo
 *
 * Created on August 4, 2017, 9:12 AM
 */

#include "ATCSelectionPanel.h"

ATCSelectionPanel::ATCSelectionPanel()
{
    widget.setupUi(this);
}

ATCSelectionPanel::~ATCSelectionPanel()
{
}

void ATCSelectionPanel::addATItem(unsigned int type, const QString& text)
{    
    widget._items->insertItem(_index, QIcon(":/img/telescope_logo_combo"), text);
    _itmeMap.insert(_index, type);
    _index++;
}

unsigned int ATCSelectionPanel::at()
{
    return _itmeMap.value(widget._items->currentIndex());
}
