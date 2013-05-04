#pragma once

#include "rBTree.h"

template<typename Type>
//! @class MyMultiSet Set-like Container with repeating elements
class MyMultiSet
{
public:
    class ConstForwardIterator;
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
//! @class ConstForwardIterator cycled forward iterator with expanding same elements to sequence
template<typename Type>
class MyMultiSet<Type>::ConstForwardIterator
{
public:
    ConstForwardIterator(const MyMultiSet<Type> *set)
        : iterator(set->tree),
          elementsCount(iterator.current().second)
    {
    }

    Type current()
    {
        return iterator.current().first;
    }

    void operator ++(int)
    {
        elementsCount--;

        if (!elementsCount)
        {
            iterator++;
            elementsCount = iterator.current().second;
        }
    }

    bool begin() const
    {
        return iterator.begin();
    }

    bool end() const
    {
        return iterator.end();
    }

    private:
        typename RBTree<Type>::ConstIterator iterator;
        int elementsCount;
};


template<typename Type>
void MyMultiSet<Type>::add(const Type &element, const int count)
{
    tree->add(element, count);
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
        for (typename RBTree<Type>::ConstIterator iterator(tree); !iterator.end(); iterator++)
        {
            int elementsCountInOther = other.contains(iterator.current().first);
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
        for (typename RBTree<Type>::ConstIterator iterator(tree); !iterator.end(); iterator++)
            summarySet->add(iterator.current().first, iterator.current().second);

        for (typename RBTree<Type>::ConstIterator iterator(other.tree); !iterator.end(); iterator++)
            summarySet->add(iterator.current().first, iterator.current().second );
    }
    catch (...)
    {
        delete summarySet;
        throw EmptySetError();
    }

    return summarySet;
}

