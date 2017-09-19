#include "addconductor.h"
#include "ui_addconductor.h"

Addconductor::Addconductor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addconductor)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Addconductor::~Addconductor()
{
    delete ui;
}

void Addconductor::on_pushButton_clicked()
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
