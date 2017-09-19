#ifndef DENGLU_H
#define DENGLU_H

#include <QDialog>
#include "passwordback.h"
#include "registration.h"
#include "mainwindow.h"

namespace Ui {
class denglu;
}

class denglu : public QDialog
{
    Q_OBJECT

public:
    explicit denglu(QWidget *parent = 0);
    ~denglu();

private slots:
    void on_pushButton_3_clicked();

    void on_showChildButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::denglu *ui;
    Passwordback passwordback;
    Registration registration;
};

#endif // DENGLU_H
