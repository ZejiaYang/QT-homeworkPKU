/********************************************************************************
** Form generated from reading UI file 'gameview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEVIEW_H
#define UI_GAMEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameview
{
public:
    QLabel *Image_Label;
    QLabel *Backg_Label;
    QLabel *Bygg;
    QPushButton *Commence;
    QPushButton *Shutdown;
    QLabel *scoreLcd;
    QLabel *pianoLabel1;
    QLabel *pianoLabel2;
    QLabel *timeLcd;
    QLabel *Result;
    QLabel *Intro_label;
    QLabel *Intro_writing;
    QLabel *Intro_writing2;
    QLabel *Intro_writing3;
    QLabel *Intro_label2;
    QPushButton *ExitButton;
    QLabel *Intro_writing4;

    void setupUi(QWidget *gameview)
    {
        if (gameview->objectName().isEmpty())
            gameview->setObjectName(QStringLiteral("gameview"));
        gameview->resize(1280, 720);
        gameview->setMinimumSize(QSize(1280, 720));
        gameview->setMaximumSize(QSize(1280, 720));
        Image_Label = new QLabel(gameview);
        Image_Label->setObjectName(QStringLiteral("Image_Label"));
        Image_Label->setGeometry(QRect(114, -6, 420, 681));
        Backg_Label = new QLabel(gameview);
        Backg_Label->setObjectName(QStringLiteral("Backg_Label"));
        Backg_Label->setGeometry(QRect(0, 0, 1280, 720));
        Bygg = new QLabel(gameview);
        Bygg->setObjectName(QStringLiteral("Bygg"));
        Bygg->setGeometry(QRect(950, 155, 350, 571));
        Commence = new QPushButton(gameview);
        Commence->setObjectName(QStringLiteral("Commence"));
        Commence->setGeometry(QRect(610, 620, 150, 60));
        Commence->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 250);    \n"
"font: 20pt \"Agency FB\";\n"
"color: rgb(0,0,0);                     \n"
"border-radius: 20px;\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-style:outset;\n"
"text-align: center;\n"
""));
        Shutdown = new QPushButton(gameview);
        Shutdown->setObjectName(QStringLiteral("Shutdown"));
        Shutdown->setGeometry(QRect(795, 620, 150, 60));
        Shutdown->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(0, 170, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        scoreLcd = new QLabel(gameview);
        scoreLcd->setObjectName(QStringLiteral("scoreLcd"));
        scoreLcd->setGeometry(QRect(605, 530, 150, 60));
        scoreLcd->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color:rgb(255, 0, 0);\n"
"font: 20pt \"Agency FB\";\n"
""));
        pianoLabel1 = new QLabel(gameview);
        pianoLabel1->setObjectName(QStringLiteral("pianoLabel1"));
        pianoLabel1->setGeometry(QRect(103, 622, 225, 98));
        pianoLabel2 = new QLabel(gameview);
        pianoLabel2->setObjectName(QStringLiteral("pianoLabel2"));
        pianoLabel2->setGeometry(QRect(328, 622, 225, 98));
        timeLcd = new QLabel(gameview);
        timeLcd->setObjectName(QStringLiteral("timeLcd"));
        timeLcd->setGeometry(QRect(795, 530, 150, 60));
        timeLcd->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"color:rgb(255, 0, 0);\n"
"font: 20pt \"Agency FB\";\n"
""));
        Result = new QLabel(gameview);
        Result->setObjectName(QStringLiteral("Result"));
        Result->setGeometry(QRect(560, -152, 563, 132));
        Intro_label = new QLabel(gameview);
        Intro_label->setObjectName(QStringLiteral("Intro_label"));
        Intro_label->setGeometry(QRect(0, 0, 1280, 720));
        Intro_writing = new QLabel(gameview);
        Intro_writing->setObjectName(QStringLiteral("Intro_writing"));
        Intro_writing->setGeometry(QRect(40, 50, 1000, 600));
        Intro_writing->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        Intro_writing2 = new QLabel(gameview);
        Intro_writing2->setObjectName(QStringLiteral("Intro_writing2"));
        Intro_writing2->setGeometry(QRect(40, 44, 1000, 600));
        Intro_writing2->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        Intro_writing3 = new QLabel(gameview);
        Intro_writing3->setObjectName(QStringLiteral("Intro_writing3"));
        Intro_writing3->setGeometry(QRect(300, 122, 700, 500));
        Intro_writing3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        Intro_label2 = new QLabel(gameview);
        Intro_label2->setObjectName(QStringLiteral("Intro_label2"));
        Intro_label2->setGeometry(QRect(0, 0, 1280, 720));
        ExitButton = new QPushButton(gameview);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(1120, 0, 161, 71));
        ExitButton->setStyleSheet(QLatin1String("font: 87 28pt \"Arial Black\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 255, 255);"));
        Intro_writing4 = new QLabel(gameview);
        Intro_writing4->setObjectName(QStringLiteral("Intro_writing4"));
        Intro_writing4->setGeometry(QRect(200, 220, 252, 234));
        Intro_writing4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));

        retranslateUi(gameview);

        QMetaObject::connectSlotsByName(gameview);
    } // setupUi

    void retranslateUi(QWidget *gameview)
    {
        gameview->setWindowTitle(QApplication::translate("gameview", "Form", Q_NULLPTR));
        Image_Label->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        Backg_Label->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        Bygg->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        Commence->setText(QApplication::translate("gameview", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        Shutdown->setText(QApplication::translate("gameview", "\344\270\255\346\255\242\346\270\270\346\210\217", Q_NULLPTR));
        scoreLcd->setText(QApplication::translate("gameview", "<html><head/><body><p align=\"center\">Best Score:</p></body></html>", Q_NULLPTR));
        pianoLabel1->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        pianoLabel2->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        timeLcd->setText(QApplication::translate("gameview", "<html><head/><body><p align=\"center\">Best Score:</p></body></html>", Q_NULLPTR));
        Result->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        Intro_label->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        Intro_writing->setText(QApplication::translate("gameview", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:600; font-style:italic; color:#ff007f;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\256\266\345\233\255\351\243\237\345\240\202</span></p><p align=\"center\"><span style=\" font-weight:600;\"><br/></span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\345\256\266\345\233\255\351\243\237\345\240\202\347\232\204\345\211\215\350\272\253\344\270\2721952\345\271\264\344\275\215\344\272\216\344\273\212\345\244\251\347\231\276\345\221\250\345\271\264\347\272\252\345\277\265\350\256\262\345\240\202\344\275\215\347\275\256\347\232\204\342\200\234\345\244\247\351\245\255\345\216\205\342\200\235</span></p><p align=\"center\"><span style=\" font-weight:600;\"><br/></span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\345\275\223\346\227\266\344\275\234\344\270\272\345\234\260\346\240\207\347\232\204\345\244\247\351\245\255\345\216\205\357\274\214\346\230\257\350\200\201\345\214"
                        "\227\345\244\247\344\272\272\351\232\276\344\273\245\345\277\230\346\200\200\347\232\204\350\256\260\345\277\206</span></p><p align=\"center\"><span style=\" font-weight:600;\"><br/></span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">2016\345\271\264\357\274\214\345\214\227\345\244\247\345\234\250\350\200\201\345\256\266\345\233\255\351\243\237\345\240\202\347\232\204\345\237\272\347\241\200\344\270\212\345\273\272\350\256\276\346\226\260\351\243\237\345\240\202</span></p><p align=\"center\"><span style=\" font-weight:600;\"><br/></span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">2020\345\271\264\357\274\214\346\226\260\345\256\266\345\233\255\351\243\237\345\240\202\347\253\243\345\267\245\357\274\214\345\271\266\345\234\250\345\220\214\345\271\26411\346\234\210\346\255\243\345\274\217\350\220\245\344\270\232 </span></p></body></html>", Q_NULLPTR));
        Intro_writing2->setText(QApplication::translate("gameview", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:600; font-style:italic; color:#ff007f;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\256\266\345\233\255\351\243\237\345\240\202</span></p><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\345\256\266\345\233\255\351\243\237\345\240\202\347\264\247\351\202\273\345\255\246\347\224\237\345\256\277\350\210\215\345\222\214\345\212\236\345\205\254\345\214\272\357\274\214\345\234\260\344\270\212\345\233\233\345\261\202\344\270\272\345\260\261\351\244\220\345\214\272</span><span style=\" font-weight:600;\"><br/></span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\345\256\266\345\233\255\351\243\237\345\240\202\350\217\234\345\223\201\345\214\205\347\275\227\344\270\207\350\261\241\357\274\214\346\257\217\345\261\202\345\220\204\345\205\267\347\211\271\350\211\262</span><span style=\" font-weight:600;\"><br/></span></p><p align=\"center\"><br/></p><p "
                        "align=\"center\"><span style=\" font-size:18pt; font-weight:600; font-style:italic; color:#ff0000;\">\344\270\200\345\261\202</span><span style=\" font-size:18pt; font-weight:600;\"> \345\224\256\345\215\226\347\273\217\346\265\216\345\244\247\344\274\231\350\217\234\350\202\264</span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; font-style:italic; color:#ff0000;\">\344\272\214\345\261\202</span><span style=\" font-size:18pt; font-weight:600;\"> \350\201\232\351\233\206\345\220\204\345\234\260\351\243\216\345\221\263\347\211\271\350\211\262\347\276\216\351\243\237</span></p><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; font-style:italic; color:#ff0000;\">\344\270\211\345\261\202</span><span style=\" font-size:18pt; font-weight:600;\"> \346\213\245\346\234\211\347\205\262\344\273\224\351\245\255\343\200\201\344\270\255\345\274\217\347\256\200\351\244\220\343\200\201\351\272\273\350\276\243\347\203\253\344\270\211\344\270\252\346\241\243\345\217\243</span></p><p al"
                        "ign=\"center\"><span style=\" font-size:18pt; font-weight:600; font-style:italic; color:#ff0000;\">\345\233\233\345\261\202</span><span style=\" font-size:18pt; font-weight:600;\"> \345\210\231\344\270\272\346\205\242\350\212\202\345\245\217\347\224\250\351\244\220\351\243\216\346\240\274\347\232\204\344\274\221\351\227\262\351\244\220\345\216\205 </span></p></body></html>", Q_NULLPTR));
        Intro_writing3->setText(QApplication::translate("gameview", "<html><head/><body><p align=\"center\"><span style=\" font-family:'\347\255\211\347\272\277'; font-size:18pt; font-weight:600;\">\344\275\234\344\270\272PKU\347\232\204\344\270\200\345\221\230\357\274\214\344\275\240\344\270\200\345\256\232\346\262\241\345\260\221\345\216\273\345\256\266\345\233\255\351\243\237\345\240\202\346\201\260\351\245\255\345\220\247\357\274\201</span></p><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-family:'\347\255\211\347\272\277'; font-size:18pt; font-weight:600;\">\345\277\253\346\235\245\346\243\200\351\252\214\344\275\240\346\230\257\345\220\246\346\230\257\345\220\210\346\240\274\347\232\204\345\256\266\345\233\255\346\201\260\351\245\255\344\272\272</span></p><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-family:'\347\255\211\347\272\277'; font-size:18pt; font-weight:600;\">\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232</span></p><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-family:'\347\255\211\347"
                        "\272\277'; font-size:18pt; font-weight:600;\">\347\202\271\345\207\273\344\273\245\344\270\213\344\270\215\345\234\250\345\256\266\345\233\255\345\224\256\345\215\226\347\232\204\347\276\216\345\221\263</span></p><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-family:'\347\255\211\347\272\277'; font-size:18pt; font-weight:600;\">\346\211\276\345\207\272\345\205\250\351\203\250\345\215\263\351\200\232\350\277\207~</span></p></body></html>", Q_NULLPTR));
        Intro_label2->setText(QApplication::translate("gameview", "TextLabel", Q_NULLPTR));
        ExitButton->setText(QApplication::translate("gameview", "Exit", Q_NULLPTR));
        Intro_writing4->setText(QApplication::translate("gameview", "<html><head/><body><p align=\"center\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:22pt; font-weight:600;\">\346\201\255\345\226\234\344\275\240~</span></p><p align=\"center\"><span style=\" font-size:22pt;\"><br/></span></p><p align=\"center\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:22pt; font-weight:600;\">\346\210\220\345\212\237\351\200\232\345\205\263!</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameview: public Ui_gameview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEVIEW_H
