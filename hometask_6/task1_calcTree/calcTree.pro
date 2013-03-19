TEMPLATE = app
CONFIG += console qtestlib
CONFIG += qt

SOURCES += main.cpp \
    calcTree.cpp \
    node.cpp \
    operatorNode.cpp \
    operandNode.cpp

HEADERS += \
    calcTree.h \
    calcTreeTest.h \
    node.h \
    operatorNode.h \
    operandNode.h

