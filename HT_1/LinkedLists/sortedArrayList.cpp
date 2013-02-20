#include "sortedArrayList.h"

SortedArrayList::SortedArrayList() :
    List(),
    containerSize(50),
    currentSize(50)
{
    array = new int[containerSize];
}

SortedArrayList::~SortedArrayList()
{
    currentSize = 0;
    elementsCount = 0;
    delete array;
}

int &SortedArrayList::operator[](int index)
{
    if (index < 0)
        return array[0];

    if (index >= elementsCount)
        return array[elementsCount - 1];

    return array[index];
}

void SortedArrayList::add(int newValue)
{
    if (isEmpty())
    {
        array[elementsCount++] = newValue;
        return;
    }

    int newIndex = getItemIndex(newValue);

    if (array[newIndex] == newValue)
        return;

    /// Shift right part
    for (int i = elementsCount; i > newIndex; i--)
        array[i] = array[i - 1];

    array[newIndex + ((array[newIndex] < newValue)? 1 : 0)] = newValue;
    elementsCount++;

    checkOverflow();
}

void SortedArrayList::checkOverflow()
{
    const int delta = 5;
    if (currentSize - elementsCount > delta)
        return;

    int *newArray = new int[currentSize + containerSize];
    for (int i = 0; i < elementsCount; i++)
        newArray[i] = array[i];

    int *temp = array;
    array = newArray;
    currentSize =+ containerSize;

    delete temp;
}

void SortedArrayList::remove(int target)
{
    int targetIndex = getItemIndex(target);
    if (array[targetIndex] != target)
        return;

    for (int i = targetIndex; i < elementsCount - 1; i++)
        array[i] = array[i + 1];

    elementsCount--;
}

int SortedArrayList::getItemIndex(const int target) const
{
    /// I wanna return the most closest item, where I can also put the new
    /// binary search
    int left = 0;
    int right = elementsCount - 1;
    int pivotIndex = 0;

    while (left < right)
    {
        pivotIndex = (left + right) / 2;

        if (array[pivotIndex] == target)
            return pivotIndex;

        if (array[pivotIndex] < target)
            left = pivotIndex + 1;
        else
            right = pivotIndex - 1;


        if (right <= 0)
            return 0;
        if (left >= elementsCount - 1)
            return (elementsCount - 1);
    }
    /// here case right == left
    return right;
}

void SortedArrayList::writeAll() const
{
    for (int i = 0; i < elementsCount; i++)
        cout << array[i] << " ";

    cout << "\n";
}


bool SortedArrayList::isExists(int target) const
{
    return array[getItemIndex(target)] == target;
}
