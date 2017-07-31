/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMAT60TablePanel.h
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:42 PM
 */

#ifndef _DBMAT60TABLEPANEL_H
#define _DBMAT60TABLEPANEL_H

#include "ui_DBMAT60TablePanel.h"

class DBMAT60TablePanel : public QWidget
{
    Q_OBJECT
public:
    DBMAT60TablePanel(QWidget *parent = 0);
    virtual ~DBMAT60TablePanel();

protected:
    void initializeSignal();
public slots:
    void selectAll();
    void selectNone();
    void initializeDatabase();
signals:
    void initializeDBFinished(int ret, const QString& msg = QString());
    
private:
    Ui::DBMAT60TablePanel widget;
};

#endif /* _DBMAT60TABLEPANEL_H */
