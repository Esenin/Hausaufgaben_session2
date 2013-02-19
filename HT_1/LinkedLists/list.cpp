#include "list.h"

List::List() :
    elementsCount(0)
{
}

List::~List()
{
    elementsCount = 0;
}

bool List::isEmpty() const
{
    return (elementsCount <= 0);
}
