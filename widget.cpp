#include "widget.h"
#include "ui_widget.h"
#include "cal.h"
#include "resample.h"
#include "R_peak.h"
#include "PSD.h"
#include "Mainqtreal.h"
#include <QImage>
#include <QIODevice>
#include <QFile>
#include <QtCore>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <QtGui/QApplication>
#include <qapplication.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qpainter.h>
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
#include <qfile.h>
#include <qtextstream.h>
#include <qfiledialog.h>

#define X_SIZE 640 //640*480 sequence
#define Y_SIZE 480 //640*480 sequence
//int ONE_SIZE= X_SIZE* Y_SIZE;
////FILE *video_ptr;
////QImage *frame;
unsigned char y_color[480][640];
//char *y_color = new char[10];
unsigned char cb_img[240][320];
unsigned char cr_img[240][320];
//unsigned char rgb_buffer[640*480*3];
//unsigned char  yuv_buffer_pointer[640*480*3];
//qint8 enable;
int w_max,w_min,h_max,h_min;

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
//    //***********************LCD***************************************
        ui->RRI_LCD->setSegmentStyle(QLCDNumber::Flat);   // Show RRI value real time(Object LCD_Number)
        ui->RRI_LCD->display(0);
        ui->HR_LCD->setSegmentStyle(QLCDNumber::Flat);      // Show HR value real time(Object LCD_Number)
        ui->HR_LCD->display(0);
        ui->ration_LCD->setSegmentStyle(QLCDNumber::Flat);  // Show Ratio of LF/HF real time(Object LCD_Number)

        connect(ui->pushButton_1,SIGNAL(clicked()), this,SLOT(cal_start()));    //  Start Button (Object push_button)
        connect(ui->pushButton_2,SIGNAL(clicked()), this,SLOT(close()));        //  Cllose Button (Object push_button)

//    //***********************wave***************************************************
        ui->qwtPlot->setCanvasBackground( QColor(0,0,0));
        ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,30*5);
        ui->qwtPlot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);
        ui->qwtPlot->setAxisScale(QwtPlot::yLeft,-3,3);
        ui->qwtPlot->setAxisMaxMinor(QwtPlot::yLeft,0.2);
        p_adplot = new QwtPlotCurve();
        p_adplot->setPen(QPen(Qt::green,1,Qt::SolidLine));
        p_adplot->attach(ui->qwtPlot);

//        //time = 0.0;

        adPlotTimer = new QTimer();
        adPlotTimer->start(1000);//1000

//        connect(adPlotTimer, SIGNAL(timeout()),this, SLOT(plotAdCurve()));

        QwtPlotGrid *grid = new QwtPlotGrid();
        grid->setPen(QPen(Qt::gray, 0.0, Qt::DotLine));
        grid->enableX(ui->qwtPlot);
        grid->enableXMin(ui->qwtPlot);
        grid->enableY(ui->qwtPlot);
        grid->enableYMin(ui->qwtPlot);
        grid->attach(ui->qwtPlot);
//        //*************************************************
//        //*********************psd*************************

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
//        psdPlotTimer->start();//1000

        //connect(psdPlotTimer, SIGNAL(timeout()),this, SLOT(plotPSDCurve()));

//        QwtPlotGrid *grid2 = new QwtPlotGrid();
//        grid2->setPen(QPen(Qt::gray, 0.0, Qt::DotLine));
//        grid2->enableX(ui->psdPlot);
//        grid2->enableXMin(ui->psdPlot);
//        grid2->enableY(ui->psdPlot);
//        grid2->enableYMin(ui->psdPlot);
//        grid2->attach(ui->psdPlot);


//    //QFile file("new000.yuv");
//    video_ptr = fopen("new000.yuv","rb");
//    frame = new QImage(rgb_buffer,640,480,QImage::Format_RGB888);
//    //QFile file("out.txt");
//    //QString bytes = "";
//    //qint64 bytes;
//    //file.open(QIODevice::ReadOnly);
//    //QByteArray bytes = file.readAll();
//    fread(yuv_buffer_pointer, sizeof(unsigned char), ONE_SIZE*2, video_ptr);

//    ///////////////422-420
//    for(int y=0;y<480;y++)
//        for(int x=0;x<640;x++)
//            y_color[y][x]=yuv_buffer_pointer[2*(x+y*640)];

//    for(int y=0;y<240;y++,y++)
//        for(int x=0;x<320;x++,x++)
//            {
//                cb_img[y][x]=yuv_buffer_pointer[(x+y*640)*4+1];
//                cr_img[y][x]=yuv_buffer_pointer[(x+y*640)*4+3];
//            }
//    //QDataStream data(&file);
//    //qint8 bytes = file.read(static_cast<char *>(y_color), sizeof(y_color));
//    //qint16 bytes;
//    //data >> bytes;

//    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][0];
//    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][1];
//    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][2];
//    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][3];
//    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][4];
//    qDebug()<<"Read one byte from file new000.yuv: "<<y_color[0][5];
    //file.close();
    video_ptr = fopen("new000.yuv","rb");
    //video_ptr = fopen("C:/Users/User/git/Imag-PPG-test/zz05.yuv","rb");
//    frame = new QImage(rgb_buffer,640,480,QImage::Format_RGB888);
    frame = new QImage(r_buffer,640,480,QImage::Format_RGB888);
    qDebug()<<">>widget::widget(QWidget *parent):QWidget(parent),ui(new Ui::widget)";
    qDebug()<<"Read one byte from file new000.yuv: "<<video_ptr;
    qDebug()<<"=================================";

}

widget::~widget()
{
    delete ui;
}

void widget::paintEvent(QPaintEvent *)
{
      // Test paintEvent
//      enable=0;
//      qDebug()<<"enable = "<<enable;
    int i;
    double t30 [cal_time*framerate],tRRI[fs*cal_time],sumRRI,meanRRI;

    int ONE_SIZE= X_SIZE* Y_SIZE;//640*480 sequence


    if(enable==1)
    {

        fread(yuv_buffer_pointer, sizeof(unsigned char), ONE_SIZE*2, video_ptr);
//        qDebug()<<">>widget::paintEvent(QPaintEvent *)";
//        qDebug()<<"=================================";
        ///////////////422-420
//        for(int y=0;y<480;y++)
//            for(int x=0;x<640;x++)
//                y_color[y][x]=yuv_buffer_pointer[2*(x+y*640)];

//        for(int y=0;y<240;y++,y++)
//            for(int x=0;x<320;x++,x++)
//            {
//                cb_img[y][x]=yuv_buffer_pointer[(x+y*640)*4+1];
//                cr_img[y][x]=yuv_buffer_pointer[(x+y*640)*4+3];
//            }


//        //======face detect=======//
//        drowsydetect(&y_color[0][0],&cb_img[0][0],&cr_img[0][0],&h_max,&h_min,&w_max,&w_min);

//            //printf("h_1=%d h_2=%d w_1=%d w_2=%d\n",h_max,h_max,w_max,w_max);

//        //////////////420-422
//        for(int y=0;y<480;y++)
//            for(int x=0;x<640;x++)
//                yuv_buffer_pointer[2*(x+y*640)]=y_color[y][x];

//            for(int y=0;y<240;y++,y++)
//                for(int x=0;x<320;x++,x++)
//                {
//                    yuv_buffer_pointer[(x+y*640)*4+1]=cb_img[y][x];
//                    yuv_buffer_pointer[(x+y*640)*4+640*2+1]=cb_img[y][x];
//                    yuv_buffer_pointer[(x+y*640)*4+3]=cr_img[y][x];
//                    yuv_buffer_pointer[(x+y*640)*4+640*2+3]=cr_img[y][x];
//                }
    }

    convert_yuv_to_rgb_buffer();

    if(enable==1)
    {
//            qDebug()<<"rgb_average";
//            rgb_average(h_min,h_max,w_min,w_max);
            rgb_average();
            plotAdCurve();

            if(f_time>=cal_time){
                if(updata==updata_time ||updata==cal_time){

                        updata=0;


                        memset(t30, 0, cal_time*framerate*sizeof(double));
                        for(i=0;i<cal_time*framerate;i++){
                            t30[i+1]= t30[i]+0.0333;//1/30=0.0333

                            //printf("%d %.4f %.4f \n",i,t30[i],wave30[i]);
                        }


                        resample(t30, wave30,wave256,0.0039,30*60,256*60);//1/256=0.0039
                        R_peak(wave256,RRI_a,rR_peak);

                        memset(tRRI, 0, fs*cal_time*sizeof(double));
                        for(i=0;i<fs*cal_time;i++){
                            tRRI[i+1]= tRRI[i]+0.5;//0.5=1/fs
                            //printf("%d %.4f %.4f \n",i,t30[i],wave30[i]);
                        }
                        int time_RRI_a=rR_peak[len_RRI_a]*fs-2;
                        resample(rR_peak, RRI_a,RRI_b,0.5,len_RRI_a,time_RRI_a);//1/2=0.5
                        for(i=0;i<time_RRI_a;i++){
                            sumRRI= sumRRI+RRI_b[i];
                            //printf("%d %.4f %.4f \n",i,t30[i],wave30[i]);
                        }
                        meanRRI=sumRRI/time_RRI_a;   //zero mean
                        for(i=0;i<time_RRI_a;i++){
                            RRI_b[i]= RRI_b[i]-meanRRI;
                            //printf("%d %.4f %.4f \n",i,t30[i],wave30[i]);
                        }
                        hannig(RRI_b,RRI_c,time_RRI_a); //Window function

                        PSD (RRI_c,128,60,freq,power);
                        //ADD******************************************************************************
                        uptime_data[xxx]=xxx;
                        xxx=xxx+1;
                        if(xxx>1999)
                        {  xxx=0;
                           led_uptime=0;
                        }
                        //ADD******************************************************************************
                        plotPSDCurve();


                       // printf("time=%4f \n",rR_peak[len_RRI_a-3]);


            }

                ui->RRI_LCD->display(RRI_mean);
                ui->HR_LCD->display(HR);
                ui->ration_LCD->display(ration);

        }
    }


//    //Box();
//    frame->loadFromData(rgb_buffer,640 * 480 * 3);
//    ui->label->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));

 //   rs = vd->unget_frame();
    // Add for paintevent update timer - Mingfan 20170516
    this->update();
}


/*yuv convert to rgb*/
int widget::convert_yuv_to_rgb_buffer()
{
//    unsigned long in, out = 0,g_out=0;
    int in, out = 0,g_out=0;
    int y0, u, y1, v;
    int r, g, b;
    for(in = 0; in < X_SIZE* Y_SIZE*2; in += 4)
    {


        y0 = yuv_buffer_pointer[in + 0];
        u  = yuv_buffer_pointer[in + 1];
        y1 = yuv_buffer_pointer[in + 2];
        v  = yuv_buffer_pointer[in + 3];

        r = y0 + (1.370705 * (v-128));
        g = y0 - (0.698001 * (v-128)) - (0.337633 * (u-128));
        b = y0 + (1.732446 * (u-128)); //YUV420

//       /*  r = y0 + 1.042*(v-128);
//         g = y0 - 0.34414*(u-128) - 0.71414*(v-128);
//         b = y0 + 1.772*(u-128);*/ // YUV422

        if(r > 255) r = 255;
        if(g > 255) g = 255;
        if(b > 255) b = 255;
        if(r < 0) r = 0;
        if(g < 0) g = 0;
        if(b < 0) b = 0;
//        rgb_buffer[out++] = r;
//        rgb_buffer[out++] = g;
//        rgb_buffer[out++] = b;
        r_buffer[g_out++]= r;
        r = y1 + (1.370705 * (v-128));
        g = y1 - (0.698001 * (v-128)) - (0.337633 * (u-128));
        b = y1 + (1.732446 * (u-128)); //YUV420

//       /* r = y0 + 1.042*(v-128);
//        g = y0 - 0.34414*(u-128) - 0.71414*(v-128);
//        b = y0 + 1.772*(u-128);*/ // YUV422

        if(r > 255) r = 255;
        if(g > 255) g = 255;
        if(b > 255) b = 255;
        if(r < 0) r = 0;
        if(g < 0) g = 0;
        if(b < 0) b = 0;
//        rgb_buffer[out++] = r;
//        rgb_buffer[out++] = g;
//        rgb_buffer[out++] = b;

        r_buffer[g_out++]= r;

    }
//    qDebug()<<"rgb(r)"<< r;
//    qDebug()<<"r_buffer[g_out-1]"<< r_buffer[g_out-1];
    return 0;
}


void widget::readAdData(QVector< double > &xData,  QVector<double> &yData){

    xData.clear();
    yData.clear();

    for(int i=0;i<30*5;i++)
    {
        //new ECG
        xData.append(time_data[i]);
        yData.append(show_buffer[i]);
        //printf("show=%f ecg_data=%f\n",show_buffer[i],yData[i]);
    }
}


void widget::plotAdCurve(){

    readAdData(xData,yData);
    p_adplot->setSamples(xData,yData);

    p_adplot->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
//    adPlotTimer->start(1000);
//    qDebug()<<"adPlotTimer = "<<1000;
}

void widget::readPSDData(QVector< double > &uptimeData,  QVector<double> &ratioData){
    int i;
//    uptimeData.clear();
//    ratioData.clear();

//    for(i=0;i<xxx;i++)
//    {
//        uptimeData.append(uptime_data[i]);
//        ratioData.append(ratio_reg[i]);
//    }
}


void widget::plotPSDCurve(){

//    readPSDData(uptimeData,ratioData);
//    p_psdplot->setSamples(uptimeData,ratioData);

//    p_psdplot->attach(ui->psdPlot);
//    ui->psdPlot->replot();
//    //adPlotTimer->start(1000);

}

void widget::cal_start(){
    enable=1;
//    qDebug()<<"enable = "<<enable;
}
