#include "quicksorter.h"

using std::swap;
using std::cout;

QuickSorter::QuickSorter(int *array[], const int rowSize, const int colSize) :
    Sorter(array, rowSize, colSize)
{
}

void QuickSorter::sort()
{
    int const arrStart = 0;
    qSort(insideArray, arrStart, rowCount - 1);
}

void QuickSorter::qSort(int *array[], int first, int last)
{
    int const keyValue = 0;
    int left = first;
    int right = last;
    int pivot = array[(left + right) / 2][0];

    do
    {
        while (array[left][keyValue] < pivot)
            left++;
        while (array[right][keyValue] > pivot)
            right--;
        if (left <= right)
        {
            swap(array[left], array[right]);
            right--;
            left++;
        }
    }
    while (left <= right);

    if (left < last)
        qSort(array, left, last);
    if (right > first)
        qSort(array, first, right);
}
