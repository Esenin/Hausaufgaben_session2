#pragma once

template <typename Type>
//! @class List is an interface for List-type container
class List
{
public:
    List()
        : elementsCount(0){}
    virtual ~List()
    {
        elementsCount = 0;
    }

    virtual void add(Type newValue) = 0;
    virtual void remove(Type target) = 0;
    virtual bool exists(Type target) const = 0;
    virtual void writeAll() const = 0;
    virtual int &operator[] (int index) = 0;
    int size() const
    {
        return elementsCount;
    }

    bool isEmpty() const
    {
        return (elementsCount <= 0);
    }

protected:
    int elementsCount;
};

