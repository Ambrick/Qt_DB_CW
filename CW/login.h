#include "biblio.h"
#ifndef LOGIN_H
#define LOGIN_H
namespace Ui { class Login;}
class Login : public QMainWindow
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
private slots:
    void on_Go_clicked();
private:
    Ui::Login *ui;
};
#endif // LOGIN_H
