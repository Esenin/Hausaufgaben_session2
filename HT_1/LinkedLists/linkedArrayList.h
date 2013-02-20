#ifndef LINKEDARRAYLIST_H
#define LINKEDARRAYLIST_H

#include "list.h"
#include <iostream>

using std::cout;

class LinkedArrayList : public List
{
public:
    LinkedArrayList();
    virtual ~LinkedArrayList();

    virtual void add(int newValue);
    virtual void remove(int target);
    virtual void writeAll() const;
    virtual bool isExists(int target) const;

protected:
    void checkOverflow();

private:
    int *array;
    const int containerSize;
    int currentSize;
};

#endif // LINKEDARRAYLIST_H
