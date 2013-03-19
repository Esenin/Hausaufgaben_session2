#pragma once

#include <QtCore/QList>

template<typename Type, int maxSize = 100>
//! @class MySet provides container based on hashtable
class MySet
{
public:
    MySet();
    ~MySet();

    void add(Type const &newValue)
    {
        if (array[hash(newValue)].contains(newValue))
            return;
        array[hash(newValue)].append(newValue);
    }

    void remove(Type const &value)
    {
        array[hash(value)].removeOne(value);
    }

    bool contains(Type const &value)
    {
        return array[hash(value)].contains(value);
    }

    //! intersect() makes intersection of two sets by maths rules
    MySet<Type, maxSize> *intersect(MySet const &other);
    //! merge() makes union of two sets
    MySet<Type, maxSize> *merge(MySet const &other);

protected:
    //! make hash by looking memory
    int hash(Type value);

private:
    QList<Type> *array;
    int arraySize;
};

template<typename Type, int maxSize>
MySet<Type, maxSize>::MySet()
{
    arraySize = maxSize;
    array = new QList<Type>[arraySize];
}

template<typename Type, int maxSize>
MySet<Type, maxSize>::~MySet()
{
    delete[] array;
}

template<typename Type, int maxSize>
int MySet<Type, maxSize>::hash(Type value)
{
    unsigned char *cortege = (unsigned char*)&value;
    int const size = sizeof(value);
    unsigned int result = 0;
    unsigned char unit = 0;
    int const salt = 1993; //prime
    for (int i = 0; i < size; i++)
    {
        unit = cortege[i];
        if (unit % 2)
            result += salt * unit;
        else
            result += (salt - 1) * unit;
    }
    return result % arraySize;
}

template<typename Type, int maxSize>
MySet<Type, maxSize> *MySet<Type, maxSize>::intersect(MySet const &other)
{
    MySet<Type, maxSize> *result = new MySet<Type, maxSize>;
    for (int i = 0; i < arraySize; i++)
        foreach(Type const &item, array[i])
            result->add(item);

    for (int i = 0; i < other.arraySize; i++)
        foreach(Type const &item, other.array[i])
            if (contains(item))
                result->add(item);
    return result;
}

template<typename Type, int maxSize>
MySet<Type, maxSize> *MySet<Type, maxSize>::merge(MySet const &other)
{
    MySet<Type, maxSize> *result = new MySet<Type, maxSize>;
    for (int i = 0; i < arraySize; i++)
        foreach(Type const &item, array[i])
            result->add(item);

    for (int i = 0; i < other.arraySize; i++)
        foreach(Type const &item, other.array[i])
            result->add(item);
    return result;
}

