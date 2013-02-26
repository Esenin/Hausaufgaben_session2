#include "quickSorter.h"


using std::swap;
using std::cout;

QuickSorter::QuickSorter(int array[], int size) :
    Sorter(array, size)
{
}

void QuickSorter::sort()
{
    int const arrStart = 0;
    qSort(insideArray, arrStart, arrSize - 1);
}

void QuickSorter::qSort(int *array, int first, int last)
{
    int left = first;
    int right = last;
    int cool = array[(left + right) / 2];

    do
    {
        while (array[left] < cool)
            left++;
        while (array[right] > cool)
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
