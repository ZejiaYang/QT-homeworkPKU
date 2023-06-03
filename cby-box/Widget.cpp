#include "Widget.h"
#include "ui_widget.h"
#include<QFileDialog>//用文件对话框去取
#include<QPainter>
#include<QMessageBox>
#include<QKeyEvent>
#include<QtDebug>
#include<QTimer>
#include<QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //初始化地图元素
    ui->setupUi(this);
    mPMap=new GameMap(this);
    //QString filename=QFileDialog::getOpenFileName(this,"打开地图","./","*.txt");
    QString filename=":/Map/lv1.txt";

    if(mPMap->InitByFile(filename))//这个为什么会警告，我明明打开了
    {
        QMessageBox::warning(this,"警告","文件打开失败");
    }
    //这个需要根据实际的路径改


    mMapPainter=new QPainter(this);//创建画家
    mRole=new Role(this);
    mTimer=new QTimer(this);
    mTimer->start(100);//更新频率100ms
    //定时器绑定更新
    connect(mTimer,&QTimer::timeout,[this](){    this->update();});
    setFixedSize(1280,720);//调整窗口大小



    //按钮设置
    quit=new QPushButton("Quit");
    quit->setFont(QFont("Algerian",18));

    quit->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                 "QPushButton:hover{color:red;}");
    connect(quit,SIGNAL(clicked(bool)),
            this,SLOT(quitClick()));
    this->setFocus();

}
void Widget::quitClick(){
    this->close();
}

Widget::~Widget()
{
    delete quit;
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    mMapPainter->begin(this);//设置画布

    //画背景
    QPainter bgPainter;
//    bgPainter.begin(this);
    QString imgurl;
    imgurl=":/Image/ground.png";//画不出来背景为什么？
    QImage img(imgurl);
    mMapPainter->drawImage(QRect(0,0,1280,720),img);
//    bgPainter.end();

    //绘制任务
    QString byggurl;
    byggurl=":/Image/bygg.png";
    QImage img2(byggurl);
//    mImg=mImg.scaled(40,40);
    img2=img2.scaled(1106,1476);
    mMapPainter->drawImage(QRect(860,180,419,560),img2);
     show_exit();
    //画地图
    mPMap->Paint(mMapPainter,QPoint(120,90));//传位置

    //画人物化郭炜
    mRole->Paint(mMapPainter,QPoint(120,90));//可以自己做偏移

    mMapPainter->end();//结束

}
void Widget::keyPressEvent(QKeyEvent*event)
{
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
bool Widget::GameOver(){
    for(int i=0;i<mPMap->mRow;i++){
        for(int j=0;j<mPMap->mCol;j++){
            if(mPMap->mPArr[i][j]==Point)
                return false;
        }
    }
    return true;
}
void Widget::show_exit(){
    if(!GameOver())return;
    qDebug()<<"游戏结束";

    QString imgURL = ":/Image/close.png";
    QImage exitG(imgURL);
    mMapPainter->drawImage(QRect( (1280- exitG.width())/2,
                              (720-exitG.height())/2,
                              exitG.width(),exitG.height()),exitG);

}

void Widget::Collision(int _dRow, int _dCol)
{
    //判断位置
    int newRow=mRole->mRow+_dRow;
    int newCol=mRole->mCol+_dCol;

    if(mPMap->mPArr[newRow][newCol]==Wall){//判断是墙
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
    qDebug()<<"人物绘制位置"<<mRole->mPaintPos;
}



void Widget::on_label_linkActivated(const QString &link)
{

}

void Widget::on_pushButton_clicked()
{
    this->close();
}
