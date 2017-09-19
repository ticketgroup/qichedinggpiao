/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

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

class Ui_Registration
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QLineEdit *LineEdit_2;
    QLabel *Label_3;
    QLineEdit *LineEdit_3;
    QLabel *Label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QStringLiteral("Registration"));
        Registration->resize(400, 300);
        label = new QLabel(Registration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 111, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        formLayoutWidget = new QWidget(Registration);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(80, 90, 221, 101));
        QFont font1;
        font1.setPointSize(12);
        formLayoutWidget->setFont(font1);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName(QStringLiteral("Label"));
        Label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        LineEdit = new QLineEdit(formLayoutWidget);
        LineEdit->setObjectName(QStringLiteral("LineEdit"));
        LineEdit->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));
        LineEdit_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

        Label_3 = new QLabel(formLayoutWidget);
        Label_3->setObjectName(QStringLiteral("Label_3"));
        Label_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, Label_3);

        LineEdit_3 = new QLineEdit(formLayoutWidget);
        LineEdit_3->setObjectName(QStringLiteral("LineEdit_3"));
        LineEdit_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, LineEdit_3);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        pushButton = new QPushButton(Registration);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 240, 75, 23));
        pushButton_2 = new QPushButton(Registration);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 240, 75, 23));

        retranslateUi(Registration);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Registration, SLOT(close()));

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Registration", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        Label->setText(QApplication::translate("Registration", "\345\247\223\345\220\215:", Q_NULLPTR));
        Label_3->setText(QApplication::translate("Registration", "\345\255\246\345\217\267:", Q_NULLPTR));
        Label_2->setText(QApplication::translate("Registration", "\344\270\200\345\215\241\351\200\232\345\217\267:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Registration", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Registration", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
