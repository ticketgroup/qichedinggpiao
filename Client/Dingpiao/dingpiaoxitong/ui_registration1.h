/********************************************************************************
** Form generated from reading UI file 'registration1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION1_H
#define UI_REGISTRATION1_H

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

class Ui_Registration1
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

    void setupUi(QDialog *Registration1)
    {
        if (Registration1->objectName().isEmpty())
            Registration1->setObjectName(QStringLiteral("Registration1"));
        Registration1->resize(400, 300);
        label = new QLabel(Registration1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 101, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        formLayoutWidget = new QWidget(Registration1);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 110, 281, 61));
        QFont font1;
        font1.setPointSize(13);
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

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));
        LineEdit_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

        pushButton = new QPushButton(Registration1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 230, 75, 23));
        pushButton_2 = new QPushButton(Registration1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 230, 75, 23));

        retranslateUi(Registration1);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Registration1, SLOT(close()));

        QMetaObject::connectSlotsByName(Registration1);
    } // setupUi

    void retranslateUi(QDialog *Registration1)
    {
        Registration1->setWindowTitle(QApplication::translate("Registration1", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Registration1", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        Label->setText(QApplication::translate("Registration1", "\346\211\213\346\234\272\345\217\267\357\274\210\347\224\250\346\210\267\345\220\215\357\274\211\357\274\232", Q_NULLPTR));
        Label_2->setText(QApplication::translate("Registration1", "\350\256\276\347\275\256\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Registration1", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Registration1", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Registration1: public Ui_Registration1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION1_H
