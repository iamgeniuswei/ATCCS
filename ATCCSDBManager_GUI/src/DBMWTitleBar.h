/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMWTitleBar.h
 * Author: lenovo
 *
 * Created on July 31, 2017, 10:07 AM
 */

#ifndef _DBMWTITLEBAR_H
#define _DBMWTITLEBAR_H

#include "ui_DBMWTitleBar.h"

class DBMWTitleBar : public QWidget
{
    Q_OBJECT
public:
    DBMWTitleBar();
    virtual ~DBMWTitleBar();

protected:
    void initializeUI();
private:
    Ui::DBMWTitleBar widget;
};

#endif /* _DBMWTITLEBAR_H */
