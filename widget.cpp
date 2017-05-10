#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QIODevice>
#include <QFile>
#include <QtCore>


widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    QFile file("C:/Users/User/git/Image-PPG-test/out.txt");
    file.open(QIODevice::Append);
    QDataStream out(&file);
    out << QString("the answer is");   // serialize a string
    out << (qint32)42;        // serialize an integer
    //out << map;
    file.close();
//    video_ptr = fopen("C:/Users/User/git/Imag-PPG-test/zz05.yuv","rb");
//    frame = new QImage(rgb_buffer,640,480,QImage::Format_RGB888);
}

widget::~widget()
{
    delete ui;
}
