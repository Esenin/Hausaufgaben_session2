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
        int compare = 1;
        for (MyMultiSet<int>::ConstForwardIterator iterator(mSet); !iterator.end(); iterator++)
        {
            QCOMPARE(iterator.current(), compare);
            compare += 2;
        }
        QVERIFY(compare >= bound);
    }

    void iteratorComplexTest()
    {
        for (int i = 1; i < 143; i++)
        {
            mSet->add(i);
        }

        MyMultiSet<int>::ConstForwardIterator iterator(mSet);

        for (int i = 1; i < 143; i++)
        {
            QCOMPARE(iterator.current(), i);
            if (i % 2)
            {
                iterator++;
                QCOMPARE(iterator.current(), i);
            }
            iterator++;
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
