#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <stdlib.h>

#include "bubbleSorter.h"
#include "quickSorter.h"

class SortersTest : public QObject
{
    Q_OBJECT
public:
    SortersTest() : size(20)
    {
    }

private slots:
    void initTestCase()
    {
        array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = rand() % size;

        bSorter = new BubbleSorter(array, size);
        qSorter = new QuickSorter(array, size);
    }

    void bubbleSortTest()
    {
        bSorter->sort();
        for (int i = 0; i < size - 1; i++)
            QVERIFY(array[i] <= array[i + 1]);
    }

    void quickSortTest()
    {
        array[0] = array[size - 1];
        qSorter->sort();
        for (int i = 0; i < size - 1; i++)
            QVERIFY(array[i] <= array[i + 1]);
    }

    void cleanupTestCase()
    {
        delete bSorter;
        delete qSorter;
        delete array;
    }

private:
    BubbleSorter *bSorter;
    QuickSorter *qSorter;
    int *array;
    int const size;
};
