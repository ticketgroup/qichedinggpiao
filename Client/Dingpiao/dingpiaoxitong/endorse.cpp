#include "endorse.h"
#include "ui_endorse.h"
#include "variables.h"
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
    ui->label_5->setText(s);
    ui->label_6->setText(e);
    ui->label_8->setText(m);
}


void Endorse::setVar(QString i,QString s,QString d)
{
    this->id = i;
    this->seatnum = s;
    this->date = d;
}

void Endorse::on_pushButton_clicked()
{

    switch(QMessageBox::question(NULL, QString::fromLocal8Bit("改签确认"), QString::fromLocal8Bit("您确定要改签吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
    {
        QList<QTableWidgetSelectionRange>ranges=ui->tableWidget->selectedRanges();
        int count = ranges.count();
        if(count!=0)
        {
            int row=ranges.at(0).topRow();
            QString busid = ui->tableWidget->item(row, 0)->text();
            QString date = ui->dateEdit->text();
            QString startplace = ui->label_5->text();
            QString endplace = ui->label_6->text();
            QString pas = ui->label_8->text();
            QByteArray ba = (this->id + ";" + this->seatnum + ";" + startplace + ";" + endplace + ";" +  date +";" + pas + ";" +  busid + ";" + date).toLatin1();
            char st[2];
            client.sendmsg("15",ba.data(), st, 100, 2);
            if(st[0] == 'Y')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("改签成功"), QString::fromLocal8Bit("您已成功改签"));
                this->close();
            }
        }
        break;
    }
    case QMessageBox::No:
        break;
    }
}

void Endorse::on_pushButton_3_clicked()
{
   QString date = ui->dateEdit->text();
   QString startplace = ui->label_5->text();
   QString finishplace = ui->label_6->text();

   QByteArray ba = (date + ";" + startplace + ";" + finishplace).toLatin1();
   char st[1000];
   client.sendmsg("4",ba.data(), st, 50, 1000);
   if(st[0] != 'N')
   {

       char *a;

       QTableWidget *table = ui->tableWidget;
       table->clearContents();
       a = strtok(st,"$");
       table->setItem(0,0,new QTableWidgetItem(QString::fromLocal8Bit(strtok(a,";"))));
       for(int i = 1; i < 7; i++)
       {
           table->setItem(0,i,new QTableWidgetItem(QString::fromLocal8Bit(strtok(NULL,";"))));
       }
       for(int m = 1; a = strtok(NULL,"$"); m++)
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
       QMessageBox::about(NULL, QString::fromLocal8Bit("搜索失败"), QString::fromLocal8Bit("无相应车辆！"));
   }
}
