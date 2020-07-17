/********************************************************************************
** Form generated from reading UI file 'Issue_Tracker.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUE_TRACKER_H
#define UI_ISSUE_TRACKER_H

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

class Ui_Issue_TrackerClass
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Issue_TrackerClass)
    {
        if (Issue_TrackerClass->objectName().isEmpty())
            Issue_TrackerClass->setObjectName(QStringLiteral("Issue_TrackerClass"));
        Issue_TrackerClass->resize(600, 400);
        listWidget = new QListWidget(Issue_TrackerClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 20, 381, 221));
        pushButton = new QPushButton(Issue_TrackerClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 260, 111, 21));
        lineEdit = new QLineEdit(Issue_TrackerClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 260, 151, 21));
        pushButton_2 = new QPushButton(Issue_TrackerClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 290, 111, 21));
        pushButton_3 = new QPushButton(Issue_TrackerClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 320, 111, 21));

        retranslateUi(Issue_TrackerClass);

        QMetaObject::connectSlotsByName(Issue_TrackerClass);
    } // setupUi

    void retranslateUi(QWidget *Issue_TrackerClass)
    {
        Issue_TrackerClass->setWindowTitle(QApplication::translate("Issue_TrackerClass", "Issue_Tracker", nullptr));
        pushButton->setText(QApplication::translate("Issue_TrackerClass", "Add", nullptr));
        pushButton_2->setText(QApplication::translate("Issue_TrackerClass", "Remove", nullptr));
        pushButton_3->setText(QApplication::translate("Issue_TrackerClass", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Issue_TrackerClass: public Ui_Issue_TrackerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUE_TRACKER_H
