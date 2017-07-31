/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWPopupWindowTitleBar.h
 * Author: lenovo
 *
 * Created on June 30, 2017, 8:06 AM
 */

#ifndef QWPOPUPWINDOWTITLEBAR_H
#define QWPOPUPWINDOWTITLEBAR_H
#include <QFrame>
#include <QPointer>
class QLabel;
class QToolButton;
class QHBoxLayout;
class QWPopupWindowTitleBar : public QFrame
{
public:
    QWPopupWindowTitleBar(QWidget *parent = 0);
    QWPopupWindowTitleBar(const QWPopupWindowTitleBar& orig) = delete;
    QWPopupWindowTitleBar(const QWPopupWindowTitleBar&& orig) = delete;
    QWPopupWindowTitleBar& operator=(const QWPopupWindowTitleBar& orig) = delete;
    QWPopupWindowTitleBar& operator=(const QWPopupWindowTitleBar&& orig) = delete;
    virtual ~QWPopupWindowTitleBar();
    
    void setLogo(QPixmap& pixmap);
    
    void setLogoObjectName(const QString& objectName);
    void setTitleObjectName(const QString& objectName);
    void setCloseBtnObjectName(const QString& objectName);
    void initializeUI();

protected:

private:
    QPointer<QLabel> _logoLabel;
    QPointer<QLabel> _titleLabel;
    QPointer<QToolButton> _closeBtn;
    QPointer<QHBoxLayout> _mainLayout;

};

#endif /* QWPOPUPWINDOWTITLEBAR_H */

