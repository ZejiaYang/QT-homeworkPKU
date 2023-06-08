/********************************************************************************
** Form generated from reading UI file 'push.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUSH_H
#define UI_PUSH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_push
{
public:
    QLabel *IntroLabel;
    QLabel *NPCLabel;
    QLabel *PlayerLabel;
    QLabel *end_page_label;
    QLabel *end_words_label;
    QLabel *scrollLabel;

    void setupUi(QWidget *push)
    {
        if (push->objectName().isEmpty())
            push->setObjectName(QStringLiteral("push"));
        push->resize(400, 300);
        IntroLabel = new QLabel(push);
        IntroLabel->setObjectName(QStringLiteral("IntroLabel"));
        IntroLabel->setGeometry(QRect(60, 130, 72, 15));
        NPCLabel = new QLabel(push);
        NPCLabel->setObjectName(QStringLiteral("NPCLabel"));
        NPCLabel->setGeometry(QRect(130, 200, 72, 15));
        PlayerLabel = new QLabel(push);
        PlayerLabel->setObjectName(QStringLiteral("PlayerLabel"));
        PlayerLabel->setGeometry(QRect(210, 130, 72, 15));
        end_page_label = new QLabel(push);
        end_page_label->setObjectName(QStringLiteral("end_page_label"));
        end_page_label->setGeometry(QRect(130, 70, 72, 15));
        end_words_label = new QLabel(push);
        end_words_label->setObjectName(QStringLiteral("end_words_label"));
        end_words_label->setGeometry(QRect(240, 260, 72, 15));
        scrollLabel = new QLabel(push);
        scrollLabel->setObjectName(QStringLiteral("scrollLabel"));
        scrollLabel->setGeometry(QRect(30, 260, 72, 15));

        retranslateUi(push);

        QMetaObject::connectSlotsByName(push);
    } // setupUi

    void retranslateUi(QWidget *push)
    {
        push->setWindowTitle(QApplication::translate("push", "push", Q_NULLPTR));
        IntroLabel->setText(QString());
        NPCLabel->setText(QString());
        PlayerLabel->setText(QString());
        end_page_label->setText(QString());
        end_words_label->setText(QString());
        scrollLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class push: public Ui_push {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUSH_H
