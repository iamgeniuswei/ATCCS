/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCSettingWindow.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 3:49 PM
 */

#ifndef _ATCSETTINGWINDOW_H
#define _ATCSETTINGWINDOW_H

#include "QWFramelessWindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include "QWPopupTitleBar.h"
#include "QWButtonPanel.h"
#include "QWLocalAddressPanel.h"
#include "QWDBAddressPanel.h"
#include "qwtimeline.h"
class QScrollArea;
class ATCSettingWindow : public QWFramelessWindow
{
    Q_OBJECT
public:
    ATCSettingWindow();
    virtual ~ATCSettingWindow();
    
    protected:

    virtual void initializeUI();

    
private:
//    Ui::ATCSettingWindow widget;
    QVBoxLayout *_mainLayout;
    QWPopupTitleBar *_titleBar;
    QLabel *_spilterTop;
    QLabel *_spilterBottom;
    QWButtonPanel *_btnPanel;
    QScrollArea *_settingArea;
    QWidget *_settingPanel;
    QGridLayout *_settingLayout;
    QWLocalAddressPanel *_hostPanel;
    QWDBAddressPanel *_dbPanel;
    QWTimeLine *_navigator;
};

#endif /* _ATCSETTINGWINDOW_H */
