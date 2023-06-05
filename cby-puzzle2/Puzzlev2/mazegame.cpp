#include "mazegame.h"
#include "ui_mazegame.h"
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
#include <QToolButton>
#include<QPropertyAnimation>

mazegame::mazegame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mazegame)
{
    ui->setupUi(this);
    show_intro();
    show_NPC();
    show_introWords();
    ui->end_page_label->hide();//如果有的话，直接绑定
    ui->PlayerLabel->hide();


    mm = ss = 0;
    isStart = true;
    totalRadius = 600;
    width = 3;
    height = 3;
    stepCount = 0;
    radius = totalRadius/width;
    win = false;

    map = new PuzzlePart*[height];//这应是暴露出来的接口？？大概，我白天没看到你们是用什么绑定上了罗哥的游戏

    for(int i = 0;i<height;i++){
        map[i] = new PuzzlePart[width];
        for(int j = 0;j<width;j++){
            map[i][j].rect = QRect(radius*j,radius*i,radius,radius);
            map[i][j].partId = i*width+j;
            map[i][j].row = i;
            map[i][j].col = j;
        }
    }

    /*这个函数用来打乱顺序*/
    orderBroken();
    update();

    this->setFixedSize(1280,720);//可以在这里绘制

    //这部分删了还异常输出不知道为什么
    QString fileName = tr(":/image/2.jpg");

    img = new QImage;
    img->load(fileName);
    *img = img->scaled(600,600,
                       Qt::IgnoreAspectRatio);

//    btn  = new QPushButton(this);
//    btn->setText(tr("选择图片"));
//    btn->setFont(QFont(tr("宋体"),12));
//    btn->setGeometry(totalRadius+80,20,120,40);
//    connect(btn,SIGNAL(clicked(bool)),/*关联函数*/
//            this,SLOT(onBtnClicked()));

    //ui绘图，衔接着对应的button逻辑
    startBtn  = new QPushButton(this);
    startBtn->setText(tr("开始"));
    startBtn->setFont(QFont(tr("宋体"),12));
    startBtn->setGeometry(totalRadius+100,640,120,40);//设置加载位置

    endBtn  = new QPushButton(this);
    endBtn->setText(tr("结束游戏"));
    endBtn->setFont(QFont(tr("宋体"),12));
    endBtn->setGeometry(totalRadius+220,640,120,40);//设置加载位置
    //20-400

        //难度level
//    diffLevel = new QSpinBox(this);
//    diffLevel->setGeometry(totalRadius+160,460,120,30);//460-380=80
//    diffLevel->setMinimum(3);
//    diffLevel->setMaximum(10);
//    diffLevel->setFont(QFont(tr("宋体"),12));
//    diffLevel->setAlignment(Qt::AlignHCenter);

//    connect(diffLevel,SIGNAL(valueChanged(int)),
//            this,SLOT(onSpinBoxValueChanged(int)));

    curStepCount = new QLineEdit(this);
    curStepCount->setGeometry(totalRadius+430,20,120,40);//510-380=130
    curStepCount->setText(tr("0步"));
    curStepCount->setEnabled(false);
    curStepCount->setAlignment(Qt::AlignHCenter);
    curStepCount->setFont(QFont(tr("宋体"),12));


    QLabel *curStepCountText = new QLabel(this);
    curStepCountText->setGeometry(totalRadius+320,30,100,30);//525-380=145
    curStepCountText->setText(tr("步数:"));
    curStepCountText->setAlignment(Qt::AlignHCenter);
    curStepCountText->setFont(QFont(tr("宋体"),12));


//    QLabel *diffLevelText = new QLabel(this);
//    diffLevelText->setGeometry(totalRadius+50,465,100,40);//465-380=85
//    diffLevelText->setText(tr("难度:"));
//    diffLevelText->setAlignment(Qt::AlignHCenter);
//    diffLevelText->setFont(QFont(tr("宋体"),12));

    QLabel *timeText = new QLabel(this);
    timeText->setGeometry(totalRadius+50,30,100,30);//580-380=200
    timeText->setText(tr("时间:"));
    timeText->setAlignment(Qt::AlignHCenter);
    timeText->setFont(QFont(tr("宋体"),12));

    timeLineEdit = new QLineEdit(this);
    timeLineEdit->setGeometry(totalRadius+160,20,120,40);//570-380=190
    timeLineEdit->setText(tr("00:00"));
    timeLineEdit->setEnabled(false);
    timeLineEdit->setAlignment(Qt::AlignHCenter);
    timeLineEdit->setFont(QFont(tr("宋体"),12));


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(onTimeOutSlot()));

    connect(startBtn,SIGNAL(clicked(bool)),
            this,SLOT(onStartBtnClicked()));
    connect(endBtn,SIGNAL(clicked(bool)),
            this,SLOT(onEndBtnClicked()));
    this->setFocus();
}

mazegame::~mazegame()
{
    delete ui;
    //release resource of space.
    for(int i = 0;i<height;i++){
        delete[] map[i];
    }
    delete[] map;

    delete img;
    delete btn;
    delete diffLevel;
    delete curStepCount;
    delete timeLineEdit;
    delete timer;
    delete startBtn;
}

void mazegame::show_intro()
{
    int i = (WINDOW_WIDTH-INTRO_WIDTH)/2;
    int j = (WINDOW_HEIGHT-INTRO_HEIGHT)/2;
    ui->scrollLabel->setGeometry(i,j,INTRO_WIDTH,INTRO_HEIGHT);
    QPixmap scr(":/image/scroll.png");
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

void mazegame::show_NPC()
{
    ui->NPCLabel->raise();
    ui->NPCLabel->setGeometry(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT);
    QPixmap npc(":/image/bygg.png");
    npc = npc.scaled(ui->NPCLabel->size(), Qt::KeepAspectRatio);
    ui->NPCLabel->setPixmap(npc);

    QPropertyAnimation *NPC_animation = new QPropertyAnimation(ui->NPCLabel, "geometry");
    NPC_animation->setDuration(NPC_APPEAR_TIME);  // Animation duration in milliseconds
    NPC_animation->setStartValue(QRect(NPC_POS_X,720,
                             NPC_WIDTH,NPC_HEIGHT));
    NPC_animation->setEndValue(QRect(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT));
    NPC_animation->start();
}

void mazegame::show_introWords()
{
    ui->IntroLabel->raise();
    ui->IntroLabel->setGeometry(WORDS_POS_X,WORDS_POS_Y,80,60);
    ui->IntroLabel->setText("            欢迎来到湖区，\n"
                            "          水光潋滟晴方好，\n"
                            "   不知这里能否勾起你美好的回忆\n"
                            "          八数码问题\n"
                            "          等你来解\n"
                            "       看你如何走出这湖区\n\n\n"
                            "      按 任意键 开始游戏。\n");
    ui->IntroLabel->setFont(QFont("华文新魏", 28));
    ui->IntroLabel->setStyleSheet("color: white");
    QPropertyAnimation *words_animation = new QPropertyAnimation(ui->IntroLabel, "geometry");
    words_animation->setDuration(WORDS_APPEAR_TIME);  // Animation duration in milliseconds
    words_animation->setStartValue(QRect(120,WORDS_POS_Y,80,60));
    words_animation->setEndValue(QRect(WORDS_POS_X,WORDS_POS_Y,800,600));
    words_animation->start();
}

void mazegame::close_all_intro()
{
    if(intro_already_closed)return;
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


void mazegame::paintEvent(QPaintEvent *)
{
    QPainter p(this);//自带画家
//    QPainter* mMapPainter;
//    mMapPainter->begin(this);

    QString imgurl;
    imgurl=":/image/ground2.png";//画不出来背景为什么？
    QImage img1(imgurl);
    p.drawImage(QRect(0,0,1280,720),img1);


    //绘制任务
    QString byggurl;
    byggurl=":/image/bygg.png";
    QImage img2(byggurl);
    img2=img2.scaled(1106,1476);
    p.drawImage(QRect(860,180,419,560),img2);

//     mMapPainter->end(


    p.setBrush(Qt::white);

    p.setPen(QPen(Qt::white,5, Qt::SolidLine));
    p.setFont(QFont("宋体", radius*0.6));

    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
           map[i][j].drawPart(p,img);
        }
    }


//    p.drawImage(totalRadius+50,totalRadius-350,
//                img->scaled(300,300,Qt::IgnoreAspectRatio),
//                0,0,300,300);//绘制答案图

    if(checkGameOver()&&!win){
        win = true;
        QMessageBox::warning(this,tr("Congratulations!"),tr("You Win!"),QMessageBox::Retry);
    }
}

void mazegame::keyPressEvent(QKeyEvent *keyevent)
{
    close_all_intro();
    ui->PlayerLabel->show();
}
void mazegame::onSpinBoxValueChanged(int value)
{
    stepCount = 0;
    curStepCount->setText(tr("%1步").arg(stepCount));
    startBtn->setText(tr("开始"));
    if(isStart == false){
        timer->stop();
        timeLineEdit->setText(tr("00:00"));
        isStart = true;
    }
    //释放资源
    for(int i = 0;i<height;i++){
        delete[] map[i];
    }
    delete[] map;
    mm = ss = 0;

    width = height = value;
    radius = totalRadius/width;

    map = new PuzzlePart*[height];

    for(int i = 0;i<height;i++){
        map[i] = new PuzzlePart[width];
        for(int j = 0;j<width;j++){
            map[i][j].rect = QRect(radius*j,radius*i,radius,radius);
            map[i][j].partId = i*width+j;
            map[i][j].row = i;
            map[i][j].col = j;
        }
    }
    orderBroken();
    update();
}

void mazegame::onTimeOutSlot()
{
    ss++;
    if(ss >= 60){
        ss = 0;
        mm++;
    }
    QString str;
    str = str.sprintf("%02d:%02d",mm,ss);
    //QMessageBox::warning(this,tr("Error!"),str,QMessageBox::Retry);
    timeLineEdit->setText(str);
}

void mazegame::onStartBtnClicked()
{
    if(isStart){
        timer->start(1000);
        startBtn->setText(tr("暂停"));
    }
    else{
        timer->stop();
        startBtn->setText(tr("继续"));
    }
    isStart = isStart != true;

}
void mazegame::onEndBtnClicked(){
    this->close();
}

void mazegame::orderBroken()
{
    //循环width*height次，随机交换两个块使得其无序
    int x1,y1,x2,y2;
    for(int i = 0;i<width*height;i++){
        x1 = rand()%width;
        x2 = rand()%width;
        y1 = rand()%height;
        y2 = rand()%height;

        PuzzlePart temp;
        temp = map[y1][x1];
        map[y1][x1] = map[y2][x2];
        map[y2][x2] = temp;
    }
}

void mazegame::click(QPoint pt)
{
    if(radius == 0)
        return;
    int y = pt.y()/radius;
    int x = pt.x()/radius;
    if(!checkRange(y,x))
        return;
    //左 右 下 上
    int cells[4][2] = {0,-1,0,1,1,0,-1,0};

    for(int i = 0;i<4;i++){
        int ry = y+cells[i][0];
        int rx = x+cells[i][1];
        if(checkRange(ry,rx) && map[ry][rx].partId == 0){
            PuzzlePart temp;
            temp = map[y][x];
            map[y][x] = map[ry][rx];
            map[ry][rx] = temp;
        }
    }
    stepCount++;
    curStepCount->setText(tr("%1步").arg(stepCount));
    update();
}

void mazegame::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton||isStart == true) { // 排除鼠标右键点击
        return;
    }
    click(ev->pos());
}

bool mazegame::checkRange(int y, int x)
{
    return y>=0&&y<height&&x>=0&&x<width;
}

bool mazegame::checkGameOver()
{
    int counter = 0;
    int last = map[0][0].partId;

    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            if(map[i][j].partId >= last)
                counter++;
            last = map[i][j].partId;
            if(counter == width*height-1)
                return true;
        }
    }
    return false;
}

