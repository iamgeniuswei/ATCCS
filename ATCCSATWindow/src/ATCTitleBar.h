/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCTitleBar.h
 * Author: lenovo
 *
 * Created on August 3, 2017, 11:17 AM
 */

#ifndef _ATCTITLEBAR_H
#define _ATCTITLEBAR_H

#include "ui_ATCTitleBar.h"

class ATCTitleBar : public QWidget
{
    Q_OBJECT
public:
    ATCTitleBar(QWidget *parent = 0);
    virtual ~ATCTitleBar();

signals:
    void settingClicked();
    void minClicked();
    void maxClicked();
    void closeClicked();
    
    
protected:
    void initializeUI();
    void initializeSignal();
    
        
private:
    Ui::ATCTitleBar widget;
};

#endif /* _ATCTITLEBAR_H */
