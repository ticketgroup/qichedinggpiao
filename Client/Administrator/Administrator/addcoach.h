#ifndef ADDCOACH_H
#define ADDCOACH_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Addcoach;
}

class Addcoach : public QDialog
{
    Q_OBJECT

public:
    explicit Addcoach(QWidget *parent = 0);
    ~Addcoach();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Addcoach *ui;
};

#endif // ADDCOACH_H
