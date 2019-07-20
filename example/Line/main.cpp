#include "linewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LineWindow w;
    w.show();

    return a.exec();
}
