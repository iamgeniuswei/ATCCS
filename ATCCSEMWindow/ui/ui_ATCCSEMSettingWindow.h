/********************************************************************************
** Form generated from reading UI file 'ATCCSEMSettingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCCSEMSETTINGWINDOW_H
#define UI_ATCCSEMSETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCCSEMSettingWindow
{
public:

    void setupUi(QWidget *ATCCSEMSettingWindow)
    {
        if (ATCCSEMSettingWindow->objectName().isEmpty())
            ATCCSEMSettingWindow->setObjectName(QStringLiteral("ATCCSEMSettingWindow"));
        ATCCSEMSettingWindow->resize(400, 300);

        retranslateUi(ATCCSEMSettingWindow);

        QMetaObject::connectSlotsByName(ATCCSEMSettingWindow);
    } // setupUi

    void retranslateUi(QWidget *ATCCSEMSettingWindow)
    {
        ATCCSEMSettingWindow->setWindowTitle(QApplication::translate("ATCCSEMSettingWindow", "ATCCSEMSettingWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCCSEMSettingWindow: public Ui_ATCCSEMSettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCCSEMSETTINGWINDOW_H
