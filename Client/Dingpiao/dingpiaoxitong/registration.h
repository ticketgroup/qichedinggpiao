#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "registration1.h"

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();



private slots:
    void on_pushButton_clicked();

private:
    Ui::Registration *ui;
    Registration1 registration1;
};

#endif // REGISTRATION_H
