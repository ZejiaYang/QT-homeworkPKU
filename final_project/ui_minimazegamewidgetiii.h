/********************************************************************************
** Form generated from reading UI file 'minimazegamewidgetiii.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIMAZEGAMEWIDGETIII_H
#define UI_MINIMAZEGAMEWIDGETIII_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniMazeGameWidgetIII
{
public:
    QLabel *scrollLabel;
    QLabel *NPCLabel;
    QLabel *IntroLabel;
    QLabel *end_page_label;
    QLabel *PlayerLabel;
    QPushButton *ExitButton;
    QLabel *end_words_label;

    void setupUi(QWidget *MiniMazeGameWidgetIII)
    {
        if (MiniMazeGameWidgetIII->objectName().isEmpty())
            MiniMazeGameWidgetIII->setObjectName(QStringLiteral("MiniMazeGameWidgetIII"));
        MiniMazeGameWidgetIII->resize(400, 300);
        scrollLabel = new QLabel(MiniMazeGameWidgetIII);
        scrollLabel->setObjectName(QStringLiteral("scrollLabel"));
        scrollLabel->setGeometry(QRect(170, 150, 54, 12));
        NPCLabel = new QLabel(MiniMazeGameWidgetIII);
        NPCLabel->setObjectName(QStringLiteral("NPCLabel"));
        NPCLabel->setGeometry(QRect(170, 190, 54, 12));
        IntroLabel = new QLabel(MiniMazeGameWidgetIII);
        IntroLabel->setObjectName(QStringLiteral("IntroLabel"));
        IntroLabel->setGeometry(QRect(160, 230, 54, 12));
        end_page_label = new QLabel(MiniMazeGameWidgetIII);
        end_page_label->setObjectName(QStringLiteral("end_page_label"));
        end_page_label->setGeometry(QRect(280, 170, 54, 12));
        PlayerLabel = new QLabel(MiniMazeGameWidgetIII);
        PlayerLabel->setObjectName(QStringLiteral("PlayerLabel"));
        PlayerLabel->setGeometry(QRect(40, 30, 54, 12));
        ExitButton = new QPushButton(MiniMazeGameWidgetIII);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(10, 260, 75, 23));
        end_words_label = new QLabel(MiniMazeGameWidgetIII);
        end_words_label->setObjectName(QStringLiteral("end_words_label"));
        end_words_label->setGeometry(QRect(280, 220, 54, 12));

        retranslateUi(MiniMazeGameWidgetIII);

        QMetaObject::connectSlotsByName(MiniMazeGameWidgetIII);
    } // setupUi

    void retranslateUi(QWidget *MiniMazeGameWidgetIII)
    {
        MiniMazeGameWidgetIII->setWindowTitle(QApplication::translate("MiniMazeGameWidgetIII", "MiniMazeGameWidgetIII", Q_NULLPTR));
        scrollLabel->setText(QApplication::translate("MiniMazeGameWidgetIII", "fill in with scroll", Q_NULLPTR));
        NPCLabel->setText(QApplication::translate("MiniMazeGameWidgetIII", "NPCLabel", Q_NULLPTR));
        IntroLabel->setText(QApplication::translate("MiniMazeGameWidgetIII", "IntroLabel", Q_NULLPTR));
        end_page_label->setText(QApplication::translate("MiniMazeGameWidgetIII", "end_page_label", Q_NULLPTR));
        PlayerLabel->setText(QApplication::translate("MiniMazeGameWidgetIII", "Player", Q_NULLPTR));
        ExitButton->setText(QString());
        end_words_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MiniMazeGameWidgetIII: public Ui_MiniMazeGameWidgetIII {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIMAZEGAMEWIDGETIII_H
