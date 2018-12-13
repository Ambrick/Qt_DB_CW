#ifndef SUDENTINFO_H
#define SUDENTINFO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QtDebug>
#include <QFileInfo>
#include <QSqlTableModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class sudentinfo;
}

class sudentinfo : public QDialog
{
    Q_OBJECT

public:
    explicit sudentinfo(QWidget *parent = nullptr);
    ~sudentinfo();

    QSqlDatabase mydb;

private slots:


private:
    Ui::sudentinfo *ui;
};

#endif // SUDENTINFO_H
