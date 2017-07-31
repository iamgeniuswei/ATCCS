/********************************************************************************
** Form generated from reading UI file 'DBMWTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMWTITLEBAR_H
#define UI_DBMWTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMWTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_logoTag;
    QVBoxLayout *verticalLayout;
    QLabel *_mainTitleTag;
    QLabel *_subTitleTag;
    QSpacerItem *horizontalSpacer;
    QToolButton *_btnClose;

    void setupUi(QWidget *DBMWTitleBar)
    {
        if (DBMWTitleBar->objectName().isEmpty())
            DBMWTitleBar->setObjectName(QStringLiteral("DBMWTitleBar"));
        DBMWTitleBar->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DBMWTitleBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _logoTag = new QLabel(DBMWTitleBar);
        _logoTag->setObjectName(QStringLiteral("_logoTag"));
        _logoTag->setMaximumSize(QSize(32, 48));
        _logoTag->setPixmap(QPixmap(QString::fromUtf8(":/img/mw_logo")));
        _logoTag->setScaledContents(true);

        horizontalLayout->addWidget(_logoTag);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        _mainTitleTag = new QLabel(DBMWTitleBar);
        _mainTitleTag->setObjectName(QStringLiteral("_mainTitleTag"));

        verticalLayout->addWidget(_mainTitleTag);

        _subTitleTag = new QLabel(DBMWTitleBar);
        _subTitleTag->setObjectName(QStringLiteral("_subTitleTag"));

        verticalLayout->addWidget(_subTitleTag);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _btnClose = new QToolButton(DBMWTitleBar);
        _btnClose->setObjectName(QStringLiteral("_btnClose"));

        horizontalLayout->addWidget(_btnClose);


        retranslateUi(DBMWTitleBar);

        QMetaObject::connectSlotsByName(DBMWTitleBar);
    } // setupUi

    void retranslateUi(QWidget *DBMWTitleBar)
    {
        DBMWTitleBar->setWindowTitle(QApplication::translate("DBMWTitleBar", "DBMWTitleBar", Q_NULLPTR));
        _logoTag->setText(QString());
        _mainTitleTag->setText(QApplication::translate("DBMWTitleBar", "ATCCS DB Manager", Q_NULLPTR));
        _subTitleTag->setText(QApplication::translate("DBMWTitleBar", "Version 1.00.00", Q_NULLPTR));
        _btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBMWTitleBar: public Ui_DBMWTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMWTITLEBAR_H
