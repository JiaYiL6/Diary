
#include "mypushbutton.h"
#include <QPropertyAnimation>

mypushbutton::mypushbutton(QString normal,QString press)
{
    this->normalpath=normal;
    this->presspath=press;
    QPixmap pix;
    bool ret=pix.load(normal);
    if(!ret)
    {
        return;
    }
    this->setFixedSize(0.5*pix.width(),0.5*pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(0.5*pix.width(),0.5*pix.height()));
}


void mypushbutton::zoom()
{
    QPropertyAnimation * ani = new QPropertyAnimation(this,"geometry");
    ani->setDuration(100);
    ani->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    ani->setStartValue(QRect(this->x(),this->y()+2,this->width(),this->height()));
    ani->setEasingCurve(QEasingCurve::OutBounce);
    ani->start();
}
