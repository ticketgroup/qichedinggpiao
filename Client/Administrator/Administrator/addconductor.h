#ifndef ADDCONDUCTOR_H
#define ADDCONDUCTOR_H

#include <QDialog>
#include "QMessageBox"

namespace Ui {
class Addconductor;
}

class Addconductor : public QDialog
{
    Q_OBJECT

public:
    explicit Addconductor(QWidget *parent = 0);
    ~Addconductor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Addconductor *ui;
};

#endif // ADDCONDUCTOR_H
