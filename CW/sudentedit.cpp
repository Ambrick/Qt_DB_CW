#include "sudentedit.h"
#include "ui_sudentedit.h"
#include "login.h"

sudentedit::~sudentedit()
{ delete ui; }

sudentedit::sudentedit(QWidget *parent) : QDialog(parent), ui(new Ui::sudentedit)
{
    ui->setupUi(this);

    connOpen("cwdb");
    QSqlQuery q_getGroupValues("SELECT Code, Name, squad.ID FROM squad\
                                INNER JOIN specialty ON Specialty.ID = Specialty_ID");
    while (q_getGroupValues.next())
        ui->Group->addItem(q_getGroupValues.value(0).toString()+" / "+q_getGroupValues.value(1).toString(), q_getGroupValues.value(2));

    QSqlQuery q_getMentorValues("SELECT discipline.Name, professor.Name, Surname, professor.ID\
                                 FROM professor INNER JOIN discipline ON professor.discipline_ID =discipline.ID");
    while (q_getMentorValues.next())
        ui->Mentor->addItem(q_getMentorValues.value(0).toString()+" / "+q_getMentorValues.value(1).toString()
                            +" "+q_getMentorValues.value(2).toString(), q_getMentorValues.value(3));

    on_Group_activated(0);
    setTable();
}

void sudentedit::setTable()
{
    ui->Table->setModel(TableView());
    for (int i = 0; i < ui->Table->horizontalHeader()->count(); i++)
        ui->Table->horizontalHeader()->setSectionResizeMode( i, QHeaderView:: Stretch);
}

void sudentedit::on_Add_clicked()
{
    QString S_ID= ui->Student->itemData(ui->Student->currentIndex()).toString(),
            P_ID =ui->Mentor->itemData(ui->Mentor->currentIndex()).toString(),
            Title= ui->Title->text(),
            Mark=ui->Mark->text();
    if ( Title.isEmpty() || ui-> Student->currentText().isEmpty() || Mark.isEmpty() ){
        QMessageBox::critical(this, "Error", "Fill all work fields correctly!");
        return;
    }
    QSqlQuery q_getDisciplineID("SELECT discipline.ID FROM discipline\
                                 INNER JOIN professor ON discipline.ID=professor.discipline_ID\
                                 WHERE professor.ID="+P_ID);
    q_getDisciplineID.next();
    QSqlQuery q("SELECT COUNT(ID) FROM coursework WHERE discipline_ID = "+q_getDisciplineID.value(0).toString()+" AND student_ID="+S_ID);
    q.next();
    if (q.value(0)>0){
        QMessageBox::critical(this, "Error", "Student can't have more than one work on one discipline!");
        return;
    }

    QSqlQuery q_insert;
    q_insert.prepare("INSERT INTO coursework (professor_ID, discipline_ID ,student_ID, Title, Mark) \
                      SELECT :B, :C, :D, :E, :F \
                      WHERE :F BETWEEN 0 AND 41");
    q_insert.bindValue(":B", P_ID);
    q_insert.bindValue(":C", q_getDisciplineID.value(0));
    q_insert.bindValue(":D", S_ID);
    q_insert.bindValue(":E", Title);
    q_insert.bindValue(":F", Mark);
    q_insert.exec();
    setTable();
}

void sudentedit::on_Edit_clicked()
{
    QString CW_ID=ui->ID->text(),
            S_ID= ui->Student->itemData(ui->Student->currentIndex()).toString(),
            P_ID =ui-> Mentor->itemData(ui->Mentor->currentIndex()).toString(),
            Title= ui->Title->text(),
            Mark=ui->Mark->text();
    if (CW_ID.isEmpty() || Title.isEmpty() || ui-> Student->currentText().isEmpty() || Mark.isEmpty() || Mark.toInt()<0 || Mark.toInt()>40){
        QMessageBox::critical(this, "Error", "Fill all work fields correctly!");
        return;
    }
    QSqlQuery q_getDisciplineID("SELECT discipline.ID FROM discipline\
                                 INNER JOIN professor ON discipline.ID=professor.discipline_ID\
                                 WHERE professor.ID="+P_ID);
    q_getDisciplineID.next();

    QSqlQuery q("SELECT COUNT(ID) FROM coursework WHERE discipline_ID = "+q_getDisciplineID.value(0).toString()+" AND student_ID="+S_ID);
    q.next();
    if (q.value(0)>0){
        QMessageBox::critical(this, "Error", "Student can't have more than one work on one discipline!");
        return;
    }
    QSqlQuery q_update;
    q_update.prepare("UPDATE coursework \
                      SET professor_ID=:A, discipline_ID=:B, student_ID=:C, `Title`=:D, `Mark`=:E \
                      WHERE coursework.ID ="+CW_ID);
    q_update.bindValue(":A", P_ID);
    q_update.bindValue(":B", q_getDisciplineID.value(0).toString());
    q_update.bindValue(":C", S_ID);
    q_update.bindValue(":D", Title);
    q_update.bindValue(":E", Mark);
    if (q_update.exec())
        QMessageBox::information(this, "Success", "Data was edited succesasfully!");
    setTable();
}

void sudentedit::on_Delete_clicked()
{
    QString ID=ui->ID->text();
    if (!DoesRowExist(ID, "coursework", "ID")){
        QMessageBox::critical(this, "Error", "Row do not exist!");
        return;
    }
    QSqlQuery q_del("DELETE FROM coursework WHERE ID ="+ID);
    q_del.next();
    QMessageBox::information(this, "Error", "Data was deleted!");
    setTable();
}

void sudentedit::on_Group_activated(int index)
{
    ui->Student->clear();
    QSqlQuery q("SELECT Name, Surname, ID FROM student WHERE squad_ID ="+QString::number(index+1));
    while (q.next())
        ui->Student->addItem(q.value(0).toString() +" "+q.value(1).toString(),q.value(2));
}

void sudentedit::on_ID_textChanged(const QString &ID)
{
    if (ID.isEmpty())
        return;
    if (!DoesRowExist(ID, "coursework", "ID")){
        QMessageBox::critical(this, "Error", "Row do not exist!");
        return;
    }

    QSqlQuery q_SValues("SELECT student.ID, discipline_ID, squad_ID, Mark, Title \
                         FROM coursework INNER JOIN student ON student_ID= student.ID \
                         WHERE coursework.ID="+ID);
    q_SValues.next();
    int  GID=q_SValues.value(2).toInt();
    ui->Group->setCurrentIndex(ui->Group->findData(GID));
    on_Group_activated(GID-1);
    ui->Student->setCurrentIndex(ui->Student->findData(q_SValues.value(0)));
    ui->Mentor->setCurrentIndex(ui->Mentor->findData(q_SValues.value(1)));
    ui->Title->setText(q_SValues.value(4).toString());
    ui->Mark->setText(q_SValues.value(3).toString());
}
