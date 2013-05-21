#pragma once

#include <QtTest/QTest>
#include <QObject>

#include "comparator.h"
#include "bubbleSort.h"
#include "sortChecker.h"

class ComparatorSortTest : public QObject
{
    Q_OBJECT
public:
    ComparatorSortTest()
        : arraySize(50)
    {
    }

private slots:
    void simpleComparatorTest()
    {
        Comparator<int> compare;
        int const lesser = 5;
        int const greater = 6;
        QVERIFY(compare.isLeftNext(lesser, greater));
    }

    void intSortTest()
    {
        Comparator<int> compare;
        SortChecker<int> checker(arraySize);
        BubbleSort<int> sorter(checker.array(), arraySize, &compare);

        sorter.sort();

        QVERIFY(checker.testSorting());
    }

    void doubleSortTest()
    {
        Comparator<double> compare;
        SortChecker<double>  checker(arraySize);
        BubbleSort<double> sorter(checker.array(), arraySize, &compare);

        sorter.sort();

        QVERIFY(checker.testSorting());
    }

private:
    int const arraySize;
};
