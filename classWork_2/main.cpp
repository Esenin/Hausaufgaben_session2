#include <QtTest/QTest>

#include "comparatorSortTest.h"

int main()
{
    ComparatorSortTest sortTest;
    QTest::qExec(&sortTest);

    return 0;
}
