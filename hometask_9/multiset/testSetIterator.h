#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "myMultiSet.h"

class SetIteratorTest : public QObject
{
    Q_OBJECT

protected:
    void loadTree()
    {
        for (int i = 1; i < bound; i += 2)
            mSet->add(i);
    }

private slots:
    void initTestCase()
    {
        mSet = new MyMultiSet<int>;
        loadTree();
    }

    void iteratorSimpleTest()
    {
        int compareModel = 1;

        MyMultiSet<int>::ForwardIterator iterator(mSet);
        while (iterator.hasNext())
        {
            QCOMPARE(iterator.next(), compareModel);
            compareModel += 2;
        }

        QVERIFY(compareModel >= bound);
    }

    void iteratorAddingTest()
    {
        MyMultiSet<int>::ForwardIterator iterator(mSet);
        for (int i = 1; i < 143; i++)
            iterator.add(i);

        iterator.resetToFirst();
        int compareModel = 1;
        while(iterator.hasNext())
        {
            QCOMPARE(iterator.next(), compareModel);
            if (compareModel % 2)
                QCOMPARE(iterator.next(), compareModel);
            compareModel++;
        }
    }

    void iteratorRemovingTest()
    {
        MyMultiSet<int>::ForwardIterator iterator(mSet);
        while (iterator.hasNext())
        {
            if (iterator.next() % 2)
            {
                iterator.removeItem();
            }
        }

        iterator.resetToFirst();
        int compareModel = 2;
        while(iterator.hasNext())
        {
            QCOMPARE(iterator.next(), compareModel);
            compareModel += 2;
        }

    }

    void cleanupTestCase()
    {
        delete mSet;
    }

private:
    MyMultiSet<int> *mSet;
    static const int bound = 143;
};
