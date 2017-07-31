/********************************************************************************
** Form generated from reading UI file 'DBMWBtnPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMWBTNPANEL_H
#define UI_DBMWBTNPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMWBtnPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *_btnInitialize;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DBMWBtnPanel)
    {
        if (DBMWBtnPanel->objectName().isEmpty())
            DBMWBtnPanel->setObjectName(QStringLiteral("DBMWBtnPanel"));
        DBMWBtnPanel->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DBMWBtnPanel);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _btnInitialize = new QPushButton(DBMWBtnPanel);
        _btnInitialize->setObjectName(QStringLiteral("_btnInitialize"));

        horizontalLayout->addWidget(_btnInitialize);

        horizontalSpacer_2 = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(DBMWBtnPanel);

        QMetaObject::connectSlotsByName(DBMWBtnPanel);
    } // setupUi

    void retranslateUi(QWidget *DBMWBtnPanel)
    {
        DBMWBtnPanel->setWindowTitle(QApplication::translate("DBMWBtnPanel", "DBMWBtnPanel", Q_NULLPTR));
        _btnInitialize->setText(QApplication::translate("DBMWBtnPanel", "Initialize", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMWBtnPanel: public Ui_DBMWBtnPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMWBTNPANEL_H
