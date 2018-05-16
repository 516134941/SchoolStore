#ifndef MESSAGEWELCOME_H
#define MESSAGEWELCOME_H

#include <QDialog>

namespace Ui {
class MessageWelcome;
}

class MessageWelcome : public QDialog
{
    Q_OBJECT

public:
    explicit MessageWelcome(QWidget *parent = 0);
    ~MessageWelcome();

private:
    Ui::MessageWelcome *ui;
};

#endif // MESSAGEWELCOME_H
