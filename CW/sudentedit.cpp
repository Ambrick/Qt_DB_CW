#include "sudentedit.h"
#include "ui_sudentedit.h"
#include "login.h"


sudentedit::sudentedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sudentedit)
{
    ui->setupUi(this);

    Login conn;
    conn.connOpen("cw");

    QSqlQuery q1("SELECT `FirstName`,`LastName`,`Name`,`ProfessorID`\
                  FROM (`professor` INNER JOIN `discipline` ON `DisciplineID` = `Discipline_DisciplineID`)");
    while (q1.next())
        ui->Mentor->addItem(q1.value(2).toString()+" / "+q1.value(0).toString()+" "+q1.value(1).toString(), QVariant(q1.value(3)));

    QSqlQuery q2("SELECT `Name`,`SquadID`, `Code` FROM (`squad` INNER JOIN `specialty` ON `SpecialtyID` = `Specialty_SpecialtyID`)");
    while (q2.next())
        ui->Group->addItem(q2.value(2).toString()+" / "+q2.value(0).toString(), QVariant(q2.value(1)));

    conn.connClose();
    on_Group_activated(0);
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
    QString StID= ui-> Student->itemData(ui-> Student->currentIndex()).toString(),
            Title= ui-> Title->text(),
            Mark=ui-> Mark->text(),
            ProfessorID =ui-> Mentor->itemData(ui-> Mentor->currentIndex()).toString();

    if (Title.isEmpty() || ui-> Student->currentText().isEmpty() || Mark.isEmpty() || Mark.toInt()<0 || Mark.toInt()>40){
        QMessageBox::critical(this, "Error", "Fill all work fields correctly!");
        return;
    }

    Login conn;
    conn.connOpen("cw");
    QSqlQuery q("SELECT `DisciplineID` \
                FROM (`discipline`  INNER JOIN `professor` ON `Discipline_DisciplineID` = `DisciplineID`)\
                WHERE `ProfessorID`='"+ProfessorID+"'");
    q.next();
    QMessageBox::information(this, "Error", q.value(0).toString());
    QSqlQuery query;
    query.prepare("INSERT INTO 'coursework' ('Professor_ProfessorID','Discipline_DisciplineID'\
                    ,'Student_StudentID', 'Title', 'Mark') VALUES ( :A, :B, :C, :D, :E)");
    query.bindValue(":A", ProfessorID);
    query.bindValue(":B", q.value(0).toString());
    query.bindValue(":C", StID);
    query.bindValue(":D", Title);
    query.bindValue(":E", Mark);
    if (query.exec())
        QMessageBox::information(this, "Error", "Data was added succesasfully!");

    conn.connClose();
}

void sudentedit::on_Edit_clicked()
{

}

void sudentedit::on_Delete_clicked()
{
    QString ID=ui->Delete_row->text();
    Login conn;
    conn.connOpen("cw");
    //Проверка на "существование", введенного айди
    if (!conn.DoesRowExist(ID, "coursework", "CourseWorkID")){
        QMessageBox::critical(this, "Error", "ID do not exist!");
        conn.connClose();
        return;
    }

    QSqlQuery q("DELETE FROM `coursework` WHERE `ID` ='"+ID+"'");
    q.next();
    QMessageBox::information(this, "Error", "Data was deleted!");
    conn.connClose();
}

void sudentedit::on_Group_activated(int index)
{
    ui->Student->clear();
    Login conn;
    conn.connOpen("cw");
    QSqlQuery q("SELECT `LastName`,`FirstName`,`StudentID` FROM `student` WHERE `Squad_SquadID` ='"+ui->Group->itemData(index).toString()+"'");
    while (q.next())
        ui->Student->addItem(q.value(0).toString() +" "+q.value(1).toString(), QVariant(q.value(2)));
    conn.connClose();
}
