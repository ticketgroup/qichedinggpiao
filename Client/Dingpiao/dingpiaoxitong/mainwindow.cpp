#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <cstring>
#include <QList>



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

void MainWindow::getmsg()
{
    /*
    char st[55];
    client.sendmsg("33","0", st, 2, 55);
    (QTextLabel*) l[4] = {ui->label_10,ui->label_11,ui->label_12,ui->label_13};
    l[0]->setText(QString::fromLocal8Bit(strtok(st,";")));
    for(int i = 1; i < 4; i++)
    {
        l[i]->setText(QString::fromLocal8Bit(strtok(NULL, ";")));
    }

    char st[1000];
    client.sendmsg("13","0", st, 2, 1000);
    char *a;
    QTableWidget *table = ui->tableWidget_4;
    a = strtok(st,"\");
    table->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
    for(int i = 1; i < 8; i++)
    {
        table->setItem(0,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
    }
    for(int m = 1; a = strtok(NULL,"\"); m++)
    {
        table->setItem(m,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
        for(int i = 1; i < 8; i++)
        {
            table->setItem(m,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
        }
    }*/

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
    /*
    QList<QTableWidgetSelectionRange>ranges=ui->tableWidget_4->selectedRanges();
    int count = ranges.count();
    if(count!=0)
    {
        int row=ranges.at(0).topRow();
        QString busid = ui->tableWidget_4->item(row, 0)->text();
        QString date = ui->tableWidget_4->item(row, 1)->text();
        QString startplace = ui->tableWidget_4->item(row, 2)->text();
        QString finishplace = ui->tableWidget_4->item(row, 4)->text();
        QString number = ui->tableWidget_4->item(row, 8)->text();
        QByteArray ba = (busid + ";" + date + ";" + startplace + ";" + finishplace + ";" + number).toLatin1();
        char st[10];
        client.sendmsg("12",ba.data()", st, 56, 2);
       */
//        endorse.setLabel(ui->tableWidget_4->item(row,2)->text(),ui->tableWidget_4->item(row,4)->text());
        endorse.show();
        endorse.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    /*
    QList<QTableWidgetSelectionRange>ranges=ui->tableWidget->selectedRanges();
    int count = ranges.count();
    if(count!=0)
    {
        int row=ranges.at(0).topRow();
        QString busid = ui->tableWidget->item(row, 0)->text();
        QString number = ui->LineEdit->text();
        QString date = ui->dateEdit->text();
        QString startplace = ui->comboBox->text();
        QString finishplace = ui->comboBox_2->text();

        QByteArray ba = (number + ";" + date + ";" + busid + ";" + startplace + ";" + finishplace).toLatin1();
        char st[10];
        client.sendmsg("12",ba.data()", st, 56, 2);
        if(st[0] == 'Y')
        {*/
//            buyticket.getmeg();
            buyticket.show();
            buyticket.exec();
       /* }
        else if(st[0] == '1')
        {
            QMessageBox::about(NULL, "购票失败", "该车次无座！");
        }

    }
    else
    {
        QMessageBox::about(NULL, "购票失败", "请选择车次");
    } */

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
     /*
    QString date = ui->dateEdit->text();
    QString startplace = ui->comboBox->text();
    QString finishplace = ui->comboBox_2->text();

    QByteArray ba = (date + ";" + startplace + ";" + finishplace).toLatin1();
    char st[1000];
    client.sendmsg("4",ba.data(), st, 40, 1000);
    if(st[0] != 'N')
    {

        char *a;

        QTableWidget *table = ui->tableWidget;
        a = strtok(st,"\");
        table->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
        for(int i = 1; i < 7; i++)
        {
            table->setItem(0,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
        }
        for(int m = 1; a = strtok(NULL,"\"); m++)
        {
            table->setItem(m,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
            for(int i = 1; i < 7; i++)
            {
                table->setItem(m,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
            }
        }
    }
    else
    {
        QMessageBox::about(NULL, "搜索失败", "无相应车辆！");
    }
     */

}
