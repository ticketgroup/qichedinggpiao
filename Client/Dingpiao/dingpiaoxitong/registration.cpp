#include "registration.h"
#include "ui_registration.h"
#include "variables.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
     setFixedSize(this->width(), this->height());
}

Registration::~Registration()
{
    delete ui;
}


void Registration::on_pushButton_clicked()
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
            client.sendmsg("7",ba.data(), st, 19, 2);
            if(st)
            {
                if(st[0] == 'Y')
                {
                    this->hide();
                    registration1.show();
                    registration1.exec();
                    this->show();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("��֤ʧ��"), QString::fromLocal8Bit("�������һ��ͨ��ѧ�Ų���ȷ��"));
                }
            }
            else
            {
                 QMessageBox::about(NULL, QString::fromLocal8Bit("��֤ʧ��"), QString::fromLocal8Bit("����������ʧ�ܣ������µ�¼��"));
            }
        }
        else
        {
            QMessageBox::about(NULL, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������ѧ������"));
        }
    }
    else
    {
        QMessageBox::about(NULL,QString::fromLocal8Bit( "����"), QString::fromLocal8Bit("�������һ��ͨ����"));
    }
}
