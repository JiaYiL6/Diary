
#ifndef UPDATEBG_H
#define UPDATEBG_H


#include <QWidget>


class updatebg : public QWidget
{
    Q_OBJECT
public:
    explicit updatebg(QWidget *parent = nullptr);   
signals:
    void back();
};

extern QString photostr;

#endif // UPDATEBG_H
