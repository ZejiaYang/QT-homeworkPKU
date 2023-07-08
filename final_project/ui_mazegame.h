/********************************************************************************
** Form generated from reading UI file 'mazegame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZEGAME_H
#define UI_MAZEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mazegame
{
public:
    QLabel *IntroLabel;
    QLabel *NPCLabel;
    QLabel *end_page_label;
    QLabel *end_words_label;
    QLabel *scrollLabel;
    QLabel *PlayerLabel;

    void setupUi(QWidget *mazegame)
    {
        if (mazegame->objectName().isEmpty())
            mazegame->setObjectName(QStringLiteral("mazegame"));
        mazegame->resize(400, 300);
        IntroLabel = new QLabel(mazegame);
        IntroLabel->setObjectName(QStringLiteral("IntroLabel"));
        IntroLabel->setGeometry(QRect(130, 110, 72, 15));
        NPCLabel = new QLabel(mazegame);
        NPCLabel->setObjectName(QStringLiteral("NPCLabel"));
        NPCLabel->setGeometry(QRect(180, 220, 72, 15));
        end_page_label = new QLabel(mazegame);
        end_page_label->setObjectName(QStringLiteral("end_page_label"));
        end_page_label->setGeometry(QRect(300, 200, 72, 15));
        end_words_label = new QLabel(mazegame);
        end_words_label->setObjectName(QStringLiteral("end_words_label"));
        end_words_label->setGeometry(QRect(70, 110, 72, 15));
        scrollLabel = new QLabel(mazegame);
        scrollLabel->setObjectName(QStringLiteral("scrollLabel"));
        scrollLabel->setGeometry(QRect(50, 210, 72, 15));
        PlayerLabel = new QLabel(mazegame);
        PlayerLabel->setObjectName(QStringLiteral("PlayerLabel"));
        PlayerLabel->setGeometry(QRect(40, 40, 72, 15));

        retranslateUi(mazegame);

        QMetaObject::connectSlotsByName(mazegame);
    } // setupUi

    void retranslateUi(QWidget *mazegame)
    {
        mazegame->setWindowTitle(QApplication::translate("mazegame", "mazegame", Q_NULLPTR));
        IntroLabel->setText(QApplication::translate("mazegame", "TextLabel", Q_NULLPTR));
        NPCLabel->setText(QApplication::translate("mazegame", "TextLabel", Q_NULLPTR));
        end_page_label->setText(QApplication::translate("mazegame", "TextLabel", Q_NULLPTR));
        end_words_label->setText(QString());
        scrollLabel->setText(QApplication::translate("mazegame", "TextLabel", Q_NULLPTR));
        PlayerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mazegame: public Ui_mazegame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZEGAME_H
