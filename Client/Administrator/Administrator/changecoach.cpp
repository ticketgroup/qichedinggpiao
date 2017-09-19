#include "changecoach.h"
#include "ui_changecoach.h"

Changecoach::Changecoach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Changecoach)
{
    ui->setupUi(this);
    QTableWidget *table = ui->tableWidget_2;
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    setFixedSize(this->width(), this->height());

}

Changecoach::~Changecoach()
{
    delete ui;
}

void Changecoach::on_pushButton_clicked()
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
