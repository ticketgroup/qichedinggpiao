#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setMinimumDate(QDate::currentDate().addDays(0));
    ui->dateEdit->setMaximumDate(QDate::currentDate().addDays(5));
    QTableWidget *table = ui->tableWidget;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table = ui->tableWidget_4;
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


void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pushButton_4_clicked()
{       
//  endorse.setLabel(ui->tableWidget_4->item(row,2)->text(),ui->tableWidget_4->item(row,4)->text(),ui->lineEdit->text());
    endorse.show();
    endorse.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
     /*
    switch(QMessageBox::question(NULL, "question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {

     case QMessageBox::Yes:
        QList<QTableWidgetSelectionRange>ranges=ui->tableWidget->selectedRanges();
        int count = ranges.count();
        if(count!=0)
        {
             /*
            int row=ranges.at(0).topRow();
            QString busid = ui->tableWidget_4->item(row, 0)->text();
            QString date = ui->tableWidget_4->item(row, 1)->text();
            QString startplace = ui->tableWidget_4->item(row, 2)->text();
            QString starttime = ui->tableWidget_4->item(row, 3)->text();
            QString finishplace = ui->tableWidget_4->item(row, 4)->text();
            QString finishtime = ui->tableWidget_4->item(row, 5)->text();
            QString seatnumber = ui->tableWidget_4->item(row, 6)->text();
            QString number = ui->lineEdit->text();
            QByteArray ba = (busid + ";" + date + ";" + startplace + ";" + starttime + ";" + finishplace + ";" +
                             finishtime + ";" + seatnumber + ";" + number).toLatin1();
            char st[72];
            client.sendmsg("19",ba.data()", st, 72, 2);
            QMessageBox::about(NULL, "退票成功", "您已成功退票");
                    if(st[0] == 'Y')
            {
                this->close();
            }
        break;
    case QMessageBox::No:
        break;
        */
}

void MainWindow::on_pushButton_6_clicked()
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

void MainWindow::on_pushButton_2_clicked()
{
    /*
    QString number = ui->lineEdit->text();
    QByteArray ba = (number).toLatin1();
    char st[1000];
    client.sendmsg("21",ba.data(), st, 10, 1000);
    char *a;
    QTableWidget *table = ui->tableWidget;
    a = strtok(st,"\");
    table->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
    for(int i = 1; i < 9; i++)
    {
        table->setItem(0,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
    }
    for(int m = 1; a = strtok(NULL,"\"); m++)
    {
        table->setItem(m,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
        for(int i = 1; i < 9; i++)
        {
            table->setItem(m,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
        }
}
