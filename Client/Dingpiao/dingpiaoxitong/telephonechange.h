#ifndef TELEPHONECHANGE_H
#define TELEPHONECHANGE_H

#include <QDialog>

namespace Ui {
class Telephonechange;
}

class Telephonechange : public QDialog
{
    Q_OBJECT

public:
    explicit Telephonechange(QWidget *parent = 0);
    ~Telephonechange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Telephonechange *ui;
};

#endif // TELEPHONECHANGE_H
