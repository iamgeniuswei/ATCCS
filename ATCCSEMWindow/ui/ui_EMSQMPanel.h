/********************************************************************************
** Form generated from reading UI file 'EMSQMPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMSQMPANEL_H
#define UI_EMSQMPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMSQMPanel
{
public:

    void setupUi(QWidget *EMSQMPanel)
    {
        if (EMSQMPanel->objectName().isEmpty())
            EMSQMPanel->setObjectName(QStringLiteral("EMSQMPanel"));
        EMSQMPanel->resize(400, 300);

        retranslateUi(EMSQMPanel);

        QMetaObject::connectSlotsByName(EMSQMPanel);
    } // setupUi

    void retranslateUi(QWidget *EMSQMPanel)
    {
        EMSQMPanel->setWindowTitle(QApplication::translate("EMSQMPanel", "EMSQMPanel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMSQMPanel: public Ui_EMSQMPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMSQMPANEL_H
