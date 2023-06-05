#include "puzzlepart.h"
#include <cmath>
#include <QMessageBox>
#include <QPainter>
#include <QRect>

PuzzlePart::PuzzlePart(QWidget *parent) : QWidget(parent)
{
    partId = 0;
}

void PuzzlePart::drawPart(QPainter &p,QImage *img)
{
    p.setBrush(Qt::white);
    p.drawRect(50+col*rect.width(),50+row*rect.height(),rect.width(),rect.height());//画白色正方形
    if(partId != 0){
        p.drawImage(50+col*rect.width(),50+row*rect.height(),*img,rect.x(),rect.y(),rect.width(),rect.height());
    }else{

    }
}

bool PuzzlePart::isBlank()
{
    return partId == 0;
}
//判断是否为空
PuzzlePart &PuzzlePart::operator =(const PuzzlePart &pp)
{
    partId = pp.partId;
    rect = pp.rect;
    return *this;
}
