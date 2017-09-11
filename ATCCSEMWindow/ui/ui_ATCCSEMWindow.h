/********************************************************************************
** Form generated from reading UI file 'ATCCSEMWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCCSEMWINDOW_H
#define UI_ATCCSEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCCSEMWindow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *_emNameTag;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ATCCSEMWindow)
    {
        if (ATCCSEMWindow->objectName().isEmpty())
            ATCCSEMWindow->setObjectName(QStringLiteral("ATCCSEMWindow"));
        ATCCSEMWindow->resize(400, 300);
        widget = new QWidget(ATCCSEMWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(110, 10, 158, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _emNameTag = new QLabel(widget);
        _emNameTag->setObjectName(QStringLiteral("_emNameTag"));

        horizontalLayout->addWidget(_emNameTag);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(ATCCSEMWindow);

        QMetaObject::connectSlotsByName(ATCCSEMWindow);
    } // setupUi

    void retranslateUi(QWidget *ATCCSEMWindow)
    {
        ATCCSEMWindow->setWindowTitle(QApplication::translate("ATCCSEMWindow", "ATCCSEMWindow", Q_NULLPTR));
        _emNameTag->setText(QApplication::translate("ATCCSEMWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCCSEMWindow: public Ui_ATCCSEMWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCCSEMWINDOW_H
