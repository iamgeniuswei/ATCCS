/********************************************************************************
** Form generated from reading UI file 'ATCCSEMTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCCSEMTITLEBAR_H
#define UI_ATCCSEMTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCCSEMTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_logoTag;
    QVBoxLayout *verticalLayout;
    QLabel *_mainTitleTag;
    QLabel *_subTitleTag;
    QToolButton *_setting;
    QToolButton *_close;

    void setupUi(QWidget *ATCCSEMTitleBar)
    {
        if (ATCCSEMTitleBar->objectName().isEmpty())
            ATCCSEMTitleBar->setObjectName(QStringLiteral("ATCCSEMTitleBar"));
        ATCCSEMTitleBar->resize(400, 66);
        ATCCSEMTitleBar->setMaximumSize(QSize(16777215, 66));
        horizontalLayout = new QHBoxLayout(ATCCSEMTitleBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _logoTag = new QLabel(ATCCSEMTitleBar);
        _logoTag->setObjectName(QStringLiteral("_logoTag"));
        _logoTag->setMaximumSize(QSize(32, 48));
        _logoTag->setPixmap(QPixmap(QString::fromUtf8(":/img/mw_logo")));
        _logoTag->setScaledContents(true);

        horizontalLayout->addWidget(_logoTag);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        _mainTitleTag = new QLabel(ATCCSEMTitleBar);
        _mainTitleTag->setObjectName(QStringLiteral("_mainTitleTag"));
        _mainTitleTag->setScaledContents(true);

        verticalLayout->addWidget(_mainTitleTag);

        _subTitleTag = new QLabel(ATCCSEMTitleBar);
        _subTitleTag->setObjectName(QStringLiteral("_subTitleTag"));

        verticalLayout->addWidget(_subTitleTag);


        horizontalLayout->addLayout(verticalLayout);

        _setting = new QToolButton(ATCCSEMTitleBar);
        _setting->setObjectName(QStringLiteral("_setting"));

        horizontalLayout->addWidget(_setting);

        _close = new QToolButton(ATCCSEMTitleBar);
        _close->setObjectName(QStringLiteral("_close"));
        _close->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(_close);


        retranslateUi(ATCCSEMTitleBar);

        QMetaObject::connectSlotsByName(ATCCSEMTitleBar);
    } // setupUi

    void retranslateUi(QWidget *ATCCSEMTitleBar)
    {
        ATCCSEMTitleBar->setWindowTitle(QApplication::translate("ATCCSEMTitleBar", "ATCCSEMTitleBar", Q_NULLPTR));
        _logoTag->setText(QString());
        _mainTitleTag->setText(QApplication::translate("ATCCSEMTitleBar", "\350\256\276\345\244\207\346\216\247\345\210\266\345\231\250", Q_NULLPTR));
        _subTitleTag->setText(QApplication::translate("ATCCSEMTitleBar", "Version 1.00.00", Q_NULLPTR));
        _setting->setText(QString());
        _close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ATCCSEMTitleBar: public Ui_ATCCSEMTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCCSEMTITLEBAR_H
