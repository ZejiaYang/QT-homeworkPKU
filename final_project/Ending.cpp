#include "Ending.h"
#include "ui_ending.h"

Ending::Ending(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ending)
{
    ui->setupUi(this);
    this->setWindowTitle("恭喜闯关成功！");
    QPixmap end_back = QPixmap(":/EndingMap/Endpage.png").scaled(ui->back_label->size(),Qt::KeepAspectRatio);
    ui->back_label->setPixmap(end_back);
    ui->back_label->lower();
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "background-color: rgb(176, 218, 246);"
                                  "color: rgb(1,77,103);"
                                  "font: 24px,'楷体';"
                                  "border-radius: 20px;"
                                  "border: 2px solid rgb(96, 143,159);"
                                  "border-style:outset;"
                                  "text-align: center;"
                                  "}"

                                  "QPushButton:hover{"                       // 鼠标浮动
                                              "background-color:rgb(255,213,255);"
                                              "color: rgb(255,0,0);"
                                              "font: 24px,'楷体';"
                                              "border-radius: 18px;"
                                              "border: 2px solid rgb(224, 150, 128);"
                                              "border-style:outset;"
                                              "text-align: center;"
                                              "}");
    ui->exitButton->setStyleSheet("QPushButton{"
                                  "background-color: rgb(176, 218, 246);"
                                  "color: rgb(1,77,103);"
                                  "font: 24px,'楷体';"
                                  "border-radius: 20px;"
                                  "border: 2px solid rgb(96, 143,159);"
                                  "border-style:outset;"
                                  "text-align: center;"
                                  "}"

                                  "QPushButton:hover{"                       // 鼠标浮动
                                              "background-color:rgb(255,213,255);"
                                              "color: rgb(255,0,0);"
                                              "font: 24px,'楷体';"
                                              "border-radius: 18px;"
                                              "border: 2px solid rgb(224, 150, 128);"
                                              "border-style:outset;"
                                              "text-align: center;"
                                              "}");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Ending::on_pushButton_clicked));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(Engding::on_exitButton_clicked));
    pass = 0;

    Intro1 = new QLabel(this);
    Intro1->setGeometry(40,70,385,68);
    QPixmap Intro_1(":/EndingMap/Intro1.png");
    Intro1->setPixmap(Intro_1);
    Intro2 = new QLabel(this);
    Intro2->setGeometry(30,170,393,42);
    QPixmap Intro_2(":/EndingMap/Intro2.png");
    Intro2->setPixmap(Intro_2);

    QGraphicsOpacityEffect *effect1 = new QGraphicsOpacityEffect(this);
    QGraphicsOpacityEffect *effect2 = new QGraphicsOpacityEffect(this);

    Intro1->setGraphicsEffect(effect1);
    Intro2->setGraphicsEffect(effect2);

    QPropertyAnimation *animation1 = new QPropertyAnimation(effect1, "opacity");
    QPropertyAnimation *animation2 = new QPropertyAnimation(effect2, "opacity");

    animation1->setDuration(1000);
    animation1->setStartValue(0.0);
    animation1->setEndValue(1.0);

    animation2->setDuration(1000);
    animation2->setStartValue(0.0);
    animation2->setEndValue(1.0);

    animation1->start();
    animation2->start();

    Intro1->show();
    Intro2->show();

}

Ending::~Ending()
{
    delete ui;
}

void Ending::on_exitButton_clicked(){
    close();
    pass = 1;
}

void Ending::on_pushButton_clicked(){
    close();
    pass = 2;
}
