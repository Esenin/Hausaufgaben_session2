#include <QtTest/QTest>

#include "testMathVector.h"

int main()
{
    MathVectorTest vectorsTest;
    QTest::qExec(&vectorsTest);

    return 0;
}

