#include "biblio.h"
#ifndef SUDENTINFO_H
#define SUDENTINFO_H
namespace Ui { class sudentinfo; }
class sudentinfo : public QDialog
{
    Q_OBJECT
public:
    explicit sudentinfo(QWidget *parent = nullptr);
    ~sudentinfo();
    QSqlDatabase mydb;
    QSqlQueryModel * CustomTableView(QString sqript)
    {
        QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *  qry = new QSqlQuery(mydb);
        qry->prepare(sqript);
        qry->exec();
        modal->setQuery(*qry);
        return  modal;
    }
    void setTable(QString script);
private slots:
    void on_Slider_valueChanged(int value);
    void on_toAVG_clicked();
    void on_toSort_clicked();
    void on_toDefault_clicked();
    void on_toGetBadStudents_clicked();
    void on_Search_textEdited(const QString &substring);
    void on_checkBox_stateChanged();
private:
    Ui::sudentinfo *ui;
};
#endif // SUDENTINFO_H
