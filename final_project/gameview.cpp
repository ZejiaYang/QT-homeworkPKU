#include "gameview.h"
#include "ui_gameview.h"
#include<iostream>
using namespace std;

gameview::gameview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameview)
{
    ui->setupUi(this);
    setFixedSize(1280,720);
    this->setWindowTitle("家园食堂钢琴块");
    ui->Backg_Label->lower();
    QPixmap backgrd(":/WhiteBlockImage/dining_hall.png");
    QPixmap backgrdPixmap = backgrd.scaled(ui->Backg_Label->size(), Qt::KeepAspectRatio);
    ui->Backg_Label->setPixmap(backgrdPixmap);
    
    //设置游戏界面大小（400，600） 位置（120，60）
     QPixmap myPixmap(":/WhiteBlockImage/Rainbow.png");
    QPixmap scaledPixmap = myPixmap.scaled(ui->Image_Label->size());
    ui->Image_Label->setPixmap(scaledPixmap);

    //设置虚拟任务
    QPixmap NPC(":/WhiteBlockImage/bygg reverse(1).png");
    QPixmap NPCPixmap = NPC.scaled(ui->Bygg->size(), Qt::KeepAspectRatio);
    ui->Bygg->setPixmap(NPCPixmap);
    ui->Bygg->raise();

    ui->scoreLcd->setAlignment(Qt::AlignCenter);
    ui->scoreLcd->setFont(QFont("楷体",14));
    ui->scoreLcd->setText(QString("得分: ") + QString::number(score));
    ui->scoreLcd->setStyleSheet("background-color: rgb(199, 237, 233);"
                                "color: rgb(0,102,0);"
                                "border-radius: 18px;"
                                 "border: 2px solid rgb(179, 214, 110);"
                                 "border-style:outset;");

    ui->timeLcd->setAlignment(Qt::AlignCenter);
    ui->timeLcd->setFont(QFont("楷体",14));
    ui->timeLcd->setText(QString("时间: ") + QString::number(lasttime) + QString("s"));
    ui->timeLcd->setStyleSheet("background-color: rgb(199, 237, 233);"
                                "color: rgb(0,102,0);"
                                "border-radius: 18px;"
                                "border: 2px solid rgb(179, 214, 110);"
                                "border-style:outset;");
    ui->ExitButton->setStyleSheet( "QPushButton{"
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
    ui->Commence->setStyleSheet(
                "QPushButton{"
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
                            "}"

                );
    ui->Shutdown->setStyleSheet(
                "QPushButton{"
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
                            "}"

                );

    QPixmap Piano(":/WhiteBlockImage/piano.png");
    QPixmap Pianos = Piano.scaled(ui->pianoLabel1->size(), Qt::KeepAspectRatio);
    ui->pianoLabel1->setPixmap(Pianos);
    ui->pianoLabel2->setPixmap(Pianos);

    QPixmap Introgrd(":/WhiteBlockImage/Intro_background.png");
    QPixmap IntrogrdPixmap = Introgrd.scaled(ui->Intro_label->size(), Qt::KeepAspectRatio);
    ui->Intro_label->setPixmap(IntrogrdPixmap);
    ui->Intro_label2->lower();

    QPixmap Result1(":/WhiteBlockImage/result1.png");
    Result1Pixmap = Result1.scaled(ui->Result->size(), Qt::KeepAspectRatio);
    QPixmap Result2(":/WhiteBlockImage/result2.png");
    Result2Pixmap = Result2.scaled(ui->Result->size(), Qt::KeepAspectRatio);
    QPixmap Result3(":/WhiteBlockImage/result3.png");
    Result3Pixmap = Result3.scaled(ui->Result->size(), Qt::KeepAspectRatio);
    ui->Result->lower();

    timer = new QTimer(this);       //总计时器 控制时长
    timer->setInterval(1000);
    test_timer = new QTimer(this);  //自动更新界面 10ms一次

    connect(timer,&QTimer::timeout,this,&gameview::timeoutslot);
    connect(test_timer, &QTimer::timeout, this, &gameview::updategameview);

    ui->Intro_writing2->lower();
    ui->Intro_writing3->setStyleSheet("background-color: rgba(244, 177, 131, 200);"
                                      "border-radius: 18px;"
                                      "border: 2px solid rgb(224, 150, 128);"
                                      "border-style:outset;");
    ui->Intro_writing3->lower();

    QPixmap Pass = QPixmap(":/WhiteBlockImage/pass.png").scaled(ui->Intro_writing4->size(),Qt::KeepAspectRatio);
    ui->Intro_writing4->lower();
    ui->Intro_writing4->setPixmap(Pass);
    Gamebegin = false; //和开关关联
    Intro_over = 0;
    Count = 0;
    Gameoverstate = 0;
    _step = 150;
    pass = 0;

}

//获取键盘事件 
void gameview::keyPressEvent(QKeyEvent *event)
{
    int lose = -1;
    int size = blockdeque.size();
    if(event->key() == Qt::Key_A){
        if(blockdeque[size - 1]->isBlack())
            lose = 1;
        else
            lose= 0;
    }else if(event->key() == Qt::Key_S){
        if(blockdeque[size - 2]->isBlack())
            lose = 1;
        else
            lose= 0;
    }else if(event->key() == Qt::Key_D){
        if(blockdeque[size - 3]->isBlack())
            lose = 1;
        else
            lose= 0;
    }else if(event->key() == Qt::Key_F){
        if(blockdeque[size - 4]->isBlack())
            lose = 1;
        else
            lose= 0;
    }
    if(lose == 1){
        for(int j = 0; j < 4; j++)
       {
           delete blockdeque.back();
           blockdeque.pop_back();
        }
        score++;
      if(score % 10 == 0)
          step += 0.5;
    }else if(lose == 0){
        test_timer->stop();
        timer->stop();
        Gameoverstate = 1; //wrong_answer
        cout << "LOSE!" << endl;
        gameover();
    }
}


int gameview::Is_success(QPoint pos){
    for(int i = 0; i < 5; i++){
        if(pos.x() >= Wrong_dishes[i][0] && pos.x() <= Wrong_dishes[i][2]
           && pos.y() >= Wrong_dishes[i][1] && pos.y() <= Wrong_dishes[i][3]){
            if(Is_choose[i] == 1)
                return 2;
            else{
                Is_choose[i] = 1;
                return 1;
            }
        }
    }
    return 0;
}

//获得鼠标点击事件  判断坐标点位置
void gameview::mousePressEvent(QMouseEvent *event)
{
    //背景介绍 以及另一个游戏的开始
    if(Intro_over == 0){
        ui->Intro_writing->hide();
        ui->Intro_writing2->raise();
        Intro_over = 1;
    }else if(Intro_over == 1){
        ui->Intro_writing2->hide();

        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->Bygg, "geometry");
        animation1->setDuration(800);
        animation1->setStartValue(ui->Bygg->geometry());
        animation1->setEndValue(QRect(ui->Bygg->x() + 400, ui->Bygg->y(), ui->Bygg->width(), ui->Bygg->height()));
        animation1->setEasingCurve(QEasingCurve::InOutQuad);

        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
        ui->Intro_label2->setGraphicsEffect(effect); // 将 QGraphicsOpacityEffect 控件嵌入到标签中
        ui->Intro_writing3->setGraphicsEffect(effect);

        // 创建属性动画对象，控制 QGraphicsOpacityEffect 控件的不透明度
        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(400); // 动画时长为2000ms
        animation->setStartValue(1.0); // 初始值为1.0，即完全不透明
        animation->setEndValue(0.0); // 结束值为0.0，即完全透明

        QPixmap Introgrd2(":/WhiteBlockImage/Intro_dishes.png");
        QPixmap Introgrd2Pixmap = Introgrd2.scaled(ui->Intro_label->size(), Qt::KeepAspectRatio);
        ui->Intro_label->lower();
        ui->Intro_label2->raise();
        ui->Bygg->raise();
        ui->Intro_label2->setPixmap(Introgrd2Pixmap);
        ui->Intro_writing3->raise();
        animation->setStartValue(0.0); // 初始值为0.0，即完全透明
        animation->setEndValue(1.0); // 结束值为1.0，即完全不透明
        animation->start(); // 启动属性动画
        animation1->start(QAbstractAnimation::KeepWhenStopped);

        Intro_over = 2;

    }else if(Intro_over == 2){
        ui->Intro_writing3->hide();
        Intro_over = 3;
    }else if(Intro_over == 3){
         QPoint pos = event->pos();
         QLabel *label = new QLabel(this);
         judge.push_back(label);
         label->setStyleSheet("background-color:transparent;border:none;");
         label->setFixedSize(120, 120);
         label->setGeometry(pos.x() - 60, pos.y() - 60,120, 120);
         QPixmap right(":/WhiteBlockImage/Yes.png");
         QPixmap wrong(":/WhiteBlockImage/No.png");
         QPropertyAnimation *animation = new QPropertyAnimation(label, "windowOpacity");
         animation->setDuration(2000); // 动画时长为1000ms
         animation->setStartValue(0.0); // 初始值为1.0，即完全不透明
         animation->setEndValue(1.0); // 结束值为0.0，即完全透明
         connect(animation, &QPropertyAnimation::finished, [=]() {
             label->deleteLater(); // 动画结束后，删除标签控件
         });
          if (Is_success(pos) == 1) {
              label->setPixmap(right);
              label->show();
              Count++;
          }
          else if(Is_success(pos) == 0){
              label->setPixmap(wrong);
              label->show();
              animation->start(); // 启动属性动画
              judge.pop_back();
          }

          if(Count == 5){
              QPropertyAnimation *animation1 = new QPropertyAnimation(ui->Bygg, "geometry");
              animation1->setDuration(800);
              animation1->setStartValue(ui->Bygg->geometry());
              animation1->setEndValue(QRect(ui->Bygg->x() - 400, ui->Bygg->y(), ui->Bygg->width(), ui->Bygg->height()));
              animation1->setEasingCurve(QEasingCurve::InOutQuad);
              animation1->start(QAbstractAnimation::KeepWhenStopped);
              ui->Bygg->raise();
              QLabel *pass_label = new QLabel(this);
              judge.push_back(pass_label);
              pass_label->setStyleSheet("color: rgb(255,0,0);"
                                        "font: 30px,'华文琥珀';");
              pass_label->setText("恭喜通关！不愧是合格干饭人！");
              pass_label->adjustSize();
              pass_label->setGeometry(850,500,pass_label->width(),label->height());
              pass_label->show();
              Intro_over = 4;
          }

    }else if(Intro_over == 4){
        int n = judge.size();
        for(int i = 0; i < n; i++)
            judge[i]->deleteLater();//删除标签控件

        m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->Intro_label2);
        m_pGraphicsOpacityEffect->setOpacity(1);
        ui->Intro_label2->setGraphicsEffect(m_pGraphicsOpacityEffect);

        m_pNameAnimation = new QPropertyAnimation(m_pGraphicsOpacityEffect,"opacity",this);
        m_pNameAnimation->setEasingCurve(QEasingCurve::Linear);
        m_pNameAnimation->setDuration(1000);
        m_pNameAnimation->setEndValue(0.0);
        m_pNameAnimation->start();

        QTimer *timer = new QTimer(this);
        int delayTime = 1000; // 延迟时间为3秒
        QObject::connect(timer, &QTimer::timeout, [=]() {
            ui->Intro_label2->hide();
        });
        timer->start(delayTime);
        Intro_over = 5;
    }


    //Whiteblock游戏的开始
    if(!Gamebegin)
        return;
    //根据坐标点 从队列获取块
    int row = event->y();
    int col = event->x();
    int size = blockdeque.size() ;
    for(int i = 1; i < 5; i++){
        if(blockdeque[size - i]->isBlack()){
            cout << "!" << endl;
            Block* temp = blockdeque[size - i];
            if(row >= temp->height - 15 && row <= temp->height + 135
               && col >= temp->width - 15 && col <= temp->width + 95){ //放宽松一些
                  score++;
                if(score % 10 == 0)
                    step += 0.1;
                for(int j = 0; j < 4; j++)
               {
                   delete blockdeque.back();
                   blockdeque.pop_back();
                }
            }else{
                test_timer->stop();
                timer->stop();
                Gameoverstate = 1; //wrong_answer
                gameover();
            }
            break;
        }
    }
}

void gameview::updategameview()//更新界面
{
    if(lasttime == 0){
        Gameoverstate = 2; //ACCEPT
        test_timer->stop();
        timer->stop();
        gameover();
    }
    if(_step >= 150){
        int idex = generateRandomNumber();
        for(int i = 0; i < 4; i++)
        {
            Block* block;
            if(idex == i)
            {
                block = blueFactory.CreateBlock(this,135 + i*100,-90);
                block->show();//显示色块
            }
            else
            {
                int n = generateRandomNumber();
                suprise += n;
                block = whiteFactory.CreateBlock(this,135 +i*100,-90,suprise%3 + 1);
                block->show();
            }
            block->move(130 + i*103, -90);
            blockdeque.insert(blockdeque.begin(),block);
        }
        _step = 0;
    }
    int size = blockdeque.size();
    if(size){
        for(int i = 0; i < size; i++)
        {
            blockdeque.at(i)->down(step);
            blockdeque.at(i)->height += step;
        }
        if(blockdeque.at(size - 1)->height >= 512){
            cout << "LOSE!" << endl;
            test_timer->stop();
            timer->stop();
            Gameoverstate = 3; // TL
            gameover();
        }
    }
    ui->scoreLcd->setText(QString("得分: ") + QString::number(score));
    _step += step;
}

void gameview::gameover()
{
    Gamebegin = false;
    if(Gameoverstate == 1){ //wrong
        ui->Result->setPixmap(Result1Pixmap);
    }else if(Gameoverstate == 2){ //Acc
        ui->Result->setPixmap(Result2Pixmap);
    }else{
        ui->Result->setPixmap(Result3Pixmap);
    }
    ui->Result->raise();
    QPropertyAnimation *animation = new QPropertyAnimation(ui->Result, "geometry");
    animation->setDuration(800);
    animation->setStartValue(ui->Result->geometry());
    animation->setEndValue(QRect(ui->Result->x(), ui->Result->y() + 190, ui->Result->width(), ui->Result->height()));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::KeepWhenStopped);
    if(score >= 90){
        ui->Intro_writing4->raise();
        tpass = 1;
    }
}

void gameview::resetgame()//重置
{
    ui->Intro_writing4->lower();
    ui->Result->lower();
    ui->Result->move(ui->Result->x(), ui->Result->y() - 190);
    score = 0;
    step = 2;
    lasttime = 50;
    ui->scoreLcd->setText(QString("得分: ") + QString::number(score));
    ui->timeLcd->setText(QString("时间: ") + QString::number(lasttime) + QString("s"));
    int size = blockdeque.size();
    for(int i =  0; i < size; i++)
    {
       delete blockdeque.back();
       blockdeque.pop_back();
    }
}

int gameview::generateRandomNumber() //生成随机数
{
    int randn;
    QTime time = QTime::currentTime();
    qsrand(time.msec()*qrand()*qrand()*qrand()*qrand());//初始化随机数种子
    randn = qrand()%4; //生成0 - 3 之间的随机数
    return randn;
}

gameview::~gameview()
{
    delete ui;
}


void gameview::on_Commence_clicked()
{
    if(Gameoverstate)
        resetgame();
    timer->start();//开始
    test_timer->start(10);
//    player->play();
    Gamebegin = true;
    Gameoverstate = 0;
}


void gameview::on_Shutdown_clicked()
{
    timer->stop();
    test_timer->stop();
    Gamebegin = false;
}

void gameview::timeoutslot(){
    lasttime -= 1;
    ui->timeLcd->setText(QString("时间: ") + QString::number(lasttime) + QString("s"));
}

void gameview::on_ExitButton_clicked()
{
    close();
    if(tpass == 1)
        pass = 1;
}
