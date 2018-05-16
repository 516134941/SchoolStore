#ifndef SHOPPINGCAR_H
#define SHOPPINGCAR_H

#include <QDialog>

namespace Ui {
class ShoppingCar;
}

class ShoppingCar : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCar(QWidget *parent = 0);
    ~ShoppingCar();

private slots:

    void on_pushButton_ok_clicked();

private:
    Ui::ShoppingCar *ui;
};

#endif // SHOPPINGCAR_H
