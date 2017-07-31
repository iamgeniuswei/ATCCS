/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DBMWOutputItem.cpp
 * Author: lenovo
 *
 * Created on July 31, 2017, 4:28 PM
 */

#include "DBMWOutputItem.h"


DBMWOutputItem::DBMWOutputItem(int icon, const QString& msg, QWidget* parent)
{
    widget.setupUi(this);
    switch(icon)
    {
        case 0:
            widget._icon->setPixmap(QPixmap(":/img/success"));
            break;
        case 1:
            widget._icon->setPixmap(QPixmap(":/img/fail"));
            break;
    }
    widget._text->setText(msg);
}



DBMWOutputItem::~DBMWOutputItem()
{
}
