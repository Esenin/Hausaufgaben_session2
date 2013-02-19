#include "linkedArrayList.h"

LinkedArrayList::LinkedArrayList() :
    List(),
    containerSize(50),
    currentSize(50)
{
    array = new int[containerSize];
}

LinkedArrayList::~LinkedArrayList()
{
    currentSize = 0;
    elementsCount = 0;
    delete array;
}

void LinkedArrayList::add(int newValue)
{
    if (isEmpty())
    {
        array[elementsCount++] = newValue;
        return;
    }

    int newIndex = findItemIndex(newValue);
    if (array[newIndex] == newValue)
        return;

    for (int i = elementsCount; i > newIndex; i--)
    {
        array[i] = array[i - 1];
    }

    array[newIndex + (array[newIndex] < newValue)? 1 : 0] = newValue;
    elementsCount++;
    checkOverflow();
}

int LinkedArrayList::findItemIndex(const int value) const
{
    int left = 0;
    int right = elementsCount - 1;
    int pivotIndex = 0;
    while (right > left)
    {
        pivotIndex = (right + left) / 2;

        if (array[pivotIndex] > value)
            right = pivotIndex;
        else
        {
            if (array[pivotIndex] < value)
                left = pivotIndex;
            else
                break;
        }
    }

    return pivotIndex;
}

void LinkedArrayList::checkOverflow()
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

void LinkedArrayList::remove(int target)
{
    int index = findItemIndex(target);
    if (array[index] != target)
        return;

    for (int i = index; i < elementsCount; i++)
        array[i] = array[i + 1];

    elementsCount--;
}

void LinkedArrayList::writeAll() const
{
    for (int i = 0; i < elementsCount; i++)
        cout << array[i] << " ";
    cout << "\n";
}


bool LinkedArrayList::isExists(int target) const
{
    int index = findItemIndex(target);
    return (array[index] == target);
}
