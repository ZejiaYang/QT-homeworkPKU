#include "parkour_2.h"
#include "ui_parkour_2.h"

parkour_2::parkour_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parkour_2)
{
    ui->setupUi(this);
    initWindow();
    showBackground();
    playGame();
}

parkour_2::~parkour_2()
{
    delete ui;
}

void parkour_2::playGame()
{

    distanceCount = 0;
    m_timer.start();
    //设定依据计时器触发的事件信号槽
    connect(&m_timer,&QTimer::timeout,
            [=](){
        playerMove();
        updatePos();//更新玩家位置
        barrierAppear();//出现障碍物
        update();//刷新画面
        updateDis();//刷新距离
        collisionDectection();//碰撞检测
        winDectection();//通关检测
        loseDectection();//失败检测
    });
    r_timer.start();
    //connect(&r_timer,&QTimer::timeout,&m_run,&Runner::stepForward);
    connect(&r_timer,&QTimer::timeout,[=](){
        m_run.stepForward();
    });
    collisionLabel = new QLabel(this);
    collisionLabel->setPixmap(QPixmap(":/parkour_resource/collision1.png"));
    collisionLabel->setGeometry(0,0,COLLISION_LABEL_WIDTH,COLLISION_LABEL_HEIGHT);
    collisionLabel->hide();
    c_timer.setInterval(COLLISION_TIME);
    connect(&c_timer,&QTimer::timeout,[=](){
        c_timer.stop();
        collisionLabel->hide();
    });
    phoneLabel = new QLabel(this);
    //phoneLabel->setPixmap(QPixmap(":/parkour_resource/phone.png"));
    phoneLabel->setGeometry(PHONE_POS_X,PHONE_POS_Y,PHONE_WIDTH,PHONE_HEIGHT);
    phoneLabel->setScaledContents(true);
    phoneLabel->setAlignment(Qt::AlignCenter);
    phoneLabel->setStyleSheet(
                QString("border-image:url(:/parkour_resource/phone.png);color:rgb(128,128,128);"));
    phoneLabel->setText("0.00km\n/\n 8.50km");
    QFont fnt;
    fnt.setPointSize(20);
    phoneLabel->setFont(fnt);
    phoneLabel->hide();
}

void parkour_2::updatePos()//更新地图移动物体的坐标
{
    m_map.mapPosition();//更新背景坐标
    for(int i = 0;i<BARRIER_NUM;++i){//更新障碍物坐标
        if(barriers[i].onMap){
            barriers[i].updatePos();
        }
    }
}

void parkour_2::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //画背景
    painter.drawPixmap(m_map.m_map1_posX,0,m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,0,m_map.m_map2);
    //画玩家
    painter.drawPixmap(m_run.m_X,m_run.m_Y,m_run.m_runner);
    //画障碍
    for(int i = 0;i<BARRIER_NUM;++i){
        if(barriers[i].onMap){
            Barrier& tmpb= barriers[i];
            painter.drawPixmap(tmpb.m_X,tmpb.m_Y,tmpb.m_bar);
        }
    }
    //画血量
    QPixmap hlt(":/parkour_resource/heart.png");
    for(int i = 0;i<m_run.health;++i){
        painter.drawPixmap(HEALTHBAR_POS_X+i*HEART_SIZE,HEALTHBAR_POS_Y,hlt);
    }
}


void parkour_2::keyPressEvent(QKeyEvent *keyevent){
    if(!intro_closed){
        intro_closed = 1;
        closeBackground();
        return;
    }
    else if(gameLose && keyevent->key()==Qt::Key_Space){
        this->close();
        return;
    }
    else if(gameWin && keyevent->key()==Qt::Key_Space){
        parkour_success_broadcast();
        this->close();
        return;
    }
    else if(keyevent->key()==Qt::Key_O){
        distanceCount = WINTIME -50;//开发者一键通关按钮
    }
    switch(keyevent->key()){
        case Qt::Key_Up:
        case Qt::Key_Down:
        case Qt::Key_W:
        case Qt::Key_S:
        case Qt::Key_Left:
        case Qt::Key_A:
        case Qt::Key_Right:
        case Qt::Key_D:
        keylist.append(keyevent->key());
    }

}

void parkour_2::keyReleaseEvent(QKeyEvent *keyevent){
    if(keylist.contains(keyevent->key()))
        keylist.removeOne(keyevent->key());
}
void parkour_2::playerMove(){
    for(int move : keylist){
        if((move==Qt::Key_Up ||move==Qt::Key_W)
                && m_run.m_Y>=RUNWAY_TOP)
            m_run.setposition(m_run.m_X,m_run.m_Y-PLAYER_SIDEWARD_SPEED);
        else if((move==Qt::Key_Down || move==Qt::Key_S)
                && m_run.m_Y<=RUNWAY_BOTTOM)
            m_run.setposition(m_run.m_X,m_run.m_Y+PLAYER_SIDEWARD_SPEED);
        else if((move==Qt::Key_Right || move==Qt::Key_D)
                && m_run.m_X <= GAME_WIDTH-5)
            m_run.setposition(m_run.m_X+PLAYER_FOREWARD_SPEED,m_run.m_Y);
        else if((move==Qt::Key_Left || move==Qt::Key_A)
                && m_run.m_X >=5)
            m_run.setposition(m_run.m_X-PLAYER_BACKWARD_SPEED,m_run.m_Y);
    }
}

void parkour_2::collisionDectection()
{
    for(int i = 0;i<BARRIER_NUM;++i){
        if(barriers[i].m_Rect.intersects(m_run.m_Rect) && barriers[i].bumped == false){
            barriers[i].bumped = true;
            collisionLabel->setGeometry(m_run.m_X+COLLISION_LABEL_WIDTH/2,m_run.m_Y,
                                        COLLISION_LABEL_WIDTH,COLLISION_LABEL_HEIGHT);
            collisionLabel->show();
            c_timer.start();
            m_run.loseHealth();
            if(m_run.health<=0)
                gameLose = 1;
            break;
        }
    }
}

void parkour_2::initWindow(){
    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    setWindowTitle(WINDOW_TITLE);

    m_timer.setInterval(REFRESH_RATE);
    r_timer.setInterval(RUNNER_STEP_TIME);

    b_recorder = 0;

    srand((unsigned int)time(NULL));
}

void parkour_2::barrierAppear(){
    if(!intro_closed)return;
    b_recorder++;
    if(b_recorder<BARRIER_INTERVAL)
        return;
    b_recorder = 0;
    for(int i = 0;i<BARRIER_NUM;++i){
        if(barriers[i].onMap)
            continue;
        barriers[i].onMap = true;
        barriers[i].bumped = false;
        barriers[i].m_X = GAME_WIDTH;
        barriers[i].m_Y = RUNWAY_TOP+(rand()%(RUNWAY_BOTTOM-RUNWAY_TOP));
        break;

    }
}

bool parkour_2::parkour_success_broadcast()
{
    return 1;
}

void parkour_2::updateDis(){
    distanceCount++;
    float tmp = float(distanceCount)/1000.0;
    QString str = QString::number(tmp);
    str+="km\n/\n8.500km";
    phoneLabel->setText(str);
}

void parkour_2::winDectection(){
    if(distanceCount >= WINTIME){
        gameWin = true;
        m_timer.stop();
        Sleep(1000);
        winLabel = new QLabel(this);
        winLabel->setFixedSize(WIN_WIDTH,WIN_HEIGHT);
        winLabel->setGeometry(WIN_POS_X, WIN_POS_Y,WIN_WIDTH,WIN_HEIGHT);
        QPixmap winPage(":/parkour_resource/win.png");
        winLabel->setPixmap(winPage);
        winLabel->show();
    }
}

void parkour_2::loseDectection(){
    if(gameLose){
        m_timer.stop();
        Sleep(1000);
        loseLabel = new QLabel(this);
        loseLabel->setFixedSize(LOSE_WIDTH,LOSE_HEIGHT);
        loseLabel->setGeometry(LOSE_POS_X, LOSE_POS_Y,LOSE_WIDTH,LOSE_HEIGHT);
        QPixmap losePage(":/parkour_resource/lose.png");
        loseLabel->setPixmap(losePage);
        loseLabel->show();
    }
}

void parkour_2::showBackground()
{
    introLabel = new QLabel(this);

    introLabel->setFixedSize(INTROWIDTH,INTROHEIGHT);
    introLabel->setGeometry(INTRO_POS_X, INTRO_POS_Y,INTROWIDTH,INTROHEIGHT);
    QPixmap introPage(":/parkour_resource/intro2.png");
    introLabel->setPixmap(introPage);

    GraphicsOpacityEffect = new QGraphicsOpacityEffect(introLabel);
    GraphicsOpacityEffect->setOpacity(0);
    introLabel->setGraphicsEffect(GraphicsOpacityEffect);
    Animation =new QPropertyAnimation(GraphicsOpacityEffect,"opacity" , this);
    Animation->setEasingCurve(QEasingCurve::Linear);
    Animation->setDuration(1000);
    Animation->setEndValue(1.0);
    introLabel->show();
    Animation->start();
}

void parkour_2::closeBackground()
{
    GraphicsOpacityEffect = new QGraphicsOpacityEffect(introLabel);
    GraphicsOpacityEffect->setOpacity(1.0);
    introLabel->setGraphicsEffect(GraphicsOpacityEffect);
    Animation =new QPropertyAnimation(GraphicsOpacityEffect,"opacity" , this);
    Animation->setEasingCurve(QEasingCurve::Linear);
    Animation->setDuration(1000);
    Animation->setEndValue(0);
    Animation->start();
    m_timer.start();
    phoneLabel->show();
}
