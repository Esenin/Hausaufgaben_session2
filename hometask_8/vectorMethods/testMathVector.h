#pragma once

#include <QtTest/QTest>
#include <QtCore/QObject>
#include <QDebug>

#include "mathVector.h"

class MathVectorTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        vector1 = new MathVector(2);
    }

    void additionTest()
    {
        vector1->setValueAt(1, 0);
        vector1->setValueAt(1, 1);

        QVERIFY(vector1->valueAt(0));
        QVERIFY(vector1->valueAt(1));
    }

    void copyTest()
    {
        MathVector vector2(vector1);
        QVERIFY(vector2.valueAt(0));
        QVERIFY(vector2.valueAt(1));
    }

    void summaryTest()
    {
        MathVector vector2(vector1);
        (*vector1) += vector2;
        QCOMPARE(vector1->valueAt(0), 2 * vector2.valueAt(0));
        QCOMPARE(vector1->valueAt(1), 2 * vector2.valueAt(1));
    }

    void subtractionTest()
    {
        MathVector vector2(vector1);
        vector2 -= vector1;
        QVERIFY(vector2.isZeroVector());
    }

    void scalarMultTest()
    {
        MathVector localVector = vector1;
        QCOMPARE(localVector * localVector, (double)8);
    }

    void cleanupTestCase()
    {
        delete vector1;
    }

private:
    MathVector *vector1;
};
