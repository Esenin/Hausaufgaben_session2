#-------------------------------------------------
#
# Project created by QtCreator 2013-02-22T19:03:39
#
#-------------------------------------------------

QT       += core gui

TARGET = QuickPlot
TEMPLATE = app


SOURCES += main.cpp\
        realTimePlot.cpp \
    sensorGraph.cpp \
    keyPoint.cpp

HEADERS  += realTimePlot.h \
    sensorGraph.h \
    keyPoint.h

FORMS    += realTimePlot.ui

OTHER_FILES += \
    reset_btn.png \
    start_btn.png \
    stop_btn.png \
    zoomIn_btn.png \
    zoomOut_btn.png
