#include "gameview.h"
#include "ui_gameview.h"

gameview::gameview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameview)
{
    ui->setupUi(this);
    setFixedSize(1280,720);

    //设置背景
    ///this->setStyleSheet("background-color: #F0F0F0;");//随便设计一个背景色
    ui->Backg_Label->lower();
    QPixmap backgrd(":/WhiteBlockImage/dining_hall.png");
    QPixmap backgrdPixmap = backgrd.scaled(ui->Backg_Label->size(), Qt::KeepAspectRatio);
    ui->Backg_Label->setPixmap(backgrdPixmap);

    //设置游戏界面大小（400，600） 位置（120，60）
    QPixmap myPixmap(":/WhiteBlockImage/R.png");
    QPixmap scaledPixmap = myPixmap.scaled(ui->Image_Label->size());
    ui->Image_Label->setPixmap(scaledPixmap);

    //设置虚拟任务
    QPixmap NPC(":/WhiteBlockImage/bygg reverse(1).png");
    QPixmap NPCPixmap = NPC.scaled(ui->Bygg->size(), Qt::KeepAspectRatio);
    ui->Bygg->setPixmap(NPCPixmap);

    //this->setWindowTitle(QStringLiteral("开始游戏"));
    //ui->timeLcd->setStyleSheet("background-color:red;");
    //ui->scoreLcd->setStyleSheet("background-color:yellow;");

    timer = new QTimer(this);       //总计时器 控制时长
    timer->setInterval(10000);
    test_timer = new QTimer(this);  //自动更新界面 10ms一次

    connect(timer,&QTimer::timeout,this,&gameview::timeoutslot);
    connect(test_timer, &QTimer::timeout, this, &gameview::testout);

    Gamebegin = false; //和开关关联
    _step = 150;
}

//初始化界面
void gameview::initgameview()
{
    for(int i = 0; i < 4; i++)
    {
        int idex = generateRandomNumber();
        for(int j = 0; j < 4; j++)
        {
            Block* block;
            if(idex == j)
            {
                block = blueFactory.CreateBlock(this);
                block->show(); //只显示黑块
            }
            else
            {
                block = whiteFacyory.CreateBlock(this);
            }
            block->move(135+j*100, 60+i*150);
            blockdeque.push_back(block);
        }
    }
}

//获得鼠标点击事件  判断坐标点位置
void gameview::mousePressEvent(QMouseEvent *event)
{
    if(!Gamebegin)
        return;
    //根据坐标点 从队列获取块
    int row = event->y()/150;
    int col = (event->x() - 135)/100;
    if(blockdeque.at(row*4 + col)->isBlack())
    {
        if(row == 3){
            score++;
            emit value(score);
            if(score%10 == 0)
            {
                step++;
            }
            for(int i = 0; i < 4; i++)
            {
                delete blockdeque.back();
                blockdeque.pop_back();
            }
            _step = 0;
        }
    }
    else
    {
        gameover();
    }
}

void gameview::updategameview()//更新分数
{
    //用户点击 or 非用户点击
    //更新得分
    //score ++;
    //if(GameSetting::getInstance()->highscore < score)
    //{
        //GameSetting::getInstance()->highscore = score;
    //}
    //ui->scoreLcd->display(score);

    //清除最下面一行色块
    if(_step >= 150){
        if(!blockdeque.empty()){
        for(int i = 0; i < 4; i++)
        {
            delete blockdeque.back();
            blockdeque.pop_back();
        }
        }

    //增加4个色块
        int idex = generateRandomNumber();
        for(int i = 0; i < 4; i++)
        {
            Block* block;
            if(idex == i)
            {
                block = blueFactory.CreateBlock(this);
                block->show();//显示色块
            }
            else
            {
                block = whiteFacyory.CreateBlock(this);
            }
            block->move(135 + i*100, -90);
            //block->stackUnder(ui->topbarWidget);
            blockdeque.insert(blockdeque.begin()+i,block);
        }
        _step = 0;
    }

    for(int i = 0; i < 16; i++)
    {
        blockdeque.at(i)->down(step);
    }
    _step += step;
}

//倒计时
void gameview::timeoutslot()
{
    lasttime -= 0.1;
    if(lasttime <= 0)
    {
        gameover();
    }
}

//游戏结束
void gameview::usertimeout()
{
    User_timer->stop();
    QString str = QString("你超时啦！\n得分: %1 \n 是否再玩一次?").arg(score);
    int ret = QMessageBox::question(this,"游戏结束",str);
    if(ret == QMessageBox::Yes)//继续游戏
    {
        resetgame();
        initgameview();
    }
    else
    {
        resetgame();
        emit gameoversignal();
    }
}
void gameview::gameover()
{
    User_timer->stop();
    timer->stop();
    QString str = QString("很厉害啊！\n得分: %1 \n 是否再玩一次?").arg(score);
    int ret = QMessageBox::question(this,"游戏结束",str);
    if(ret == QMessageBox::Yes)//继续游戏
    {
        resetgame();
        initgameview();
    }
    else
    {
        resetgame();
        emit gameoversignal();
    }
}

void gameview::resetgame()//重置
{
    lasttime = 10;
    score = 0;
    //ui->timeLcd->display(lasttime);
    //ui->scoreLcd->display(0);
    for(int i =  0; i < 16; i++)
    {
       delete blockdeque.at(i);
    }
    blockdeque.clear();
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
    timer->start();//开始
    test_timer->start(10);
    Gamebegin = true;
}

void gameview::testout()
{
    updategameview();
}
