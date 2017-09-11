/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWOutputPanel.h
 * Author: lenovo
 *
 * Created on August 2, 2017, 8:30 AM
 */

#ifndef _QWOUTPUTPANEL_H
#define _QWOUTPUTPANEL_H

#include "ui_QWOutputPanel.h"

class QWOutputPanel : public QWidget
{
    Q_OBJECT
public:
    QWOutputPanel();
    virtual ~QWOutputPanel();
private:
    Ui::QWOutputPanel widget;
};

#endif /* _QWOUTPUTPANEL_H */
