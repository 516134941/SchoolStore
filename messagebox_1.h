#ifndef MESSAGEBOX_1_H
#define MESSAGEBOX_1_H

#include <QDialog>

namespace Ui {
class MessageBox_1;
}

class MessageBox_1 : public QDialog
{
    Q_OBJECT

public:
    explicit MessageBox_1(QWidget *parent = 0);
    ~MessageBox_1();

private:
    Ui::MessageBox_1 *ui;
};

#endif // MESSAGEBOX_1_H
