/********************************************************************************
** Form generated from reading UI file 'DBMWEditPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMWEDITPANEL_H
#define UI_DBMWEDITPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMWEditPancel
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *_btnInitialize;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DBMWEditPancel)
    {
        if (DBMWEditPancel->objectName().isEmpty())
            DBMWEditPancel->setObjectName(QStringLiteral("DBMWEditPancel"));
        DBMWEditPancel->resize(860, 488);
        verticalLayout = new QVBoxLayout(DBMWEditPancel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(DBMWEditPancel);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 840, 436));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _btnInitialize = new QPushButton(DBMWEditPancel);
        _btnInitialize->setObjectName(QStringLiteral("_btnInitialize"));

        horizontalLayout->addWidget(_btnInitialize);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DBMWEditPancel);

        QMetaObject::connectSlotsByName(DBMWEditPancel);
    } // setupUi

    void retranslateUi(QWidget *DBMWEditPancel)
    {
        DBMWEditPancel->setWindowTitle(QApplication::translate("DBMWEditPancel", "DBMWEditPancel", Q_NULLPTR));
        _btnInitialize->setText(QApplication::translate("DBMWEditPancel", "Initialize", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMWEditPancel: public Ui_DBMWEditPancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMWEDITPANEL_H
