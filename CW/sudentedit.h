#include "biblio.h"
#ifndef SUDENTEDIT_H
#define SUDENTEDIT_H
namespace Ui { class sudentedit; }
class sudentedit : public QDialog
{
    Q_OBJECT
public:
    explicit sudentedit(QWidget *parent = nullptr);
    ~sudentedit();
    QSqlDatabase mydb;
    QSqlQueryModel * TableView()
    {
        QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *  q_show = new QSqlQuery(mydb);
        q_show->prepare("SELECT \
                         coursework.ID AS \"ID\",\
                         discipline.Name AS \"Дисциплина\",\
                         professor.Name AS \"Имя профессора\",\
                         professor.Surname AS \"Фамилия профессора\",\
                         student.Name AS \"Имя студента\",\
                         student.Surname AS \"Фамилия студента\",\
                         coursework.Title AS \"Название\",\
                         coursework.Mark AS \"Оценка\"\
                         FROM coursework INNER JOIN professor ON coursework.professor_ID= professor.ID\
                         INNER JOIN discipline ON coursework.discipline_ID=discipline.ID\
                         INNER JOIN student ON coursework.student_ID = student.ID");
        q_show->exec();
        modal->setQuery(*q_show);
        return  modal;
    }
    void setTable();
    void connOpen(QString filename){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("roooooot");
        db.setDatabaseName(filename);
        db.open();
    }
    bool DoesRowExist(QString El, QString Table, QString Column){
        QSqlQuery query("SELECT * FROM "+Table+" WHERE "+Column+"="+El);
        if (query.next())
            return true;
        return false;
    }
private slots:
    void on_Delete_clicked();
    void on_Edit_clicked();
    void on_Add_clicked();
    void on_Group_activated(int index);
    void on_ID_textChanged(const QString &ID);
private:
    Ui::sudentedit *ui;
};
#endif // SUDENTEDIT_H
