#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"upload.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ncgc_Button_clicked();

    void on_wywm_Button_clicked();

    void on_jxnu_Button_3_clicked();

    void on_jxnu_Button_clicked();

    void on_homeButton_clicked();

    void on_user_Button_clicked();

    void on_pushButton_recharge_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_admin_clicked();


    void on_pushButton_get_clicked();

    void on_pushButton_get_2_clicked();

    void on_pushButton_get_3_clicked();

    void on_pushButton_get_4_clicked();

    void on_pushButton_get_5_clicked();

    void on_pushButton_get_7_clicked();

    void on_pushButton_get_8_clicked();

    void on_pushButton_get_9_clicked();

    void on_pushButton_get_10_clicked();

    void on_pushButton_get_11_clicked();

    void on_pushButton_get_12_clicked();

    void on_pushButton_get_13_clicked();

    void on_pushButton_get_14_clicked();

    void on_pushButton_get_15_clicked();

    void on_pushButton_get_16_clicked();

    void on_pushButton_get_17_clicked();

    void on_pushButton_get_18_clicked();

    void on_pushButton_get_19_clicked();

    void on_pushButton_get_20_clicked();

    void on_pushButton_get_21_clicked();

    void on_collectionButton_clicked();

    void on_messageButton_clicked();

    void on_pushButton_create_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    UpLoad *lp;
};

#endif // MAINWINDOW_H
