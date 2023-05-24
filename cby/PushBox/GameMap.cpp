#include "GameMap.h"
#include<QFile>
#include<QDebug>
#include <QByteArray>

GameMap::GameMap(QObject *parent) : QObject(parent)
{
    mRow=0;
    mCol=0;
    mPArr=nullptr;
}
GameMap::~GameMap()
{
    Clear();
}
void GameMap::Clear()
{
    if(mPArr!=nullptr)
    {
        for(int i=0;i<mRow;i++){
            delete[] mPArr[i];
        }
        delete[]mPArr;
    }
}

 bool GameMap::InitByFile(QString fileName)
 {
     QFile file(fileName);//把文件名打开
     if(!(file.open(QIODevice::ReadOnly)))
     {
         return false;//打开失败
     }
     QByteArray arrAll=file.readAll();//返回字节数组
     arrAll.replace("\r\n","\n");//把\r\n换成\n
     QList<QByteArray> lineList=arrAll.split('\n');//返回是一个链表
     mRow=lineList.size();//确定行
     mPArr=new int*[mRow];
     for(int i=0;i<mRow;i++)
     {
         QList<QByteArray> colList =lineList[i].split(',');
         mCol=colList.size();//确定列
         mPArr[i]=new int[mCol];
         for(int j=0;j<mCol;j++)//遍历列
         {
             mPArr[i][j]=colList[j].toInt();
         }
     }

 }
 void GameMap::Paint(QPainter* _p,QPoint _Pos){
     for(int i=0;i<mRow;i++){
         for(int j=0;j<mCol;j++){
             QString imgUrl;
             switch(mPArr[i][j])
             {

             case Road:imgUrl=":/Image/sky.png";break;
                 case Wall:imgUrl=":/Image/wall.png";break;
                 case Box:imgUrl=":/Image/case.png";break;
                 case Point:imgUrl=":/Image/end.png";break;
                 case InPoint:imgUrl=":/Image/win.png";break;
             }
             //列画图
             QImage img(imgUrl);
             _p->drawImage(QRect(_Pos.x()+j*img.width(),_Pos.y()+i*img.height(),img.width(),img.height()),img);
             //_p->drawImage(_Pos,img);//这样就是默认img大小了
         }
     }
 }

