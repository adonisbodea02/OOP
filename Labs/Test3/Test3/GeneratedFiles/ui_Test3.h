/********************************************************************************
** Form generated from reading UI file 'Test3.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3_H
#define UI_TEST3_H

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

class Ui_Test3Class
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *Test3Class)
    {
        if (Test3Class->objectName().isEmpty())
            Test3Class->setObjectName(QStringLiteral("Test3Class"));
        Test3Class->resize(600, 400);
        listWidget = new QListWidget(Test3Class);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(70, 30, 256, 192));
        pushButton = new QPushButton(Test3Class);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 240, 141, 41));
        pushButton_2 = new QPushButton(Test3Class);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 240, 101, 41));
        listWidget_2 = new QListWidget(Test3Class);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(70, 300, 256, 71));
        lineEdit = new QLineEdit(Test3Class);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(340, 30, 113, 20));
        lineEdit_2 = new QLineEdit(Test3Class);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(340, 60, 113, 20));
        lineEdit_3 = new QLineEdit(Test3Class);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(340, 90, 113, 20));

        retranslateUi(Test3Class);

        QMetaObject::connectSlotsByName(Test3Class);
    } // setupUi

    void retranslateUi(QWidget *Test3Class)
    {
        Test3Class->setWindowTitle(QApplication::translate("Test3Class", "Test3", nullptr));
        pushButton->setText(QApplication::translate("Test3Class", "Solve Equation", nullptr));
        pushButton_2->setText(QApplication::translate("Test3Class", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test3Class: public Ui_Test3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3_H
