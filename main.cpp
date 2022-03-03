#include "ingame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InGame w;
    w.show();
    return a.exec();
}
