/********************************************************************************
** Form generated from reading UI file 'Legume.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEGUME_H
#define UI_LEGUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LegumeClass
{
public:
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QListWidget *listWidget_2;

    void setupUi(QWidget *LegumeClass)
    {
        if (LegumeClass->objectName().isEmpty())
            LegumeClass->setObjectName(QStringLiteral("LegumeClass"));
        LegumeClass->resize(600, 400);
        listWidget = new QListWidget(LegumeClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 40, 251, 192));
        lineEdit = new QLineEdit(LegumeClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 270, 113, 20));
        lineEdit_2 = new QLineEdit(LegumeClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 320, 113, 20));
        pushButton = new QPushButton(LegumeClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 270, 101, 41));
        listWidget_2 = new QListWidget(LegumeClass);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(295, 40, 151, 81));

        retranslateUi(LegumeClass);

        QMetaObject::connectSlotsByName(LegumeClass);
    } // setupUi

    void retranslateUi(QWidget *LegumeClass)
    {
        LegumeClass->setWindowTitle(QApplication::translate("LegumeClass", "Legume", nullptr));
        pushButton->setText(QApplication::translate("LegumeClass", "Send Vegie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LegumeClass: public Ui_LegumeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEGUME_H
