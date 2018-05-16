#include "user_information.h"
#include "ui_user_information.h"
#include <mainwindow.h>
#include"login.h"
#include"QMessageBox"
User_information::User_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_information)
{
    ui->setupUi(this);
    User_information::reSetting();//设置各个控件的状态

}

User_information::~User_information()
{
    delete ui;
}

void User_information::reSetting()
{
        ui->set_password->setVisible(false);
        ui->set_email->setVisible(false);
        ui->set_tel->setVisible(false);
        ui->set_explain->setVisible(false);
        ui->confirm_Button->setVisible(false);
        //将user的实例化显示出来
        ui->label->setText("尊敬的用户 " + user::userId + " 欢迎你");
        ui->label_2->setText(user::userId + " 的个人信息");
        ui->m_user->setText     ("用户ID:       " + user::userId);
        ui->m_password->setText ("用户密码:      ********");
        ui->m_auth->setText     ("用户权限:      " + user::userAuthority);
        QString userTreasure_copy= QString::number( user::userTreasure,10);
        ui->m_money->setText      ("用户余额:    " + userTreasure_copy +"RMB");
        ui->m_sex->setText      ("用户邮箱:      " + user::userEmail);
        ui->m_tel->setText      ("用户电话:      " + user::userTel);
        ui->m_explaim->setText  ("说明:         " + user::userExplain);
}

void User_information::on_supply_Button_clicked()
{
    //重新设置控件状态
    ui->set_password->setVisible(true);
    ui->m_password->setText ("用户密码:      ");
    ui->m_sex->setText      ("用户邮箱:      ");
    ui->m_tel->setText      ("用户电话:      ");
    ui->m_explaim->setText  ("说明:         ");
    ui->set_email->setVisible(true);
    ui->set_tel->setVisible(true);
    ui->set_explain->setVisible(true);
    ui->confirm_Button->setVisible(true);
    ui->set_password->setText(user::userPassword);
    ui->set_email->setText(user::userEmail);
    ui->set_tel->setText(user::userTel);
    ui->set_explain->setText(user::userExplain);
}

void User_information::on_confirm_Button_clicked()
{
    QSqlQuery query;
    const  QByteArray text1=ui->set_password->text().trimmed().toLocal8Bit();
    const char *password=text1.data();
    const  QByteArray text2=ui->set_email->text().trimmed().toLocal8Bit();
    const char *email=text2.data();
    const  QByteArray text3=ui->set_tel->text().trimmed().toLocal8Bit();
    const char *tel=text3.data();
    const  QByteArray text4=ui->set_explain->text().trimmed().toLocal8Bit();
    const char *explain=text4.data();
    query.exec("select * from users");
    while(query.next())
    {
        if(user::userId == query.value(0).toString())
        {
             query.exec(QString("update users set password='%1',email='%2',tel='%3',explain='%4' where user_id='%5'").arg(password).arg(email).arg(tel).arg(explain).arg(user::userId));
             QMessageBox box1;
             box1.setText("完善或修改信息成功");
             box1.exec();
             reSetting2();
             reSetting();
             break ;
        }
    }
}
void User_information::reSetting2()
{
    QSqlQuery query;
    query.exec("select * from users");
    while(query.next())
    {
        if(user::userId == query.value(0).toString())
        {
            user::userPassword=query.value(1).toString();
            user::userAuthority=query.value(2).toString();
            user::userTreasure=query.value(3).toInt();
            user::userEmail=query.value(4).toString();
            user::userTel=query.value(5).toString();
            user::userExplain=query.value(6).toString();
            break;
        }
    }
}
