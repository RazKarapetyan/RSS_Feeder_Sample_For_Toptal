#include "RSSFeeder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RSSFeeder w;
    w.show();
    return a.exec();
}
