#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include"QMessageBox"
QString user::userId=NULL;
QString user::userPassword=NULL;
QString user::userAuthority="normal";
int user::userTreasure=0;
QString user::userEmail=NULL;
QString user::userTel=NULL;
QString user::userExplain=NULL;
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    ui->pwdLineEdit_2->setVisible(false);
    ui->usrLineEdit_2->setVisible(false);
    ui->registerBtn->setVisible(false);
    ui->backBtn->setVisible(false);
    ui->telLineEdit_3->setVisible(false);
    ui->label_3->setVisible(false);
    ui->usrLineEdit->setFocus();
    ui->loginBtn->setShortcut(QKeySequence::InsertParagraphSeparator);
    setTabOrder(ui->usrLineEdit,ui->pwdLineEdit);
    setTabOrder(ui->pwdLineEdit,ui->loginBtn);
    setWindowTitle("登录");
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确，如果错误则弹出警告对话框
    int sign=0;//记录是否输入正确 默认为0 不正确
    QSqlQuery query;
    query.exec("select * from users");
    //query.first();
   // query.next();
    if(ui->usrLineEdit->text().isEmpty()||ui->pwdLineEdit->text().isEmpty())
    {
        QMessageBox msg_error3;
        msg_error3.setText("输入的账号或者密码不能为空");
        msg_error3.exec();
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
        sign=2;
    }
    while(query.next())
    {
        if(ui->usrLineEdit->text().trimmed() == query.value(0).toString()
             && ui->pwdLineEdit->text() == query.value(1).toString())
        {
            sign=1;
            user::userId=query.value(0).toString();
            user::userPassword=query.value(1).toString();
            user::userAuthority=query.value(2).toString();
            user::userTreasure=query.value(3).toInt();
            user::userEmail=query.value(4).toString();
            user::userTel=query.value(5).toString();
            user::userExplain=query.value(6).toString();
            accept();
            break;
        }
        if(sign==2)
            break;//账号密码为空 直接跳出
    }
    if(sign==0)
    {
        QMessageBox::warning(this, tr("Waring"),
                             tr("user name or password error!"),
                             QMessageBox::Yes);
        // 清空内容并定位光标
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}
void Login::on_pushButton_register_clicked()
{
   ui->usrLineEdit->setVisible(false);
   ui->pwdLineEdit->setVisible(false);
   //ui->label->setVisible(false);
  // ui->label_2->setVisible(false);
   ui->loginBtn->setVisible(false);
   ui->exitBtn->setVisible(false);
   ui->usrLineEdit_2->setVisible(true);
   ui->pwdLineEdit_2->setVisible(true);
   setWindowTitle("注册");
   ui->registerBtn->setVisible(true);
   ui->backBtn->setVisible(true);
   ui->loginBtn_2->setVisible(false);
   ui->telLineEdit_3->setVisible(true);
   ui->usrLineEdit_2->setFocus();
   ui->pushButton_register->setVisible(false);
   ui->label_3->setVisible(true);
   setTabOrder(ui->telLineEdit_3,ui->loginBtn_2);
}

void Login::on_registerBtn_clicked()//用户注册按钮
{
    QSqlQuery query;
    int sign2=0;//sign2用于判定是否有相同的用户名，若有相同的用户名则赋值为1，默认为0,输入为空赋值为2
    query.exec("select id,password from users");
    if(ui->usrLineEdit_2->text().isEmpty()||ui->pwdLineEdit_2->text().isEmpty())
    {
        QMessageBox msg_error3;
        msg_error3.setText("输入的账号或者密码不能为空");
        msg_error3.exec();
        ui->usrLineEdit_2->clear();
        ui->pwdLineEdit_2->clear();
        ui->telLineEdit_3->clear();
        ui->usrLineEdit_2->setFocus();
        sign2=2;
    }
    while(query.next())//检索数据库  看是否有相同的用户名
    {
        if(ui->usrLineEdit_2->text().trimmed() == query.value(0).toString())
        {
            sign2=1;
            QMessageBox msg_error1;
            msg_error1.setText("已存在相同的用户，请重新输入一个用户名与密码");
            msg_error1.exec();
            ui->usrLineEdit_2->clear();
            ui->pwdLineEdit_2->clear();
            ui->telLineEdit_3->clear();
            ui->usrLineEdit_2->setFocus();
            break;
        }

    }
    QRegExp rx_tel("^1[358]\\d{9}$");
    const QByteArray text3=ui->telLineEdit_3->text().trimmed().toLocal8Bit();
    if(rx_tel.indexIn(text3.data())!=-1)
        sign2=0;
    else {
        sign2=3;
        QMessageBox mag_error2;
        mag_error2.setText("请输入正确的手机号");
        mag_error2.exec();
    }

    if(sign2==0)//将用户添加到数据库中
    {
        //QString user;//用户名
        //QString password;//密码
        const  QByteArray text1=ui->usrLineEdit_2->text().trimmed().toLocal8Bit();//强赚const*char
        const char *user=text1.data();
        const  QByteArray text2=ui->pwdLineEdit_2->text().trimmed().toLocal8Bit();
        const char *password=text2.data();
       // const QByteArray text3=ui->telLineEdit_3->text().trimmed().toLocal8Bit();
        const char *tel=text3.data();
        //password=ui->pwdLineEdit_2->text().trimmed();

        query.exec(QString("insert into users values('%1','%2','normal',0,NULL,'%3',NULL)").arg(user).arg(password).arg(tel));
        QMessageBox msg_success;
        msg_success.setText("创建成功");
        msg_success.exec();
        ui->usrLineEdit_2->clear();
        ui->pwdLineEdit_2->clear();
        ui->telLineEdit_3->clear();
        on_backBtn_clicked();
    }
}
void Login::on_backBtn_clicked()//返回按钮
{
    ui->usrLineEdit->setVisible(true);
    ui->pwdLineEdit->setVisible(true);
    //ui->label->setVisible(false);
   // ui->label_2->setVisible(false);
    ui->loginBtn->setVisible(true);
    ui->exitBtn->setVisible(true);
    ui->usrLineEdit_2->setVisible(false);
    ui->pwdLineEdit_2->setVisible(false);
    setWindowTitle("登录");
    ui->registerBtn->setVisible(false);
    ui->backBtn->setVisible(false);
    ui->loginBtn_2->setVisible(true);
    ui->telLineEdit_3->setVisible(false);
    ui->pushButton_register->setVisible(true);
    ui->label_3->setVisible(false);
}

void Login::on_loginBtn_2_clicked()
{
    accept();
}
