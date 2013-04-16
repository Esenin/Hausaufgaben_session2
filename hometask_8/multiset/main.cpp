#include <QtTest/QTest>

#include "testRBTree.h"
#include "testRBTreeIterator.h"
#include "testBag.h"

int main()
{
    RBTreeTest treeTest;
    QTest::qExec(&treeTest);

    RBTreeIteratorTest iteratorTest;
    QTest::qExec(&iteratorTest);

    BagTest multiSetTest;
    QTest::qExec(&multiSetTest);

    return 0;
}

