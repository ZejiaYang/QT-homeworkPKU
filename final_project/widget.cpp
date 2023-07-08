#include "widget.h"

#include "ui_widget.h"
#include "mazegame.h"

#include<iostream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("重生之我要上北大"));
    setFixedSize(1280,720);

    QPixmap back_ground_3(":/MenuMap/Menu_map.png");
    QPixmap backg3Pixmap = back_ground_3.scaled(ui->back_ground_3->size());
    ui->back_ground_3->setPixmap(backg3Pixmap);
    ui->back_ground_3->hide();

    QPixmap back_ground_2(":/MenuMap/back_ground2.png");
    QPixmap backg2Pixmap = back_ground_2.scaled(ui->back_ground_2->size());
    ui->back_ground_2->setPixmap(backg2Pixmap);
    ui->back_ground_2->lower();

    QPixmap back_ground(":/MenuMap/back_ground.png");
    ui->back_ground->setPixmap(back_ground);
    ui->back_ground->setScaledContents(true);

    QPixmap I_am(":/MenuMap/Iam.png");
    QPixmap IamscaledPixmap = I_am.scaled(ui->Iam->size());
    ui->Iam->setPixmap(IamscaledPixmap);
    ui->Iam->hide();


    QPixmap Reset(":/MenuMap/Reset.png");
    QPixmap RscaledPixmap = Reset.scaled(ui->Reset->size());
    ui->Reset->setPixmap(RscaledPixmap);
    ui->Reset->hide();

    QPixmap PKU(":/MenuMap/PKU.png");
    QPixmap PKUPixmap = PKU.scaled(ui->PKU->size());
    ui->PKU->setPixmap(PKUPixmap);
    ui->PKU->setScaledContents(true);
    ui->PKU->hide();

    ui->pushButton->setStyleSheet("background-color: rgba(255, 217, 102, 100);"
                                  "border-image: url(:/MenuMap/Begin.png);"
                                  "border-radius: 18px;");
    ui->pushButton->setVisible(false);
    ui->pushButton->raise();

    ui->Intro1->hide();
    ui->Intro2->hide();
    ui->Intro3->hide();
    ui->Intro1_2->hide();
    ui->Intro3_2->hide();
    m = new mazegame();
    p = new push();
    q = new parkour_2();
    v = new Visitor();
    M = new MiniMazeGameWidgetIII();
    g = new gameview();
    e = new Ending();
    update_timer = new QTimer(this);
    update_timer->setInterval(500);
    connect(update_timer,&QTimer::timeout,this,&Widget::stars_update);

    //————播放音乐————
    QMediaPlayer *player = new QMediaPlayer(this);//设置背景音乐
    QMediaPlaylist *playerlist = new QMediaPlaylist(player);
    playerlist->addMedia(QUrl::fromUserInput("qrc:/Image/music_push.mp3"));
    playerlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playerlist);
    player->setVolume(70);//音量
    player->play();
}

void Widget::stars_update(){
    QPixmap star(":/MenuMap/star.png");
    if(m->pass == 1){
        delete Spot[0];
        Spot[0] = new QLabel(this);
        Spot[0]->setGeometry(spotpos[0][0],spotpos[0][1],50,50);
        Spot[0]->setPixmap(star.scaled(Spot[0]->size()));
        Spot[0]->show();
        m->pass = 2;
    }
    if(p->pass == 1){
        delete Spot[1];
        Spot[1] = new QLabel(this);
        Spot[1]->setGeometry(spotpos[1][0],spotpos[1][1],50,50);
        Spot[1]->setPixmap(star.scaled(Spot[1]->size()));
        Spot[1]->show();
        p->pass = 2;
    }
    if(g->pass == 1){
        delete Spot[2];
        Spot[2] = new QLabel(this);
        Spot[2]->setGeometry(spotpos[2][0],spotpos[2][1],50,50);
        Spot[2]->setPixmap(star.scaled(Spot[2]->size()));
        Spot[2]->show();
        g->pass = 2;
    }
    if(M->pass == 1){
        delete Spot[3];
        Spot[3] = new QLabel(this);
        Spot[3]->setGeometry(spotpos[3][0],spotpos[3][1],50,50);
        Spot[3]->setPixmap(star.scaled(Spot[3]->size()));
        Spot[3]->show();
        M->pass = 2;
    }
    if(q->pass == 1){
        delete Spot[4];
        Spot[4] = new QLabel(this);
        Spot[4]->setGeometry(spotpos[4][0],spotpos[4][1],50,50);
        Spot[4]->setPixmap(star.scaled(Spot[4]->size()));
        Spot[4]->show();
        q->pass = 2;
     }
    if(v->pass == 1){
        delete Spot[5];
        Spot[5] = new QLabel(this);
        Spot[5]->setGeometry(spotpos[5][0],spotpos[5][1],50,50);
        Spot[5]->setPixmap(star.scaled(Spot[5]->size()));
        Spot[5]->show();
        v->pass = 2;
     }
    if(M->pass == 2 && p->pass == 2
       && v->pass == 2 && p->pass == 2
       && m->pass == 2 && q->pass == 2){
        if(e->pass == 1){
            update_timer->stop();
            close();
        }else if(e->pass == 2){
            delete m;
            delete p;
            delete q;
            delete v;
            delete M;
            delete g;
            m = new mazegame();
            p = new push();//
            v = new Visitor(); //
            M = new MiniMazeGameWidgetIII();//
            g = new gameview();//
            q = new parkour_2();
            QPixmap Spotpic = QPixmap(":/MenuMap/spot.png");
            for(int i = 0; i < 6; i++){
               if(Spot[i])
                   delete Spot[i];
               Spot[i] = new QLabel(this);
               Spot[i]->setGeometry(spotpos[i][0],spotpos[i][1],40,53);
               Spot[i]->setPixmap(Spotpic.scaled(Spot[i]->size()));
               Spot[i]->show();
            }
        }else{
             e->show();
        }
        e->pass = 0;
    }
}
void Widget::mousePressEvent(QMouseEvent *event){
    if(!Intro_end){
    GraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->Reset);
    GraphicsOpacityEffect->setOpacity(0);
    ui->Reset->setGraphicsEffect(GraphicsOpacityEffect);
    Animation = new QPropertyAnimation(GraphicsOpacityEffect,"opacity",this);
    Animation->setEasingCurve(QEasingCurve::Linear);
    Animation->setDuration(1000);
    Animation->setEndValue(1.0);
    ui->Reset->show();
    Animation->start();

    QTimer *timer = new QTimer(this);
    int delayTime = 400; // 延迟时间为3秒
    QObject::connect(timer, &QTimer::timeout, [=]() {
        GraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->Iam);
        GraphicsOpacityEffect->setOpacity(0);
        ui->Iam->setGraphicsEffect(GraphicsOpacityEffect);
        Animation = new QPropertyAnimation(GraphicsOpacityEffect,"opacity",this);
        Animation->setEasingCurve(QEasingCurve::Linear);
        Animation->setDuration(1000);
        Animation->setEndValue(1.0);
        ui->Iam->show();
        Animation->start();
        timer->stop();
    });
    timer->start(delayTime);

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, [=]() {
        GraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->PKU);
        GraphicsOpacityEffect->setOpacity(0);
        ui->PKU->setGraphicsEffect(GraphicsOpacityEffect);
        Animation = new QPropertyAnimation(GraphicsOpacityEffect,"opacity",this);
        Animation->setEasingCurve(QEasingCurve::Linear);
        Animation->setDuration(1000);
        Animation->setEndValue(1.0);
        ui->PKU->show();
        Animation->start();
        timer->stop();
    });
    timer->start(delayTime + 1000);

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, [=]() {
        ui->pushButton->setVisible(true);
        timer->stop();
    });
    timer->start(delayTime + 2000);
    Intro_end = 1;
    }else if(page_two){
         if(Intro_begin == 0){
            ui->Intro1->show();
            QTimer *timer = new QTimer(this);
            QString text = "欢迎来到北京大学！成为PKU的一份子qwq";
            QVector<QChar>::const_iterator iter = text.constBegin(); // 获取迭代器

            QObject::connect(timer, &QTimer::timeout, [=]()mutable{
                if(iter != text.constEnd()){
                    ui->Intro1->setText(ui->Intro1->text() + *iter); // 逐个添加字符
                    ++iter;
                }
                else{
                    timer->stop();
                }
            });
            timer->start(100);
            Intro_begin++;
        }else if(Intro_begin == 1){
             ui->Intro2->show();
             QTimer *timer = new QTimer(this);
             QString text = "点击PKU地图上的地标，进入闯关任务！";
             QVector<QChar>::const_iterator iter = text.constBegin(); // 获取迭代器

             QObject::connect(timer, &QTimer::timeout, [=]()mutable{
                 if(iter != text.constEnd()){
                     ui->Intro2->setText(ui->Intro2->text() + *iter); // 逐个添加字符
                     ++iter;
                 }
                 else{
                     timer->stop();
                 }
             });
             timer->start(100);
             Intro_begin++;
        }else if(Intro_begin == 2){
             ui->Intro3->show();
             QTimer *timer = new QTimer(this);
             QString text = "快来和我们一起，开启有趣的未名之旅吧~"; //待完善
             QVector<QChar>::const_iterator iter = text.constBegin(); // 获取迭代器

             QObject::connect(timer, &QTimer::timeout, [=]()mutable{
                 if(iter != text.constEnd()){
                     ui->Intro3->setText(ui->Intro3->text() + *iter); // 逐个添加字符
                     ++iter;
                 }
                 else{
                     timer->stop();
                 }
             });
             timer->start(100);
             Intro_begin++;
        }else if(Intro_begin == 3){
             GraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->back_ground_3);
             GraphicsOpacityEffect->setOpacity(0);
             ui->back_ground_3->setGraphicsEffect(GraphicsOpacityEffect);
             Animation = new QPropertyAnimation(GraphicsOpacityEffect,"opacity",this);
             Animation->setEasingCurve(QEasingCurve::Linear);
             Animation->setDuration(500);
             Animation->setEndValue(1.0);
             Animation->start();
             ui->Intro1->hide();
             ui->Intro2->hide();
             ui->Intro3->hide();
             ui->back_ground_3->show();
             ui->Intro1_2->show();
             ui->Intro3_2->show();
             page_two = 0;
             page_three = 1;
             QPixmap Spotpic = QPixmap(":/MenuMap/spot.png");
             for(int i = 0; i < 6; i++){
                Spot[i] = new QLabel(this);
                Spot[i]->setGeometry(spotpos[i][0],spotpos[i][1],40,53);
                Spot[i]->setPixmap(Spotpic.scaled(Spot[i]->size()));
                Spot[i]->show();
             }
             update_timer->start();
         }
   }else if(page_three){
        QPoint pos = event->pos();
        QWidget* spotgame[6] = {m,p,g,M,q,v};
        for(int i = 0; i < 6; i++){
            if(pos.x() >= spotpos[i][0] - 10 && pos.x() <= spotpos[i][0] + 50
              && pos.y() >= spotpos[i][1] - 10 && pos.y() <= spotpos[i][1] + 63)
            {
                spotgame[i]->show();
                break;
            }
        }
    }
}

Widget::~Widget()
{
    delete ui;
    delete m;
    delete v;
    delete M;
    delete p;
    delete g;
    delete q;
}


void Widget::on_pushButton_clicked()
{
    if(Intro_end == 1){
    ui->Iam->hide();
    ui->Reset->hide();
    ui->PKU->hide();
    GraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->back_ground);
    GraphicsOpacityEffect->setOpacity(1);
    ui->back_ground->setGraphicsEffect(GraphicsOpacityEffect);
    Animation = new QPropertyAnimation(GraphicsOpacityEffect,"opacity",this);
    Animation->setEasingCurve(QEasingCurve::Linear);
    Animation->setDuration(500);
    Animation->setEndValue(0.0);
    Animation->start();
    ui->pushButton->setVisible(false);
    }
    page_two = 1;
}
