#include "mainscenery.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainScenery w;
    w.show();
    return a.exec();
}
