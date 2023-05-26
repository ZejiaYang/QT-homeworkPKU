#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include "block.h"
#include <deque>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include "gamesetting.h"
using namespace std;

namespace Ui {
class gameview;
}

class gameview : public QWidget
{
    Q_OBJECT
signals:
    void gameoversignal();
public:
    explicit gameview(QWidget *parent = 0);
    ~gameview();
    void initgameview();
    void mousePressEvent(QMouseEvent *event);
    void updategameview();
    void resetgame();
    void gameover();
private slots:
//    void on_scoreLcd_overflow();

//    void on_GameView_destroyed();

    void on_Commence_clicked();

private:
    float lasttime = 600;
    int interval = 0;
    int score = 0;
    int step = 1;
    int _step;
    void timeoutslot();
    void usertimeout();
    void testout();
    QTimer* timer;
    QTimer* User_timer;

    QTimer* test_timer;

    Ui::gameview *ui;
    BlueBlockFactory blueFactory;
    WhiteBlockFactory whiteFacyory;
    //队列 存放块
    deque<Block*> blockdeque;
    int generateRandomNumber();
    bool Gamebegin;

signals:
    void failure();
    void value(int value);
};

#endif // GAMEVIEW_H


