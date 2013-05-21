#pragma once

#include <stdlib.h>

#include "comparator.h"

using std::swap;

//! class BubbleSort provides array sorting with different compare method
template <typename Type>
class BubbleSort
{
public:
    //! @arg compObject specific comparator
    BubbleSort(Type *array, int const &count, Comparator<Type> const *compObject)
        : mCompare(compObject),
          mArray(array),
          size(count)
    {
    }

    void sort()
    {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - 1; j++)
                if (mCompare->isRightNext(mArray[j], mArray[j + 1]))
                    swap(mArray[j], mArray[j + 1]);
    }

private:
    Comparator<Type> const *mCompare;
    Type *mArray;
    int const size;
};


