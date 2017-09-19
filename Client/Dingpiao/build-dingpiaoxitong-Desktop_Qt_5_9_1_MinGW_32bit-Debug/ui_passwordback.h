/********************************************************************************
** Form generated from reading UI file 'passwordback.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDBACK_H
#define UI_PASSWORDBACK_H

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

class Ui_Passwordback
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label_2;
    QLineEdit *LineEdit_2;
    QLabel *Label_3;
    QLineEdit *LineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Passwordback)
    {
        if (Passwordback->objectName().isEmpty())
            Passwordback->setObjectName(QStringLiteral("Passwordback"));
        Passwordback->resize(400, 300);
        formLayoutWidget = new QWidget(Passwordback);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 110, 231, 71));
        QFont font;
        font.setPointSize(12);
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Label_2);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));
        LineEdit_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit_2);

        Label_3 = new QLabel(formLayoutWidget);
        Label_3->setObjectName(QStringLiteral("Label_3"));
        Label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_3);

        LineEdit_3 = new QLineEdit(formLayoutWidget);
        LineEdit_3->setObjectName(QStringLiteral("LineEdit_3"));
        LineEdit_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_3);

        pushButton = new QPushButton(Passwordback);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 240, 75, 23));
        pushButton_2 = new QPushButton(Passwordback);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 240, 75, 23));
        label = new QLabel(Passwordback);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 401, 41));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Passwordback);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Passwordback, SLOT(close()));

        QMetaObject::connectSlotsByName(Passwordback);
    } // setupUi

    void retranslateUi(QDialog *Passwordback)
    {
        Passwordback->setWindowTitle(QApplication::translate("Passwordback", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        Label_2->setText(QApplication::translate("Passwordback", "\344\270\200\345\215\241\351\200\232\345\217\267:", Q_NULLPTR));
        Label_3->setText(QApplication::translate("Passwordback", "\345\255\246\345\217\267:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Passwordback", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Passwordback", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("Passwordback", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Passwordback: public Ui_Passwordback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDBACK_H
