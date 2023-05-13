
#ifndef EDIT_H
#define EDIT_H


#include <QWidget>


class edit : public QWidget
{
    Q_OBJECT
public:
    explicit edit(QWidget *parent = nullptr);
signals:
    void back();
};

#endif // EDIT_H
