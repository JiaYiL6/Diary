
#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H


#include <QPushButton>
#include <QWidget>
#include <QLabel>


class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    mypushbutton(QString normal,QString press="");
    void seticon(QString n)
    {
        QPixmap pix;
        pix.load(n);
        this->setFixedSize(0.5*pix.width(),0.5*pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(0.5*pix.width(),0.5*pix.height()));
    }
    QString normalpath;
    QString presspath;
    int n;
    mypushbutton(int a,QString t,QString normal="",QString press="")
    {
        n=a;
        QLabel*title = new QLabel;
        title->setParent(this);
        title->setText(t);
        title->show();
//        this->setText(t);
        QPixmap pix;
        pix.load(":/res/show.png");
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //弹跳
    void zoom();

signals:

};

#endif // MYPUSHBUTTON_H
