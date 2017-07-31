/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMStarupEditPanel.h
 * Author: lenovo
 *
 * Created on July 28, 2017, 11:42 AM
 */

#ifndef _DBMSTARUPEDITPANEL_H
#define _DBMSTARUPEDITPANEL_H

#include "ui_DBMStarupEditPanel.h"

class DBMStarupEditPanel : public QWidget
{
    Q_OBJECT
public:
    DBMStarupEditPanel(QWidget *parent = 0);
    virtual ~DBMStarupEditPanel();
protected:
    void initializeUI();
public slots:
    void connectToDatabase();
signals:
    void successToConnectDB();

private:
    Ui::DBMStarupEditPanel widget;
};

#endif /* _DBMSTARUPEDITPANEL_H */
