#pragma once

#include "rBTree.h"

template<typename Type>
//! @class MyMultiSet Set-like Container with repeating elements
class MyMultiSet
{
public:
    //! @class ForwardIterator java-styled forward iterator
    class ForwardIterator;

    class SetExceptions{};
    class EmptySetError : public SetExceptions{};

    MyMultiSet()
    {
        tree = new RBTree<Type>;
    }

    ~MyMultiSet()
    {
        delete tree;
    }

    void add(const Type &element, const int count = 1);
    void add(const QPair<Type, int> &item);

    void removeOne(const Type &element);
    void removeAllAs(const Type &element);

    bool empty() const;

    //! return count of such elements in set
    int contains(const Type &element) const;

    //! returns new set in heap with common elements from both multiSets
    MyMultiSet<Type> *intersectWith(const MyMultiSet &other);

    //! return new set united with other
    MyMultiSet<Type> *sumWith(const MyMultiSet &other);

private:
    RBTree<Type> *tree;
};

// Implementation
//! @class ConstForwardIterator looped forward iterator with expanding same elements to sequence
template<typename Type>
class MyMultiSet<Type>::ForwardIterator
{
public:
    ForwardIterator(MyMultiSet<Type> *set)
        : iterator(set->tree),
          elementsCount(iterator.current().second),
          zeroPosition(true)
    {
    }

    Type current()
    {
        return iterator.current().first;
    }

    Type next()
    {
        this->operator ++(empty);
        elementsCount--;
        return current();
    }

    void add(const Type &item)
    {
        iterator.add(item);
        if (item == current())
            elementsCount++;
    }

    //! removes current element
    void removeItem()
    {
        iterator.removeOne();
        elementsCount--;
    }

    bool hasNext()
    {
        return (iterator.hasNext() || elementsCount > empty);
    }

    void resetToFirst()
    {
        iterator.resetToFirst();
    }

protected:
    void operator ++(int)
    {
        if (zeroPosition)
        {
            zeroPosition = false;
            return;
        }


        if (elementsCount <= empty)
        {
            iterator++;
            elementsCount = iterator.current().second;
        }
    }

private:
    static const int empty = 0;
    typename RBTree<Type>::ForwardIterator iterator;
    int elementsCount;
    bool zeroPosition;
};


template<typename Type>
void MyMultiSet<Type>::add(const Type &element, const int count)
{
    tree->add(element, count);
}

template<typename Type>
void MyMultiSet<Type>::add(const QPair<Type, int> &item)
{
    tree->add(item.first, item.second);
}

template<typename Type>
void MyMultiSet<Type>::removeOne(const Type &element)
{
    try
    {
        tree->removeOne(element);
    }
    catch (const RBTree<int>::NoSuchKey &)
    {
        throw SetExceptions();
    }
}

template<typename Type>
void MyMultiSet<Type>::removeAllAs(const Type &element)
{
    try
    {
        tree->removeAllAs(element);
    }
    catch (const RBTree<int>::NoSuchKey &)
    {
        throw SetExceptions();
    }
}

template<typename Type>
bool MyMultiSet<Type>::empty() const
{
    return tree->isEmpty();
}

template<typename Type>
int MyMultiSet<Type>::contains(const Type &element) const
{
    return tree->exists(element);
}

template<typename Type>
MyMultiSet<Type> *MyMultiSet<Type>::intersectWith(const MyMultiSet &other)
{
    MyMultiSet<Type> *commonSet = new MyMultiSet<Type>;

    try
    {
        typename RBTree<Type>::ForwardIterator iterator(tree);
        while (iterator.hasNext())
        {
            int elementsCountInOther = other.contains(iterator.next().first);
            if (elementsCountInOther)
                commonSet->add(iterator.current().first, qMin(iterator.current().second, elementsCountInOther));
        }
    }
    catch (...)
    {
        delete commonSet;
        throw EmptySetError();
    }

    return commonSet;
}

template<typename Type>
MyMultiSet<Type> *MyMultiSet<Type>::sumWith(const MyMultiSet &other)
{
    MyMultiSet<Type> *summarySet = new MyMultiSet<Type>;

    try
    {
        typename RBTree<Type>::ForwardIterator iterator(tree);
        while (iterator.hasNext())
            summarySet->add(iterator.next());

        typename RBTree<Type>::ForwardIterator otherIterator(other.tree);
        while (otherIterator.hasNext())
            summarySet->add(otherIterator.next());
    }
    catch (...)
    {
        delete summarySet;
        throw EmptySetError();
    }

    return summarySet;
}

