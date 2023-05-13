
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QString>

#include "mypushbutton.h"
#include "build.h"
#include "history.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //固定大小
    this->setFixedSize(420,720);
    //窗口图标
    setWindowIcon(QIcon(":/res/diary.png"));
    //窗口标题
    setWindowTitle("日记本");
    //新建按钮
    mypushbutton * newbtn = new mypushbutton(":/res/new.png");
    newbtn->setParent(this);
    newbtn->move(this->width()*0.75,this->height()*0.8);
    //浏览按钮
    //新建日记页面
    build = new class build;
    connect(newbtn,&mypushbutton::clicked,[=]()
            {

                //按钮音效
//                btnsound->play();
                newbtn->zoom();
                //进入场景
                QTimer::singleShot(300,this,[=](){
                    build->setGeometry(this->geometry());
                    this->hide();
                    build->show();
                });

            });

    //返回页面
    connect(build,&build::back,this,[=](){
        this->setGeometry(build->geometry());
        build->hide();
        this->show();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

//背景图片
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/bg2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
