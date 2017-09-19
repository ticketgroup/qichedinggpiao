#ifndef BUYTICKET_H
#define BUYTICKET_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Buyticket;
}

class Buyticket : public QDialog
{
    Q_OBJECT

public:
    explicit Buyticket(QWidget *parent = 0);
    ~Buyticket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Buyticket *ui;
};

#endif // BUYTICKET_H
