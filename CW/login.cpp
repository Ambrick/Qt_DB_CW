#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_Go_clicked()
{
    connOpen("users");

    QSqlQuery query("SELECT `Rights` FROM `client` WHERE Login='"+ui->Log->text()+"' and Pass='"+ui->Pass->text()+"';");
    query.next();
    if (query.value(0).toString()=="admin"){
        ui->statusBar->showMessage("You have admin's rights!");
        connClose();
        sudentedit edit;
        edit.setModal(true);
        edit.exec();
    } else if (query.value(0).toString()=="client"){
        ui->statusBar->showMessage("You have user's rights!");
        connClose();
        sudentinfo info;
        info.setModal(true);
        info.exec();
    }
    connClose();
    ui->statusBar->showMessage("Wrong login or password!");
    return;
}


