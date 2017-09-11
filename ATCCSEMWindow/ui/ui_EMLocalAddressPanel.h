/********************************************************************************
** Form generated from reading UI file 'EMLocalAddressPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMLOCALADDRESSPANEL_H
#define UI_EMLOCALADDRESSPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMLocalAddressPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *_nameTag;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *_localIPTag;
    QLineEdit *_ip;
    QLabel *_localPortTag;
    QLineEdit *_port;
    QFrame *line;

    void setupUi(QWidget *EMLocalAddressPanel)
    {
        if (EMLocalAddressPanel->objectName().isEmpty())
            EMLocalAddressPanel->setObjectName(QStringLiteral("EMLocalAddressPanel"));
        EMLocalAddressPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(EMLocalAddressPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _nameTag = new QLabel(EMLocalAddressPanel);
        _nameTag->setObjectName(QStringLiteral("_nameTag"));

        horizontalLayout->addWidget(_nameTag);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        _localIPTag = new QLabel(EMLocalAddressPanel);
        _localIPTag->setObjectName(QStringLiteral("_localIPTag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, _localIPTag);

        _ip = new QLineEdit(EMLocalAddressPanel);
        _ip->setObjectName(QStringLiteral("_ip"));

        formLayout->setWidget(0, QFormLayout::FieldRole, _ip);

        _localPortTag = new QLabel(EMLocalAddressPanel);
        _localPortTag->setObjectName(QStringLiteral("_localPortTag"));

        formLayout->setWidget(1, QFormLayout::LabelRole, _localPortTag);

        _port = new QLineEdit(EMLocalAddressPanel);
        _port->setObjectName(QStringLiteral("_port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, _port);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(EMLocalAddressPanel);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);


        retranslateUi(EMLocalAddressPanel);

        QMetaObject::connectSlotsByName(EMLocalAddressPanel);
    } // setupUi

    void retranslateUi(QWidget *EMLocalAddressPanel)
    {
        EMLocalAddressPanel->setWindowTitle(QApplication::translate("EMLocalAddressPanel", "EMLocalAddressPanel", Q_NULLPTR));
        _nameTag->setText(QApplication::translate("EMLocalAddressPanel", "Local Address Setting", Q_NULLPTR));
        _localIPTag->setText(QApplication::translate("EMLocalAddressPanel", "Local Addr:", Q_NULLPTR));
        _localPortTag->setText(QApplication::translate("EMLocalAddressPanel", "Local Port:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMLocalAddressPanel: public Ui_EMLocalAddressPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMLOCALADDRESSPANEL_H
