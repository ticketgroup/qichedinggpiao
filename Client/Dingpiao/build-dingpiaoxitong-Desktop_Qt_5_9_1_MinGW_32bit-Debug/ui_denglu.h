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

class Ui_denglu
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *nLabel_2;
    QLineEdit *nLineEdit_2;
    QLabel *pLabel_2;
    QLineEdit *pLineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *showChildButton;
    QLabel *label;

    void setupUi(QDialog *denglu)
    {
        if (denglu->objectName().isEmpty())
            denglu->setObjectName(QStringLiteral("denglu"));
        denglu->resize(400, 300);
        QFont font;
        font.setPointSize(9);
        denglu->setFont(font);
        denglu->setWindowOpacity(1);
        denglu->setLayoutDirection(Qt::LeftToRight);
        denglu->setSizeGripEnabled(false);
        denglu->setModal(false);
        formLayoutWidget = new QWidget(denglu);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 110, 251, 61));
        QFont font1;
        font1.setPointSize(12);
        formLayoutWidget->setFont(font1);
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        nLabel_2 = new QLabel(formLayoutWidget);
        nLabel_2->setObjectName(QStringLiteral("nLabel_2"));
        nLabel_2->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nLabel_2);

        nLineEdit_2 = new QLineEdit(formLayoutWidget);
        nLineEdit_2->setObjectName(QStringLiteral("nLineEdit_2"));
        nLineEdit_2->setFont(font1);
        nLineEdit_2->setClearButtonEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nLineEdit_2);

        pLabel_2 = new QLabel(formLayoutWidget);
        pLabel_2->setObjectName(QStringLiteral("pLabel_2"));
        pLabel_2->setFont(font1);
        pLabel_2->setLayoutDirection(Qt::LeftToRight);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pLabel_2);

        pLineEdit_2 = new QLineEdit(formLayoutWidget);
        pLineEdit_2->setObjectName(QStringLiteral("pLineEdit_2"));
        pLineEdit_2->setFont(font1);
        pLineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pLineEdit_2);

        pushButton = new QPushButton(denglu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 260, 75, 23));
        pushButton->setCheckable(false);
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(denglu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 230, 75, 23));
        pushButton_3 = new QPushButton(denglu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 230, 75, 23));
        showChildButton = new QPushButton(denglu);
        showChildButton->setObjectName(QStringLiteral("showChildButton"));
        showChildButton->setGeometry(QRect(190, 260, 75, 23));
        showChildButton->setFlat(true);
        label = new QLabel(denglu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 50, 401, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font2.setPointSize(17);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(denglu);
        QObject::connect(pushButton_2, SIGNAL(clicked()), denglu, SLOT(reject()));

        QMetaObject::connectSlotsByName(denglu);
    } // setupUi

    void retranslateUi(QDialog *denglu)
    {
        denglu->setWindowTitle(QApplication::translate("denglu", "\347\231\273\345\275\225", Q_NULLPTR));
        nLabel_2->setText(QApplication::translate("denglu", "\347\224\250\346\210\267\345\220\215(&N):", Q_NULLPTR));
        nLineEdit_2->setText(QString());
        pLabel_2->setText(QApplication::translate("denglu", "\345\257\206\347\240\201(&P):", Q_NULLPTR));
        pLineEdit_2->setText(QString());
        pushButton->setText(QApplication::translate("denglu", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("denglu", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("denglu", "\347\231\273\345\275\225", Q_NULLPTR));
        showChildButton->setText(QApplication::translate("denglu", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("denglu", "\346\261\275\350\275\246\350\256\242\347\245\250\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class denglu: public Ui_denglu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGLU_H
