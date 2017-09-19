#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passwordchange.h"
#include "telephonechange.h"
#include "buyticket.h"
#include "endorse.h"


#include <QDialog>
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
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();


private:
    Ui::MainWindow *ui;
    Passwordchange passwordchange;
    Telephonechange telephonechange;
    Buyticket buyticket;
    Endorse endorse;



};

#endif // MAINWINDOW_H
