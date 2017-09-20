/********************************************************************************
** Form generated from reading UI file 'addconductor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONDUCTOR_H
#define UI_ADDCONDUCTOR_H

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

class Ui_Addconductor
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QLabel *Label_2;
    QLineEdit *LineEdit_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Addconductor)
    {
        if (Addconductor->objectName().isEmpty())
            Addconductor->setObjectName(QStringLiteral("Addconductor"));
        Addconductor->resize(332, 210);
        formLayoutWidget = new QWidget(Addconductor);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 80, 191, 61));
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

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));
        LineEdit_2->setFont(font);
        LineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

        label = new QLabel(Addconductor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 111, 31));
        QFont font1;
        font1.setPointSize(17);
        label->setFont(font1);
        pushButton = new QPushButton(Addconductor);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 160, 75, 23));
        pushButton_2 = new QPushButton(Addconductor);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 160, 75, 23));

        retranslateUi(Addconductor);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Addconductor, SLOT(close()));

        QMetaObject::connectSlotsByName(Addconductor);
    } // setupUi

    void retranslateUi(QDialog *Addconductor)
    {
        Addconductor->setWindowTitle(QApplication::translate("Addconductor", "\346\267\273\345\212\240\345\224\256\347\245\250\345\221\230", Q_NULLPTR));
        Label->setText(QApplication::translate("Addconductor", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        Label_2->setText(QApplication::translate("Addconductor", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("Addconductor", "\346\267\273\345\212\240\345\224\256\347\245\250\345\221\230", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Addconductor", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Addconductor", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Addconductor: public Ui_Addconductor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONDUCTOR_H
