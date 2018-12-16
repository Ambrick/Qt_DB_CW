#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QtDebug>
#include <QFileInfo>
#include <QComboBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include "sudentinfo.h"
#include "sudentedit.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT


public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QSqlDatabase mydb;

    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase ::defaultConnection);
    }

    void connOpen(QString filename){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("roooooot");
        db.setDatabaseName(filename);
        db.open();
    }

    bool DoesRowExist(QString El, QString Table, QString Column){
        QSqlQuery query("SELECT * FROM `"+Table+"` WHERE `"+Column+"`='"+El+"'");
        if (query.next())
            return true;
        return false;
    }


private slots:

    void on_Go_clicked();

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
