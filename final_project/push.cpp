#include "push.h"
#include "ui_push.h"
#include<QFileDialog>//用文件对话框去取
#include<QPainter>
#include<QMessageBox>
#include<QKeyEvent>
#include<QtDebug>
#include<QTimer>
#include<QBrush>
#include <QPainter>
#include <cmath>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QTimer>
#include <QKeyEvent>
#include<QMediaPlayer>
#include <QToolButton>
#include<QPropertyAnimation>
push::push(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::push)
{
    //初始化地图元素
    ui->setupUi(this);
    show_intro();
    show_NPC();
    show_introWords();
    ui->end_page_label->hide();//如果有的话，直接绑定
    ui->PlayerLabel->hide();


    mPMap=new GameMap(this);
    QString filename=":/Map/lv1.txt";
    mPMap->InitByFile(filename);


    mMapPainter=new QPainter(this);//创建画家
    mRole=new Role(this);
    mTimer=new QTimer(this);
    mTimer->start(50);//更新频率100ms
    //定时器绑定更新
    connect(mTimer,&QTimer::timeout,[this](){    this->update();});
    setFixedSize(1280,720);//调整窗口大小


    totalRadius = 600;
    endBtn  = new QPushButton(this);
    endBtn->setText(tr("结束游戏"));
    endBtn->setFont(QFont(tr("宋体"),12));
    endBtn->setGeometry(totalRadius+230,640,120,40);//设置加载位置
    connect(endBtn,SIGNAL(clicked(bool)),
            this,SLOT(quitClick()));

    changeBtn  = new QPushButton(this);
    changeBtn->setText(tr("一键换装"));
    changeBtn->setFont(QFont(tr("宋体"),12));
    changeBtn->setGeometry(totalRadius+90,640,120,40);//设置加载位置
    connect(changeBtn,SIGNAL(clicked(bool)),
            this,SLOT(changeClick()));
    changeflag=1;
    close_flag=1;
    pass = 0;
    tpass = 0;
}
void push::quitClick(){
    this->close();
    if(tpass)
        pass = 1;
}
void push::changeClick(){
    if(changeflag){
    mRole->mImg=QImage(":/Image/peopleend.png");
    mRole->mImg=mRole->mImg.scaled(40,40);
    changeflag--;
    }
    else{

        changeflag++;
        mRole->mImg=QImage(":/Image/people_push.png");
        mRole->mImg=mRole->mImg.scaled(40,40);
    }

}
void push::show_intro()
{
    int i = (WINDOW_WIDTH-INTRO_WIDTH)/2;
    int j = (WINDOW_HEIGHT-INTRO_HEIGHT)/2;
    ui->scrollLabel->setGeometry(i,j,INTRO_WIDTH,INTRO_HEIGHT);
    QPixmap scr(":/Image/scroll_push.png");
    scr = scr.scaled(ui->scrollLabel->size(), Qt::KeepAspectRatio);
    ui->scrollLabel->setPixmap(scr);
    //以下为卷轴的动画
    QPropertyAnimation *intro_animation = new QPropertyAnimation(ui->scrollLabel, "geometry");
    intro_animation->setDuration(INTRO_APPEAR_TIME);  // Animation duration in milliseconds
    intro_animation->setStartValue(QRect(1280,j,
                             INTRO_WIDTH,INTRO_HEIGHT));
    intro_animation->setEndValue(QRect(i,j,INTRO_WIDTH,INTRO_HEIGHT));
    intro_animation->start();
}

void push::show_NPC()
{
    ui->NPCLabel->raise();
    ui->NPCLabel->setGeometry(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT);
    QPixmap npc(":/Image/bygg_push.png");
    npc = npc.scaled(ui->NPCLabel->size(), Qt::KeepAspectRatio);
    ui->NPCLabel->setPixmap(npc);

    QPropertyAnimation *NPC_animation = new QPropertyAnimation(ui->NPCLabel, "geometry");
    NPC_animation->setDuration(NPC_APPEAR_TIME);  // Animation duration in milliseconds
    NPC_animation->setStartValue(QRect(NPC_POS_X,720,
                             NPC_WIDTH,NPC_HEIGHT));
    NPC_animation->setEndValue(QRect(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT));
    NPC_animation->start();
}

void push::show_introWords()
{
    ui->IntroLabel->raise();
    ui->IntroLabel->setGeometry(WORDS_POS_X,WORDS_POS_Y,80,60);
    ui->IntroLabel->setText("            欢迎来到图书馆，\n"
                            "          唯谈笑可以遣平生，\n"
                            "          唯文词可以陈心赏，\n"
                            "          一塔湖图\n"
                            "          静谧的自习环境\n"
                            "         能否帮助你顺利debug\n"
                            "           加油小狮子！\n\n"
                            "      按 任意键 开始游戏。\n");
    ui->IntroLabel->setFont(QFont("华文新魏", 28));
    ui->IntroLabel->setStyleSheet("color: white");
    QPropertyAnimation *words_animation = new QPropertyAnimation(ui->IntroLabel, "geometry");
    words_animation->setDuration(WORDS_APPEAR_TIME);  // Animation duration in milliseconds
    words_animation->setStartValue(QRect(120,WORDS_POS_Y,80,60));
    words_animation->setEndValue(QRect(WORDS_POS_X,WORDS_POS_Y,800,600));
    words_animation->start();
}
void push::endWords()
{
    ui->IntroLabel->raise();
    ui->IntroLabel->setGeometry(WORDS_POS_X,WORDS_POS_Y,80,60);
    ui->IntroLabel->setText("            欢迎来到图书馆，\n"
                            "          唯谈笑可以遣平生，\n"
                            "          唯文词可以陈心赏，\n"
                            "          一塔湖图\n"
                            "          静谧的自习环境\n"
                            "         能否帮助你顺利debug\n"
                            "           加油小狮子！\n\n"
                            "      按 任意键 开始游戏。\n");
    ui->IntroLabel->setFont(QFont("华文新魏", 28));
    ui->IntroLabel->setStyleSheet("color: white");
    QPropertyAnimation *words_animation = new QPropertyAnimation(ui->IntroLabel, "geometry");
    words_animation->setDuration(WORDS_APPEAR_TIME);  // Animation duration in milliseconds
    words_animation->setStartValue(QRect(120,WORDS_POS_Y,80,60));
    words_animation->setEndValue(QRect(WORDS_POS_X,WORDS_POS_Y,800,600));
    words_animation->start();
}

void push::close_all_intro()
{
    if(intro_already_closed==1){intro_already_closed=0;return;}
    intro_already_closed = 1;

    QPropertyAnimation *words_close_animation = new QPropertyAnimation(ui->IntroLabel, "geometry");
    words_close_animation->setDuration(WORDS_APPEAR_TIME);  // Animation duration in milliseconds
    words_close_animation->setEndValue(QRect(1280,WORDS_POS_Y,800,600));
    words_close_animation->setStartValue(QRect(WORDS_POS_X,WORDS_POS_Y,800,600));
    words_close_animation->start();

    QPropertyAnimation *NPC_close_animation = new QPropertyAnimation(ui->NPCLabel, "geometry");
    NPC_close_animation->setDuration(NPC_APPEAR_TIME);  // Animation duration in milliseconds
    NPC_close_animation->setEndValue(QRect(NPC_POS_X,720,
                             NPC_WIDTH,NPC_HEIGHT));
    NPC_close_animation->setStartValue(QRect(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT));
    NPC_close_animation->start();

    int i = (WINDOW_WIDTH-INTRO_WIDTH)/2;
    int j = (WINDOW_HEIGHT-INTRO_HEIGHT)/2;
    QPropertyAnimation *intro_close_animation = new QPropertyAnimation(ui->scrollLabel, "geometry");
    intro_close_animation->setDuration(INTRO_APPEAR_TIME);  // Animation duration in milliseconds
    intro_close_animation->setEndValue(QRect(1280,j,
                             INTRO_WIDTH,INTRO_HEIGHT));
    intro_close_animation->setStartValue(QRect(i,j,INTRO_WIDTH,INTRO_HEIGHT));
    intro_close_animation->start();
}
push::~push()
{

    delete ui;
}
void push::paintEvent(QPaintEvent *event)
{
    mMapPainter->begin(this);//设置画布

    //画背景
    QPainter bgPainter;
    QString imgurl;
    imgurl=":/Image/ground.png";
    QImage img(imgurl);
    mMapPainter->drawImage(QRect(0,0,1280,720),img);

    //绘制任务
    QString byggurl;
    byggurl=":/Image/bygg_push.png";
    QImage img2(byggurl);
    img2=img2.scaled(1106,1476);
    mMapPainter->drawImage(QRect(860,180,419,560),img2);
     show_exit();
    //画地图
    mPMap->Paint(mMapPainter,QPoint(120,90));//传位置

    //画人物化郭炜
    mRole->Paint(mMapPainter,QPoint(120,90));//可以自己做偏移

    mMapPainter->end();//结束

}
void push::keyPressEvent(QKeyEvent*event)
{
    if(close_flag){
    close_all_intro();
    ui->PlayerLabel->show();
    close_flag--;//只关一次
    }
    if(GameOver()){
       close_all_intro();
    }
    if(!GameOver()){
    switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_Up:
    {
        //逻辑判断函数
        Collision(-1,0);
        break;
    }
    case Qt::Key_S:
    case Qt::Key_Down:{
        Collision(1,0);
        break;
    }
    case Qt::Key_A:
    case Qt::Key_Left:{
        Collision(0,-1);
        break;
    }
    case Qt::Key_D:
    case Qt::Key_Right:{
        Collision(0,1);
        break;
    }
    }}
}
bool push::GameOver(){
    for(int i=0;i<mPMap->mRow;i++){
        for(int j=0;j<mPMap->mCol;j++){
            if(mPMap->mPArr[i][j]==Point)
                return false;
        }
    }
    return true;
}
int playflag=0;
void push::show_exit(){
    if(!GameOver())return;
    qDebug()<<"游戏结束";
    int i = (WINDOW_WIDTH-INTRO_WIDTH)/2;
    int j = (WINDOW_HEIGHT-INTRO_HEIGHT)/2;
    ui->scrollLabel->setGeometry(i,j,INTRO_WIDTH,INTRO_HEIGHT);
    QPixmap scr(":/Image/close.png");
    scr = scr.scaled(ui->scrollLabel->size(), Qt::KeepAspectRatio);
    ui->scrollLabel->setPixmap(scr);
    if(playflag==0){++playflag;
    QMediaPlayer *player1 = new QMediaPlayer(this);//设置背景音乐
    player1->setMedia(QUrl("qrc:/Image/end.wav"));
    player1->setVolume(100);//音量
    player1->play();
    tpass = 1;
    }
}

void push::Collision(int _dRow, int _dCol)
{
    //判断位置
    int newRow=mRole->mRow+_dRow;
    int newCol=mRole->mCol+_dCol;

    if(mPMap->mPArr[newRow][newCol]==Wall||mPMap->mPArr[newRow][newCol]==Wall1){//判断是墙
        return ;
    }
    else if(mPMap->mPArr[newRow][newCol]==Box){

        //定义箱子前方
        if(mPMap->mPArr[newRow+_dRow][newCol+_dCol]==Road){
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol+_dCol]=Box;
            mPMap->mPArr[newRow][newCol]=Road;
        }
        else if(mPMap->mPArr[newRow+_dRow][newCol+_dCol]==Point){
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol+_dCol]=InPoint;//箱子前方编程进目标点
            mPMap->mPArr[newRow][newCol]=Road;
        }
        else{
            return;//无法推动,包含了前面是墙的情况
        }
    }
    else if(mPMap->mPArr[newRow][newCol]==InPoint){//前方是进目标点(二者重合)
        //定义箱子前方
        if(mPMap->mPArr[newRow+_dRow][newCol+_dCol]==Road){
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol+_dCol]=Box;
            mPMap->mPArr[newRow][newCol]=Point;
        }
        else if(mPMap->mPArr[newRow+_dRow][newCol+_dCol]==Point){
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol+_dCol]=InPoint;//箱子进点
            mPMap->mPArr[newRow][newCol]=Point;
        }
        else{
            return;//无法推动,包含了前面是墙的情况
        }
    }
    //直接在collision中实现移动
    mRole->Move(_dRow,_dCol);
    //这里调用一个游戏结束
    show_exit();
}



void push::on_label_linkActivated(const QString &link)
{
}

void push::on_pushButton_clicked()
{
    this->close();
    if(tpass)
        pass = 1;
}
