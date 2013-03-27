#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "linkedList.h"

using namespace linkedListExceptions;

class ListTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        linkedList = NULL;
        linkedList = new LinkedList<int>;
        QVERIFY(linkedList);
    }

    void simpleAddTest()
    {
        linkedList->add(42);
        QVERIFY(linkedList->size() == 1);
        QVERIFY(linkedList->exists(42));
    }

    void simpleRemoveTest()
    {
        linkedList->remove(42);
        QCOMPARE(linkedList->size(), 0);
        QVERIFY(!linkedList->exists(42));
    }

    void exceptionAddingTest()
    {
        int const count = 10;
        int data[count] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
        int exceptionCounter = 0;
        for (int i = 0; i < count; i++)
        {
            try
            {
                linkedList->add(data[i]);
            }
            catch(BadNewKey const &)
            {
                exceptionCounter++;
            }
            catch(LinkedListExceptions const &)
            {
                exceptionCounter++;
            }
        }

        QCOMPARE(exceptionCounter, 5);
    }

    void searchTest()
    {
        QCOMPARE(linkedList->exists(1), true);
        QCOMPARE(linkedList->exists(6), false);
    }

    void removingTest()
    {
        int exceptionCounter = 0;
        try
        {
            linkedList->remove(5);
            linkedList->remove(5);
        }
        catch(NoSuchKey const &)
        {
            exceptionCounter++;
        }

        QCOMPARE(exceptionCounter, 1);
        QCOMPARE(linkedList->exists(5), false);
    }

    void indexingTest()
    {
        try
        {
            QCOMPARE((*linkedList)[2], 3);
            linkedList->exists((*linkedList)[100500]);
        }
        catch(OutOfRange const &)
        {
            QVERIFY(true);
            return;
        }
        QVERIFY(false);
    }


    void cleanupTestCase()
    {
        delete linkedList;
    }

private:
    LinkedList<int> *linkedList;

};
