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
    common.h

FORMS    += widget.ui

DEFINES += QWT_DLL
CONFIG += qwt
LIBS +=-L"C:/Qt/4.8.6/lib" -lqwtd
INCLUDEPATH +=C:/Qt/4.8.6/include/QtQwt
INCLUDEPATH +=C:/Qt/4.8.6/include/phonon

