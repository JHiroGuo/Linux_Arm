#include "mainwindow.h"
#include <QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"command- line  arguments :"<<argc;
    qDebug()<<"command- line  arguments :"<<argv[1];
    MainWindow w;
    w.setFixedSize(480,480);
    w.show();


    return a.exec();
}
