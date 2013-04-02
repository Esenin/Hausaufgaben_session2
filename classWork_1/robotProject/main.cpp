#include <QtTest/QTest>

#include "robotManagetTest.h"

int main()
{
    RobotManagerTest test;
    QTest::qExec(&test);

    return 0;
}

