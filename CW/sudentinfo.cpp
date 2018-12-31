#include "sudentinfo.h"
#include "ui_sudentinfo.h"
#include "sudentedit.h"

sudentinfo::~sudentinfo()
{   delete ui;    }
sudentinfo::sudentinfo(QWidget *parent) :  QDialog(parent), ui(new Ui::sudentinfo)
{
    ui->setupUi(this);
    sudentedit conn;
    conn.connOpen("cwdb");
    ui->SortType->addItem("По убыванию", 1);
    ui->SortType->addItem("По возрастанию", 2);
    on_toDefault_clicked();
}

void sudentinfo::setTable(QString script)
{
    ui->Table->setModel(CustomTableView(script));
    for (int i = 0; i < ui->Table->horizontalHeader()->count(); i++)
        ui->Table->horizontalHeader()->setSectionResizeMode( i, QHeaderView::Stretch);
}

void sudentinfo::on_Slider_valueChanged(int value)
{
    ui->Count->setText(QString ::number(value));
}

void sudentinfo::on_toAVG_clicked()
{
    setTable("SELECT squad.Name AS \"Название группы\", AVG(Mark) AS \"Средняя оценка\"\
             FROM squad JOIN student ON squad.ID = student.squad_ID \
             INNER JOIN coursework ON student.ID = coursework.student_ID \
             GROUP BY squad.Name");
}

void sudentinfo::on_toSort_clicked()
{
    ui->Search->clear();
    QString edge= ui->Count->text(), str=" ";
    if (ui-> SortType->itemData(ui-> SortType->currentIndex()) == 1)
        str+="DESC";
    setTable("SELECT \
              discipline.Name AS \"Дисциплина\",\
              professor.Name AS \"Имя профессора\",\
              professor.Surname AS \"Фамилия профессора\",\
              student.Name AS \"Имя студента\",\
              student.Surname AS \"Фамилия студента\",\
              coursework.Title AS \"Название\",\
              coursework.Mark AS \"Оценка\"\
              FROM coursework INNER JOIN professor ON coursework.professor_ID= professor.ID\
              INNER JOIN discipline ON coursework.discipline_ID=discipline.ID\
              INNER JOIN student ON coursework.student_ID = student.ID\
              WHERE coursework.Mark>"+edge+" Group BY coursework.Mark"+str);
}

void sudentinfo::on_toDefault_clicked()
{
    setTable("SELECT \
              discipline.Name AS \"Дисциплина\",\
              professor.Name AS \"Имя профессора\",\
              professor.Surname AS \"Фамилия профессора\",\
              student.Name AS \"Имя студента\",\
              student.Surname AS \"Фамилия студента\",\
              coursework.Title AS \"Название\",\
              coursework.Mark AS \"Оценка\"\
              FROM coursework INNER JOIN professor ON coursework.professor_ID= professor.ID\
              INNER JOIN discipline ON coursework.discipline_ID=discipline.ID\
              INNER JOIN student ON coursework.student_ID = student.ID\
              Group BY coursework.ID");
}

void sudentinfo::on_toGetBadStudents_clicked()
{
    ui->Search->clear();
    setTable("SELECT \
              student.ID, \
              student.Name AS \"Имя студента\",\
              student.Surname AS \"Фамилия студента\",\
              squad.Name AS \"Группа\"\
              FROM student INNER JOIN squad ON squad.ID= student.squad_ID \
              WHERE student.ID NOT IN (SELECT coursework.student_ID FROM coursework)");
}

void sudentinfo::on_Search_textEdited(const QString &substring)
{
    if (substring.isEmpty())
        return;
    QString searchcolumn;
    if (ui->checkBox->isChecked())
        searchcolumn="student.Surname";
    else
        searchcolumn="coursework.Title";
    setTable("SELECT \
              discipline.Name AS \"Дисциплина\",\
              professor.Name AS \"Имя профессора\",\
              professor.Surname AS \"Фамилия профессора\",\
              student.Name AS \"Имя студента\",\
              student.Surname AS \"Фамилия студента\",\
              coursework.Title AS \"Название\",\
              coursework.Mark AS \"Оценка\"\
              FROM coursework INNER JOIN professor ON  coursework.professor_ID= professor.ID\
              INNER JOIN discipline ON  coursework.discipline_ID=professor.ID\
              INNER JOIN student ON coursework.student_ID = student.ID\
              WHERE "+searchcolumn+" LIKE '"+substring+"%'\
              Group BY coursework.Mark");
}

void sudentinfo::on_checkBox_stateChanged()
{
    on_toDefault_clicked();
    on_Search_textEdited(ui->Search->text());
}
