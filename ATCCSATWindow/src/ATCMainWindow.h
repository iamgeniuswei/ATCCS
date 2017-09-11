/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCMainWindow.h
 * Author: lenovo
 *
 * Created on August 3, 2017, 5:50 PM
 */

#ifndef _ATCMAINWINDOW_H
#define _ATCMAINWINDOW_H

#include "ui_ATCMainWindow.h"
#include "ATCTitleBar.h"
#include "ATCDisplayArea.h"
#include "QWOutputPanel.h"
#include "QWFramelessWindow.h"
class ATCMainWindow : public QWFramelessWindow
{
    Q_OBJECT
public:
    ATCMainWindow();
    virtual ~ATCMainWindow();
    

    virtual void paintEvent(QPaintEvent* event);

    protected:
        void initializeSignal();
    
    
private:
    ATCTitleBar *_titleBar;
    ATCDisplayArea *_displayArea;
    QWOutputPanel *_outputArea;
    QVBoxLayout *_mainLayout;
};

#endif /* _ATCMAINWINDOW_H */
