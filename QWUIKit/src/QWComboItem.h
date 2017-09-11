/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWComboItem.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 10:01 AM
 */

#ifndef _QWCOMBOITEM_H
#define _QWCOMBOITEM_H

#include "ui_QWComboItem.h"

class QWComboItem : public QWidget
{
    Q_OBJECT
public:
    QWComboItem();
    virtual ~QWComboItem();
private:
    Ui::QWComboItem widget;
};

#endif /* _QWCOMBOITEM_H */
