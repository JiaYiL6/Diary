
#include "check.h"
#include "updatebg.h"
#include "mypushbutton.h"
#include "edit.h"

#include <QLineEdit>
#include <QGraphicsOpacityEffect>
#include <QCalendarWidget>
#include <QFont>
#include <QDebug>

#include "history.h"
#include "mypushbutton.h"

QPushButton * showbtn[51]={NULL};
int a=0;
int i;

check::check(QWidget *parent)
    : QWidget{parent}
{
    for (i = 0; i <= 50; i++) {
        showbtn[i] = new QPushButton;
    }
    //修改实现
    edit = new class edit;
    connect(showbtn[0],&QPushButton::clicked,[=](){a=0;});
    connect(showbtn[1],&QPushButton::clicked,[=](){a=1;});
    connect(showbtn[2],&QPushButton::clicked,[=](){a=2;});
    connect(showbtn[3],&QPushButton::clicked,[=](){a=3;});
    connect(showbtn[4],&QPushButton::clicked,[=](){a=4;});
    connect(showbtn[5],&QPushButton::clicked,[=](){a=5;});
    connect(showbtn[6],&QPushButton::clicked,[=](){a=6;});

    //监听返回
    connect(edit,&edit::back,this,[=](){
        qDebug()<<"返回";
        i=0;
        edit->close();
        this->setGeometry(edit->geometry());
        this->show();
        for(i=0;i<=50;i++)
        {
            showbtn[i]->hide();
        }
        int height=220;
        for(i=0;i<=num;i++)
        {
            if(his[i].date==QDateTime::currentDateTime().toString("yyyy-MM-dd")&&his[i].flag==1)
            {
                height+=80;
                showbtn[i]->setParent(this);
                showbtn[i]->setGeometry(35,height,350,70);
                showbtn[i]->show();
                showbtn[i]->setText(his[i].title);
                showbtn[i]->setStyleSheet("background-color:rgba(255,255,255,133);");
                connect(showbtn[i],&QPushButton::clicked,[=](){
                    edit->setGeometry(this->geometry());
                    this->hide();
                    emit edit->showup();
                    edit->show();
                });
            }
        }
    });
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
    //返回按钮
    mypushbutton * backbtn = new mypushbutton(":/res/back.png");
        backbtn->setParent(this);
        backbtn->move(this->width()*0.02,this->height()*0.01);
        connect(backbtn,&QPushButton::clicked,[=](){
            emit this->back();
        });
    //日期标签
    QLineEdit * datelabel = new QLineEdit;
    QFont datefont;
    datefont.setPixelSize(20);
    datelabel->setFont(datefont);
    datelabel->setParent(this);
    datelabel->show();
    datelabel->setAlignment(Qt::AlignHCenter);
    datelabel->setEnabled(false);
    datelabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    datelabel->setGraphicsEffect(opacity);
    datelabel->setGeometry(this->width()*0.5-75,this->height()*0.02,150,50);

    //日历
    QCalendarWidget * calendar = new QCalendarWidget;
    calendar->setParent(this);
    calendar->show();
    calendar->setGeometry(60,80,300,200);
    int height=220;
    for(i=0;i<=50;i++)
    {
        showbtn[i]->hide();
    }
    for(i=0;i<=num;i++)
    {
        if(his[i].date==QDateTime::currentDateTime().toString("yyyy-MM-dd")&&his[i].flag==1)
        {
            height+=80;
            showbtn[i]->setParent(this);
            showbtn[i]->setGeometry(35,height,350,70);
            showbtn[i]->show();
            showbtn[i]->setText(his[i].title);
            showbtn[i]->setStyleSheet("background-color:rgba(255,255,255,133);");
            connect(showbtn[i],&QPushButton::clicked,[=](){
                edit->setGeometry(this->geometry());
                this->hide();
                emit edit->showup();
                edit->show();
            });
        }
    }
    connect(calendar,&QCalendarWidget::clicked,[=](){
        QString str = calendar->selectedDate().toString("yyyy-MM-dd");
        datelabel->setText(str);
        int height=220;
        for(i=0;i<=50;i++)
        {
            showbtn[i]->hide();
        }
        for(i=0;i<=num;i++)//循环遍历每一篇日记，num是日记的总篇数+1
        {
            if(his[i].date==str&&his[i].flag==1)//当第i篇日记的日期等于选择的日期且第i篇日记flag为1即存在时
            {
                height+=80;
                showbtn[i]->setParent(this);//以下是按钮的文字和位置设置
                showbtn[i]->setGeometry(35,height,350,70);
                showbtn[i]->show();//按钮出现在应该的位置
                showbtn[i]->setText(his[i].title);
                showbtn[i]->setStyleSheet("background-color:rgba(255,255,255,133);");
                connect(showbtn[i],&QPushButton::clicked,[=](){//点击按钮执行的操作
                    //原本此处有一个a=i
                    edit->setGeometry(this->geometry());
                    this->hide();//本窗口隐藏
                    emit edit->showup();
                    edit->show(); //查看的日记的窗口显现
                });
            }
        }        
    });
}

int editsignal(int n)
{
    return n;
}

