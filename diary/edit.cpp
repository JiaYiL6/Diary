#include "edit.h"

#include <QPainter>
#include <QLineEdit>
#include <QFont>
#include <QString>
#include <QTextEdit>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QCalendarWidget>
#include <QDate>
#include <QDebug>
#include <QTimer>
#include <QDialog>
#include <QPalette>
#include <QMenu>
#include <QAction>
#include <QGraphicsOpacityEffect>

#include "mypushbutton.h"
#include "history.h"
#include "updatebg.h"
#include "build.h"

edit::edit(QWidget *parent)
    : QWidget{parent}
{   
    //固定大小
    this->setFixedSize(420,720);
    //窗口图标
    setWindowIcon(QIcon(":/res/diary.png"));
    //窗口标题
    setWindowTitle("日记本");
    //背景图片
    QPalette palcheck = this->palette();
    palcheck.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
    setPalette(palcheck);
    //透明设置
    QGraphicsOpacityEffect * opacity = new QGraphicsOpacityEffect;
    opacity->setOpacity(0.6);
    QGraphicsOpacityEffect * opacity1 = new QGraphicsOpacityEffect;
    opacity->setOpacity(0.6);
    //返回按钮
    mypushbutton * backbtn = new mypushbutton(":/res/back.png");
    backbtn->setParent(this);
    backbtn->move(this->width()*0.02,this->height()*0.01);
    connect(backbtn,&QPushButton::clicked,[=](){
        emit this->back();
    });    
    //输入标题
    QLineEdit * title = new QLineEdit(this);
    QFont titlefont;
    titlefont.setPixelSize(20);
    title->setFont(titlefont);
    title->setText(his[a].title);
    title->show();
    title->setGeometry(35,50,350,50);
    title->setGraphicsEffect(opacity1);
    //输入内容
    QTextEdit * content = new QTextEdit(this);
    QFont contentfont;
    contentfont.setPixelSize(18);
    content->setFont(contentfont);
    content->setText(his[a].content);
    content->show();
    content->setGeometry(35,145,350,520);
    content->setStyleSheet("background-color:rgba(255,255,255,133);");
    //选择天气
    mypushbutton * weatherbtn = new mypushbutton(his[a].weather);
    weatherbtn->setParent(this);
    weatherbtn->move(this->width()*0.1,105);
    connect(weatherbtn,&QPushButton::clicked,[=](){
        QDialog * weatherwidget = new QDialog;
        weatherwidget->show();
        weatherwidget->setWindowIcon(QIcon(":/res/w.png"));
        weatherwidget->setWindowTitle("");
        weatherwidget->setGeometry(600,220,120,90);
        //晴天按钮
        mypushbutton * sunbtn = new mypushbutton(":/res/w6.png");
        sunbtn->setParent(weatherwidget);
        sunbtn->show();
        connect(sunbtn,&QPushButton::clicked,[=](){
            w=":/res/w6.png";
            weatherbtn->seticon(w);
            QTimer::singleShot(300,this,[=](){
                weatherwidget->close();
            });
        });
        //阴天按钮
        mypushbutton * cloudbtn = new mypushbutton(":/res/w10.png");
        cloudbtn->setParent(weatherwidget);
        cloudbtn->show();
        cloudbtn->setGeometry(40,0,75,75);
        connect(cloudbtn,&QPushButton::clicked,[=](){
            w=":/res/w10.png";
            weatherbtn->seticon(w);
            QTimer::singleShot(300,this,[=](){
                weatherwidget->close();
            });
        });
        //多云按钮
        mypushbutton * mcloudbtn = new mypushbutton(":/res/w3.png");
        mcloudbtn->setParent(weatherwidget);
        mcloudbtn->show();
        mcloudbtn->setGeometry(80,0,75,75);
        connect(mcloudbtn,&QPushButton::clicked,[=](){
            w=":/res/w3.png";
            weatherbtn->seticon(w);
            QTimer::singleShot(300,this,[=](){
                weatherwidget->close();
            });
        });
        //下雪按钮
        mypushbutton * snowbtn = new mypushbutton(":/res/w1.png");
        snowbtn->setParent(weatherwidget);
        snowbtn->show();
        snowbtn->setGeometry(0,50,75,75);
        connect(snowbtn,&QPushButton::clicked,[=](){
            w=":/res/w1.png";
            weatherbtn->seticon(w);
            QTimer::singleShot(300,this,[=](){
                weatherwidget->close();
            });
        });
        //下雨按钮
        mypushbutton * rainbtn = new mypushbutton(":/res/w2.png");
        rainbtn->setParent(weatherwidget);
        rainbtn->show();
        rainbtn->setGeometry(40,50,75,75);
        connect(rainbtn,&QPushButton::clicked,[=](){
            w=":/res/w2.png";
            weatherbtn->seticon(w);
            QTimer::singleShot(300,this,[=](){
                weatherwidget->close();
            });
        });
        //刮风按钮
        mypushbutton * windbtn = new mypushbutton(":/res/w4.png");
        windbtn->setParent(weatherwidget);
        windbtn->show();
        windbtn->setGeometry(80,50,75,75);
        connect(windbtn,&QPushButton::clicked,[=](){
            w=":/res/w4.png";
            weatherbtn->seticon(w);
            QTimer::singleShot(300,this,[=](){
                weatherwidget->close();
            });
        });
    });

    //选择心情

    mypushbutton * moodbtn = new mypushbutton(his[a].mood);
    moodbtn->setParent(this);
    moodbtn->move(this->width()*0.2,105);
    connect(moodbtn,&QPushButton::clicked,[=](){
        QDialog * moodwidget = new QDialog;
        //      moodwidget->setParent(this);
        moodwidget->show();
        moodwidget->setWindowIcon(QIcon(":/res/e1.png"));
        moodwidget->setWindowTitle((""));
        moodwidget->setGeometry(600,220,120,90);
        //开心按钮
        mypushbutton * happybtn = new mypushbutton(":/res/e1.png");
        happybtn->setParent(moodwidget);
        happybtn->show();
        connect(happybtn,&QPushButton::clicked,[=](){
            m=":/res/e1.png";
            moodbtn->seticon(m);
            QTimer::singleShot(300,this,[=](){
                moodwidget->close();
            });
        });
        //无聊按钮
        mypushbutton * boringbtn = new mypushbutton(":/res/e4.png");
        boringbtn->setParent(moodwidget);
        boringbtn->show();
        boringbtn->setGeometry(40,0,75,75);
        connect(boringbtn,&QPushButton::clicked,[=](){
            m=":/res/e4.png";
            moodbtn->seticon(m);
            QTimer::singleShot(300,this,[=](){
                moodwidget->close();
            });
        });
        //惊恐按钮
        mypushbutton * scarebtn = new mypushbutton(":/res/e6.png");
        scarebtn->setParent(moodwidget);
        scarebtn->show();
        scarebtn->setGeometry(80,0,75,75);
        connect(scarebtn,&QPushButton::clicked,[=](){
            m=":/res/e6.png";
            moodbtn->seticon(m);
            QTimer::singleShot(300,this,[=](){
                moodwidget->close();
            });
        });
        //悲伤按钮
        mypushbutton * sadbtn = new mypushbutton(":/res/e7.png");
        sadbtn->setParent(moodwidget);
        sadbtn->show();
        sadbtn->setGeometry(0,50,75,75);
        connect(sadbtn,&QPushButton::clicked,[=](){
            m=":/res/e7.png";
            moodbtn->seticon(m);
            QTimer::singleShot(300,this,[=](){
                moodwidget->close();
            });
        });
        //生气按钮
        mypushbutton * angrybtn = new mypushbutton(":/res/e10.png");
        angrybtn->setParent(moodwidget);
        angrybtn->show();
        angrybtn->setGeometry(40,50,75,75);
        connect(angrybtn,&QPushButton::clicked,[=](){
            m=":/res/e10.png";
            moodbtn->seticon(m);
            QTimer::singleShot(300,this,[=](){
                moodwidget->close();
            });
        });
        //调皮按钮
        mypushbutton * naughtybtn = new mypushbutton(":/res/e11.png");
        naughtybtn->setParent(moodwidget);
        naughtybtn->show();
        naughtybtn->setGeometry(80,50,75,75);
        connect(naughtybtn,&QPushButton::clicked,[=](){
            m=":/res/e11.png";
            moodbtn->seticon(m);
            QTimer::singleShot(300,this,[=](){
                moodwidget->close();
            });
        });
    });

    //选择日期
    QLineEdit * date = new QLineEdit(this);
    date->setEnabled(false);
    date->show();
    date->setGeometry(240,108,80,25);
    str = his[a].date;
    date->setText(str);
    date->setGraphicsEffect(opacity);
    mypushbutton * datebtn = new mypushbutton(":/res/date.png");
    datebtn->setParent(this);
    datebtn->move(this->width()*0.8,105);
    connect(datebtn,&QPushButton::clicked,[=](){
        QCalendarWidget * calendar = new QCalendarWidget;
        calendar->setParent(this);
        calendar->show();
        calendar->setGeometry(150,140,273,193);
        connect(calendar,&QCalendarWidget::clicked,[=](){
            str = calendar->selectedDate().toString("yyyy-MM-dd");
            date->setText(str);
            QTimer::singleShot(150,this,[=](){
                calendar->hide();
            });
        });
    });
    //重新出现
    connect(this,&edit::showup,[=](){
        title->setText(his[a].title);
        content->setText(his[a].content);
        weatherbtn->seticon(his[a].weather);
        moodbtn->seticon(his[a].mood);
        str = his[a].date;
        date->setText(str);
    });
    //清空按钮
    QPushButton * clearbtn = new QPushButton(this);
    clearbtn->setGeometry(this->width()*0.55,this->height()*0.94,70,30);
    clearbtn->setText("清空");
    connect(clearbtn,&QPushButton::clicked,[=](){
        title->clear();
        content->clear();
        weatherbtn->seticon(":/res/w.png");
        moodbtn->seticon(":/res/e1.png");
        w = ":/res/w.png";
        m = ":/res/e1.png";
        str = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        date->setText(str);
    });
    //保存按钮
    QPushButton * savebtn = new QPushButton(this);
    savebtn->setGeometry(this->width()*0.75,this->height()*0.94,70,30);
    savebtn->setText("保存");
    connect(savebtn,&QPushButton::clicked,[=](){
        qDebug()<<a;
        //获取文本
        his[a].title = title->text();
        his[a].content = content->toPlainText();
        his[a].date=str;
        his[a].mood=m;
        his[a].weather=w;
        his[a].flag=1;
        emit this->back();
        title->clear();
        content->clear();
        weatherbtn->seticon(":/res/w.png");
        moodbtn->seticon(":/res/e1.png");
        w = ":/res/w.png";
        m = ":/res/e1.png";
        str = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        date->setText(str);
    });
    //删除按钮
    QPushButton * deletebtn = new QPushButton(this);
    deletebtn->setParent(this);
    deletebtn->setGeometry(this->width()*0.35,this->height()*0.94,70,30);
    deletebtn->setText("删除");
    connect(deletebtn,&QPushButton::clicked,[=](){
        his[a].flag=0;
        emit this->back();
        title->clear();
        content->clear();
        weatherbtn->seticon(":/res/w.png");
        moodbtn->seticon(":/res/e1.png");
        w = ":/res/w.png";
        m = ":/res/e1.png";
        str = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        date->setText(str);
    });
}

