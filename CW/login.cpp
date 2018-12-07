#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

   if  (!mydb.open())
       ui->label->setText("Failed...");
   else
       ui->label->setText("Connected...");

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    connOpen("database.db");
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


}


void Login::on_Go_clicked()
{
    QString login=ui->Log->text(),
            password=ui->Pass->text();

    QSqlDatabase mydb = QSqlDatabase ::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Qdera/Desktop/users.db");

    connOpen("users.db");

    QSqlQuery qry;

    if(qry.exec("SELECT * FROM user where Login="+login+" and Pass="+password)){
        int count=0;
        while (qry.next())
            count++;

        if (count==1){
            ui->statusBar->showMessage("The data is correct!");
            //this->hide();
            connClose();
            sudentinfo info;
            info.setModal(true);
            info.exec();

        }
        else
            ui->statusBar->showMessage("The data is corrupted!");
    }

}
