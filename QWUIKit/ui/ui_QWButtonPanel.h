/********************************************************************************
** Form generated from reading UI file 'QWButtonPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWBUTTONPANEL_H
#define UI_QWBUTTONPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWButtonPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *_ok;
    QPushButton *_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *QWButtonPanel)
    {
        if (QWButtonPanel->objectName().isEmpty())
            QWButtonPanel->setObjectName(QStringLiteral("QWButtonPanel"));
        QWButtonPanel->resize(400, 80);
        QWButtonPanel->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(QWButtonPanel);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, 25);
        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _ok = new QPushButton(QWButtonPanel);
        _ok->setObjectName(QStringLiteral("_ok"));
        _ok->setCursor(QCursor(Qt::PointingHandCursor));
        _ok->setFlat(true);

        horizontalLayout->addWidget(_ok);

        _cancel = new QPushButton(QWButtonPanel);
        _cancel->setObjectName(QStringLiteral("_cancel"));
        _cancel->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(_cancel);

        horizontalSpacer_2 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(QWButtonPanel);

        _ok->setDefault(true);


        QMetaObject::connectSlotsByName(QWButtonPanel);
    } // setupUi

    void retranslateUi(QWidget *QWButtonPanel)
    {
        QWButtonPanel->setWindowTitle(QApplication::translate("QWButtonPanel", "QWButtonPanel", Q_NULLPTR));
        _ok->setText(QApplication::translate("QWButtonPanel", "ok", Q_NULLPTR));
        _cancel->setText(QApplication::translate("QWButtonPanel", "cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QWButtonPanel: public Ui_QWButtonPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWBUTTONPANEL_H
