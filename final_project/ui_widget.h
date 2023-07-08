/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *back_ground;
    QLabel *Reset;
    QLabel *Iam;
    QLabel *PKU;
    QPushButton *pushButton;
    QLabel *back_ground_2;
    QLabel *Intro1;
    QLabel *Intro2;
    QLabel *Intro3;
    QLabel *back_ground_3;
    QLabel *Intro3_2;
    QLabel *Intro1_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1280, 720);
        Widget->setMinimumSize(QSize(1280, 720));
        Widget->setMaximumSize(QSize(1280, 720));
        back_ground = new QLabel(Widget);
        back_ground->setObjectName(QStringLiteral("back_ground"));
        back_ground->setGeometry(QRect(0, 0, 1280, 720));
        back_ground->setMinimumSize(QSize(1280, 720));
        back_ground->setMaximumSize(QSize(1280, 720));
        Reset = new QLabel(Widget);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setGeometry(QRect(60, 170, 340, 119));
        Iam = new QLabel(Widget);
        Iam->setObjectName(QStringLiteral("Iam"));
        Iam->setGeometry(QRect(220, 290, 340, 119));
        PKU = new QLabel(Widget);
        PKU->setObjectName(QStringLiteral("PKU"));
        PKU->setGeometry(QRect(270, 430, 400, 120));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(880, 560, 300, 90));
        back_ground_2 = new QLabel(Widget);
        back_ground_2->setObjectName(QStringLiteral("back_ground_2"));
        back_ground_2->setGeometry(QRect(0, 0, 1280, 720));
        back_ground_2->setMinimumSize(QSize(1280, 720));
        back_ground_2->setMaximumSize(QSize(1280, 720));
        Intro1 = new QLabel(Widget);
        Intro1->setObjectName(QStringLiteral("Intro1"));
        Intro1->setGeometry(QRect(170, 150, 631, 101));
        Intro1->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight: bold;"));
        Intro2 = new QLabel(Widget);
        Intro2->setObjectName(QStringLiteral("Intro2"));
        Intro2->setGeometry(QRect(320, 270, 631, 101));
        Intro2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight: bold;"));
        Intro3 = new QLabel(Widget);
        Intro3->setObjectName(QStringLiteral("Intro3"));
        Intro3->setGeometry(QRect(420, 390, 631, 101));
        Intro3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight: bold;"));
        back_ground_3 = new QLabel(Widget);
        back_ground_3->setObjectName(QStringLiteral("back_ground_3"));
        back_ground_3->setGeometry(QRect(405, 6, 600, 705));
        back_ground_3->setMinimumSize(QSize(600, 705));
        back_ground_3->setMaximumSize(QSize(600, 636));
        Intro3_2 = new QLabel(Widget);
        Intro3_2->setObjectName(QStringLiteral("Intro3_2"));
        Intro3_2->setGeometry(QRect(30, 100, 311, 101));
        Intro3_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight: bold;"));
        Intro1_2 = new QLabel(Widget);
        Intro1_2->setObjectName(QStringLiteral("Intro1_2"));
        Intro1_2->setGeometry(QRect(30, 160, 371, 101));
        Intro1_2->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight: bold;"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        back_ground->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        Reset->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        Iam->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        PKU->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        pushButton->setText(QString());
        back_ground_2->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        Intro1->setText(QString());
        Intro2->setText(QString());
        Intro3->setText(QString());
        back_ground_3->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        Intro3_2->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-style:italic; color:#0055ff;\">\345\214\227\345\244\247\345\234\260\345\233\276</span></p></body></html>", Q_NULLPTR));
        Intro1_2->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:18pt; font-style:italic; color:#0055ff;\">\351\200\232\345\205\263\345\220\216\345\234\260\346\240\207\344\274\232\345\217\230\346\210\220\346\230\237\346\230\237\345\231\242\357\274\201</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
