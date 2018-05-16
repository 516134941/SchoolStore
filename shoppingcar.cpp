#include "shoppingcar.h"
#include "ui_shoppingcar.h"
#include "login.h"
#include <QSqlQuery>
#include<QMessageBox>
float sum=0;//用于计算物品总价
ShoppingCar::ShoppingCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCar)
{
    ui->setupUi(this);
    setWindowTitle("物品收藏夹");
    QSqlQuery query1,query2;
    query1.exec("select * from shopping_car");
  //  query2.exec("select * from goods");
    int sign=0;//sign用于做label标记
    while(query1.next())
    {
        if(user::userId == query1.value(0).toString()&&sign==0)
        {
         //   ui->label_name->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                   ui-> label_name->setText(query2.value(1).toString());
                   ui->label_price->setText(query2.value(2).toString());
                   sum=sum+query2.value(2).toFloat();
                }
            }
        }
        if(user::userId == query1.value(0).toString()&&sign==1)
        {
         //   ui->label_name_2->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_2->setText(query2.value(1).toString());
                    ui->label_price_2->setText(query2.value(2).toString());
                   sum=sum+query2.value(2).toFloat();
                }

            }
        }
        if(user::userId == query1.value(0).toString()&&sign==2)
        {
           // ui->label_name_3->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_3->setText(query2.value(1).toString());
                    ui->label_price_3->setText(query2.value(2).toString());
                    sum=sum+query2.value(2).toFloat();
                }

            }
        }
        if(user::userId == query1.value(0).toString()&&sign==3)
        {
          //  ui->label_name_4->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_4->setText(query2.value(1).toString());
                    ui->label_price_4->setText(query2.value(2).toString());
                    sum=sum+query2.value(2).toFloat();
                }

            }
        }
        if(user::userId == query1.value(0).toString()&&sign==4)
        {
          //  ui->label_name_5->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_5->setText(query2.value(1).toString());
                    ui->label_price_5->setText(query2.value(2).toString());
                    sum=sum+query2.value(2).toFloat();
                }

            }
        }
        if(user::userId == query1.value(0).toString()&&sign==5)
        {
          //  ui->label_name_6->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_6->setText(query2.value(1).toString());
                    ui->label_price_6->setText(query2.value(2).toString());
                    sum=sum+query2.value(2).toFloat();

                }

            }
        }
        if(user::userId == query1.value(0).toString()&&sign==6)
        {
          //  ui->label_name_7->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_7->setText(query2.value(1).toString());
                    ui->label_price_7->setText(query2.value(2).toString());
                    sum=sum+query2.value(2).toFloat();
                }

            }
        }
        if(user::userId == query1.value(0).toString()&&sign==7)
        {
           // ui->label_name_8->setText(query1.value(1).toString());
            query2.exec("select * from goods");
            while(query2.next())
            {
                if(query2.value(0)==query1.value(1))
                {
                    ui->label_name_8->setText(query2.value(1).toString());
                    ui->label_price_8->setText(query2.value(2).toString());
                    sum=sum+query2.value(2).toFloat();
                }
            }
        }
        sign++;
    }
    QString sum_string = QString("%1").arg(sum);
    ui->label_sum->setText("总价值： "+sum_string);
}

ShoppingCar::~ShoppingCar()
{
    delete ui;
}

void ShoppingCar::on_pushButton_ok_clicked()
{
    QSqlQuery query,query1;
    query.exec("select * from users");
    while(query.next())
    {
        if(user::userId == query.value(0).toString())
        {
            float price=query.value(3).toFloat();
            if(price>=sum)
            {
                price=price-sum;
                query.exec(QString("update users set treasure='%1' where user_id='%2'").arg(price).arg(user::userId));
                sum=0;
               query1.exec("select * from shopping_car");
               while(query1.next())
               {
                   if(user::userId == query1.value(0).toString())
                   {
                       query1.exec(QString("delete from shopping_car where user_id = '%1'").arg(user::userId));
                   }
               }
               ui-> label_name->setText("无");
               ui->label_price->setText("0");
               ui-> label_name_2->setText("无");
               ui->label_price_2->setText("0");
               ui-> label_name_3->setText("无");
               ui->label_price_3->setText("0");
               ui-> label_name_4->setText("无");
               ui->label_price_4->setText("0");
               ui-> label_name_5->setText("无");
               ui->label_price_5->setText("0");
               ui-> label_name_6->setText("无");
               ui->label_price_6->setText("0");
               ui-> label_name_7->setText("无");
               ui->label_price_7->setText("0");
               ui-> label_name_8->setText("无");
               ui->label_price_8->setText("0");
               ui->label_sum->setText("0");
               QMessageBox msgBox2;
               msgBox2.setText("支付成功");
               msgBox2.setWindowTitle("通知");
               msgBox2.exec();
            }
            else{
                QMessageBox msgBox;
                msgBox.setText("余额不足");
                msgBox.setWindowTitle("通知");
                msgBox.exec();
            }
        }
    }
}
