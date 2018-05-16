#include "recharge.h"
#include "ui_recharge.h"

Recharge::Recharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recharge)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("充值");
    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(false);
    ui->pushButton_back->setVisible(false);
    ui->label_zfb_10->setVisible(false);
    ui->label_zfb_all->setVisible(false);
    ui->label_wx->setVisible(false);
    ui->label_wx_10->setVisible(false);
}

Recharge::~Recharge()
{
    delete ui;
}

void Recharge::on_pushButton_zfb_clicked()
{
    ui->groupBox->setVisible(true);
    ui->pushButton_zfb->setVisible(false);
    ui->pushButton_wx->setVisible(false);
    ui->pushButton_back->setVisible(true);
}

void Recharge::on_pushButton_wx_clicked()
{
    ui->groupBox_2->setVisible(true);
    ui->pushButton_zfb->setVisible(false);
    ui->pushButton_wx->setVisible(false);
    ui->pushButton_back->setVisible(true);
}

void Recharge::on_pushButton_back_clicked()
{
    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(false);
    ui->pushButton_back->setVisible(false);
    ui->pushButton_wx->setVisible(true);
    ui->pushButton_zfb->setVisible(true);
    ui->label_zfb_10->setVisible(false);
    ui->label_zfb_all->setVisible(false);
    ui->label_wx->setVisible(false);
    ui->label_wx_10->setVisible(false);
}

void Recharge::on_pushButton_zfb_10_clicked()
{
    ui->label_zfb_10->setVisible(true);
    ui->groupBox->setVisible(false);
}


void Recharge::on_pushButton_zfb_all_clicked()
{
    ui->label_zfb_all->setVisible(true);
    ui->groupBox->setVisible(false);
}

void Recharge::on_pushButton_wx_10_clicked()
{
    ui->label_wx_10->setVisible(true);
    ui->groupBox_2->setVisible(false);
}

void Recharge::on_pushButton_wx_all_clicked()
{
    ui->label_wx->setVisible(true);
    ui->groupBox_2->setVisible(false);
}
