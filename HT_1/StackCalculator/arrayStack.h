#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

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

#endif // ARRAYSTACK_H
