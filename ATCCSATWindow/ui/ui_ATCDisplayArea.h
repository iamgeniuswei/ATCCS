/********************************************************************************
** Form generated from reading UI file 'ATCDisplayArea.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATCDISPLAYAREA_H
#define UI_ATCDISPLAYAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATCDisplayArea
{
public:

    void setupUi(QWidget *ATCDisplayArea)
    {
        if (ATCDisplayArea->objectName().isEmpty())
            ATCDisplayArea->setObjectName(QStringLiteral("ATCDisplayArea"));
        ATCDisplayArea->resize(400, 300);

        retranslateUi(ATCDisplayArea);

        QMetaObject::connectSlotsByName(ATCDisplayArea);
    } // setupUi

    void retranslateUi(QWidget *ATCDisplayArea)
    {
        ATCDisplayArea->setWindowTitle(QApplication::translate("ATCDisplayArea", "ATCDisplayArea", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ATCDisplayArea: public Ui_ATCDisplayArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATCDISPLAYAREA_H
