
#ifndef HISTORY_H
#define HISTORY_H

#endif // HISTORY_H
#include <QString>

extern int num;

class history
{
public:
    int flag;//判断是否删除
    QString title;
    QString content;
    QString date;
    QString mood;
    QString weather;
    history(){
        title="";
        content="";
        flag=0;
        mood=":/res/e1.png";
        weather=":/res/w.png";
    }
    history(QString t, QString c, QString d, QString m, QString w, int f){
        title=t;
        content=c;
        date=d;
        mood=m;
        weather=w;
        flag=f;
    }
};

extern history his[50];
