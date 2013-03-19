#pragma once

#include <QtTest/QtTest>

#include "mySet.h"

class MySetTest : public QObject
{
    Q_OBJECT
public:
    MySetTest()
        : size(5)
    {
        data = new int[size];
        // data consists of even numbers
        for (int i = 0; i < size; i++)
            data[i] = 2 * i;
    }

    ~MySetTest()
    {
        delete[] data;
    }

private slots:
    void initTestCase()
    {
        set = new MySet<int, 50>;
    }

    void addTest()
    {
        QVERIFY(!set->contains(42));
        set->add(42);
        QVERIFY(set->contains(42));
    }

    void multiAddTest()
    {
        for (int i = 0; i < size; i++)
            set->add(data[i]);

        for (int i = 0; i < size; i++)
            QVERIFY(set->contains(data[i]));
    }

    void removeTest()
    {
        QVERIFY(set->contains(42));
        set->remove(42);
        QVERIFY(!set->contains(42));
    }

    void mergeTest()
    {
        MySet<int, 50> other;
        for (int i = 0; i < 2 * size; i++)
            other.add(i);

        MySet<int, 50> *result = set->merge(other);

        for (int i = 0; i < size; i++)
            QVERIFY(result->contains(data[i]));
        for (int i = 0; i < size; i++)
            QVERIFY(result->contains(i));

        delete result;
    }

    void intersectTest()
    {
        MySet<int, 50> other;
        for (int i = 0; i < 2 * size; i++)
            other.add(i);

        MySet<int, 50> *result = set->intersect(other);

        for (int i = 0; i < 2 * size; i++)
            if (i % 2)
                QVERIFY(!result->contains(i));
            else
                QVERIFY(result->contains(i));

        delete result;
    }

    void cleanupTestCase()
    {
        delete set;
    }

private:
    MySet<int, 50> *set;
    int *data;
    int const size;
};

