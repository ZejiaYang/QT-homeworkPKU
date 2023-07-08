#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include <deque>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMediaObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "gamesetting.h"
#include "block.h"
using namespace std;

namespace Ui {
class gameview;
}

class gameview : public QWidget
{
    Q_OBJECT
public:
    int tpass;
    int pass;
    explicit gameview(QWidget *parent = 0);
    ~gameview();
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void updategameview();
    void resetgame();
    void gameover();

private slots:
    void on_Commence_clicked();
    void on_Shutdown_clicked();
    void on_ExitButton_clicked();

private:
    float lasttime = 50;
    int interval = 0;
    int score = 0;
    double step = 2;
    int _step;
    int suprise = 0;
    void timeoutslot();
    QTimer* timer;
    QTimer* test_timer;

    Ui::gameview *ui;
    BlueBlockFactory blueFactory;
    WhiteBlockFactory whiteFactory;

    deque<Block*> blockdeque;
    int generateRandomNumber();
    bool Gamebegin;
    int Intro_over;
    int Count;
    int Gameoverstate;
    int Wrong_dishes[5][4] = {{300,200,472,387},{150,11,388,189},{900,315,983,495},{657,201,887,374},
                                 {101,480,379,666}};
    bool Is_choose[5] = {};
    int Is_success(QPoint pos);
    deque<QLabel*> judge;

    QPixmap Result1Pixmap;
    QPixmap Result2Pixmap;
    QPixmap Result3Pixmap;
    QGraphicsOpacityEffect *m_pGraphicsOpacityEffect;
    QPropertyAnimation * m_pNameAnimation;
};



#endif // GAMEVIEW_H


