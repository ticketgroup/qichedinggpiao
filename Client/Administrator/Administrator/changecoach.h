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
    void setId(QString);
    ~Changecoach();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Changecoach *ui;
    QString id;
};

#endif // CHANGECOACH_H
