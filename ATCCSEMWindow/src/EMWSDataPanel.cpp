/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EMWSDataPanel.cpp
 * Author: lenovo
 *
 * Created on August 1, 2017, 9:43 AM
 */

#include "EMWSDataPanel.h"

EMWSDataPanel::EMWSDataPanel()
{
    widget.setupUi(this);
    setObjectName("atccs_em_displaypanel");
    setAttribute(Qt::WA_StyledBackground);
    QObjectList child = this->children();
    for (auto it : child)
    {
        QLabel *item = qobject_cast<QLabel*>(it);
        if(item && item->objectName().contains("Tag"))
            item->setObjectName("atccs_em_tag");
        else if(item && item->objectName().contains("Value"))
            item->setObjectName("atccs_em_value");
    }
    widget._emName->setObjectName("atccs_em_name");    

}

EMWSDataPanel::~EMWSDataPanel()
{
}
