/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMStartupBtnPanel.h
 * Author: lenovo
 *
 * Created on July 28, 2017, 11:24 AM
 */

#ifndef _DBMSTARTUPBTNPANEL_H
#define _DBMSTARTUPBTNPANEL_H

#include "ui_DBMStartupBtnPanel.h"

class DBMStartupBtnPanel : public QWidget
{
    Q_OBJECT
public:
    DBMStartupBtnPanel(QWidget *parent = 0);
    virtual ~DBMStartupBtnPanel();

protected:
    void initializeSignal();
signals:
    void cancelBtnClicked();
    void okBtnClicked();
    void testBtnClicked();

private:
    Ui::DBMStartupBtnPanel widget;
};

#endif /* _DBMSTARTUPBTNPANEL_H */
