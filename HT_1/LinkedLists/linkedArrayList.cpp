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
    array[elementsCount++] = newValue;
    checkOverflow();
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
    for (int i = elementsCount - 1; i >= 0; i--)
    {
        if (array[i] == target)
        {
            for (int shift = i; shift < elementsCount - 1; shift++)
                array[shift] = array[shift + 1];
            elementsCount--;
        }
    }
}

void LinkedArrayList::writeAll() const
{
    for (int i = 0; i < elementsCount; i++)
        cout << array[i] << " ";
    cout << "\n";
}


bool LinkedArrayList::isExists(int target) const
{
    for (int i = 0; i < elementsCount; i++)
        if (array[i] == target)
            return true;
    return false;
}
