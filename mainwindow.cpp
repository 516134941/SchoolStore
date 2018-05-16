#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMessageBox"
#include"user_information.h"
#include"login.h"
#include"recharge.h"
#include <QSqlQuery>
#include<QMovie>
#include"adminchange.h"
#include"shoppingcar.h"
#include"message.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口固定大小
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    //设置窗口名字
    setWindowTitle("S-Store 校园个人商铺");
    //dateTimeEdit设置
    ui->dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
   /* QMovie *movie=new QMovie("./pic_main/gif1.gif");
    ui->label_gif->setMovie(movie);
    movie->start();*/
    //
    //toolBox设置
   // ui->toolBox->setItemText(0,"南昌地区(东)");
    ui->toolBox->setItemText(1,"南昌地区(北)");
    ui->toolBox->setItemText(2,"南昌地区(西)");
    ui->toolBox->setItemText(3,"    收     ");
    QIcon icon_position(":/pic_main/location_2.png");
    ui->toolBox->setItemIcon(0,icon_position);
    ui->toolBox->setItemIcon(1,icon_position);
    ui->toolBox->setItemIcon(2,icon_position);
    QIcon icon_back(":/pic_toolBox/up.png");
    ui->toolBox->setItemIcon(3,icon_back);
    //
    //设置初始状态
    ui->tabWidget_jxnu->setVisible(false);
    //
    //获取金币余额
    User_information seaching;
    seaching.reSetting2();
    QString money=QString::number( user::userTreasure,10);
    ui->label_money->setText(money +"RMB");
    QFont ft_money;
    ft_money.setPointSize(18); //money字号
    ui->label_money->setFont(ft_money);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::darkYellow);//money颜色
    ui->label_money->setPalette(pa);
    //

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ncgc_Button_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("此版块尚未开通.");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_wywm_Button_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("此版块尚未开通.");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_jxnu_Button_3_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("此版块尚未开通.");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_jxnu_Button_clicked()
{
    ui->tabWidget_jxnu->setVisible(true);
    ui->groupBox_11->setVisible(false);
    on_pushButton_3_clicked();
    QSqlQuery query;
    query.exec("select * from goods");//查询货物信息
    while(query.next())
    {
        if(query.value(0).toInt()==10001)
        {
            ui->label_desc->setText(query.value(4).toString());
            ui->label_value->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==10002)
        {
            ui->label_desc_2->setText(query.value(4).toString());
            ui->label_value_2->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==10003)
        {
            ui->label_desc_3->setText(query.value(4).toString());
            ui->label_value_3->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==10004)
        {
            ui->label_desc_4->setText(query.value(4).toString());
            ui->label_value_4->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==10005)
        {
            ui->label_desc_5->setText(query.value(4).toString());
            ui->label_value_5->setText(query.value(2).toString()+"¥");

        }if(query.value(0).toInt()==10006)
        {
            ui->label_desc_6->setText(query.value(4).toString());
            ui->label_value_6->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==10007)
        {
            ui->label_desc_7->setText(query.value(4).toString());
            ui->label_value_7->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==10008)
        {
            ui->label_desc_8->setText(query.value(4).toString());
            ui->label_value_8->setText(query.value(2).toString()+"¥");
            break;
        }
    }
}

void MainWindow::on_homeButton_clicked()//首页按键
{
    ui->tabWidget_jxnu->setVisible(false);
    ui->groupBox_hold->setVisible(true);
}

void MainWindow::on_user_Button_clicked()
{
       if(user::userId==NULL)
       {
           QMessageBox::about(NULL,"提示","游客账户  请先注册！！");
       }
       else
        {
           User_information dlg;
            dlg.exec();
       }
}

void MainWindow::on_pushButton_recharge_clicked()
{
    Recharge recharge;
    recharge.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->groupBox_11->setVisible(true);
    ui->groupBox_12->setVisible(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->groupBox_11->setVisible(false);
    ui->groupBox_12->setVisible(true);
    ui->groupBox_hold->setVisible(false);
    QSqlQuery query;
    query.exec("select * from goods");//查询货物信息
    while(query.next())//麻辣类  9-22  20001-20012
    {
        if(query.value(0).toInt()==20001)
        {
            ui->label_desc_9->setText(query.value(4).toString());
            ui->label_value_9->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20002)
        {
            ui->label_desc_10->setText(query.value(4).toString());
            ui->label_value_10->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20003)
        {
            ui->label_desc_11->setText(query.value(4).toString());
            ui->label_value_11->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20004)
        {
            ui->label_desc_12->setText(query.value(4).toString());
            ui->label_value_12->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20005)
        {
            ui->label_desc_13->setText(query.value(4).toString());
            ui->label_value_13->setText(query.value(2).toString()+"¥");

        }if(query.value(0).toInt()==20006)
        {
            ui->label_desc_14->setText(query.value(4).toString());
            ui->label_value_14->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20007)
        {
            ui->label_desc_15->setText(query.value(4).toString());
            ui->label_value_15->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20008)
        {
            ui->label_desc_16->setText(query.value(4).toString());
            ui->label_value_16->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20009)
        {
            ui->label_desc_17->setText(query.value(4).toString());
            ui->label_value_17->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20010)
        {
            ui->label_desc_18->setText(query.value(4).toString());
            ui->label_value_18->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20011)
        {
            ui->label_desc_20->setText(query.value(4).toString());
            ui->label_value_20->setText(query.value(2).toString()+"¥");

        }
        if(query.value(0).toInt()==20012)
        {
            ui->label_desc_22->setText(query.value(4).toString());
            ui->label_value_22->setText(query.value(2).toString()+"¥");

        }
    }
}

void MainWindow::on_pushButton_admin_clicked()
{
    QString a="admin";
    if(user::userAuthority!=a)
    {
        QMessageBox msgBox;
        msgBox.setText("您没有管理员权限.");
        msgBox.setWindowTitle("通知");
        msgBox.exec();
    }
    else
    {
        AdminChange adminchange;
        adminchange.exec();
    }

}

void MainWindow::on_pushButton_get_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10001)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_2_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10002)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_3_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10003)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_4_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10004)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_5_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10005)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_7_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10006)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_8_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10007)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_9_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',10008)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_10_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20001)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_11_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20002)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_12_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20003)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_13_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20004)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_14_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20005)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_15_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20006)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_16_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20007)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_17_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20008)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_18_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20009)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_19_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20010)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_20_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20011)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_pushButton_get_21_clicked()
{
    QSqlQuery query1;
    query1.exec(QString("insert into shopping_car values('%1',20012)").arg(user::userId));
    QMessageBox msgBox;
    msgBox.setText("添加成功");
    msgBox.setWindowTitle("通知");
    msgBox.exec();
}

void MainWindow::on_collectionButton_clicked()
{
    ShoppingCar shoppingcar;
    shoppingcar.exec();
}

void MainWindow::on_messageButton_clicked()
{
    Message messg;
    messg.exec();
}

void MainWindow::on_pushButton_create_clicked()
{
   lp=new UpLoad;
    lp->show();
}

void MainWindow::on_pushButton_clicked()
{

}
