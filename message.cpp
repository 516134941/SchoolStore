#include "message.h"
#include "ui_message.h"
#include"messagebox_1.h"
#include"messagewelcome.h"
Message::Message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);
    setWindowTitle("信息");
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
}

Message::~Message()
{
    delete ui;
}

void Message::on_pushButton_clicked()
{
    MessageWelcome box1;
    box1.exec();
}
