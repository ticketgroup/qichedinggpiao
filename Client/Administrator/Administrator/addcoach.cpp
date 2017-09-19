#include "addcoach.h"
#include "ui_addcoach.h"

Addcoach::Addcoach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addcoach)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Addcoach::~Addcoach()
{
    delete ui;
}

void Addcoach::on_pushButton_clicked()
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
