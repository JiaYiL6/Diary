
#ifndef CHECK_H
#define CHECK_H


#include <QWidget>
#include "edit.h"

class check : public QWidget
{
    Q_OBJECT
public:
    explicit check(QWidget *parent = nullptr);
    edit * edit = NULL;
signals:
    void back();
    int editsignal(int n);
};

#endif // CHECK_H

extern int a;
