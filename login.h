#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class Login;
}
class user
{
public:
   static  QString userId;
   static  QString userPassword;
   static  QString userAuthority;
   static  int userTreasure;
   static  QString userEmail;
   static  QString  userTel;
   static  QString userExplain;

};
class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;

private slots:
    void on_loginBtn_clicked();

    void on_pushButton_register_clicked();

    void on_registerBtn_clicked();

    void on_backBtn_clicked();

    void on_loginBtn_2_clicked();
};

#endif // LOGIN_H
