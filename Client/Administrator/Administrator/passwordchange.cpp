#include "passwordchange.h"
#include "ui_passwordchange.h"

Passwordchange::Passwordchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passwordchange),
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Passwordchange::setId(QString i)
{
    id = i;
}

Passwordchange::~Passwordchange()
{
    delete ui;
}

void Passwordchange::on_pushButton_clicked()
{
    QString password = ui->LineEdit->text();
    QRegExp rp("^\\w{1,40}$");
    if(rp.indexIn(password) != -1)
    {
       switch(QMessageBox::question(NULL, QString::fromLocal8Bit("确认修改"), QString::fromLocal8Bit("确认要修改该售票员吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
       {
       case QMessageBox::Yes:

           QByteArray ba = (id + ";" + password).toLatin1();
           char st[2];
           client.sendmsg("26",ba.data(), st, 53, 2);
           if(st)
           {
               if(st[0] == 'Y')
                {
                   QMessageBox::about(NULL, QString::fromLocal8Bit("修改成功"), QString::fromLocal8Bit("密码修改成功！"));
                   this->close();
                }
                else if(st[0]  == 'N')//?????????????????????????????????????
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("登录失败"), QString::fromLocal8Bit("密码错误！"));
                }
            }
            else
                 QMessageBox::about(NULL, QString::fromLocal8Bit("登录失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
        }
           break;
       case QMessageBox::No:
           break;
       }
    else
       QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("密码中含有非法字符！"));

}

void Passwordchange::on_pushButton_2_clicked()
{
    this->close();
}
