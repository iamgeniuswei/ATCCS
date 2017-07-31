/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMPublicTablePanel.h
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:32 PM
 */

#ifndef _DBMPUBLICTABLEPANEL_H
#define _DBMPUBLICTABLEPANEL_H

#include "ui_DBMPublicTablePanel.h"

class DBMPublicTablePanel : public QWidget
{
    enum RETCODE
    {
        SUCCESS,
        FAIL
    };
    
    Q_OBJECT
public:
    DBMPublicTablePanel(QWidget *parent = 0);
    virtual ~DBMPublicTablePanel();

protected:
    void initializeSignal();
public slots:
    void selectAll();
    void selectNone();
    void initializeDatabase();
signals:
    void initializeDBFinished(int ret, const QString& msg = QString());
private:
    Ui::DBMPublicTablePanel widget;
};

#endif /* _DBMPUBLICTABLEPANEL_H */
