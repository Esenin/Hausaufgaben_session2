#include <QtTest/QTest>

#include "testRBTree.h"

int main()
{
    int debug = 0;
    debug = getchar();

    RBTreeTest treeTest;
    QTest::qExec(&treeTest);

    return 0;
}

