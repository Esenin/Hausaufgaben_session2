#pragma once

class List
{
public:
    List();
    virtual ~List();

    virtual void add(int newValue) = 0;
    virtual void remove(int target) = 0;
    virtual bool exists(int target) const = 0;
    virtual void writeAll() const = 0;
    virtual int &operator[] (int index) = 0;

    bool isEmpty() const;

protected:
    int elementsCount;
};

