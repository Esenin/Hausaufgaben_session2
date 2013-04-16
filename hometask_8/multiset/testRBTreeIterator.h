#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "rBTree.h"

class RBTreeIteratorTest : public QObject
{
    Q_OBJECT

protected:
    void loadTree()
    {
        for (int i = 1; i < 143; i += 2)
            tree->add(i);
    }

private slots:
    void initTestCase()
    {
        tree = new RBTree<int>;
        loadTree();
    }

    void iteratorSimpleTest()
    {
        RBTree<int>::ConstIterator iterator(tree);

        for (int i = 1; i < 143; i += 2)
        {
            QCOMPARE(iterator.current().first, i);
            iterator++;
        }
    }

    void iteratorComplexTest()
    {
        RBTree<int>::ConstIterator iterator(tree);

        for (int i = 1; i < 143; i++)
        {
            tree->add(i);
        }

        for (int i = 1; i < 143; i++)
        {
            QCOMPARE(iterator.current().first, i);
            QCOMPARE(iterator.current().second, (i % 2) + 1);
            iterator++;
        }
    }

    void cleanupTestCase()
    {
        delete tree;
    }

private:
    RBTree<int> *tree;
};
