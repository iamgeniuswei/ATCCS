/********************************************************************************
** Form generated from reading UI file 'ATCSelectionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCSELECTIONWINDOW_H
#define UI_ATCSELECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCSelectionWindow
{
public:

    void setupUi(QWidget *ATCSelectionWindow)
    {
        if (ATCSelectionWindow->objectName().isEmpty())
            ATCSelectionWindow->setObjectName(QStringLiteral("ATCSelectionWindow"));
        ATCSelectionWindow->resize(400, 300);

        retranslateUi(ATCSelectionWindow);

        QMetaObject::connectSlotsByName(ATCSelectionWindow);
    } // setupUi

    void retranslateUi(QWidget *ATCSelectionWindow)
    {
        ATCSelectionWindow->setWindowTitle(QApplication::translate("ATCSelectionWindow", "ATCSelectionWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCSelectionWindow: public Ui_ATCSelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCSELECTIONWINDOW_H
