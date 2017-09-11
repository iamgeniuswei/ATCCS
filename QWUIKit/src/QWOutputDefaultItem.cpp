/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   QWOutputDefaultItem.cpp
 * Author: lenovo
 *
 * Created on August 2, 2017, 8:31 AM
 */

#include "QWOutputDefaultItem.h"

QWOutputDefaultItem::QWOutputDefaultItem(QWidget *parent)
:QWidget(parent)
{
    widget.setupUi(this);
}

QWOutputDefaultItem::~QWOutputDefaultItem()
{
}

void QWOutputDefaultItem::setIcon(const QPixmap& icon)
{
    if(widget._icon)
        widget._icon->setPixmap(icon);
}

void QWOutputDefaultItem::setText(const QString& text)
{
    if(widget._text)
        widget._text->setText(text);
}


