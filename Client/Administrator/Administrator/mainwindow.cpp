#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *table = ui->tableWidget;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table = ui->tableWidget_2;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
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
    switch(QMessageBox::question(NULL, "question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        QMessageBox::about(NULL, "About", "About this application");

        break;
    case QMessageBox::No:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    addconductor.show();
    addconductor.exec();
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

void MainWindow::on_pushButton_4_clicked()
{
    addcoach.show();
    addcoach.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    changecoach.show();
    changecoach.exec();
}
