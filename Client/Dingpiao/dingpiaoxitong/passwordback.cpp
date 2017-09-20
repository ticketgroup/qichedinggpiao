#include "variables.h"
#include "passwordback.h"
#include "ui_passwordback.h"

Passwordback::Passwordback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passwordback)
{
    ui->setupUi(this);
     setFixedSize(this->width(), this->height());
}

Passwordback::~Passwordback()
{
    delete ui;
}

void Passwordback::on_pushButton_clicked()
{
    QString id = ui->LineEdit_2->text();
    QString num = ui->LineEdit_3->text();
    QRegExp rx("^\\d{9}$");
    QRegExp ru("^\\d{2}[A-Za-z0-9]\\d{5}$");
    if(rx.indexIn(id) != -1)
    {
        if(ru.indexIn(num) != -1)
        {
            QByteArray ba = (id + ";" + num).toLatin1();
            char st[2];
            client.sendmsg("10",ba.data(), st, 19, 2);
            if(st)
            {
                if(st[0] == 'Y')
                {
                    this->hide();
                    passwordback1.show();
                    passwordback1.exec();
                    this->show();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("验证失败"), QString::fromLocal8Bit("您输入的一卡通或学号不正确！"));
                }
            }
            else
            {
                 QMessageBox::about(NULL, QString::fromLocal8Bit("验证失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
            }
        }
        else
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("您输入的学号有误！"));
        }
    }
    else
    {
        QMessageBox::about(NULL, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("您输入的一卡通有误！"));
    }
}



