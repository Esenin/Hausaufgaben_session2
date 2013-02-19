#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>
#include "list.h"
#include <iostream>

using std::cout;


class LinkedList : public List
{
public:
    LinkedList();
    virtual ~LinkedList();

    int getElementsCount();
    virtual void add(const int newValue);
    virtual void remove(int target);
    virtual bool isExists(const int target) const;
    virtual void writeAll() const;

private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;

    void deleteAll();
};

#endif // LLIST_H
