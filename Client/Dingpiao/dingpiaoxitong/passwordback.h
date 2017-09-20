#ifndef PASSWORDBACK_H
#define PASSWORDBACK_H

#include <QDialog>
#include "passwordback1.h"


namespace Ui {
class Passwordback;
}

class Passwordback : public QDialog
{
    Q_OBJECT

public:
    explicit Passwordback(QWidget *parent = 0);
    ~Passwordback();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Passwordback *ui;
    Passwordback1 passwordback1;

};

#endif // PASSWORDBACK_H
