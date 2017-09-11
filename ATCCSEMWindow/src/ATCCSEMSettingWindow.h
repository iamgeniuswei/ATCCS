/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSEMSettingWindow.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 11:24 AM
 */

#ifndef _ATCCSEMSETTINGWINDOW_H
#define _ATCCSEMSETTINGWINDOW_H

#include "ui_ATCCSEMSettingWindow.h"
#include "EMLocalAddressPanel.h"
#include "EMDBAddressPanel.h"
#include "EMDisplaySetPanel.h"
#include <QScrollArea>
#include "QWUIInitializer.h"
#include "QWFramelessWindow.h"
#include "EMSettingTilteBar.h"

class ATCCSEMSettingWindow : public QWFramelessWindow, protected QWUIInitializer
{
    Q_OBJECT
public:
    ATCCSEMSettingWindow(QWidget *parent = 0);
    virtual ~ATCCSEMSettingWindow();

protected:

    virtual void initializeUI();
    virtual void initializeSignal();


private:
    //    Ui::ATCCSEMSettingWindow widget;
    QScrollArea *_scrollArea;
    EMSettingTilteBar *_titleBar;
    QWidget *_contentWidget;
    QVBoxLayout *_mainLayout;
    QVBoxLayout *_scrollLayout;
    EMLocalAddressPanel *_localPanel;
    EMDBAddressPanel *_dbPanel;
    EMDisplaySetPanel *_displayPanel;
};

#endif /* _ATCCSEMSETTINGWINDOW_H */
