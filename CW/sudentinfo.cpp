#include "sudentinfo.h"
#include "ui_sudentinfo.h"
#include "login.h"

sudentinfo::sudentinfo(QWidget *parent) :  QDialog(parent), ui(new Ui::sudentinfo)
{
    ui->setupUi(this);

  /*  Login conn;
    conn.connOpen("database.db");

    QSqlQuery query;
    query.prepare("SELECT Name FROM Universities");
    query.exec();

    int i=0;
    while (query.next())
    {
        i++;
        QString item = query.value(0).toString();
        ui-> Universities->addItem(item ,QVariant(i));
    }

    query.prepare("SELECT NameFaculty FROM Faculty");
    query.exec();

    i=0;
    while (query.next())
    {
        i++;
        QString item = query.value(0).toString();
        ui-> Faculty->addItem(item ,QVariant(i));
    }

    query.prepare("SELECT Name FROM Professor");
    query.exec();

    i=0;
    while (query.next())
    {
        i++;
        QString item = query.value(0).toString();
        ui-> Mentor->addItem(item ,QVariant(i));
    }

    query.prepare("SELECT Name FROM Discipline");
    query.exec();

    i=0;
    while (query.next())
    {
        i++;
        QString item = query.value(0).toString();
        ui-> Discipline->addItem(item ,QVariant(i));
    }
    conn.connClose();

    conn.connOpen("database.db");
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *qry= new QSqlQuery(conn.mydb);
    qry->prepare("SELECT Name, RectorName, RectorSurname FROM Universities");
    qry->exec();

    modal->setQuery(*qry);
    ui->Table->setModel(modal);
    conn.connClose();
    ui->Table->resizeRowsToContents();
    ui->Table->resizeColumnsToContents();*/
}

sudentinfo::~sudentinfo()
{
    delete ui;
}








/*
    QSqlDatabase mydb = QSqlDatabase ::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Qdera/Desktop/database.db");

    if  (!mydb.open())
       qDebug()<<("Failed...");
    else
       qDebug()<<("Connected...");

    //Осуществляем запрос
    QSqlQuery query;
    query.prepare("SELECT Name, RectorName, RectorSurname FROM Universities");
    query.exec();

    //Выводим значения из запроса
    while (query.next())
    {
        QString _id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString age = query.value(2).toString();
        ui->textEdit->insertPlainText(_id+" "+name+" "+age+"\n");
    }
*/
