#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}

//cmake -DCMAKE_PREFIX_PATH="D:\Qt\6.8.2\msvc2022_64\lib\cmake\Qt6" ..