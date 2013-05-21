QT       += core

QT       -= gui

TARGET = strangeSort
CONFIG   += console += qtestlib
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    bubbleSort.h \
    comparator.h \
    comparatorSortTest.h \
    sortChecker.h
