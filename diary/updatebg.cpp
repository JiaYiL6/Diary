#include <QPainter>
#include <QPalette>
#include <QBrush>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include "updatebg.h"
#include "mypushbutton.h"

QString photostr = ":/res/bg6.jpg";

updatebg::updatebg(QWidget *parent)
    : QWidget{parent}
{
    //固定大小
    this->setFixedSize(420,720);
    //窗口图标
    setWindowIcon(QIcon(":/res/diary.png"));
    //窗口标题
    setWindowTitle("日记本");
    //背景图片
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
    setPalette(pal);
    //返回按钮
<<<<<<< HEAD
    mypushbutton * backbtn = new mypushbutton(":/res/back.png");
    backbtn->setParent(this);
    backbtn->move(this->width()*0.02,this->height()*0.01);
    connect(backbtn,&QPushButton::clicked,[=](){
        emit this->back();
    });
=======
//    mypushbutton * backbtn = new mypushbutton(":/res/back.png");
//    backbtn->setParent(this);
//    backbtn->move(this->width()*0.02,this->height()*0.01);
//    connect(backbtn,&QPushButton::clicked,[=](){
//        emit this->back();
//    });
>>>>>>> 75cb49728c3a260d5fc3912394ecef35bfb2a734
    //按钮
    mypushbutton * bg6 = new mypushbutton(":/res/bg6.png");
    bg6->setParent(this);
    bg6->move(35,50);
    bg6->show();
    connect(bg6,&QPushButton::clicked,[=](){
        photostr=":/res/bg6.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg2 = new mypushbutton(":/res/bg2.png");
    bg2->setParent(this);
    bg2->move(175,50);
    bg2->show();
    connect(bg2,&QPushButton::clicked,[=](){
        photostr=":/res/bg2.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg3 = new mypushbutton(":/res/bg3.png");
    bg3->setParent(this);
    bg3->move(315,50);
    bg3->show();
    connect(bg3,&QPushButton::clicked,[=](){
        photostr=":/res/bg3.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg4 = new mypushbutton(":/res/bg4.png");
    bg4->setParent(this);
    bg4->move(35,290);
    bg4->show();
    connect(bg4,&QPushButton::clicked,[=](){
        photostr=":/res/bg4.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg5 = new mypushbutton(":/res/bg5.png");
    bg5->setParent(this);
    bg5->move(175,290);
    bg5->show();
    connect(bg5,&QPushButton::clicked,[=](){
        photostr=":/res/bg5.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg7 = new mypushbutton(":/res/bg7.png");
    bg7->setParent(this);
    bg7->move(315,290);
    bg7->show();
    connect(bg7,&QPushButton::clicked,[=](){
        photostr=":/res/bg7.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg8 = new mypushbutton(":/res/bg8.png");
    bg8->setParent(this);
    bg8->move(35,530);
    bg8->show();
    connect(bg8,&QPushButton::clicked,[=](){
        photostr=":/res/bg8.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg9 = new mypushbutton(":/res/bg9.png");
    bg9->setParent(this);
    bg9->move(175,530);
    bg9->show();
    connect(bg9,&QPushButton::clicked,[=](){
        photostr=":/res/bg9.jpg";
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
    mypushbutton * bg10 = new mypushbutton(":/res/add.png");
    bg10->setParent(this);
    bg10->move(315,530);
    bg10->show();
    connect(bg10,&QPushButton::clicked,[=](){        
        photostr=QFileDialog::getOpenFileName(this,"选择背景","C:\\Users\\86150\\Desktop","(*JPG *PNG)");
        QPalette pal = this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
        setPalette(pal);
        emit this->back();
    });
}

