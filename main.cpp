#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<">>int main(int argc, char *argv[])";
    qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath();
    qDebug()<<"current currentPath: "<<QDir::currentPath();
    qDebug()<<"=================================";
    widget w;
    w.show();

    return a.exec();
}
