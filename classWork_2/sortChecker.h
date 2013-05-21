#pragma once

#include <stdlib.h>

//! @class SortChecker check array of any standart type for regular sorting
template <typename Type>
class SortChecker
{
public:
    SortChecker(int const &size)
        : mSize(size)
    {
        int const maxRand = 100;
        mArray = new Type[mSize];
        for (int i = 0; i < mSize; i++)
        {
            mArray[i] = rand() % maxRand;
        }
    }

    ~SortChecker()
    {
        delete[] mArray;
    }

    bool testSorting()
    {
        for (int i = 0; i < mSize - 1; i++)
        {
            if (mArray[i] > mArray[i + 1])
                return false;
        }
        return true;
    }

    Type* array()
    {
        return mArray;
    }

private:
    Type *mArray;
    int const mSize;
};


