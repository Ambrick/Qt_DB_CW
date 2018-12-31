#include "login.h"
#include "ui_login.h"
#include "sudentinfo.h"
#include "sudentedit.h"
Login::~Login()
{   delete ui;  }
Login::Login(QWidget *parent) :QMainWindow(parent), ui(new Ui::Login)
{   ui->setupUi(this); }
void Login::on_Go_clicked()
{
    sudentedit conn;
    conn.connOpen("users");
    QSqlQuery query("SELECT Rights FROM data WHERE Login='"+ui->Log->text()+"' and Pass='"+ui->Pass->text()+"';");
    query.next();
    if (query.value(0).toString()=="admin"){
        ui->statusBar->showMessage("You have admin's rights!");
        sudentedit edit;
        edit.setModal(true);
        edit.exec();
    } else if (query.value(0).toString()=="user"){
        ui->statusBar->showMessage("You have user's rights!");
        sudentinfo info;
        info.setModal(true);
        info.exec();
    }
    else
        ui->statusBar->showMessage("Wrong login or password!");
}
