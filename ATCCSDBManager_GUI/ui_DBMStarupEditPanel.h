/********************************************************************************
** Form generated from reading UI file 'DBMStarupEditPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMSTARUPEDITPANEL_H
#define UI_DBMSTARUPEDITPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMStarupEditPanel
{
public:
    QVBoxLayout *verticalLayout;
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
    QLabel *_outputTag;

    void setupUi(QWidget *DBMStarupEditPanel)
    {
        if (DBMStarupEditPanel->objectName().isEmpty())
            DBMStarupEditPanel->setObjectName(QStringLiteral("DBMStarupEditPanel"));
        DBMStarupEditPanel->resize(400, 300);
        verticalLayout = new QVBoxLayout(DBMStarupEditPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        _dbTypeTag = new QLabel(DBMStarupEditPanel);
        _dbTypeTag->setObjectName(QStringLiteral("_dbTypeTag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, _dbTypeTag);

        _dbType = new QComboBox(DBMStarupEditPanel);
        _dbType->setObjectName(QStringLiteral("_dbType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, _dbType);

        _dbNameTag = new QLabel(DBMStarupEditPanel);
        _dbNameTag->setObjectName(QStringLiteral("_dbNameTag"));

        formLayout->setWidget(1, QFormLayout::LabelRole, _dbNameTag);

        _dbName = new QLineEdit(DBMStarupEditPanel);
        _dbName->setObjectName(QStringLiteral("_dbName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, _dbName);

        _dbIPTag = new QLabel(DBMStarupEditPanel);
        _dbIPTag->setObjectName(QStringLiteral("_dbIPTag"));

        formLayout->setWidget(2, QFormLayout::LabelRole, _dbIPTag);

        _dbIP = new QLineEdit(DBMStarupEditPanel);
        _dbIP->setObjectName(QStringLiteral("_dbIP"));

        formLayout->setWidget(2, QFormLayout::FieldRole, _dbIP);

        _dbPortTag = new QLabel(DBMStarupEditPanel);
        _dbPortTag->setObjectName(QStringLiteral("_dbPortTag"));

        formLayout->setWidget(3, QFormLayout::LabelRole, _dbPortTag);

        _dbPort = new QLineEdit(DBMStarupEditPanel);
        _dbPort->setObjectName(QStringLiteral("_dbPort"));

        formLayout->setWidget(3, QFormLayout::FieldRole, _dbPort);

        _dbUserTag = new QLabel(DBMStarupEditPanel);
        _dbUserTag->setObjectName(QStringLiteral("_dbUserTag"));

        formLayout->setWidget(4, QFormLayout::LabelRole, _dbUserTag);

        _dbUser = new QLineEdit(DBMStarupEditPanel);
        _dbUser->setObjectName(QStringLiteral("_dbUser"));

        formLayout->setWidget(4, QFormLayout::FieldRole, _dbUser);

        _dbPasswordTag = new QLabel(DBMStarupEditPanel);
        _dbPasswordTag->setObjectName(QStringLiteral("_dbPasswordTag"));

        formLayout->setWidget(5, QFormLayout::LabelRole, _dbPasswordTag);

        _dbPassword = new QLineEdit(DBMStarupEditPanel);
        _dbPassword->setObjectName(QStringLiteral("_dbPassword"));
        _dbPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(5, QFormLayout::FieldRole, _dbPassword);


        verticalLayout->addLayout(formLayout);

        _outputTag = new QLabel(DBMStarupEditPanel);
        _outputTag->setObjectName(QStringLiteral("_outputTag"));
        _outputTag->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_outputTag);


        retranslateUi(DBMStarupEditPanel);

        QMetaObject::connectSlotsByName(DBMStarupEditPanel);
    } // setupUi

    void retranslateUi(QWidget *DBMStarupEditPanel)
    {
        DBMStarupEditPanel->setWindowTitle(QApplication::translate("DBMStarupEditPanel", "DBMStarupEditPanel", Q_NULLPTR));
        _dbTypeTag->setText(QApplication::translate("DBMStarupEditPanel", "DB Type:", Q_NULLPTR));
        _dbType->clear();
        _dbType->insertItems(0, QStringList()
         << QApplication::translate("DBMStarupEditPanel", "pgsql", Q_NULLPTR)
        );
        _dbNameTag->setText(QApplication::translate("DBMStarupEditPanel", "DB Name:", Q_NULLPTR));
        _dbIPTag->setText(QApplication::translate("DBMStarupEditPanel", "DB IPAddr:", Q_NULLPTR));
        _dbPortTag->setText(QApplication::translate("DBMStarupEditPanel", "DB Port:", Q_NULLPTR));
        _dbUserTag->setText(QApplication::translate("DBMStarupEditPanel", "DB User", Q_NULLPTR));
        _dbPasswordTag->setText(QApplication::translate("DBMStarupEditPanel", "DB Pwd:", Q_NULLPTR));
        _outputTag->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBMStarupEditPanel: public Ui_DBMStarupEditPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMSTARUPEDITPANEL_H
