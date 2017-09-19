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

void Buyticket::on_pushButton_clicked()
{
    QMessageBox::about(NULL, "About", "About this application");
    this->close();
}
