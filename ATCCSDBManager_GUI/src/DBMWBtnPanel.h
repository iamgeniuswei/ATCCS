/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMWBtnPanel.h
 * Author: lenovo
 *
 * Created on July 31, 2017, 11:36 AM
 */

#ifndef _DBMWBTNPANEL_H
#define _DBMWBTNPANEL_H

#include "ui_DBMWBtnPanel.h"

class DBMWBtnPanel : public QWidget
{
    Q_OBJECT
public:
    DBMWBtnPanel();
    virtual ~DBMWBtnPanel();
protected:
    void initializeSignal();
signals:
    void initializeBtnClicked();
private:
    Ui::DBMWBtnPanel widget;
};

#endif /* _DBMWBTNPANEL_H */
