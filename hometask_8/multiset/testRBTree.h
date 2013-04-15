#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "rBTree.h"

class RBTreeTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        tree = NULL;
        tree = new RBTree;
        QVERIFY(tree);
    }

    void singleAdditionTest()
    {
        QCOMPARE(tree->exists(42), false);
        tree->add(42);
        QVERIFY(tree->exists(42));
    }

    void grandAdditionTest()
    {
        for (int i = 1; i < 1993; i += 2)
            tree->add(i);

        for (int i = 1; i < 1993; i += 2)
            QVERIFY(tree->exists(i));
        QVERIFY(tree->exists(42));
    }

    void singleRemoveTest()
    {
        tree->removeOne(42);
        QVERIFY(!tree->exists(42));
    }

    void grandRemoveTest()
    {
        for (int i = 1; i < 1993; i += 2)
            tree->removeOne(i);

        for (int i = 1; i < 1993; i += 2)
            QVERIFY(tree->exists(i) == false);
    }

    void multiRemovingTest()
    {
        for (int i = 0; i < 14; i++)
            tree->add(451);

        QVERIFY(tree->exists(451));

        tree->removeOne(451);
        QVERIFY(tree->exists(451));

        tree->removeAllAs(451);
        QVERIFY(tree->exists(451) == false);
    }

    void cleanupTestCase()
    {
        delete tree;
    }

private:
    RBTree *tree;
};
