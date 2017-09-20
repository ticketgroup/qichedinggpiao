#include "variables.h"
#include "mainwindow.h"
#include "denglu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Denglu denglu;
    if(denglu.exec()==QDialog::Accepted){
    w.show();
    return a.exec();
    }



    else return 0;
}
