#include "addcoach.h"
#include "ui_addcoach.h"

Addcoach::Addcoach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addcoach)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Addcoach::~Addcoach()
{
    delete ui;
}

void Addcoach::on_pushButton_clicked()
{

    switch(QMessageBox::question(NULL, QString::fromLocal8Bit("确认增加"), QString::fromLocal8Bit("确认增加这条车辆信息吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        char st[2];
        QString str = "";
        QTableWidget *table = ui->tableWidget_2;
        int i = 0;
        for(; table->item(i,0)!=0; i++)
        {
            str += (table->item(i,0)->text() + ";");
        }
        if(i < 8 || (i - 1)%3 != 0 )
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("增加失败"),  QString::fromLocal8Bit("请填充好汽车的基本信息！"));
            break;
        }
        else
        {
            client.sendmsg("28", str, st, 335, 2);
            if(st[0] == 'Y')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("增加成功"), QString::fromLocal8Bit("增加成功！"));
                this->close();
            }
            else if(st[0] == 'N')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("增加失败"), QString::fromLocal8Bit("增加失败！请重新尝试。"));
            }
        }
        break;
    case QMessageBox::No:
        break;
    }
}

void Addcoach::on_pushButton_2_clicked()
{
    this->close();
}
