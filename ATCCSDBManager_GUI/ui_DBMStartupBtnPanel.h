/********************************************************************************
** Form generated from reading UI file 'DBMStartupBtnPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMSTARTUPBTNPANEL_H
#define UI_DBMSTARTUPBTNPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBMStartupBtnPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *DBMStartupBtnPanel)
    {
        if (DBMStartupBtnPanel->objectName().isEmpty())
            DBMStartupBtnPanel->setObjectName(QStringLiteral("DBMStartupBtnPanel"));
        DBMStartupBtnPanel->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DBMStartupBtnPanel);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okBtn = new QPushButton(DBMStartupBtnPanel);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/test"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(DBMStartupBtnPanel);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);

        horizontalLayout->addWidget(cancelBtn);


        retranslateUi(DBMStartupBtnPanel);

        QMetaObject::connectSlotsByName(DBMStartupBtnPanel);
    } // setupUi

    void retranslateUi(QWidget *DBMStartupBtnPanel)
    {
        DBMStartupBtnPanel->setWindowTitle(QApplication::translate("DBMStartupBtnPanel", "DBMStartupBtnPanel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        okBtn->setToolTip(QApplication::translate("DBMStartupBtnPanel", "ok", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("DBMStartupBtnPanel", "OK", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("DBMStartupBtnPanel", "CANCEL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBMStartupBtnPanel: public Ui_DBMStartupBtnPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMSTARTUPBTNPANEL_H
