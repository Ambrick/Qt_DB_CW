#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QtDebug>
#include <QFileInfo>
#include "sudentinfo.h"

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
    bool connOpen(QString filename){
        QSqlDatabase mydb = QSqlDatabase ::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Qdera/Desktop/"+filename);

       if  (!mydb.open()){
           qDebug()<<("Failed...");
           return false;
       }
       else{
           qDebug()<<("Connected...");
           return true;
       }
    }

private slots:
    void on_pushButton_clicked();

    void on_Go_clicked();

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
