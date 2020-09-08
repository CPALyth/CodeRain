#include "hackRain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    hackRain w;
    w.show();

    return a.exec();
}
