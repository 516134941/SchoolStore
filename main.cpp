#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include"login.h"
#include"user_information.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection()) return 0;
    Login loginDlg;
    if (loginDlg.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        //w.showMaximized();
        return a.exec();
    }
    else return 0;
}
