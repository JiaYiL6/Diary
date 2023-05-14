#include "build.h"
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
#include "check.h"

QString str = QDateTime::currentDateTime().toString("yyyy-MM-dd");
QString w = ":/res/w.png";
QString m = ":/res/e1.png";



build::build(QWidget *parent)
    : QMainWindow{parent}
{
    //固定大小
    this->setFixedSize(420,720);
    //窗口图标
    setWindowIcon(QIcon(":/res/diary.png"));
    //窗口标题
    setWindowTitle("日记本");
    //背景图片
    QPalette pal2 = this->palette();
    pal2.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
    setPalette(pal2);
    //透明化
    QGraphicsOpacityEffect * opacity = new QGraphicsOpacityEffect;
    opacity->setOpacity(0.6);
    QGraphicsOpacityEffect * opacity1 = new QGraphicsOpacityEffect;
    opacity1->setOpacity(0.6);
    //写日记标题
    QPalette diarycolor;
    diarycolor.setColor(QPalette::WindowText,Qt::white);
    QLabel * diary = new QLabel(this);
    diary->setPalette(diarycolor);
    QFont diaryfont;
    diaryfont.setPixelSize(28);
    diaryfont.setItalic(1);
    diaryfont.setUnderline(1);
    diary->setFont(diaryfont);
    diary->show();
    diary->setGeometry(40,-4,350,50);
    diary->setText("写日记");
    //更多菜单
    mypushbutton * morebtn = new mypushbutton(":/res/more.png");
    morebtn->setParent(this);
    morebtn->move(this->width()*0.85,9);
    connect(morebtn,&QPushButton::clicked,[=](){
        morebtn->zoom();
        QMenu * moremenu = new QMenu(this);
        moremenu->setParent(this);
        moremenu->show();
        moremenu->setGeometry(820,85,70,80);
        QAction *date = new QAction;
        date->setText("按日期查看");
        date->setIcon(QIcon(":/res/date.png"));
        QAction * update = new QAction;
        update->setText("修改背景图片");
        update->setIcon(QIcon(":/res/photo.png"));
        moremenu->addAction(date);
        moremenu->addSeparator();
        moremenu->addAction(update);
        //按日期查看
        check = new class check;
        connect(date,&QAction::triggered,[=](){            
            check->setGeometry(this->geometry());
            this->hide();
            check->show();
        });
        connect(check,&check::back,this,[=](){
            this->setGeometry(check->geometry());
            this->show();
            check->hide();
        });
        //修改背景图片
        updatebg = new class updatebg;
        connect(update,&QAction::triggered,[=](){
            updatebg->setGeometry(this->geometry());
            this->hide();
            updatebg->show();
        });
        connect(updatebg,&updatebg::back,this,[=](){
            QPalette pal = this->palette();
            pal.setBrush(QPalette::Window,QBrush(QPixmap(photostr)));
            setPalette(pal);
            this->setGeometry(updatebg->geometry());
            updatebg->hide();
            this->show();
        });
    });
    //输入标题
    QLineEdit * title = new QLineEdit(this);
    QFont titlefont;
    titlefont.setPixelSize(20);
    title->setFont(titlefont);
    title->setPlaceholderText("输入标题");
    title->show();
    title->setGeometry(35,50,350,50);
    title->setGraphicsEffect(opacity1);
    //输入内容
    QTextEdit * content = new QTextEdit(this);
    QFont contentfont;
    contentfont.setPixelSize(18);
    content->setFont(contentfont);
    content->setPlaceholderText("输入内容");
    content->show();
    content->setGeometry(35,145,350,520);
    content->setStyleSheet("background-color:rgba(255,255,255,133);");
    //选择天气
    mypushbutton * weatherbtn = new mypushbutton(":/res/w.png");
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
    mypushbutton * moodbtn = new mypushbutton(":/res/e1.png");
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
            QTimer::singleShot(130,this,[=](){
                calendar->hide();
            });  
        });
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
    QPushButton * savebtn = new QPushButton;
    savebtn->setParent(this);
    savebtn->setGeometry(this->width()*0.75,this->height()*0.94,70,30);
    savebtn->setText("保存");
    connect(savebtn,&QPushButton::clicked,[=](){
        //获取文本
        his[num].title = title->text();
        his[num].content = content->toPlainText();
        his[num].date=str;
        his[num].mood=m;
        his[num].weather=w;
        his[num].flag=1;
        num++;
        qDebug()<<str;
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
