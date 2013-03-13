#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "calcProcessor.h"

class CalculatorTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        calculator = new CalcProcessor;
    }

    void calcSimpleTest()
    {
        QVERIFY(calculator->calculate(QString("1 + 1")) == 2);
    }

    void calcHardTest()
    {
        QVERIFY(calculator->calculate(QString("1 / 3")) - (1.0 / 3) < calculator->fastNull);
    }

    void cleanupTestCase()
    {
        delete calculator;
    }

private:
    CalcProcessor *calculator;
};
