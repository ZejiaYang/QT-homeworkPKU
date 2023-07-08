/********************************************************************************
** Form generated from reading UI file 'Ending.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDING_H
#define UI_ENDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ending
{
public:
    QPushButton *pushButton;
    QPushButton *exitButton;
    QLabel *back_label;

    void setupUi(QWidget *Ending)
    {
        if (Ending->objectName().isEmpty())
            Ending->setObjectName(QStringLiteral("Ending"));
        Ending->resize(950, 713);
        Ending->setMinimumSize(QSize(950, 713));
        Ending->setMaximumSize(QSize(950, 713));
        pushButton = new QPushButton(Ending);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 620, 151, 61));
        exitButton = new QPushButton(Ending);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(760, 620, 151, 61));
        back_label = new QLabel(Ending);
        back_label->setObjectName(QStringLiteral("back_label"));
        back_label->setGeometry(QRect(0, 0, 950, 713));

        retranslateUi(Ending);

        QMetaObject::connectSlotsByName(Ending);
    } // setupUi

    void retranslateUi(QWidget *Ending)
    {
        Ending->setWindowTitle(QApplication::translate("Ending", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Ending", "\351\207\215\347\275\256\346\270\270\346\210\217", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Ending", "\351\200\200\345\207\272\346\270\270\346\210\217", Q_NULLPTR));
        back_label->setText(QApplication::translate("Ending", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ending: public Ui_Ending {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDING_H
