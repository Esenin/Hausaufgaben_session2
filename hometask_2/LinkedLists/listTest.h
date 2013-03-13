#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "linkedList.h"
#include "sortedArrayList.h"

class ListTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        linkedList = new LinkedList;
        arrList = new SortedArrayList;
    }

    void addingTest()
    {
        int const count = 10;
        int data[count] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
        for (int i = 0; i < count; i++)
        {
            linkedList->add(data[i]);
            arrList->add(data[i]);
        }

        QCOMPARE((*linkedList)[0], (*linkedList)[count - 1]);
        QCOMPARE((*linkedList)[count / 2], 5);
        QCOMPARE((*arrList)[4], 5);
    }

    void searchTest()
    {
        QCOMPARE(linkedList->exists(1), true);
        QCOMPARE(linkedList->exists(6), false);

        QCOMPARE(arrList->exists(1), true);
        QCOMPARE(arrList->exists(6), false);
    }

    void removingTest()
    {
        linkedList->remove(5);
        linkedList->remove(5);
        QCOMPARE(linkedList->exists(5), false);

        arrList->remove(5);
        QCOMPARE(arrList->exists(5), false);
    }


    void cleanupTestCase()
    {
        delete linkedList;
        delete arrList;
    }

private:
    LinkedList *linkedList;
    SortedArrayList *arrList;

};
