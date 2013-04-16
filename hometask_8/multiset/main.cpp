#include <QtTest/QTest>

#include "testRBTree.h"
#include "testRBTreeIterator.h"

int main()
{
    RBTreeTest treeTest;
    QTest::qExec(&treeTest);

    RBTreeIteratorTest iteratorTest;
    QTest::qExec(&iteratorTest);

    return 0;
}

