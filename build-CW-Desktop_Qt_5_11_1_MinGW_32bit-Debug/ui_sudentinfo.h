/********************************************************************************
** Form generated from reading UI file 'sudentinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDENTINFO_H
#define UI_SUDENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sudentinfo
{
public:
    QTableView *Table;
    QPushButton *pushButton_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *University;
    QLineEdit *Faculty;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *Mentor;
    QPushButton *pushButton;

    void setupUi(QDialog *sudentinfo)
    {
        if (sudentinfo->objectName().isEmpty())
            sudentinfo->setObjectName(QStringLiteral("sudentinfo"));
        sudentinfo->resize(815, 537);
        Table = new QTableView(sudentinfo);
        Table->setObjectName(QStringLiteral("Table"));
        Table->setGeometry(QRect(150, 10, 621, 291));
        pushButton_2 = new QPushButton(sudentinfo);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 370, 75, 23));
        widget = new QWidget(sudentinfo);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 135, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        University = new QLineEdit(widget);
        University->setObjectName(QStringLiteral("University"));

        verticalLayout->addWidget(University);

        Faculty = new QLineEdit(widget);
        Faculty->setObjectName(QStringLiteral("Faculty"));

        verticalLayout->addWidget(Faculty);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        verticalLayout->addWidget(lineEdit_7);

        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        verticalLayout->addWidget(lineEdit_8);

        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        verticalLayout->addWidget(lineEdit_9);

        Mentor = new QLineEdit(widget);
        Mentor->setObjectName(QStringLiteral("Mentor"));

        verticalLayout->addWidget(Mentor);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(sudentinfo);

        QMetaObject::connectSlotsByName(sudentinfo);
    } // setupUi

    void retranslateUi(QDialog *sudentinfo)
    {
        sudentinfo->setWindowTitle(QApplication::translate("sudentinfo", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("sudentinfo", "Show", nullptr));
        University->setPlaceholderText(QApplication::translate("sudentinfo", "\320\243\320\275\320\270\320\262\320\265\321\200\321\201\320\270\321\202\320\265\321\202:", nullptr));
        Faculty->setPlaceholderText(QApplication::translate("sudentinfo", "\320\244\320\260\320\272\321\203\320\273\321\214\321\202\320\265\321\202:", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("sudentinfo", "\320\223\321\200\321\203\320\277\320\277\320\260:", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("sudentinfo", "\320\230\320\274\321\217:", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("sudentinfo", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        lineEdit_6->setPlaceholderText(QApplication::translate("sudentinfo", "\320\241\321\202\320\270\320\277\320\265\320\275\320\264\320\270\321\217:", nullptr));
        lineEdit_7->setPlaceholderText(QApplication::translate("sudentinfo", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\260\320\261\320\276\321\202\321\213:", nullptr));
        lineEdit_8->setText(QString());
        lineEdit_8->setPlaceholderText(QApplication::translate("sudentinfo", "\320\236\321\206\320\265\320\275\320\272\320\260:", nullptr));
        lineEdit_9->setText(QString());
        lineEdit_9->setPlaceholderText(QApplication::translate("sudentinfo", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260:", nullptr));
        Mentor->setText(QString());
        Mentor->setPlaceholderText(QApplication::translate("sudentinfo", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", nullptr));
        pushButton->setText(QApplication::translate("sudentinfo", "New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sudentinfo: public Ui_sudentinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDENTINFO_H
