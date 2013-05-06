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
        for (int i = 1; i < size; i += 2)
            tree->add(i);
    }

private:
    RBTree<int> *tree;
    static const int size = 143;

private slots:
    void initTestCase()
    {
        tree = new RBTree<int>;
        loadTree();
    }

    void iteratorSimpleTest()
    {
        RBTree<int>::ForwardIterator iterator(tree);
        for (int i = 1; i < size; i += 2)
            QCOMPARE(iterator.next().first, i);
    }

    void iteratorAddingTest()
    {
        RBTree<int>::ForwardIterator iterator(tree);
        for (int i = 1; i < size; i++)
            iterator.add(i);

        int model = 0;
        while (iterator.hasNext())
        {
            QCOMPARE(iterator.next().first, ++model);
            QCOMPARE(iterator.current().second, (model % 2) + 1);
        }

        QVERIFY(model <= size);
    }

    void removingTest()
    {
        RBTree<int>::ForwardIterator iterator(tree);
        while(iterator.hasNext())
        {
            iterator.next();
            iterator.removeOne();
        }

        RBTree<int>::ForwardIterator postIterator(tree);
        while(postIterator.hasNext())
        {
            QVERIFY(postIterator.next().first % 2);
        }
    }

    void cleanupTestCase()
    {
        delete tree;
    }


};
