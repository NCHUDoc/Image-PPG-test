#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QIODevice>
#include <QFile>
#include <QtCore>
#include <QDebug>

//unsigned char y_color[480][640];
char *y_color = new char[10];
unsigned char cb_img[240][320];
unsigned char cr_img[240][320];

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    QFile file("new000.yuv");
    file.open(QIODevice::ReadOnly);
    //QDataStream data(&file);
    qint8 bytes = file.read(static_cast<char *>(y_color), sizeof(y_color));

    file.close();
    qDebug()<<"Read one byte from file new000.yuv: "<<bytes;
//    video_ptr = fopen("C:/Users/User/git/Imag-PPG-test/zz05.yuv","rb");
//    frame = new QImage(rgb_buffer,640,480,QImage::Format_RGB888);
}

widget::~widget()
{
    delete ui;
}
