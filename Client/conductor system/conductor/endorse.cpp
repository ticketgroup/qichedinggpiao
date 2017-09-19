#include "endorse.h"
#include "ui_endorse.h"
#include <QMessageBox>

Endorse::Endorse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Endorse)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setMinimumDate(QDate::currentDate().addDays(0));
    ui->dateEdit->setMaximumDate(QDate::currentDate().addDays(5));
    QTableWidget *table = ui->tableWidget;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setFixedSize(this->width(), this->height());
}

Endorse::~Endorse()
{
    delete ui;
}

void Endorse::on_pushButton_clicked()
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
