#include "registration1.h"
#include "ui_registration1.h"
#include "variables.h"

Registration1::Registration1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration1)
{
    ui->setupUi(this);

    setFixedSize(this->width(), this->height());
}

Registration1::~Registration1()
{
    delete ui;
}


void Registration1::on_pushButton_clicked()
{
    QString phone = ui->LineEdit->text();
    QString password = ui->LineEdit_2->text();
    QRegExp rx("^\\d{11}$");
    QRegExp rp("^\\w{1,40}$");
    if(rx.indexIn(phone) != -1)
    {
        if(rp.indexIn(password) != -1)
        {
            QByteArray ba = (phone + ";" + password).toLatin1();
            char st[2];
            client.sendmsg("8",ba.data(), st, 53, 2);
            if(st)
            {
                if(st[0] == 'Y')
                {
                    QMessageBox::about(NULL, "注册成功", "注册成功！");
                    this->close();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, "修改失败", "您输入的手机号有误！");
                }
            }
            else
                 QMessageBox::about(NULL, "修改失败", "服务器连接失败！请重新登录！");
        }
        else
        {
            QMessageBox::about(NULL, "修改失败", "密码中含有非法字符！");
        }
    }
    else
    {
        QMessageBox::about(NULL, "修改失败", "您输入的手机号有误！");
    }
}
