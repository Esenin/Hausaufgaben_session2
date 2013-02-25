#include "arrayStack.h"

ArrayStack::ArrayStack() :
    Stack(),
    stackSize(50),
    currentStackSize(stackSize)
{
    array = new QString[stackSize];
}

ArrayStack::~ArrayStack()
{
    clear();
    delete[] array;
}

void ArrayStack::clear()
{
    for (int i = 0; i < elementsCount; i++)
        array[i].clear();
    elementsCount = 0;
}

void ArrayStack::push(const QString value)
{
    array[elementsCount++] = value;

    const int delta = 5;
    if (currentStackSize - elementsCount < delta)
        increaseStackSize();
}

QString ArrayStack::pop()
{
    return array[--elementsCount];
}

QString ArrayStack::top()
{
    return QString(array[elementsCount - 1]);
}

void ArrayStack::increaseStackSize()
{
    QString *newArray = new QString[currentStackSize + stackSize];
    for (int i = 0; i < elementsCount; i++)
        newArray[i] = array[i];

    QString *temp = array;
    array = newArray;
    delete temp;

    currentStackSize += stackSize;
}




