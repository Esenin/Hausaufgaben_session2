#pragma once

#include <stdlib.h>
#include <QString.h>
#include "stack.h"

#include <iostream>


class LinkedStack : public Stack
{
public:
    LinkedStack();
    virtual ~LinkedStack();

    virtual void push(const QString newValue);
    virtual QString pop();
    virtual void clear();
    virtual QString top();


private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;

    void deleteAll();
};

