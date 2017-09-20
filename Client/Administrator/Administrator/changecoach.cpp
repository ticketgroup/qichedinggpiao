#include "changecoach.h"
#include "ui_changecoach.h"

Changecoach::Changecoach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Changecoach)
{
    ui->setupUi(this);
    QTableWidget *table = ui->tableWidget_2;
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    setFixedSize(this->width(), this->height());
}

Changecoach::~Changecoach()
{
    delete ui;
}

Passwordchange::setId(QString i)
{
    id = i;
}


void Changecoach::on_pushButton_clicked()
{
    switch(QMessageBox::question(NULL, QString::fromLocal8Bit("确认修改"), QString::fromLocal8Bit("确认修改这条车辆信息吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        char st[2];
        QString str = id + ";";
        QTableWidget *table = ui->tableWidget_2;
        int i = 0;
        for(; table->item(i,0)!=0; i++)
        {
            str += (table->item(i,0)->text() + ";");
        }
        if(i < 8 || (i - 1)%3 != 0 )
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"),  QString::fromLocal8Bit("请填充好汽车的基本信息！"));
            break;
        }
        else
        {
            client.sendmsg("28", str, st, 346, 2);
            if(st[0] == 'Y')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("修改成功"), QString::fromLocal8Bit("修改成功！"));
                this->close();
            }
            else if(st[0] == 'N')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("修改失败！请重新尝试。"));
            }
        }
        break;
    case QMessageBox::No:
        break;
    }
}

void Changecoach::on_pushButton_2_clicked()
{
    this->close();
}
