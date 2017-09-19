/********************************************************************************
** Form generated from reading UI file 'passwordback1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDBACK1_H
#define UI_PASSWORDBACK1_H

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

class Ui_Passwordback1
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

    void setupUi(QDialog *Passwordback1)
    {
        if (Passwordback1->objectName().isEmpty())
            Passwordback1->setObjectName(QStringLiteral("Passwordback1"));
        Passwordback1->resize(400, 300);
        label = new QLabel(Passwordback1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 40, 121, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        formLayoutWidget = new QWidget(Passwordback1);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 120, 221, 81));
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

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));
        LineEdit_2->setFont(font1);
        LineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

        pushButton = new QPushButton(Passwordback1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 240, 75, 23));
        pushButton_2 = new QPushButton(Passwordback1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 240, 75, 23));

        retranslateUi(Passwordback1);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Passwordback1, SLOT(close()));

        QMetaObject::connectSlotsByName(Passwordback1);
    } // setupUi

    void retranslateUi(QDialog *Passwordback1)
    {
        Passwordback1->setWindowTitle(QApplication::translate("Passwordback1", "\346\233\264\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("Passwordback1", "\350\256\276\347\275\256\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        Label->setText(QApplication::translate("Passwordback1", "\346\211\213\346\234\272\345\217\267:", Q_NULLPTR));
        Label_2->setText(QApplication::translate("Passwordback1", "\346\226\260\345\257\206\347\240\201:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Passwordback1", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Passwordback1", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Passwordback1: public Ui_Passwordback1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDBACK1_H
