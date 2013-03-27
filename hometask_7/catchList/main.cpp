#include <QtTest/QTest>

#include "listTest.h"

int main()
{
    ListTest test;
    QTest::qExec(&test);

    return 0;
}

