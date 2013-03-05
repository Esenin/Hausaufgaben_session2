#-------------------------------------------------
#
# Project created by QtCreator 2012-10-12T16:31:24
#
#-------------------------------------------------

QT       += core gui

TARGET = calc
TEMPLATE = app


SOURCES += main.cpp\
        calcWidget.cpp \
    polandFormulaTranslator.cpp \
    calcProcessor.cpp \
    priorityInfo.cpp \
    formulaChecker.cpp

HEADERS  += calcWidget.h \
    polandFormulaTranslator.h \
    calcProcessor.h \
    priorityInfo.h \
    formulaChecker.h

FORMS    += calcWidget.ui
