
#ifndef BUILD_H
#define BUILD_H


#include <QMainWindow>
#include <QGraphicsOpacityEffect>

#include "updatebg.h"
#include "check.h"


class build : public QMainWindow
{
    Q_OBJECT
public:
    explicit build(QWidget *parent = nullptr);   
    //修改背景
    updatebg * updatebg = NULL;
    //按日期查看
    check * check = NULL;
signals:   
};

#endif // BUILD_H

extern QString str;
extern QString w;
extern QString m;


