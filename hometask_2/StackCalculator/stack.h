#pragma once

#include <QString>

class Stack
{
public:
    Stack();
    virtual ~Stack();

    virtual void clear() = 0;
    virtual void push(const QString value) = 0;
    virtual QString pop() = 0;
    virtual QString top() = 0;

    bool isEmpty() const;

protected:
    int elementsCount;
};

