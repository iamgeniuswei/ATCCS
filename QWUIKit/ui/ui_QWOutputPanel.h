/********************************************************************************
** Form generated from reading UI file 'QWOutputPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWOUTPUTPANEL_H
#define UI_QWOUTPUTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWOutputPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *_outputTag;
    QSpacerItem *horizontalSpacer;
    QListWidget *_outputList;

    void setupUi(QWidget *QWOutputPanel)
    {
        if (QWOutputPanel->objectName().isEmpty())
            QWOutputPanel->setObjectName(QStringLiteral("QWOutputPanel"));
        QWOutputPanel->resize(400, 128);
        QWOutputPanel->setMaximumSize(QSize(16777215, 200));
        verticalLayout = new QVBoxLayout(QWOutputPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        _outputTag = new QLabel(QWOutputPanel);
        _outputTag->setObjectName(QStringLiteral("_outputTag"));

        horizontalLayout->addWidget(_outputTag);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        _outputList = new QListWidget(QWOutputPanel);
        _outputList->setObjectName(QStringLiteral("_outputList"));

        verticalLayout->addWidget(_outputList);


        retranslateUi(QWOutputPanel);

        QMetaObject::connectSlotsByName(QWOutputPanel);
    } // setupUi

    void retranslateUi(QWidget *QWOutputPanel)
    {
        QWOutputPanel->setWindowTitle(QApplication::translate("QWOutputPanel", "QWOutputPanel", Q_NULLPTR));
        _outputTag->setText(QApplication::translate("QWOutputPanel", "Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QWOutputPanel: public Ui_QWOutputPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWOUTPUTPANEL_H
