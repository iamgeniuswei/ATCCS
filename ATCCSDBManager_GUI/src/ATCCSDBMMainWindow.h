/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ATCCSDBMMainWindow.h
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:24 PM
 */

#ifndef _ATCCSDBMMAINWINDOW_H
#define _ATCCSDBMMAINWINDOW_H

#include "QWFramelessWindow.h"
#include "DBMPublicTablePanel.h"
#include "DBMEMETablePanel.h"
#include "DBMAT60TablePanel.h"
#include "DBMWEditPanel.h"
#include "DBMWOutPanel.h"
#include "DBMWTitleBar.h"
#include "DBMWBtnPanel.h"
#include <QPointer>
class QVBoxLayout;
class QWTitleBar;


class ATCCSDBMMainWindow : public QWFramelessWindow
{
    Q_OBJECT
public:
    ATCCSDBMMainWindow(QWidget *parent = 0);
    virtual ~ATCCSDBMMainWindow();
    
protected:
    void initializeUI();
    void initializeSignal();
public slots:
    
private:
    QPointer<QVBoxLayout> _mainLayout;
    QPointer<DBMWTitleBar> _titleBar;
    DBMWEditPanel* _editPanel;
    DBMWOutPanel* _outPanel;
    DBMWBtnPanel *_btnPanel;
    
};

#endif /* _ATCCSDBMMAINWINDOW_H */
