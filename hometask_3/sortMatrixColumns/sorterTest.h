#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "quickSorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    SorterTest()
        : arraySorter(NULL)
        , rowCount(5)
        , colCount(10)
    {
        mainArray = createArray(rowCount, colCount);

        fillArray(mainArray, rowCount, colCount);
    }
    ~SorterTest()
    {
        for (int i = 0; i < rowCount; i++)
            delete[] mainArray[i];
        delete[] mainArray;
    }

private slots:
    void initTestCase()
    {
        arraySorter = new QuickSorter(mainArray, rowCount, colCount);
    }

    void sortTest()
    {
        arraySorter->sort();
        for (int i = 0; i < rowCount - 1; i++)
            QVERIFY(mainArray[i][0] <= mainArray[i + 1][0]);
    }

    void cleanupTestCase()
    {
        delete arraySorter;
    }

private:
    void fillArray(int *array[], int const rowSize, int const colSize)
    {
        int const randomMax = 50;

        for (int i = 0; i < rowSize; i++)
            for (int j = 0; j < colSize; j++)
                array[i][j] = rand() % randomMax;
    }

    int** createArray(int const &rowCount, int const &colCount)
    {
        int **array = new int* [rowCount];
        for (int i = 0; i < rowCount; i++)
            array[i] = new int[colCount];
        return array;
    }

    int **mainArray;
    QuickSorter *arraySorter;
    int const rowCount;
    int const colCount;
};
