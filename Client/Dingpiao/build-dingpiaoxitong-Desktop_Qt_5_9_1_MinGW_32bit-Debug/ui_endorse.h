/********************************************************************************
** Form generated from reading UI file 'endorse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDORSE_H
#define UI_ENDORSE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Endorse
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Endorse)
    {
        if (Endorse->objectName().isEmpty())
            Endorse->setObjectName(QStringLiteral("Endorse"));
        Endorse->resize(587, 352);
        tableWidget = new QTableWidget(Endorse);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 571, 241));
        pushButton = new QPushButton(Endorse);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 320, 75, 23));
        pushButton_2 = new QPushButton(Endorse);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 320, 75, 23));
        label = new QLabel(Endorse);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 581, 31));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Endorse);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 40, 81, 20));
        label_4->setAlignment(Qt::AlignCenter);
        dateEdit = new QDateEdit(Endorse);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(90, 40, 71, 21));
        dateEdit->setCurrentSection(QDateTimeEdit::MonthSection);
        dateEdit->setCalendarPopup(true);
        dateEdit->setCurrentSectionIndex(0);
        dateEdit->setTimeSpec(Qt::LocalTime);
        dateEdit->setDate(QDate(2017, 6, 2));
        label_2 = new QLabel(Endorse);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 40, 41, 21));
        label_3 = new QLabel(Endorse);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 40, 51, 21));
        label_5 = new QLabel(Endorse);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 40, 51, 21));
        label_6 = new QLabel(Endorse);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 40, 61, 21));
        pushButton_3 = new QPushButton(Endorse);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 40, 75, 23));

        retranslateUi(Endorse);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Endorse, SLOT(close()));

        QMetaObject::connectSlotsByName(Endorse);
    } // setupUi

    void retranslateUi(QDialog *Endorse)
    {
        Endorse->setWindowTitle(QApplication::translate("Endorse", "\346\224\271\347\255\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Endorse", "\346\261\275\350\275\246\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Endorse", "\345\207\272\345\217\221\345\234\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Endorse", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Endorse", "\345\210\260\350\276\276\345\234\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Endorse", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Endorse", "\345\211\251\344\275\231\347\245\250\346\225\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Endorse", "\345\224\256\344\273\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Endorse", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Endorse", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("Endorse", "\346\224\271\347\255\276", Q_NULLPTR));
        label_4->setText(QApplication::translate("Endorse", "\345\207\272\345\217\221\346\227\245\346\234\237", Q_NULLPTR));
        dateEdit->setDisplayFormat(QApplication::translate("Endorse", "MM/dd", Q_NULLPTR));
        label_2->setText(QApplication::translate("Endorse", "\345\207\272\345\217\221\345\234\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("Endorse", "\345\210\260\350\276\276\345\234\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("Endorse", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Endorse", "TextLabel", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Endorse", "\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Endorse: public Ui_Endorse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDORSE_H
