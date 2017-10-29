#include "testtouch.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestTouch w;
    w.show();

    return a.exec();
}
