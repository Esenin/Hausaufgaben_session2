#pragma once

#include <stdlib.h>
#include <iostream>

#include "list.h"

using std::cout;

class LinkedList : public List
{
public:
    LinkedList();
    virtual ~LinkedList();

    int getElementsCount();
    virtual void add(const int newValue);
    virtual void remove(int target);
    virtual bool exists(const int target) const;
    virtual void writeAll() const;
    virtual int& operator[](int index);

private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;

    ListElement *currPointer;
    int currPointerPosition;

    void deleteAll();
};

