/********************************************************************************
** Form generated from reading UI file 'ATCCSEMDisplayArea.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCCSEMDISPLAYAREA_H
#define UI_ATCCSEMDISPLAYAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCCSEMDisplayArea
{
public:

    void setupUi(QWidget *ATCCSEMDisplayArea)
    {
        if (ATCCSEMDisplayArea->objectName().isEmpty())
            ATCCSEMDisplayArea->setObjectName(QStringLiteral("ATCCSEMDisplayArea"));
        ATCCSEMDisplayArea->resize(400, 300);

        retranslateUi(ATCCSEMDisplayArea);

        QMetaObject::connectSlotsByName(ATCCSEMDisplayArea);
    } // setupUi

    void retranslateUi(QWidget *ATCCSEMDisplayArea)
    {
        ATCCSEMDisplayArea->setWindowTitle(QApplication::translate("ATCCSEMDisplayArea", "ATCCSEMDisplayArea", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCCSEMDisplayArea: public Ui_ATCCSEMDisplayArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCCSEMDISPLAYAREA_H
