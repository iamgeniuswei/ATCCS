/********************************************************************************
** Form generated from reading UI file 'DBMWOutputItem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMWOUTPUTITEM_H
#define UI_DBMWOUTPUTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMWOutputItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_icon;
    QLabel *_text;

    void setupUi(QWidget *DBMWOutputItem)
    {
        if (DBMWOutputItem->objectName().isEmpty())
            DBMWOutputItem->setObjectName(QStringLiteral("DBMWOutputItem"));
        DBMWOutputItem->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DBMWOutputItem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _icon = new QLabel(DBMWOutputItem);
        _icon->setObjectName(QStringLiteral("_icon"));
        _icon->setMaximumSize(QSize(18, 18));
        _icon->setScaledContents(true);

        horizontalLayout->addWidget(_icon);

        _text = new QLabel(DBMWOutputItem);
        _text->setObjectName(QStringLiteral("_text"));

        horizontalLayout->addWidget(_text);


        retranslateUi(DBMWOutputItem);

        QMetaObject::connectSlotsByName(DBMWOutputItem);
    } // setupUi

    void retranslateUi(QWidget *DBMWOutputItem)
    {
        DBMWOutputItem->setWindowTitle(QApplication::translate("DBMWOutputItem", "DBMWOutputItem", Q_NULLPTR));
        _icon->setText(QString());
        _text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBMWOutputItem: public Ui_DBMWOutputItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMWOUTPUTITEM_H
