#ifndef RECHARGE_H
#define RECHARGE_H

#include <QDialog>

namespace Ui {
class Recharge;
}

class Recharge : public QDialog
{
    Q_OBJECT

public:
    explicit Recharge(QWidget *parent = 0);
    ~Recharge();

private slots:
    void on_pushButton_zfb_clicked();

    void on_pushButton_wx_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_zfb_10_clicked();

    void on_pushButton_zfb_all_clicked();

    void on_pushButton_wx_10_clicked();

    void on_pushButton_wx_all_clicked();

private:
    Ui::Recharge *ui;
};

#endif // RECHARGE_H
