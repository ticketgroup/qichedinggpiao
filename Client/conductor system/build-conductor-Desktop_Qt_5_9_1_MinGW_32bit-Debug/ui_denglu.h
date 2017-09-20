/********************************************************************************
** Form generated from reading UI file 'denglu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DENGLU_H
#define UI_DENGLU_H

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

class Ui_Denglu
{
public:
    QPushButton *pushButton_3;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *nLabel_2;
    QLineEdit *nLineEdit_2;
    QLabel *pLabel_2;
    QLineEdit *pLineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Denglu)
    {
        if (Denglu->objectName().isEmpty())
            Denglu->setObjectName(QStringLiteral("Denglu"));
        Denglu->resize(400, 300);
        pushButton_3 = new QPushButton(Denglu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 240, 75, 23));
        formLayoutWidget = new QWidget(Denglu);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 120, 221, 62));
        QFont font;
        font.setPointSize(12);
        formLayoutWidget->setFont(font);
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        nLabel_2 = new QLabel(formLayoutWidget);
        nLabel_2->setObjectName(QStringLiteral("nLabel_2"));
        nLabel_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nLabel_2);

        nLineEdit_2 = new QLineEdit(formLayoutWidget);
        nLineEdit_2->setObjectName(QStringLiteral("nLineEdit_2"));
        nLineEdit_2->setFont(font);
        nLineEdit_2->setClearButtonEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nLineEdit_2);

        pLabel_2 = new QLabel(formLayoutWidget);
        pLabel_2->setObjectName(QStringLiteral("pLabel_2"));
        pLabel_2->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pLabel_2);

        pLineEdit_2 = new QLineEdit(formLayoutWidget);
        pLineEdit_2->setObjectName(QStringLiteral("pLineEdit_2"));
        pLineEdit_2->setFont(font);
        pLineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pLineEdit_2);

        pushButton_2 = new QPushButton(Denglu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 240, 75, 23));
        label = new QLabel(Denglu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 401, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(17);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Denglu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 60, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(Denglu);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Denglu, SLOT(close()));

        QMetaObject::connectSlotsByName(Denglu);
    } // setupUi

    void retranslateUi(QDialog *Denglu)
    {
        Denglu->setWindowTitle(QApplication::translate("Denglu", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Denglu", "\347\231\273\345\275\225", Q_NULLPTR));
        nLabel_2->setText(QApplication::translate("Denglu", "\347\224\250\346\210\267\345\220\215(&N):", Q_NULLPTR));
        pLabel_2->setText(QApplication::translate("Denglu", "\345\257\206\347\240\201(&P):", Q_NULLPTR));
        pLineEdit_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Denglu", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QApplication::translate("Denglu", "\346\261\275\350\275\246\350\256\242\347\245\250\347\263\273\347\273\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("Denglu", "\345\224\256\347\245\250\345\221\230\344\270\223\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Denglu: public Ui_Denglu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGLU_H
