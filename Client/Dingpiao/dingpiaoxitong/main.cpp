#include "mainwindow.h"
#include "denglu.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    denglu *Denglu = new denglu();
    if(Denglu->exec()==QDialog::Accepted){
        w.show();
        //w.getmsg();
        return a.exec();
    }
    else
        return 0;
}


