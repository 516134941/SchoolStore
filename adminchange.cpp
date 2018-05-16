#include "adminchange.h"
#include "ui_adminchange.h"
#include "login.h"
#include <QSqlQuery>
#include<QMessageBox>
int goods_id;
QString label_name_cp;
QString label_price_cp;
QString label_dsc_cp;
QString label_sum_cp;
AdminChange::AdminChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminChange)
{
    ui->setupUi(this);
    setWindowTitle("修改");
    ui->label_change->setVisible(false);
    ui->pushButton_change->setVisible(false);
    ui->lineEdit_dsc->setVisible(false);
    ui->lineEdit_name->setVisible(false);
    ui->lineEdit_price->setVisible(false);
    ui->lineEdit_sum->setVisible(false);
    ui->label_change->setVisible(false);
    ui->pushButton_change->setVisible(false);
    ui->pushButton_ok->setVisible(false);
}

AdminChange::~AdminChange()
{
    delete ui;
}

void AdminChange::on_pushButton_find_clicked()
{
     QSqlQuery query1,query2;
     query1.exec("select * from goods");
     query2.exec("select * from goods_num");
     goods_id= ui->lineEdit_id->text().toInt();
     while(query1.next())
     {
         if(query1.value(0).toInt()==goods_id)
         {
              label_name_cp=query1.value(1).toString();
              label_price_cp=query1.value(2).toString();
              label_dsc_cp=query1.value(4).toString();
              ui->label_name->setText(query1.value(1).toString());
              ui->label_price->setText(query1.value(2).toString());
              ui->label_dsc->setText(query1.value(4).toString());
              break;
         }
     }
     while(query2.next())
     {
         if(query2.value(0).toInt()==goods_id)
         {
             label_sum_cp=query2.value(1).toString();
             ui->label_sum->setText("剩余库存: "+query2.value(1).toString());
             break;
         }
     }
     ui->label_change->setVisible(true);
     ui->pushButton_change->setVisible(true);
     ui->pushButton_ok->setVisible(true);
}

void AdminChange::on_pushButton_change_clicked()
{
    ui->lineEdit_dsc->setVisible(true);
    ui->lineEdit_name->setVisible(true);
    ui->lineEdit_price->setVisible(true);
    ui->lineEdit_sum->setVisible(true);
    ui->label_dsc->setVisible(false);
    ui->label_name->setVisible(false);
    ui->label_price->setVisible(false);
    ui->label_sum->setVisible(false);
    ui->lineEdit_name->setText(label_name_cp);
    ui->lineEdit_price->setText(label_price_cp);
    ui->lineEdit_dsc->setText(label_dsc_cp);
    ui->lineEdit_sum->setText(label_sum_cp);
}

void AdminChange::on_pushButton_ok_clicked()
{
    label_name_cp=ui->lineEdit_name->text();
    label_dsc_cp=ui->lineEdit_dsc->text();
    label_price_cp=ui->lineEdit_price->text();
    label_sum_cp=ui->lineEdit_sum->text();
    QSqlQuery query1,query2;
    query1.exec("select * from goods");
    query2.exec("select * from goods_num");
    while(query1.next())
    {
        if(query1.value(0).toInt()==goods_id)
        {
             float label_price_cp2=label_price_cp.toFloat();
             query1.exec(QString("update goods set goods_name='%1',goods_price='%2',goods_dscrb='%3' where goods_id='%4'").arg(label_name_cp).arg(label_price_cp2).arg(label_dsc_cp).arg(goods_id));
             break ;
        }
    }
    while(query2.next())
    {
        if(query2.value(0).toInt()==goods_id)
        {
            int label_sum_cp2=label_sum_cp.toInt();
             query2.exec(QString("update goods_num set goods_sum='%1' where goods_id='%2'").arg(label_sum_cp2).arg(goods_id));

             QMessageBox box1;
             box1.setText("修改成功");
             box1.exec();
             ui->label_change->setVisible(false);
             ui->pushButton_change->setVisible(false);
             ui->lineEdit_dsc->setVisible(false);
             ui->lineEdit_name->setVisible(false);
             ui->lineEdit_price->setVisible(false);
             ui->lineEdit_sum->setVisible(false);
             ui->pushButton_change->setVisible(false);
             ui->pushButton_ok->setVisible(false);
             ui->label_dsc->setVisible(true);
             ui->label_name->setVisible(true);
             ui->label_price->setVisible(true);
             ui->label_sum->setVisible(true);
             ui->lineEdit_name->setText(label_name_cp);
             ui->lineEdit_price->setText(label_price_cp);
             ui->lineEdit_dsc->setText(label_dsc_cp);
             ui->lineEdit_sum->setText(label_sum_cp);
             break ;
        }
    }
}
