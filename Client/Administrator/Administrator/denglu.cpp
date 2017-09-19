#include "denglu.h"
#include "ui_denglu.h"

Denglu::Denglu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Denglu)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Denglu::~Denglu()
{
    delete ui;
}

void Denglu::on_pushButton_3_clicked()
{
    accept();
}
