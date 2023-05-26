#include "widget.h"

#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(320,480);
    this->setWindowTitle(QStringLiteral("别踩白块"));
    GameSetting::getInstance();
    gameVc = new gameview;
    gameVc->hide();
    connect(gameVc,&gameview::gameoversignal,this,&Widget::gameoverslot);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.drawPixmap(0,0,width(),height(),QPixmap(":/resources/img_bg_level_2.jpg"));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_3_clicked()
{
    gameVc->show();
    hide();
    gameVc->initgameview();
//    this->hide();//隐藏本窗口
//     gameview *child = new gameview();//进入游戏界面
//    // child->move(QPoint(100,100));//窗口位置
    //     child->show();
}

void Widget::gameoverslot()
{
    gameVc->hide();
    show();
}

void Widget::on_pushButton_2_clicked()
{
    QMessageBox::about(this,"玩法","在30秒内尽量多的点击黑块！\n如果点击到白块，游戏立刻结束!");
}

void Widget::on_pushButton_clicked()
{
    QString str = QString("历史最高分：\n\n      %1").arg(GameSetting::getInstance()->highscore);
    QMessageBox::about(this,"最高分",str);
}




