/********************************************************************************
** Form generated from reading UI file 'visitor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITOR_H
#define UI_VISITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Visitor
{
public:
    QGridLayout *gridLayout_6;
    QFrame *frame_background;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_1;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *btn_2;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *btn_3;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *btn_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_17;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_login;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_login;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_20;
    QFrame *frame_user_name;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame_pwd;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_6;
    QFrame *frame_pic;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QWidget *Visitor)
    {
        if (Visitor->objectName().isEmpty())
            Visitor->setObjectName(QStringLiteral("Visitor"));
        Visitor->resize(1280, 720);
        Visitor->setMinimumSize(QSize(1280, 720));
        Visitor->setMaximumSize(QSize(1280, 720));
        Visitor->setStyleSheet(QStringLiteral(""));
        gridLayout_6 = new QGridLayout(Visitor);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_background = new QFrame(Visitor);
        frame_background->setObjectName(QStringLiteral("frame_background"));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_background);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        btn_5 = new QPushButton(frame_background);
        btn_5->setObjectName(QStringLiteral("btn_5"));
        btn_5->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy);
        btn_5->setMinimumSize(QSize(100, 30));
        QFont font;
        font.setPointSize(10);
        btn_5->setFont(font);

        horizontalLayout_12->addWidget(btn_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        btn_1 = new QPushButton(frame_background);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        sizePolicy.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy);
        btn_1->setMinimumSize(QSize(100, 30));
        btn_1->setMaximumSize(QSize(100, 30));
        btn_1->setFont(font);

        horizontalLayout_12->addWidget(btn_1);

        horizontalSpacer_23 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_23);

        btn_2 = new QPushButton(frame_background);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        sizePolicy.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy);
        btn_2->setMinimumSize(QSize(100, 30));
        btn_2->setMaximumSize(QSize(100, 30));
        btn_2->setFont(font);

        horizontalLayout_12->addWidget(btn_2);

        horizontalSpacer_24 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_24);

        btn_3 = new QPushButton(frame_background);
        btn_3->setObjectName(QStringLiteral("btn_3"));
        sizePolicy.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy);
        btn_3->setMinimumSize(QSize(100, 30));
        btn_3->setMaximumSize(QSize(100, 30));
        btn_3->setFont(font);

        horizontalLayout_12->addWidget(btn_3);

        horizontalSpacer_25 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_25);

        btn_4 = new QPushButton(frame_background);
        btn_4->setObjectName(QStringLiteral("btn_4"));
        sizePolicy.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy);
        btn_4->setMinimumSize(QSize(100, 30));
        btn_4->setMaximumSize(QSize(100, 30));
        btn_4->setFont(font);

        horizontalLayout_12->addWidget(btn_4);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_12);

        verticalSpacer_9 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_17);

        frame = new QFrame(frame_background);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame_login = new QFrame(frame);
        frame_login->setObjectName(QStringLiteral("frame_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_login->sizePolicy().hasHeightForWidth());
        frame_login->setSizePolicy(sizePolicy1);
        frame_login->setMinimumSize(QSize(500, 600));
        frame_login->setMaximumSize(QSize(500, 600));
        frame_login->setFrameShape(QFrame::StyledPanel);
        frame_login->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_login);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_login = new QLabel(frame_login);
        label_login->setObjectName(QStringLiteral("label_login"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(22);
        label_login->setFont(font1);

        horizontalLayout->addWidget(label_login);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        label_7 = new QLabel(frame_login);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label_7->setFont(font2);

        verticalLayout->addWidget(label_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_20 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_20);

        frame_user_name = new QFrame(frame_login);
        frame_user_name->setObjectName(QStringLiteral("frame_user_name"));
        frame_user_name->setFrameShape(QFrame::StyledPanel);
        frame_user_name->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_user_name);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_2 = new QLabel(frame_user_name);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        label_2->setFont(font3);

        horizontalLayout_11->addWidget(label_2);


        gridLayout_4->addLayout(horizontalLayout_11, 0, 0, 1, 1);


        horizontalLayout_10->addWidget(frame_user_name);

        horizontalSpacer_22 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_22);


        verticalLayout->addLayout(horizontalLayout_10);

        label_5 = new QLabel(frame_login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        frame_pwd = new QFrame(frame_login);
        frame_pwd->setObjectName(QStringLiteral("frame_pwd"));
        frame_pwd->setFrameShape(QFrame::StyledPanel);
        frame_pwd->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_pwd);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(frame_pwd);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font3);

        horizontalLayout_3->addWidget(label);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(frame_pwd);

        horizontalSpacer_19 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_19);


        verticalLayout->addLayout(horizontalLayout_2);

        label_6 = new QLabel(frame_login);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font4.setPointSize(8);
        label_6->setFont(font4);

        verticalLayout->addWidget(label_6);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_8->addWidget(frame_login);

        frame_pic = new QFrame(frame);
        frame_pic->setObjectName(QStringLiteral("frame_pic"));
        sizePolicy1.setHeightForWidth(frame_pic->sizePolicy().hasHeightForWidth());
        frame_pic->setSizePolicy(sizePolicy1);
        frame_pic->setMinimumSize(QSize(500, 600));
        frame_pic->setFrameShape(QFrame::StyledPanel);
        frame_pic->setFrameShadow(QFrame::Raised);

        horizontalLayout_8->addWidget(frame_pic);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        horizontalLayout_9->addWidget(frame);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_18);


        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalSpacer_10 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_10);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);


        gridLayout_6->addWidget(frame_background, 0, 0, 1, 1);


        retranslateUi(Visitor);

        QMetaObject::connectSlotsByName(Visitor);
    } // setupUi

    void retranslateUi(QWidget *Visitor)
    {
        Visitor->setWindowTitle(QApplication::translate("Visitor", "Widget", Q_NULLPTR));
        btn_5->setText(QApplication::translate("Visitor", "\347\273\223\346\235\237\346\270\270\350\247\210", Q_NULLPTR));
        btn_1->setText(QApplication::translate("Visitor", "\350\277\231\351\207\214\347\234\213\347\234\213", Q_NULLPTR));
        btn_2->setText(QApplication::translate("Visitor", "\351\202\243\351\207\214\347\234\213\347\234\213", Q_NULLPTR));
        btn_3->setText(QApplication::translate("Visitor", "\345\206\215\347\234\213\347\234\213", Q_NULLPTR));
        btn_4->setText(QApplication::translate("Visitor", "\345\210\260\345\244\204\347\234\213\347\234\213", Q_NULLPTR));
        label_login->setText(QApplication::translate("Visitor", "Yard Planting College", Q_NULLPTR));
        label_7->setText(QApplication::translate("Visitor", "                B1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Visitor", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\272\267\345\276\267\346\212\245\345\221\212\345\216\205</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\344\275\234\344\270\272ypers\350\201\232\351\233\206\347\232\204\345\205\254\345\205\261\345\214\272\345\237\237</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\345\256\203\346\227\242\346\211\277\350\275\275\344\272\206\345\255\246\346\234\257\344\272\244\346\265\201\347\232\204\345\212\237\350\203\275</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\345\217\210\346\230\257\346\241\214\346\270\270\343\200\201\350\256\277\350\260\210\343\200\201\346\221\204\345\275\261\347\232\204\344\270\215\344\272\214\344\271\213\351\200\211</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("Visitor", "                B2", Q_NULLPTR));
        label->setText(QApplication::translate("Visitor", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\234\260\344\270\213\347\224\265\345\275\261\351\231\242</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\345\222\214\346\234\252\345\220\215\346\271\226\345\272\225\345\220\214\346\265\267\346\213\224</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\345\234\250\350\277\231\351\207\214</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\346\227\242\346\234\211\346\277\200\346\203\205\346\276\216\346\271\203\347\232\204\347\220\203\350\265\233\347\233\264\346\222\255</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\345\217\210\346\234\211\345\256\232\346\234\237\344\270\276\345\212\236\347\232\204\347\224\265\345\275\261\346\224\276\346\230\240</span></p><p align=\"center\"><span style=\" font-size:11pt;\">\346\233\264\346\230\257\345\233\242\345\273\272\347\232\204\345\245\275\345\216\273\345\244\204</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("Visitor", "<html><head/><body><p align=\"center\">\345\275\223\347\204\266\357\274\214\345\234\260\344\270\213\347\224\265\345\275\261\345\256\244\343\200\201\345\201\245\350\272\253\346\210\277\343\200\201\345\217\260\347\220\203\345\256\244\343\200\201\345\222\226\345\225\241\345\216\205\342\200\246\342\200\246</p><p align=\"center\">YP\345\234\260\344\270\213\345\256\244\357\274\214\347\255\211\345\276\205\344\275\240\350\277\233\344\270\200\346\255\245\346\216\242\347\264\242</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Visitor: public Ui_Visitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITOR_H
