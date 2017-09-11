/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSEMWindow.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:36 AM
 */

#ifndef _ATCCSEMWINDOW_H
#define _ATCCSEMWINDOW_H

#include "ui_ATCCSEMWindow.h"
#include "QWFramelessWindow.h"
#include "ATCCSEMTitleBar.h"
#include "QWUIInitializer.h"
#include "ATCCSEMDisplayArea.h"
class QWOutputPanel;
class ATCCSEMWindow : public QWFramelessWindow, protected QWUIInitializer
{
    Q_OBJECT
public:
    ATCCSEMWindow(QWidget *parent = 0);
    virtual ~ATCCSEMWindow();
protected:
    virtual void initializeUI();
    void initializeSignal() override;
    
public slots:
    void showSettingWindow();
    


private:
    QVBoxLayout *_mainLayout;
    ATCCSEMTitleBar *_titleBar;
    ATCCSEMDisplayArea *_displayArea;
    QWOutputPanel *_outputArea;
    
};

#endif /* _ATCCSEMWINDOW_H */
