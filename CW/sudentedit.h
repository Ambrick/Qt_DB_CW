#ifndef SUDENTEDIT_H
#define SUDENTEDIT_H

#include <QDialog>

namespace Ui {
class sudentedit;
}

class sudentedit : public QDialog
{
    Q_OBJECT

public:
    explicit sudentedit(QWidget *parent = nullptr);
    ~sudentedit();

    void RefreshItems();
private slots:


    void on_Delete_clicked();

    void on_Edit_clicked();

    void on_Add_clicked();

    void on_Group_activated(int index);

private:
    Ui::sudentedit *ui;
};

#endif // SUDENTEDIT_H
