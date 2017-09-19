#ifndef PASSWORDCHANGE_H
#define PASSWORDCHANGE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Passwordchange;
}

class Passwordchange : public QDialog
{
    Q_OBJECT

public:
    explicit Passwordchange(QWidget *parent = 0);
    ~Passwordchange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Passwordchange *ui;
};

#endif // PASSWORDCHANGE_H
