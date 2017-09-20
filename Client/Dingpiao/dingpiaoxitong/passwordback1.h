#ifndef PASSWORDBACK1_H
#define PASSWORDBACK1_H

#include <QDialog>
#include "QMessageBox"

namespace Ui {
class Passwordback1;
}

class Passwordback1 : public QDialog
{
    Q_OBJECT

public:
    explicit Passwordback1(QWidget *parent = 0);
    ~Passwordback1();



private slots:
    void on_pushButton_clicked();

private:
    Ui::Passwordback1 *ui;
};

#endif // PASSWORDBACK1_H
