#pragma once

#include <iostream>
#include "list.h"


using std::cout;

class SortedArrayList : public List
{
public:
    SortedArrayList();
    virtual ~SortedArrayList();

    virtual void add(int newValue);
    virtual void remove(int target);
    virtual void writeAll() const;
    virtual bool exists(int target) const;
    virtual int& operator[](int index);

protected:
    void checkOverflow();
    int getItemIndex(const int target) const;

private:
    int *array;
    const int containerSize;
    int currentSize;
};

