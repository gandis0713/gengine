#include "splinewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SplineWindow w;
    w.show();

    return a.exec();
}
