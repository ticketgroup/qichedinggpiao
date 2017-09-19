#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <cstring>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    char a[100] = "12345|北京北|12:31|北京南|13:10|21|￥10|";

    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setMinimumDate(QDate::currentDate().addDays(0));
    ui->dateEdit->setMaximumDate(QDate::currentDate().addDays(5));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    QTableWidget *table = ui->tableWidget;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setRowCount(3);
    table->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,"|"))));
    for(int i = 1; i < 7; i++)
    {
        table->setItem(0,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,"|"))));
    }
    table = ui->tableWidget_4;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    /*
    table->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit("安抚")));
    table->setItem(1,0,new QTableWidgetItem("01002"));
    table->setItem(2,0,new QTableWidgetItem("01003"));
    table->setItem(0,1,new QTableWidgetItem("Ann"));
    table->setItem(1,1,new QTableWidgetItem("Sam"));
    table->setItem(2,1,new QTableWidgetItem("Lily"));
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{

    passwordchange.show();
    passwordchange.exec();

}

void MainWindow::on_pushButton_2_clicked()
{

    telephonechange.show();
    telephonechange.exec();

}

void MainWindow::on_pushButton_5_clicked()
{
    endorse.show();
    endorse.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    buyticket.show();
    buyticket.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    switch(QMessageBox::question(NULL, "question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        QMessageBox::about(NULL, "About", "About this application");
        break;
    case QMessageBox::No:
        break;

    }
}

