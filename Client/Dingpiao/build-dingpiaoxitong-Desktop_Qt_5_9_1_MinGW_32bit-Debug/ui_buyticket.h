/********************************************************************************
** Form generated from reading UI file 'buyticket.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYTICKET_H
#define UI_BUYTICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buyticket
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_11;

    void setupUi(QDialog *Buyticket)
    {
        if (Buyticket->objectName().isEmpty())
            Buyticket->setObjectName(QStringLiteral("Buyticket"));
        Buyticket->resize(400, 300);
        formLayoutWidget = new QWidget(Buyticket);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(100, 90, 181, 121));
        QFont font;
        font.setPointSize(13);
        formLayoutWidget->setFont(font);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_5);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_7);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_8);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, label_9);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, label_10);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        pushButton = new QPushButton(Buyticket);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 250, 75, 23));
        pushButton_2 = new QPushButton(Buyticket);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 250, 75, 23));
        label_11 = new QLabel(Buyticket);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 20, 401, 41));
        QFont font1;
        font1.setPointSize(17);
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        retranslateUi(Buyticket);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Buyticket, SLOT(close()));

        QMetaObject::connectSlotsByName(Buyticket);
    } // setupUi

    void retranslateUi(QDialog *Buyticket)
    {
        Buyticket->setWindowTitle(QApplication::translate("Buyticket", "\350\256\242\345\215\225\347\241\256\350\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("Buyticket", "\346\261\275\350\275\246\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Buyticket", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Buyticket", "\344\271\230\350\275\246\344\272\272\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("Buyticket", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Buyticket", "\345\272\247\344\275\215\345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("Buyticket", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Buyticket", "\345\207\272\345\217\221\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("Buyticket", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("Buyticket", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Buyticket", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Buyticket", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Buyticket", "\345\217\226\346\266\210", Q_NULLPTR));
        label_11->setText(QApplication::translate("Buyticket", "\350\256\242\345\215\225\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Buyticket: public Ui_Buyticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYTICKET_H
