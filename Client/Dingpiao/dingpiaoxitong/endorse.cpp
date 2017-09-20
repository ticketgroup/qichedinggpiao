#include "endorse.h"
#include "ui_endorse.h"
#include <QMessageBox>

Endorse::Endorse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Endorse)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setMinimumDate(QDate::currentDate().addDays(0));
    ui->dateEdit->setMaximumDate(QDate::currentDate().addDays(5));
    QTableWidget *table = ui->tableWidget;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
     setFixedSize(this->width(), this->height());
}

Endorse::~Endorse()
{
    delete ui;
}

//bool Endorse::close()
//{
//    QMessageBox::about(NULL, "About", "About this application");
//    this->close();
//}

void Endorse::setLabel(QString s, QString e,QString m)
{
//    ui->label_5->setText(s);
//    ui->label_6->setText(e);
//    ui->label_8->setText(m);

}

void Endorse::on_pushButton_clicked()
{
    /*
    switch(QMessageBox::question(NULL, "question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        QList<QTableWidgetSelectionRange>ranges=ui->tableWidget->selectedRanges();
        int count = ranges.count();
        if(count!=0)
        {
            int row=ranges.at(0).topRow();
            QString busid = ui->tableWidget->item(row, 0)->text();
            QString date = ui->dateEdit->text();
            QByteArray ba = (busid + ";" + date).toLatin1();
            char st[10];
            client.sendmsg("15",ba.data()", st, 11, 2);
            QMessageBox::about(NULL, "改签成功", "您已成功改签");
                    if(st[0] == 'Y')
            {
                this->close();
            }
        break;
    case QMessageBox::No:
        break;
    }*/
}

void Endorse::on_pushButton_3_clicked()
{
    /*
   QString date = ui->dateEdit->text();
   QString startplace = ui->label_5->text();
   QString finishplace = ui->label_6->text();
   QString number = ui->label_8->text();

   QByteArray ba = (date + ";" + startplace + ";" + finishplace + ";" + number).toLatin1();
   char st[1000];
   client.sendmsg("4",ba.data(), st, 50, 1000);
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
