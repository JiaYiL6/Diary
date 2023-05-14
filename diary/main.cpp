
#include "build.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    build b;
    b.show();
    return a.exec();
}
