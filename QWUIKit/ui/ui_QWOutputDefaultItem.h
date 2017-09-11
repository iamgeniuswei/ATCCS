/********************************************************************************
** Form generated from reading UI file 'QWOutputDefaultItem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWOUTPUTDEFAULTITEM_H
#define UI_QWOUTPUTDEFAULTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWOutputDefaultItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_icon;
    QLabel *_text;

    void setupUi(QWidget *QWOutputDefaultItem)
    {
        if (QWOutputDefaultItem->objectName().isEmpty())
            QWOutputDefaultItem->setObjectName(QStringLiteral("QWOutputDefaultItem"));
        QWOutputDefaultItem->resize(400, 114);
        horizontalLayout = new QHBoxLayout(QWOutputDefaultItem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        _icon = new QLabel(QWOutputDefaultItem);
        _icon->setObjectName(QStringLiteral("_icon"));
        _icon->setScaledContents(true);

        horizontalLayout->addWidget(_icon);

        _text = new QLabel(QWOutputDefaultItem);
        _text->setObjectName(QStringLiteral("_text"));
        _text->setScaledContents(true);

        horizontalLayout->addWidget(_text);

        horizontalLayout->setStretch(1, 1);

        retranslateUi(QWOutputDefaultItem);

        QMetaObject::connectSlotsByName(QWOutputDefaultItem);
    } // setupUi

    void retranslateUi(QWidget *QWOutputDefaultItem)
    {
        QWOutputDefaultItem->setWindowTitle(QApplication::translate("QWOutputDefaultItem", "QWOutputDefaultItem", Q_NULLPTR));
        _icon->setText(QString());
        _text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QWOutputDefaultItem: public Ui_QWOutputDefaultItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWOUTPUTDEFAULTITEM_H
