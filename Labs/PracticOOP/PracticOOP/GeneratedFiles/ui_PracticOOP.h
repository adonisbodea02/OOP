/********************************************************************************
** Form generated from reading UI file 'PracticOOP.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICOOP_H
#define UI_PRACTICOOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticOOPClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PracticOOPClass)
    {
        if (PracticOOPClass->objectName().isEmpty())
            PracticOOPClass->setObjectName(QStringLiteral("PracticOOPClass"));
        PracticOOPClass->resize(600, 400);
        layoutWidget = new QWidget(PracticOOPClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 501, 361));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        retranslateUi(PracticOOPClass);

        QMetaObject::connectSlotsByName(PracticOOPClass);
    } // setupUi

    void retranslateUi(QWidget *PracticOOPClass)
    {
        PracticOOPClass->setWindowTitle(QApplication::translate("PracticOOPClass", "PracticOOP", nullptr));
        label->setText(QApplication::translate("PracticOOPClass", "Revised", nullptr));
        label_3->setText(QApplication::translate("PracticOOPClass", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("PracticOOPClass", "To Revise", nullptr));
        label_4->setText(QApplication::translate("PracticOOPClass", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("PracticOOPClass", "Add", nullptr));
        pushButton_2->setText(QApplication::translate("PracticOOPClass", "Revise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PracticOOPClass: public Ui_PracticOOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICOOP_H
