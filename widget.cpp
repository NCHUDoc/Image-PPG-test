#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QIODevice>
#include <QFile>
#include <QtCore>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_curve.h>
#include <qwt_scale_draw.h>
#include <qwt_scale_widget.h>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_grid.h>
#include <QTime>
#include <qtimer.h>
#include <QMessageBox>
#include <qcolor.h>
#include <qwt_plot_zoomer.h>

#define X_SIZE 640 //640*480 sequence
#define Y_SIZE 480 //640*480 sequence
int ONE_SIZE= X_SIZE* Y_SIZE;
//FILE *video_ptr;
//QImage *frame;
unsigned char y_color[480][640];
//char *y_color = new char[10];
unsigned char cb_img[240][320];
unsigned char cr_img[240][320];
unsigned char rgb_buffer[640*480*3];
unsigned char  yuv_buffer_pointer[640*480*3];
qint8 enable;


widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    //***********************LCD***************************************
        ui->RRI_LCD->setSegmentStyle(QLCDNumber::Flat);   // Show RRI value real time(Object LCD_Number)
        ui->RRI_LCD->display(0);
        ui->HR_LCD->setSegmentStyle(QLCDNumber::Flat);      // Show HR value real time(Object LCD_Number)
        ui->HR_LCD->display(0);
        ui->ration_LCD->setSegmentStyle(QLCDNumber::Flat);  // Show Ratio of LF/HF real time(Object LCD_Number)

        //connect(ui->pushButton_1,SIGNAL(clicked()), this,SLOT(cal_start()));    //  Start Button (Object push_button)
        connect(ui->pushButton_2,SIGNAL(clicked()), this,SLOT(close()));        //  Cllose Button (Object push_button)

    //***********************wave***************************************************
        ui->qwtPlot->setCanvasBackground( QColor(0,0,0));
        ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,30*5);
        ui->qwtPlot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);
        ui->qwtPlot->setAxisScale(QwtPlot::yLeft,-3,3);
        ui->qwtPlot->setAxisMaxMinor(QwtPlot::yLeft,0.2);
        p_adplot = new QwtPlotCurve();
        p_adplot->setPen(QPen(Qt::green,1,Qt::SolidLine));
        p_adplot->attach(ui->qwtPlot);

        //time = 0.0;

//        adPlotTimer = new QTimer();
        //adPlotTimer->start();//1000

        //connect(adPlotTimer, SIGNAL(timeout()),this, SLOT(plotAdCurve()));

        QwtPlotGrid *grid = new QwtPlotGrid();
        grid->setPen(QPen(Qt::gray, 0.0, Qt::DotLine));
        grid->enableX(ui->qwtPlot);
        grid->enableXMin(ui->qwtPlot);
        grid->enableY(ui->qwtPlot);
        grid->enableYMin(ui->qwtPlot);
        grid->attach(ui->qwtPlot);
    //*************************************************
    //*********************psd*************************

//        ui->psdPlot->setCanvasBackground( QColor(0,0,0));
//        ui->psdPlot->setAxisScale(QwtPlot::xBottom,0,500);
//        ui->psdPlot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);
//        ui->psdPlot->setAxisScale(QwtPlot::yLeft,0,6);
//        ui->psdPlot->setAxisMaxMinor(QwtPlot::yLeft,0.2);
//        p_psdplot = new QwtPlotCurve();
//        p_psdplot->setPen(QPen(Qt::green,1,Qt::SolidLine));
//        p_psdplot->attach(ui->psdPlot);

        //time = 0.0;

//        psdPlotTimer = new QTimer();
        //psdPlotTimer->start();//1000

        //connect(psdPlotTimer, SIGNAL(timeout()),this, SLOT(plotPSDCurve()));

        QwtPlotGrid *grid2 = new QwtPlotGrid();
        grid2->setPen(QPen(Qt::gray, 0.0, Qt::DotLine));
        grid2->enableX(ui->psdPlot);
        grid2->enableXMin(ui->psdPlot);
        grid2->enableY(ui->psdPlot);
        grid2->enableYMin(ui->psdPlot);
        grid2->attach(ui->psdPlot);







    //QFile file("new000.yuv");
    video_ptr = fopen("new000.yuv","rb");
    frame = new QImage(rgb_buffer,640,480,QImage::Format_RGB888);
    //QFile file("out.txt");
    //QString bytes = "";
    //qint64 bytes;
    //file.open(QIODevice::ReadOnly);
    //QByteArray bytes = file.readAll();
    fread(yuv_buffer_pointer, sizeof(unsigned char), ONE_SIZE*2, video_ptr);

    ///////////////422-420
    for(int y=0;y<480;y++)
        for(int x=0;x<640;x++)
            y_color[y][x]=yuv_buffer_pointer[2*(x+y*640)];

    for(int y=0;y<240;y++,y++)
        for(int x=0;x<320;x++,x++)
            {
                cb_img[y][x]=yuv_buffer_pointer[(x+y*640)*4+1];
                cr_img[y][x]=yuv_buffer_pointer[(x+y*640)*4+3];
            }
    //QDataStream data(&file);
    //qint8 bytes = file.read(static_cast<char *>(y_color), sizeof(y_color));
    //qint16 bytes;
    //data >> bytes;

    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][0];
    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][1];
    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][2];
    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][3];
    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][4];
    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][5];
    //file.close();
//    video_ptr = fopen("C:/Users/User/git/Imag-PPG-test/zz05.yuv","rb");
//    frame = new QImage(rgb_buffer,640,480,QImage::Format_RGB888);
}

widget::~widget()
{
    delete ui;
}

void widget::paintEvent(QPaintEvent *)
{
    enable=1;
}

void widget::cal_start(){
    //enable=1;
}

void widget::plotAdCurve(){

    //enable=1;
    //readAdData(xData,yData);
    //p_adplot->setSamples(xData,yData);

    //p_adplot->attach(ui->qwtPlot);
    //ui->qwtPlot->replot();
    //adPlotTimer->start(1000);
}


void widget::plotPSDCurve(){



    //readPSDData(uptimeData,ratioData);
    //p_psdplot->setSamples(uptimeData,ratioData);

    //p_psdplot->attach(ui->psdPlot);
    //ui->psdPlot->replot();
    //adPlotTimer->start(1000);

}
