#include "messagebox_1.h"
#include "ui_messagebox_1.h"

MessageBox_1::MessageBox_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageBox_1)
{
    ui->setupUi(this);
}

MessageBox_1::~MessageBox_1()
{
    delete ui;
}
