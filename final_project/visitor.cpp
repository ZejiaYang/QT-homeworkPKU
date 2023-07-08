#include "visitor.h"
#include "ui_visitor.h"
#include <QFile>
#include <QTextStream>
Visitor::Visitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Visitor)
{
    ui->setupUi(this);
    QFile file(":/res/qss/style-1.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_3,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_4,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_5,SIGNAL(clicked(bool)),this,SLOT(close_visitor()));
    pass = 0;
}

Visitor::~Visitor()
{
    delete ui;
}
QPushButton* btn;
void Visitor::set_style()
{
    btn = qobject_cast<QPushButton*>(sender());//获取发射信号的对象
    QString filePath;
    if("btn_1" == btn->objectName())        //粉色
    {
        filePath = ":/res/qss/style-1.qss";
    }else if("btn_2" == btn->objectName())  //黄蓝
    {
        filePath = ":/res/qss/style-2.qss";
    }else if("btn_3" == btn->objectName())  //浅紫
    {
        filePath = ":/res/qss/style-3.qss";
    }else if("btn_4" == btn->objectName())  //青绿
    {
        filePath = ":/res/qss/style-4.qss";
    }
    else if("btn_5"==btn->objectName()){
        filePath = ":/res/qss/style-1.qss";
    }

    /*皮肤设置*/
    QFile file(filePath);/*QSS文件所在的路径*/
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
}

void Visitor::close_visitor()
{
    this->close();
    pass = 1;
}
