#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "myMultiSet.h"

class BagTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        set = new MyMultiSet<int>;
    }

    void simpleAdditionTest()
    {
        QVERIFY(!set->contains(42));
        for (int i = 1; i < 300; i += 2)
            set->add(i);

        for (int i = 1; i < 300; i++)
            QCOMPARE(set->contains(i), i % 2);
    }

    void complexAdditionTest()
    {
        for (int i = 1; i < 300; i++)
            set->add(i, 2);

        for (int i = 1; i < 300; i++)
            QCOMPARE(set->contains(i), (i % 2) + 2);
    }

    void intersectTest()
    {
        MyMultiSet<int> secondSet;
        secondSet.add(-42, 100500);

        MyMultiSet<int> *commonSet = set->intersectWith(secondSet);

        QVERIFY(!commonSet->contains(-42));
        for (int i = 1; i < 300; i++)
            QVERIFY(!commonSet->contains(i));
        delete commonSet;
    }

    void mergeTest()
    {
        MyMultiSet<int> secondSet;

        for (int i = 0; i < 300; i += 2)
            secondSet.add(i);

        MyMultiSet<int> *summarySet = set->sumWith(secondSet);

        QVERIFY(summarySet->contains(0));
        for (int i = 1; i < 300; i++)
            QCOMPARE(summarySet->contains(i), 3);
        delete summarySet;
    }

    void simpleRemoveTest()
    {
        for (int i = 1; i < 300; i += 2)
            set->removeOne(i);

        for (int i = 1; i < 300; i++)
            QCOMPARE(set->contains(i), 2);
    }

    void exceptionTest()
    {
        bool catched = false;
        try
        {
            set->removeAllAs(465465464);
        }
        catch (const MyMultiSet<int>::SetExceptions &)
        {
            catched = true;
        }

        QVERIFY(catched);
    }

    void totalRemovingTest()
    {
        for (int i = 1; i < 300; i++)
        {
            set->removeAllAs(i);
            QVERIFY(!set->contains(i));
        }
    }

    void cleanupTestCase()
    {
        delete set;
    }

private:
    MyMultiSet<int> *set;
};

