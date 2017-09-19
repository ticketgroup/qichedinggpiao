#include "passwordchange.h"
#include "ui_passwordchange.h"
#include "variables.h"
#include <QMessageBox>

Passwordchange::Passwordchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passwordchange)
{
    ui->setupUi(this);
     setFixedSize(this->width(), this->height());
}

Passwordchange::~Passwordchange()
{
    delete ui;
}

void Passwordchange::on_pushButton_clicked()
{
    QString oldp = ui->LineEdit->text();
    QString newp = ui->LineEdit_2->text();
    QRegExp rp("^\\w{1,40}$");
    if(rp.indexIn(oldp) != -1 && rp.indexIn(newp) != -1)
    {
        QByteArray ba = (oldp + ";" + newp).toLatin1();
        char st[2];
        client.sendmsg("18",ba.data(), st, 82, 2);
        if(st)
        {
            if(st[0] == 'Y')
            {
                QMessageBox::about(NULL, "修改成功", "修改成功！");
                this->close();
            }
            else if(st[0] == 'N')
            {
                QMessageBox::about(NULL, "修改失败", "您输入的密码错误！");
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
