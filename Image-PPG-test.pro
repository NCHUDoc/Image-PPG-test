#-------------------------------------------------
#
# Project created by QtCreator 2017-05-09T17:28:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Image-PPG-test
TEMPLATE = app


SOURCES += main.cpp \
    widget.cpp

HEADERS  += widget.h \
    common.h \
    cal.h \
    fir64.h \
    resample.h \
    R_peak.h \
    PSD.h \
    Mainqtreal.h \
    nod.h

FORMS    += widget.ui

DEFINES += QWT_DLL
CONFIG += qwt
LIBS +=-L"C:/Qt/4.8.6/lib" -lqwtd
LIBS +=-L"C:/Qt/4.8.6/lib" -lqwt
LIBS +=-L"C:/Qt/4.8.6/bin"
#LIBS +=-L"D:\\qwt-6.0.1\\lib" -lqwtd
#LIBS +=-L"D:\\qwt-6.0.1\\lib" -lqwt
INCLUDEPATH +=C:/Qt/4.8.6/include/
INCLUDEPATH +=C:/Qt/4.8.6/include/phonon
INCLUDEPATH +=C:/Qt/4.8.6/bin/
#INCLUDEPATH +=D:\\qwt-6.0.1\\src


