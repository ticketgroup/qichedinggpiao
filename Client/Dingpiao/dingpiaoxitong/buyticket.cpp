#include "buyticket.h"
#include "ui_buyticket.h"

Buyticket::Buyticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buyticket)
{
    ui->setupUi(this);
     setFixedSize(this->width(), this->height());
}

Buyticket::~Buyticket()
{
    delete ui;
}

void Buyticket::getmsg()
{
    /*
    char st[47];
    client.sendmsg("32","0", st, 2, 47);
    (QTextLabel*) l[5] = {ui->label_5,ui->label_7,ui->label_8,ui->label_9,ui->label_10};
    l[0]->setText(QString::fromLocal8Bit(strtok(st,";")));
    for(int i = 1; i < 5; i++)
    {
        l[i]->setText(QString::fromLocal8Bit(strtok(NULL, ";")));
    }*/
}

void Buyticket::on_pushButton_clicked()
{
    QMessageBox::about(NULL, "About", "About this application");
    this->close();
}
