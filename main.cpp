//  This software is covered by the MIT open source license. See misc/MIT.txt

#include <QApplication>
#include <QThread>
#include "Controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller controller;

    while ( controller.wakeUp() ) {
        a.processEvents();
        QThread::msleep(200);
    }
    return 0;
}
