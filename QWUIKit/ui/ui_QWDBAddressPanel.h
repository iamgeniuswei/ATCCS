/********************************************************************************
** Form generated from reading UI file 'QWDBAddressPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDBADDRESSPANEL_H
#define UI_QWDBADDRESSPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_EMDBAddressPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *_nameTag;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *_dbTypeTag;
    QComboBox *_dbType;
    QLabel *_dbNameTag;
    QLineEdit *_dbName;
    QLabel *_dbIPTag;
    QLineEdit *_dbIP;
    QLabel *_dbPortTag;
    QLineEdit *_dbPort;
    QLabel *_dbUserTag;
    QLineEdit *_dbUser;
    QLabel *_dbPasswordTag;
    QLineEdit *_dbPassword;
    QFrame *line;

    void setupUi(QWidget *EMDBAddressPanel)
    {
        if (EMDBAddressPanel->objectName().isEmpty())
            EMDBAddressPanel->setObjectName(QStringLiteral("EMDBAddressPanel"));
        EMDBAddressPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(EMDBAddressPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _nameTag = new QLabel(EMDBAddressPanel);
        _nameTag->setObjectName(QStringLiteral("_nameTag"));

        horizontalLayout->addWidget(_nameTag);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        _dbTypeTag = new QLabel(EMDBAddressPanel);
        _dbTypeTag->setObjectName(QStringLiteral("_dbTypeTag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, _dbTypeTag);

        _dbType = new QComboBox(EMDBAddressPanel);
        _dbType->setObjectName(QStringLiteral("_dbType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, _dbType);

        _dbNameTag = new QLabel(EMDBAddressPanel);
        _dbNameTag->setObjectName(QStringLiteral("_dbNameTag"));

        formLayout->setWidget(1, QFormLayout::LabelRole, _dbNameTag);

        _dbName = new QLineEdit(EMDBAddressPanel);
        _dbName->setObjectName(QStringLiteral("_dbName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, _dbName);

        _dbIPTag = new QLabel(EMDBAddressPanel);
        _dbIPTag->setObjectName(QStringLiteral("_dbIPTag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, _dbIPTag);

        _dbIP = new QLineEdit(EMDBAddressPanel);
        _dbIP->setObjectName(QStringLiteral("_dbIP"));

        formLayout->setWidget(2, QFormLayout::FieldRole, _dbIP);

        _dbPortTag = new QLabel(EMDBAddressPanel);
        _dbPortTag->setObjectName(QStringLiteral("_dbPortTag"));

        formLayout->setWidget(3, QFormLayout::LabelRole, _dbPortTag);

        _dbPort = new QLineEdit(EMDBAddressPanel);
        _dbPort->setObjectName(QStringLiteral("_dbPort"));

        formLayout->setWidget(3, QFormLayout::FieldRole, _dbPort);

        _dbUserTag = new QLabel(EMDBAddressPanel);
        _dbUserTag->setObjectName(QStringLiteral("_dbUserTag"));

        formLayout->setWidget(4, QFormLayout::LabelRole, _dbUserTag);

        _dbUser = new QLineEdit(EMDBAddressPanel);
        _dbUser->setObjectName(QStringLiteral("_dbUser"));

        formLayout->setWidget(4, QFormLayout::FieldRole, _dbUser);

        _dbPasswordTag = new QLabel(EMDBAddressPanel);
        _dbPasswordTag->setObjectName(QStringLiteral("_dbPasswordTag"));

        formLayout->setWidget(5, QFormLayout::LabelRole, _dbPasswordTag);

        _dbPassword = new QLineEdit(EMDBAddressPanel);
        _dbPassword->setObjectName(QStringLiteral("_dbPassword"));

        formLayout->setWidget(5, QFormLayout::FieldRole, _dbPassword);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(EMDBAddressPanel);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(EMDBAddressPanel);

        QMetaObject::connectSlotsByName(EMDBAddressPanel);
    } // setupUi

    void retranslateUi(QWidget *EMDBAddressPanel)
    {
        EMDBAddressPanel->setWindowTitle(QApplication::translate("EMDBAddressPanel", "EMDBAddressPanel", Q_NULLPTR));
        _nameTag->setText(QApplication::translate("EMDBAddressPanel", "Database Setting", Q_NULLPTR));
        _dbTypeTag->setText(QApplication::translate("EMDBAddressPanel", "DB Type:", Q_NULLPTR));
        _dbNameTag->setText(QApplication::translate("EMDBAddressPanel", "DB Name:", Q_NULLPTR));
        _dbIPTag->setText(QApplication::translate("EMDBAddressPanel", "DB Addr:", Q_NULLPTR));
        _dbPortTag->setText(QApplication::translate("EMDBAddressPanel", "DB Port:", Q_NULLPTR));
        _dbUserTag->setText(QApplication::translate("EMDBAddressPanel", "DB User:", Q_NULLPTR));
        _dbPasswordTag->setText(QApplication::translate("EMDBAddressPanel", "DB Pwd:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMDBAddressPanel: public Ui_EMDBAddressPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDBADDRESSPANEL_H
