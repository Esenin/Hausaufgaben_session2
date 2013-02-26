#include "bubbleSorter.h"

using std::swap;
using std::cout;

BubbleSorter::BubbleSorter(int array[], int size) :
    Sorter(array, size)
{
}

void BubbleSorter::sort()
{
    int const arrStart = 0;
    bSort(insideArray, arrStart, arrSize - 1);
}

void BubbleSorter::bSort(int *array, int first, int last)
{
    for (int k = first; k < last - 1; k++)
        for (int i = first; i < last - k; i++ )
            if (array[i] > array[i + 1])
                swap(array[i], array[i + 1]);
}
