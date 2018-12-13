#include "sudentedit.h"
#include "ui_sudentedit.h"
#include "login.h"


sudentedit::sudentedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sudentedit)
{
    ui->setupUi(this);

    Login conn;
    conn.connOpen("coursework.db");
    QSqlQuery q1("SELECT `FirstName`,`LastName`, `ID` FROM `Professor`");
    while (q1.next())
        ui->Mentor->addItem(q1.value(0).toString()+" "+q1.value(1).toString(), QVariant(q1.value(2)));
    QSqlQuery q2("SELECT `Name`,`ID` FROM `Groups`");
    while (q2.next())
        ui->Group->addItem(q2.value(0).toString(), QVariant(q2.value(1)));
    conn.connClose();
}
sudentedit::~sudentedit()
{
    delete ui;
}

void sudentedit:: RefreshItems()
{

}

void sudentedit::on_Add_clicked()
{
  /*
    QString NameID= ui-> Name->text(),
            Surname= ui-> Surname->text(),
            Scholarship= ui-> Scholarship->text(),
            Mark=ui-> Mark->text(),
            DisciplineID= ui-> Discipline-> currentText(),
            ProfessorID =ui-> Mentor-> currentText(),
            GroupID = ui-> Group->currentText();

    if (NameID.isEmpty() || Surname.isEmpty() || ui-> WorkName->text().isEmpty() ||
                                Mark.isEmpty() || Mark.toInt()<0 || Mark.toInt()>40){
        QMessageBox::critical(this, "Error", "Fill all work fields correctly!");
        return;
    }

    Login conn;
    conn.connOpen("cw_db.db");


    QSqlQuery q1("SELECT `ID` FROM `Discipline` WHERE Name='"+DisciplineID+"'");
    QSqlQuery q2("SELECT `ID` FROM `Professor` WHERE Surname='"+ProfessorID+"'");
    QSqlQuery q3("SELECT `ID` FROM `Groups` WHERE Name='"+GroupID+"'");
    q1.next();
        DisciplineID=q1.value(0).toString();
    q2.next();
        ProfessorID=q2.value(0).toString();
    q3.next();
        GroupID=q3.value(0).toString();

    QSqlQuery query;


        if (Scholarship.toInt()<0 || Scholarship.toInt()>20000 || Scholarship.isEmpty()){
            QMessageBox::critical(this, "Error", "Incorrect scholarship value!");
            return;
        }

        QSqlQuery q4("SELECT `ID` FROM `Student` WHERE  Name='"+ui-> Name->text()+"' and Surname='"+Surname+"'");
        if (q4.next()){
            QMessageBox::critical(this, "Error", "Student already exist!");
            conn.connClose();
            return;
        }


        query.prepare("INSERT INTO 'Student' ('GroupsID','Name','Surname', 'Scholarship') VALUES ( :A, :B, :C, :D)");
        query.bindValue(":A", GroupID);
        query.bindValue(":B", NameID);
        query.bindValue(":C", Surname);
        query.bindValue(":D", Scholarship);
        query.exec();


    query.prepare("SELECT `ID` FROM `Student` WHERE Name='"+NameID+"' and Surname='"+Surname+"'");
    query.exec();
    while (query.next())
        NameID=query.value(0).toString();

    query.prepare("INSERT INTO 'CourseWork' ('DisciplineID','StudentID', 'ProfessorID', 'Name', 'Mark') VALUES ( :A, :B, :C, :D, :E)");
    query.bindValue(":A", DisciplineID);
    query.bindValue(":B", NameID);
    query.bindValue(":C", ProfessorID);
    query.bindValue(":D", ui-> WorkName->text());
    query.bindValue(":E", Mark);
    query.exec();

    conn.connClose();*/
}

void sudentedit::on_Edit_clicked()
{

}

void sudentedit::on_Delete_clicked()
{
  /*  QString ID=ui->Delete_row->text();
    Login conn;
    conn.connOpen("cw_db.db");

    //Проверка на "существование", введенного айди
    if (!conn.DoesRowExist(ID, "CourseWork", "ID")){
        QMessageBox::critical(this, "Error", "ID do not exist!");
        conn.connClose();
        return;
    }

    if (ui->StudentInclude->isChecked()){

        QMessageBox::StandardButton reply = QMessageBox::question(this, "Warning",
            "Are you sure you wanna delete all info!", QMessageBox::Yes|QMessageBox::No);
         if (reply == QMessageBox::No) {
             conn.connClose();
             return;
         }

         //Запрашиваем ID студента для удаления
        QSqlQuery q1("SELECT `StudentID` FROM `CourseWork` WHERE ID="+ID);
        q1.next();
        QString StudentID=q1.value(0).toString();

        //удаляем все записи у этого студента
        QSqlQuery q2("DELETE FROM CourseWork WHERE StudentID ='"+StudentID+"'");
        q2.next();
        QSqlQuery q3("DELETE FROM Student WHERE ID ='"+StudentID+"'");
        q3.next();

    } else {
        QSqlQuery q4("DELETE FROM CourseWork WHERE ID ='"+ID+"'");
        q4.next();
    }

    QMessageBox::information(this, "Error", "Data was deleted!");
    conn.connClose();*/
}


void sudentedit::on_Group_activated(int index)
{
    ui->Student->clear();
    Login conn;
    conn.connOpen("coursework.db");
    QSqlQuery q("SELECT `LastName`,`FirstName`,`ID` FROM `Student` WHERE Groups_ID ='"+ui->Group->itemData(index).toString()+"'");
    while (q.next())
        ui->Student->addItem(q.value(0).toString() +" "+q.value(1).toString(), QVariant(q.value(2)));
    conn.connClose();
}
