
#ifndef BUILD_H
#define BUILD_H


#include <QMainWindow>

#include "updatebg.h"
#include "check.h"


class build : public QMainWindow
{
    Q_OBJECT
public:
    explicit build(QWidget *parent = nullptr);
    //绘图事件
//    void paintEvent(QPaintEvent *);
    //修改背景
    updatebg * updatebg = NULL;
    //按日期查看
    check * check = NULL;
signals:
    void back();
};

#endif // BUILD_H

extern QString str;
extern QString w;
extern QString m;

