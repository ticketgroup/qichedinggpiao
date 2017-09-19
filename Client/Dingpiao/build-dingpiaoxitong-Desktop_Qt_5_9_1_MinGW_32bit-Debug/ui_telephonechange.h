/********************************************************************************
** Form generated from reading UI file 'telephonechange.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEPHONECHANGE_H
#define UI_TELEPHONECHANGE_H

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

class Ui_Telephonechange
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QLabel *Label_2;
    QLineEdit *LineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Telephonechange)
    {
        if (Telephonechange->objectName().isEmpty())
            Telephonechange->setObjectName(QStringLiteral("Telephonechange"));
        Telephonechange->resize(400, 300);
        label = new QLabel(Telephonechange);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 40, 401, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(Telephonechange);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 120, 221, 91));
        QFont font1;
        font1.setPointSize(12);
        formLayoutWidget->setFont(font1);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName(QStringLiteral("Label"));
        Label->setFont(font1);
        Label->setMargin(0);
        Label->setIndent(-1);

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        LineEdit = new QLineEdit(formLayoutWidget);
        LineEdit->setObjectName(QStringLiteral("LineEdit"));
        LineEdit->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setFont(font1);
        Label_2->setScaledContents(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));
        LineEdit_2->setFont(font1);
        LineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

        pushButton = new QPushButton(Telephonechange);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 250, 75, 23));
        pushButton_2 = new QPushButton(Telephonechange);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 250, 75, 23));

        retranslateUi(Telephonechange);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Telephonechange, SLOT(close()));

        QMetaObject::connectSlotsByName(Telephonechange);
    } // setupUi

    void retranslateUi(QDialog *Telephonechange)
    {
        Telephonechange->setWindowTitle(QApplication::translate("Telephonechange", "\344\277\256\346\224\271\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("Telephonechange", "\344\277\256\346\224\271\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        Label->setText(QApplication::translate("Telephonechange", "\345\216\237\346\211\213\346\234\272\345\217\267:", Q_NULLPTR));
        Label_2->setText(QApplication::translate("Telephonechange", "\346\226\260\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Telephonechange", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Telephonechange", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Telephonechange: public Ui_Telephonechange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEPHONECHANGE_H
