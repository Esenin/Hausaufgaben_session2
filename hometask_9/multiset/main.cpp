#include <QtTest/QTest>

#include "testRBTree.h"
#include "testRBTreeIterator.h"
#include "testBag.h"
#include "testSetIterator.h"

int main()
{
    RBTreeTest treeTest;
    QTest::qExec(&treeTest);

    RBTreeIteratorTest iteratorTest;
    QTest::qExec(&iteratorTest);

    BagTest multiSetTest;
    QTest::qExec(&multiSetTest);

    SetIteratorTest setIteratorTest;
    QTest::qExec(&setIteratorTest);

    return 0;
}

