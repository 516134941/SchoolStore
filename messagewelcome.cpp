#include "messagewelcome.h"
#include "ui_messagewelcome.h"

MessageWelcome::MessageWelcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageWelcome)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("welcome");
}

MessageWelcome::~MessageWelcome()
{
    delete ui;
}
