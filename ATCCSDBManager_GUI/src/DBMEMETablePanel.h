/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DMBEMETablePanel.h
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:39 PM
 */

#ifndef _DMBEMETABLEPANEL_H
#define _DMBEMETABLEPANEL_H

#include "ui_DBMEMETablePanel.h"

class DBMEMETablePanel : public QWidget
{
    Q_OBJECT
public:
    DBMEMETablePanel(QWidget *parent = 0);
    virtual ~DBMEMETablePanel();

protected:
    void initializeSignal();
public slots:
    void selectAll();
    void selectNone();
    void initializeDatabase();
signals:
    void initializeDBFinished(int ret, const QString& msg = QString());
private:
    Ui::DMBEMETablePanel widget;
};

#endif /* _DMBEMETABLEPANEL_H */
