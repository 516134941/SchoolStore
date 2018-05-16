#ifndef ADMINCHANGE_H
#define ADMINCHANGE_H

#include <QDialog>

namespace Ui {
class AdminChange;
}

class AdminChange : public QDialog
{
    Q_OBJECT

public:
    explicit AdminChange(QWidget *parent = 0);
    ~AdminChange();

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::AdminChange *ui;
};

#endif // ADMINCHANGE_H
