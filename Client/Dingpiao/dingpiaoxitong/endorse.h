#ifndef ENDORSE_H
#define ENDORSE_H

#include <QDialog>

namespace Ui {
class Endorse;
}

class Endorse : public QDialog
{
    Q_OBJECT

public:
    explicit Endorse(QWidget *parent = 0);
    ~Endorse();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Endorse *ui;
};

#endif // ENDORSE_H
