#include "mySetTest.h"

using namespace std;

int main()
{
    MySetTest test;
    QTest::qExec(&test);

    return 0;
}

