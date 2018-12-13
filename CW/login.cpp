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
    connOpen("users.db");

    QSqlQuery query("SELECT Rights FROM user Where Login='"+ui->Log->text()+"' and Pass='"+ui->Pass->text()+"';");
    if (query.next()){
        connClose();
        if (query.value(0).toString()=="admin"){
            ui->statusBar->showMessage("You have admin's rights!");
            sudentedit edit;
            edit.setModal(true);
            edit.exec();
        }
        else {
            ui->statusBar->showMessage("You have user's rights!");
            sudentinfo info;
            info.setModal(true);
            info.exec();
        }
        return;
    }
    ui->statusBar->showMessage("Wrong login or password!");
    connClose();
}


