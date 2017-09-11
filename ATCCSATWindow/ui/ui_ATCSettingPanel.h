/********************************************************************************
** Form generated from reading UI file 'ATCSettingPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCSETTINGPANEL_H
#define UI_ATCSETTINGPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCSettingPanel
{
public:

    void setupUi(QWidget *ATCSettingPanel)
    {
        if (ATCSettingPanel->objectName().isEmpty())
            ATCSettingPanel->setObjectName(QStringLiteral("ATCSettingPanel"));
        ATCSettingPanel->resize(400, 300);

        retranslateUi(ATCSettingPanel);

        QMetaObject::connectSlotsByName(ATCSettingPanel);
    } // setupUi

    void retranslateUi(QWidget *ATCSettingPanel)
    {
        ATCSettingPanel->setWindowTitle(QApplication::translate("ATCSettingPanel", "ATCSettingPanel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCSettingPanel: public Ui_ATCSettingPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCSETTINGPANEL_H
