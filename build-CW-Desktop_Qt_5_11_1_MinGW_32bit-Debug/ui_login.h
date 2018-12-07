/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLineEdit *Log;
    QLabel *log;
    QLabel *pass;
    QLineEdit *Pass;
    QPushButton *Go;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 210, 131, 21));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(210, 170, 171, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 210, 75, 23));
        Log = new QLineEdit(centralWidget);
        Log->setObjectName(QStringLiteral("Log"));
        Log->setGeometry(QRect(70, 10, 113, 20));
        log = new QLabel(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(30, 10, 31, 16));
        pass = new QLabel(centralWidget);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(10, 40, 47, 13));
        Pass = new QLineEdit(centralWidget);
        Pass->setObjectName(QStringLiteral("Pass"));
        Pass->setGeometry(QRect(70, 40, 113, 20));
        Go = new QPushButton(centralWidget);
        Go->setObjectName(QStringLiteral("Go"));
        Go->setGeometry(QRect(40, 70, 101, 23));
        Login->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Login);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        Login->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Login);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Login->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Login);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Login->setStatusBar(statusBar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        label->setText(QApplication::translate("Login", "[+]Status", nullptr));
        pushButton->setText(QApplication::translate("Login", "PushButton", nullptr));
        log->setText(QApplication::translate("Login", "Login", nullptr));
        pass->setText(QApplication::translate("Login", "Password", nullptr));
        Go->setText(QApplication::translate("Login", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
