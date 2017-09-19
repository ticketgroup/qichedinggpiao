#ifndef REGISTRATION1_H
#define REGISTRATION1_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Registration1;
}

class Registration1 : public QDialog
{
    Q_OBJECT

public:
    explicit Registration1(QWidget *parent = 0);
    ~Registration1();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Registration1 *ui;
};

#endif // REGISTRATION1_H
