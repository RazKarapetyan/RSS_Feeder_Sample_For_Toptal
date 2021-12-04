#include "GUI/RSSFeeder.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":icons/rss.png"));
    RSSFeeder w;
    w.show();
    return a.exec();
}
