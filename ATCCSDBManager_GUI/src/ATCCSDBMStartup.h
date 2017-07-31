/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDBMStartup.h
 * Author: lenovo
 *
 * Created on July 28, 2017, 10:13 AM
 */

#ifndef _ATCCSDBMSTARTUP_H
#define _ATCCSDBMSTARTUP_H
#include <QPointer>
#include "ui_ATCCSDBMStartup.h"
#include "QWFramelessWindow.h"
class QWPopupWindowTitleBar;
class DBMStartupBtnPanel;
class DBMStarupEditPanel;
class QVBoxLayout;
class ATCCSDBMStartup : public QWFramelessWindow
{
    Q_OBJECT
public:
    ATCCSDBMStartup(QWidget *parent = 0);
    virtual ~ATCCSDBMStartup();
    
public slots:
    void showATCCSDBMainWindow();
protected:
    void initializeUI();
    void initializeSignal();
private:
    QPointer<QWPopupWindowTitleBar> _titleBar;
    DBMStartupBtnPanel* _btnPanel;
    DBMStarupEditPanel* _editPanel;
    QPointer<QVBoxLayout> _mainLayout;
    
};

#endif /* _ATCCSDBMSTARTUP_H */
