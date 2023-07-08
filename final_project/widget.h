#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include "gamesetting.h"
#include "gameview.h"
#include "minimazegamewidgetiii.h"
#include "minimaze_config.h"
#include "puzzlepart.h"
#include "mazegame.h"
#include "visitor.h"
#include "push.h"
#include "Ending.h"
#include "parkour_2.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTimer *timer;
private slots:
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *event) override
     {
        m->close();
        v->close();
        p->close();
        g->close();
        q->close();
        M->close();
        delete m;
        delete v;
        delete p;
        delete q;
        delete g;
        delete M;
        event->accept();
        deleteLater();
     }
private:
    int Intro_end = 0;
    int Intro_begin = 0;
    int page_two = 0;
    int page_three = 0;
    void mousePressEvent(QMouseEvent *event);
    void stars_update();
    QGraphicsOpacityEffect *GraphicsOpacityEffect;
    QPropertyAnimation * Animation;
    Ui::Widget *ui;
    int spotpos[6][2] = {{670,163},
                         {688,315},
                         {628,593},
                         {883,445},
                         {835,540},
                         {703,523}};
    mazegame* m;
    push* p;
    gameview* g;
    MiniMazeGameWidgetIII* M;
    parkour_2* q;
    Visitor* v;
    Ending* e;
    QLabel* Spot[6];
    QTimer* update_timer;
};

#endif // WIDGET_H

