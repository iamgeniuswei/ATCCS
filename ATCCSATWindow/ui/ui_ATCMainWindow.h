/********************************************************************************
** Form generated from reading UI file 'ATCMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCMAINWINDOW_H
#define UI_ATCMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCMainWindow
{
public:

    void setupUi(QWidget *ATCMainWindow)
    {
        if (ATCMainWindow->objectName().isEmpty())
            ATCMainWindow->setObjectName(QStringLiteral("ATCMainWindow"));
        ATCMainWindow->resize(400, 300);

        retranslateUi(ATCMainWindow);

        QMetaObject::connectSlotsByName(ATCMainWindow);
    } // setupUi

    void retranslateUi(QWidget *ATCMainWindow)
    {
        ATCMainWindow->setWindowTitle(QApplication::translate("ATCMainWindow", "ATCMainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCMainWindow: public Ui_ATCMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCMAINWINDOW_H
