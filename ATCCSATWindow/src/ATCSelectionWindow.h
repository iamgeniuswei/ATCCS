/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCSelectionWindow.h
 * Author: lenovo
 *
 * Created on August 4, 2017, 9:01 AM
 */

#ifndef _ATCSELECTIONWINDOW_H
#define _ATCSELECTIONWINDOW_H

#include "ui_ATCSelectionWindow.h"
#include "QWFramelessWindow.h"
#include "ATCSelectionPanel.h"
#include "QWButtonPanel.h"
#include "QWPopupTitleBar.h"
class QVBoxLayout;
class QWPopupTitleBar;
class ATCSelectionWindow : public QWFramelessWindow
{
    Q_OBJECT
public:
    ATCSelectionWindow();
    virtual ~ATCSelectionWindow();

    virtual void paintEvent(QPaintEvent* event);

    void initializeSignal();
    
public slots:
    void showMainWindow();
private:
    QVBoxLayout *_mainLayout;
    QWPopupTitleBar *_titleBar;
    QLabel *_spliterTop;
    QLabel *_spliterBottom;
    ATCSelectionPanel *_selectionPanel;
    QWButtonPanel *_btnPanel;
};

#endif /* _ATCSELECTIONWINDOW_H */
