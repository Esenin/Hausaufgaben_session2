#include "stack.h"

Stack::Stack() :
    elementsCount(0)
{
}

Stack::~Stack()
{
    elementsCount = 0;
}

bool Stack::isEmpty() const
{
    return (elementsCount <= 0);
}
