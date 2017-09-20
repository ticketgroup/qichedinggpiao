#include "addconductor.h"
#include "ui_addconductor.h"

Addconductor::Addconductor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addconductor)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Addconductor::~Addconductor()
{
    delete ui;
}

void Addconductor::on_pushButton_clicked()
{
    QString id = ui->nLineEdit_2->text();
    QString password = ui->pLineEdit_2->text();
    QRegExp rx("^\\d{11}$");
    QRegExp rp("^\\w{1,40}$");
    if(rx.indexIn(id) != -1)
    {
        if(rp.indexIn(password) != -1)
        {
            switch(QMessageBox::question(NULL, QString::fromLocal8Bit("确认增加"), QString::fromLocal8Bit("确认要增加该售票员吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
            {
            case QMessageBox::Yes:
                QByteArray ba = (id + ";" + password).toLatin1();
                char st[2];
                client.sendmsg("25",ba.data(), st, 53, 2);
                if(st)
                {
                   if(st[0] == 'Y')
                    {
                       QMessageBox::about(NULL, QString::fromLocal8Bit("添加成功"), QString::fromLocal8Bit("添加成功！"));
                       this->close();
                    }
                    else if(st[0] == 'N')
                    {
                        QMessageBox::about(NULL, QString::fromLocal8Bit("添加失败"),QString::fromLocal8Bit( "添加失败！"));
                    }
                }
                else
                     QMessageBox::about(NULL, QString::fromLocal8Bit("添加失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
                break;
            case QMessageBox::No:
                break;
            }
        }
        else
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("增加失败"), QString::fromLocal8Bit("密码中含有非法字符！"));
        }
    }
    else
    {
        QMessageBox::about(NULL, QString::fromLocal8Bit("增加失败"), QString::fromLocal8Bit("您输入的用户名有误！"));
    }
}

void Addconductor::on_pushButton_2_clicked()
{
    this->close();
}
