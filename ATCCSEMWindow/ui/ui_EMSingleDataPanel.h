/********************************************************************************
** Form generated from reading UI file 'EMSingleDataPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMSINGLEDATAPANEL_H
#define UI_EMSINGLEDATAPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMSingleDataPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *_emNameTag;
    QSpacerItem *horizontalSpacer_2;
    QLabel *_valueTag;
    QLabel *_timeTag;

    void setupUi(QWidget *EMSingleDataPanel)
    {
        if (EMSingleDataPanel->objectName().isEmpty())
            EMSingleDataPanel->setObjectName(QStringLiteral("EMSingleDataPanel"));
        EMSingleDataPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(EMSingleDataPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _emNameTag = new QLabel(EMSingleDataPanel);
        _emNameTag->setObjectName(QStringLiteral("_emNameTag"));
        _emNameTag->setScaledContents(true);
        _emNameTag->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(_emNameTag);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        _valueTag = new QLabel(EMSingleDataPanel);
        _valueTag->setObjectName(QStringLiteral("_valueTag"));
        _valueTag->setScaledContents(true);
        _valueTag->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_valueTag);

        _timeTag = new QLabel(EMSingleDataPanel);
        _timeTag->setObjectName(QStringLiteral("_timeTag"));
        _timeTag->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_timeTag);


        retranslateUi(EMSingleDataPanel);

        QMetaObject::connectSlotsByName(EMSingleDataPanel);
    } // setupUi

    void retranslateUi(QWidget *EMSingleDataPanel)
    {
        EMSingleDataPanel->setWindowTitle(QApplication::translate("EMSingleDataPanel", "EMSingleDataPanel", Q_NULLPTR));
        _emNameTag->setText(QApplication::translate("EMSingleDataPanel", "TextLabel", Q_NULLPTR));
        _valueTag->setText(QApplication::translate("EMSingleDataPanel", "TextLabel", Q_NULLPTR));
        _timeTag->setText(QApplication::translate("EMSingleDataPanel", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMSingleDataPanel: public Ui_EMSingleDataPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMSINGLEDATAPANEL_H
