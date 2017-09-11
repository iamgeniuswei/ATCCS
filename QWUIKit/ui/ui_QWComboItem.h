/********************************************************************************
** Form generated from reading UI file 'QWComboItem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWCOMBOITEM_H
#define UI_QWCOMBOITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWComboItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *_logo;
    QLabel *_text;

    void setupUi(QWidget *QWComboItem)
    {
        if (QWComboItem->objectName().isEmpty())
            QWComboItem->setObjectName(QStringLiteral("QWComboItem"));
        QWComboItem->resize(400, 241);
        horizontalLayout = new QHBoxLayout(QWComboItem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _logo = new QLabel(QWComboItem);
        _logo->setObjectName(QStringLiteral("_logo"));

        horizontalLayout->addWidget(_logo);

        _text = new QLabel(QWComboItem);
        _text->setObjectName(QStringLiteral("_text"));

        horizontalLayout->addWidget(_text);

        horizontalLayout->setStretch(1, 1);

        retranslateUi(QWComboItem);

        QMetaObject::connectSlotsByName(QWComboItem);
    } // setupUi

    void retranslateUi(QWidget *QWComboItem)
    {
        QWComboItem->setWindowTitle(QApplication::translate("QWComboItem", "QWComboItem", Q_NULLPTR));
        _logo->setText(QApplication::translate("QWComboItem", "TextLabel", Q_NULLPTR));
        _text->setText(QApplication::translate("QWComboItem", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QWComboItem: public Ui_QWComboItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWCOMBOITEM_H
