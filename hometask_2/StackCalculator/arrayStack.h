#pragma once

#include "stack.h"
#include "QString.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    virtual ~ArrayStack();

    virtual void clear();
    virtual void push(const QString value);
    virtual QString pop();
    virtual QString top();

protected:
    void increaseStackSize();

private:
    QString *array;
    const int stackSize;
    int currentStackSize;
};

