#include "passwordchange.h"
#include "ui_passwordchange.h"

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
    switch(QMessageBox::question(NULL, "question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        QMessageBox::about(NULL, "About", "About this application");
        this->close();
        break;
    case QMessageBox::No:
        break;
    }
}
