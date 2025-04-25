#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CPU Scheduler");
    QIcon icon("cpu.png");
    w.setWindowIcon(icon);


    w.show();
    return a.exec();
}
