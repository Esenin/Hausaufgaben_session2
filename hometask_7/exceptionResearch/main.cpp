#include "corruptedClass.h"
#include "exceptionTest.h"

int main()
{
    ExceptionTest test;
    QTest::qExec(&test);

    return 0;
}

