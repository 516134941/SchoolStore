#ifndef USER_INFORMATION_H
#define USER_INFORMATION_H

#include <QDialog>
namespace Ui {
class User_information;
}

class User_information : public QDialog
{
    Q_OBJECT

public:
    explicit User_information(QWidget *parent = 0);
    ~User_information();
    void reSetting();//初始化或修改完成的控件显示情况，并将user里的值显示出来
    void reSetting2();//将数据库的值重新赋给user

private slots:
    void on_supply_Button_clicked();

    void on_confirm_Button_clicked();

private:
    Ui::User_information *ui;
};

#endif // USER_INFORMATION_H
