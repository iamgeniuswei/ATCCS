/********************************************************************************
** Form generated from reading UI file 'DBMWOutPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMWOUTPANEL_H
#define UI_DBMWOUTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMWOutPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;

    void setupUi(QWidget *DBMWOutPanel)
    {
        if (DBMWOutPanel->objectName().isEmpty())
            DBMWOutPanel->setObjectName(QStringLiteral("DBMWOutPanel"));
        DBMWOutPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(DBMWOutPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DBMWOutPanel);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(DBMWOutPanel);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(DBMWOutPanel);

        QMetaObject::connectSlotsByName(DBMWOutPanel);
    } // setupUi

    void retranslateUi(QWidget *DBMWOutPanel)
    {
        DBMWOutPanel->setWindowTitle(QApplication::translate("DBMWOutPanel", "DBMWOutPanel", Q_NULLPTR));
        label->setText(QApplication::translate("DBMWOutPanel", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMWOutPanel: public Ui_DBMWOutPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMWOUTPANEL_H
