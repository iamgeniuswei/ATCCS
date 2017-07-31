/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DBMWEditPancel.h
 * Author: lenovo
 *
 * Created on July 29, 2017, 7:57 PM
 */

#ifndef _DBMWEDITPANCEL_H
#define _DBMWEDITPANCEL_H

#include "ui_DBMWEditPancel.h"
#include "DBMAT60TablePanel.h"
#include <QScrollArea>
#include <QPointer>

class DBMPublicTablePanel;
class DBMAT60TablePanel;
class DBMEMETablePanel;
class QVBoxLayout;

class DBMWEditPanel : public QScrollArea
{
    Q_OBJECT
public:
    DBMWEditPanel(QWidget *parent = 0);
    virtual ~DBMWEditPanel();
public slots:
    void selectAll();
    void selectNone();
signals:
    void initializeDatabase();
    void initializeDBFinished(int ret, const QString &msg = QString());


protected:
    void initializeUI();
    void initializeSignal();
private:
    QPointer<QWidget> _contentWidget;
    QPointer<QVBoxLayout> _mainLayout;
    DBMPublicTablePanel* _publicPanel;
    DBMEMETablePanel* _emePanel;
    DBMAT60TablePanel* _at60Panel;
};

#endif /* _DBMWEDITPANCEL_H */
