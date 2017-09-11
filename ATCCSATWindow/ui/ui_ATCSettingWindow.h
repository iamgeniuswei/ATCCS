/********************************************************************************
** Form generated from reading UI file 'ATCSettingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCSETTINGWINDOW_H
#define UI_ATCSETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCSettingWindow
{
public:

    void setupUi(QWidget *ATCSettingWindow)
    {
        if (ATCSettingWindow->objectName().isEmpty())
            ATCSettingWindow->setObjectName(QStringLiteral("ATCSettingWindow"));
        ATCSettingWindow->resize(400, 300);

        retranslateUi(ATCSettingWindow);

        QMetaObject::connectSlotsByName(ATCSettingWindow);
    } // setupUi

    void retranslateUi(QWidget *ATCSettingWindow)
    {
        ATCSettingWindow->setWindowTitle(QApplication::translate("ATCSettingWindow", "ATCSettingWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCSettingWindow: public Ui_ATCSettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCSETTINGWINDOW_H
