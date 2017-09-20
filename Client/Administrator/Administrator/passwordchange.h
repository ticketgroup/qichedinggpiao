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
    void setId(QString);
    ~Passwordchange();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Passwordchange *ui;
    QString id;
};

#endif // PASSWORDCHANGE_H
