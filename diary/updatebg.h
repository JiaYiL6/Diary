
#ifndef UPDATEBG_H
#define UPDATEBG_H


#include <QWidget>


class updatebg : public QWidget
{
    Q_OBJECT
public:
    explicit updatebg(QWidget *parent = nullptr);
    //绘图事件
//    void paintEvent(QPaintEvent *);
signals:
    void back();
};

extern QString photostr;

#endif // UPDATEBG_H
