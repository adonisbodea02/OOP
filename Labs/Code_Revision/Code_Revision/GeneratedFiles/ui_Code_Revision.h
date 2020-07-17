/********************************************************************************
** Form generated from reading UI file 'Code_Revision.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODE_REVISION_H
#define UI_CODE_REVISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Code_RevisionClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Code_RevisionClass)
    {
        if (Code_RevisionClass->objectName().isEmpty())
            Code_RevisionClass->setObjectName(QStringLiteral("Code_RevisionClass"));
        Code_RevisionClass->resize(600, 400);
        verticalLayout_4 = new QVBoxLayout(Code_RevisionClass);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(Code_RevisionClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Code_RevisionClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(Code_RevisionClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(Code_RevisionClass);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(Code_RevisionClass);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(Code_RevisionClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        lineEdit = new QLineEdit(Code_RevisionClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_2 = new QPushButton(Code_RevisionClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Code_RevisionClass);

        QMetaObject::connectSlotsByName(Code_RevisionClass);
    } // setupUi

    void retranslateUi(QWidget *Code_RevisionClass)
    {
        Code_RevisionClass->setWindowTitle(QApplication::translate("Code_RevisionClass", "Code_Revision", nullptr));
        label->setText(QApplication::translate("Code_RevisionClass", "Revise", nullptr));
        label_2->setText(QApplication::translate("Code_RevisionClass", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("Code_RevisionClass", "To Revise", nullptr));
        label_4->setText(QApplication::translate("Code_RevisionClass", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("Code_RevisionClass", "Add", nullptr));
        pushButton_2->setText(QApplication::translate("Code_RevisionClass", "Revise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Code_RevisionClass: public Ui_Code_RevisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODE_REVISION_H
