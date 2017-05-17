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

INCLUDEPATH +=C:/opencv/install/include
INCLUDEPATH +=C:/opencv/debug/install/include

LIBS +=-LC:\\OpenCV\\install\\x86\\mingw\\bin\\
   -lopencv_core320 \
   -lopencv_features2d320 \
   -lopencv_flann320 \
   -lopencv_highgui320 \
   -lopencv_imgcodecs320 \
   -lopencv_imgproc320 \
   -lopencv_ml320 \
   -lopencv_objdetect320 \
   -lopencv_photo320 \
   -lopencv_shape320 \
   -lopencv_stitching320 \
   -lopencv_superres320 \
   -lopencv_video320 \
   -lopencv_videoio320 \
   -lopencv_videostab320

