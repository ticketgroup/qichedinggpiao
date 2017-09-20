#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget *table = ui->tableWidget;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table = ui->tableWidget_2;
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    QList<QTableWidgetSelectionRange>ranges=ui->tableWidget->selectedRanges();
    int count = ranges.count();
    if(count!=0)
    {
        int row=ranges.at(0).topRow();
        passwordchange.setId(ui->tableWidget->item(row, 0)->text());
        passwordchange.show();
        passwordchange.exec();
    }
    else
    {

        QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("请选择售票员！"));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    switch(QMessageBox::question(NULL, QString::fromLocal8Bit("删除确定"), QString::fromLocal8Bit("您确定要删除这个售票员吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        QList<QTableWidgetSelectionRange>ranges=ui->tableWidget->selectedRanges();
        int count = ranges.count();
        if(count!=0)
        {
            int row=ranges.at(0).topRow();
            QByteArray ba = ui->tableWidget->item(row, 0)->text().toLatin1();
            char st[2];
            client.sendmsg("27",ba.data(), st, 10, 2);
            if(st)
            {
               if(st[0] == 'Y')
                {
                   QMessageBox::about(NULL, QString::fromLocal8Bit("删除成功"), QString::fromLocal8Bit("删除成功！"));
                   this->close();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("删除失败"),QString::fromLocal8Bit( "删除失败！"));
                }
            }
            else
                 QMessageBox::about(NULL, QString::fromLocal8Bit("删除失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
        }
        else
        {

            QMessageBox::about(NULL, QString::fromLocal8Bit("删除失败"), QString::fromLocal8Bit("请选择售票员！"));
        }

        break;
    case QMessageBox::No:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    addconductor.show();
    addconductor.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    switch(QMessageBox::question(NULL, QString::fromLocal8Bit("删除确定"), QString::fromLocal8Bit("您确定要删除次车次吗？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        QList<QTableWidgetSelectionRange>ranges=ui->tableWidget_2->selectedRanges();
        int count = ranges.count();
        if(count!=0)
        {
            int row=ranges.at(0).topRow();
            QByteArray ba = ui->tableWidget_2->item(row, 0)->text().toLatin1();
            char st[2];
            client.sendmsg("29",ba.data(), st, 10, 2);
            if(st)
            {
               if(st[0] == 'Y')
                {
                   QMessageBox::about(NULL, QString::fromLocal8Bit("删除成功"), QString::fromLocal8Bit("删除成功！"));
                   this->close();
                }
                else if(st[0] == 'N')
                {
                    QMessageBox::about(NULL, QString::fromLocal8Bit("删除失败"),QString::fromLocal8Bit( "删除失败！"));
                }
            }
            else
                 QMessageBox::about(NULL, QString::fromLocal8Bit("删除失败"), QString::fromLocal8Bit("服务器连接失败！请重新登录！"));
        }
        else
        {

            QMessageBox::about(NULL, QString::fromLocal8Bit("删除失败"), QString::fromLocal8Bit("请选择车次！"));
        }

        break;
    case QMessageBox::No:
        break;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    addcoach.show();
    addcoach.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    QList<QTableWidgetSelectionRange>ranges=ui->tableWidget_2->selectedRanges();
    int count = ranges.count();
    if(count!=0)
    {
        int row=ranges.at(0).topRow();
        changecoach.setId(ui->tableWidget_2->item(row, 0)->text());
        changecoach.show();
        changecoach.exec();
    }
    else
    {

        QMessageBox::about(NULL, QString::fromLocal8Bit("修改失败"), QString::fromLocal8Bit("请选择车次！"));
    }
}
