/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWButtonPanel.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 9:09 AM
 */

#ifndef _QWBUTTONPANEL_H
#define _QWBUTTONPANEL_H

#include "ui_QWButtonPanel.h"

class QWButtonPanel : public QWidget
{
    Q_OBJECT
public:
    QWButtonPanel(QWidget *parent = 0);
    virtual ~QWButtonPanel();
    signals:
    void okClicked();
    void cancelClicked();
    
private:
    Ui::QWButtonPanel widget;
};

#endif /* _QWBUTTONPANEL_H */
