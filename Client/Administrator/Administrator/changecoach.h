#ifndef CHANGECOACH_H
#define CHANGECOACH_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Changecoach;
}

class Changecoach : public QDialog
{
    Q_OBJECT

public:
    explicit Changecoach(QWidget *parent = 0);
    ~Changecoach();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Changecoach *ui;
};

#endif // CHANGECOACH_H
