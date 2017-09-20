#include "passwordback1.h"
#include "ui_passwordback1.h"
#include "variables.h"

Passwordback1::Passwordback1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passwordback1)
{
    ui->setupUi(this);
     setFixedSize(this->width(), this->height());
}

Passwordback1::~Passwordback1()
{
    delete ui;
}




void Passwordback1::on_pushButton_clicked()
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
            client.sendmsg("11",ba.data(), st, 53, 2);
            if(st)
            {
                if(st[0] == 'Y')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("�޸ĳɹ�"), QString::fromLocal8Bit("�޸ĳɹ��������޸ĺ�������¼��"));
                    this->close();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("�޸�ʧ��"), QString::fromLocal8Bit("��������ֻ�������"));
                }
            }
            else
                 QMessageBox::about(NULL, QString::fromLocal8Bit("�޸�ʧ��"), QString::fromLocal8Bit("����������ʧ�ܣ������µ�¼��"));
        }
        else
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("�޸�ʧ��"), QString::fromLocal8Bit("�����к��зǷ��ַ���"));
        }
    }
    else
    {
        QMessageBox::about(NULL, QString::fromLocal8Bit("�޸�ʧ��"), QString::fromLocal8Bit("��������ֻ�������"));
    }
}
