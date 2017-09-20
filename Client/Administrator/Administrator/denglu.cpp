#include "denglu.h"
#include "ui_denglu.h"
#include "variables.h"
#include <QMessageBox>

Denglu::Denglu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Denglu)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Denglu::~Denglu()
{
    delete ui;
}

void Denglu::on_pushButton_3_clicked()
{
    QString id = ui->nLineEdit_2->text();
    QString password = ui->pLineEdit_2->text();
    QRegExp rx("^\\d{5}$");
    QRegExp rp("^\\w{1,40}$");
    if(rx.indexIn(id) != -1)
    {
        if(rp.indexIn(password) != -1)
        {
            QByteArray ba = (id + ";" + password).toLatin1();
            char st[2];
            client.sendmsg("22",ba.data(), st, 47, 2);
            if(st)
            {
               if(st[0] == 'Y')
                {
                    accept();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("登录失败"),QString::fromLocal8Bit( "登录失败！"));
                }
            }
            else
                 QMessageBox::about(NULL, QString::fromLocal8Bit("登录失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
        }
        else
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("登录失败"), QString::fromLocal8Bit("密码中含有非法字符！"));
        }
    }
    else
    {
        QMessageBox::about(NULL, QString::fromLocal8Bit("登录失败"), QString::fromLocal8Bit("您输入的用户名有误！"));
    }
}
