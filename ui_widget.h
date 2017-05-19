/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QLCDNumber *RRI_LCD;
    QLCDNumber *HR_LCD;
    QLCDNumber *ration_LCD;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QwtPlot *qwtPlot;
    QwtPlot *psdPlot;
    QLabel *RRI;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QString::fromUtf8("widget"));
        widget->resize(1023, 633);
        RRI_LCD = new QLCDNumber(widget);
        RRI_LCD->setObjectName(QString::fromUtf8("RRI_LCD"));
        RRI_LCD->setGeometry(QRect(80, 570, 101, 51));
        HR_LCD = new QLCDNumber(widget);
        HR_LCD->setObjectName(QString::fromUtf8("HR_LCD"));
        HR_LCD->setGeometry(QRect(240, 570, 111, 51));
        ration_LCD = new QLCDNumber(widget);
        ration_LCD->setObjectName(QString::fromUtf8("ration_LCD"));
        ration_LCD->setGeometry(QRect(430, 570, 101, 51));
        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(690, 560, 71, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_1->setFont(font);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(810, 560, 71, 51));
        pushButton_2->setFont(font);
        qwtPlot = new QwtPlot(widget);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
        qwtPlot->setGeometry(QRect(670, 30, 321, 241));
        qwtPlot->setFrameShape(QFrame::StyledPanel);
        qwtPlot->setFrameShadow(QFrame::Raised);
        psdPlot = new QwtPlot(widget);
        psdPlot->setObjectName(QString::fromUtf8("psdPlot"));
        psdPlot->setGeometry(QRect(670, 310, 311, 201));
        psdPlot->setFrameShape(QFrame::StyledPanel);
        psdPlot->setFrameShadow(QFrame::Raised);
        RRI = new QLabel(widget);
        RRI->setObjectName(QString::fromUtf8("RRI"));
        RRI->setGeometry(QRect(30, 570, 47, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        RRI->setFont(font1);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 580, 31, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 580, 47, 41));
        label_3->setFont(font1);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 640, 480));
        label->setFrameShape(QFrame::NoFrame);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(910, 10, 71, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(900, 280, 91, 20));
        label_5->setFont(font2);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(930, 520, 51, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Agency FB"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_6->setFont(font3);

        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "win_camera_AVI", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("widget", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("widget", "Close", 0, QApplication::UnicodeUTF8));
        RRI->setText(QApplication::translate("widget", "RRI", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("widget", "HR", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("widget", "LF/HF", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_4->setText(QApplication::translate("widget", "Data 30fps", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("widget", "Ratio of LF/HF", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("widget", "4 Seconds", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
