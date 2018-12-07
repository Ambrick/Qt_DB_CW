#include "sudentinfo.h"
#include "ui_sudentinfo.h"

sudentinfo::sudentinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sudentinfo)
{
    ui->setupUi(this);



}

sudentinfo::~sudentinfo()
{
    delete ui;
}


void sudentinfo::on_pushButton_2_clicked()
{
    QSqlDatabase mydb = QSqlDatabase ::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Qdera/Desktop/database.db");

   if  (!mydb.open()){
       qDebug()<<("Failed...");
   }
   else{
       qDebug()<<("Connected...");
   }

   QSqlTableModel *model = new QSqlTableModel(this,mydb);




   ui->Table->setModel(model);
}
