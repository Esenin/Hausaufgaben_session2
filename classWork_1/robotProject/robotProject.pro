TEMPLATE = app
CONFIG += console qtestlib
CONFIG += qt

SOURCES += main.cpp \
    robotModel.cpp \
    connector.cpp \
    usbConnector.cpp \
    bToothConnector.cpp \
    robotManager.cpp

HEADERS += \
    robotModel.h \
    connector.h \
    usbConnector.h \
    bToothConnector.h \
    robotManager.h \
    robotManagetTest.h

