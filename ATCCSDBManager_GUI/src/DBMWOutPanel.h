/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMWOutPanel.h
 * Author: lenovo
 *
 * Created on July 31, 2017, 4:24 PM
 */

#ifndef _DBMWOUTPANEL_H
#define _DBMWOUTPANEL_H

#include "ui_DBMWOutPanel.h"

class DBMWOutPanel : public QWidget
{
    Q_OBJECT
public:
    DBMWOutPanel();
    virtual ~DBMWOutPanel();
    
    protected:
        void initializeUI();

public slots:
    void updateOutput(int ret, const QString &msg = QString());
private:
    Ui::DBMWOutPanel widget;
};

#endif /* _DBMWOUTPANEL_H */
