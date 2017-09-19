/********************************************************************************
** Form generated from reading UI file 'passwordchange.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDCHANGE_H
#define UI_PASSWORDCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passwordchange
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Passwordchange)
    {
        if (Passwordchange->objectName().isEmpty())
            Passwordchange->setObjectName(QStringLiteral("Passwordchange"));
        Passwordchange->resize(261, 186);
        formLayoutWidget = new QWidget(Passwordchange);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 70, 160, 31));
        QFont font;
        font.setPointSize(13);
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName(QStringLiteral("Label"));
        Label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        LineEdit = new QLineEdit(formLayoutWidget);
        LineEdit->setObjectName(QStringLiteral("LineEdit"));
        LineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit);

        pushButton = new QPushButton(Passwordchange);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 130, 75, 23));
        pushButton_2 = new QPushButton(Passwordchange);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 130, 75, 23));
        label = new QLabel(Passwordchange);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 91, 21));
        QFont font1;
        font1.setPointSize(17);
        label->setFont(font1);

        retranslateUi(Passwordchange);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Passwordchange, SLOT(close()));

        QMetaObject::connectSlotsByName(Passwordchange);
    } // setupUi

    void retranslateUi(QDialog *Passwordchange)
    {
        Passwordchange->setWindowTitle(QApplication::translate("Passwordchange", "\345\257\206\347\240\201\344\277\256\346\224\271", Q_NULLPTR));
        Label->setText(QApplication::translate("Passwordchange", "\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Passwordchange", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Passwordchange", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("Passwordchange", "\345\257\206\347\240\201\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Passwordchange: public Ui_Passwordchange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCHANGE_H
