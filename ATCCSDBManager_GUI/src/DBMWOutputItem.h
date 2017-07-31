/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMWOutputItem.h
 * Author: lenovo
 *
 * Created on July 31, 2017, 4:28 PM
 */

#ifndef _DBMWOUTPUTITEM_H
#define _DBMWOUTPUTITEM_H

#include "ui_DBMWOutputItem.h"

class DBMWOutputItem : public QWidget
{
    enum ICON
    {
        SUCCESS,
        FAIL
    };
    
    Q_OBJECT
public:
    DBMWOutputItem(int icon, const QString& msg, QWidget *parent = 0);
    virtual ~DBMWOutputItem();
    
private:
    Ui::DBMWOutputItem widget;
};

#endif /* _DBMWOUTPUTITEM_H */
