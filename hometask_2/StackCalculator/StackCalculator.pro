TEMPLATE = app
CONFIG += console qtestlib
CONFIG += qt

SOURCES += main.cpp \
    stack.cpp \
    priorityInfo.cpp \
    polandFormulaTranslator.cpp \
    formulaChecker.cpp \
    calcProcessor.cpp \
    arrayStack.cpp \
    linkedStack.cpp

HEADERS += \
    stack.h \
    priorityInfo.h \
    polandFormulaTranslator.h \
    formulaChecker.h \
    calcProcessor.h \
    arrayStack.h \
    linkedStack.h \
    stackTests.h \
    calculatorTest.h

