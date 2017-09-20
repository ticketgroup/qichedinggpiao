#include "telephonechange.h"
#include "ui_telephonechange.h"
#include "variables.h"
#include <QMessageBox>

Telephonechange::Telephonechange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Telephonechange)
{
    ui->setupUi(this);

    setFixedSize(this->width(), this->height());
}

Telephonechange::~Telephonechange()
{
    delete ui;
}

void Telephonechange::on_pushButton_clicked()
{
    QString oldp = ui->LineEdit->text();
    QString newp = ui->LineEdit_2->text();
    QRegExp rp("^\\w{11}$");
    if(rp.indexIn(oldp) != -1 && rp.indexIn(newp) != -1)
    {
        QByteArray ba = (oldp + ";" + newp).toLatin1();
        char st[2];
        client.sendmsg("16",ba.data(), st,24, 2);
        if(st)
        {
            if(st[0] == 'Y')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("修改成功"), QString::fromLocal8Bit("修改成功！"));
                this->close();
            }
            else if(st[0] == 'N')
            {
                QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("您输入的原手机号错误！"));
            }
        }
        else
             QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
    }
    else
    {
        QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("您输入的手机号错误！"));
    }
}
