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

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QString::fromUtf8("widget"));
        widget->resize(1023, 633);
        RRI_LCD = new QLCDNumber(widget);
        RRI_LCD->setObjectName(QString::fromUtf8("RRI_LCD"));
        RRI_LCD->setGeometry(QRect(80, 550, 101, 51));
        HR_LCD = new QLCDNumber(widget);
        HR_LCD->setObjectName(QString::fromUtf8("HR_LCD"));
        HR_LCD->setGeometry(QRect(240, 550, 111, 51));
        ration_LCD = new QLCDNumber(widget);
        ration_LCD->setObjectName(QString::fromUtf8("ration_LCD"));
        ration_LCD->setGeometry(QRect(430, 550, 71, 51));
        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(690, 560, 75, 23));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(840, 560, 75, 23));
        qwtPlot = new QwtPlot(widget);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
        qwtPlot->setGeometry(QRect(530, 20, 431, 241));
        qwtPlot->setFrameShape(QFrame::StyledPanel);
        qwtPlot->setFrameShadow(QFrame::Raised);
        psdPlot = new QwtPlot(widget);
        psdPlot->setObjectName(QString::fromUtf8("psdPlot"));
        psdPlot->setGeometry(QRect(530, 310, 431, 181));
        psdPlot->setFrameShape(QFrame::StyledPanel);
        psdPlot->setFrameShadow(QFrame::Raised);
        RRI = new QLabel(widget);
        RRI->setObjectName(QString::fromUtf8("RRI"));
        RRI->setGeometry(QRect(20, 570, 47, 12));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 570, 47, 12));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 570, 47, 12));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 471, 451));

        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "widget", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("widget", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("widget", "Close", 0, QApplication::UnicodeUTF8));
        RRI->setText(QApplication::translate("widget", "RRI", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("widget", "HR", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("widget", "LF/HF", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("widget", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
