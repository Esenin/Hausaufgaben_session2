#pragma once

#include <stdlib.h>
#include <iostream>

#include "list.h"

using std::cout;

//! @namespace linkedListExceptions have exception classes for @class LinkedList
namespace linkedListExceptions
{
class LinkedListExceptions{};
class BadNewKey : public LinkedListExceptions{};
class NoSuchKey : public LinkedListExceptions{};
class OutOfRange : public LinkedListExceptions{};
}

//! @class LinkedList list-type container
template<typename Type>
class LinkedList : public List<Type>
{
public:
    LinkedList();
    virtual ~LinkedList();

    virtual void add(Type const newValue) throw (linkedListExceptions::BadNewKey);
    virtual void remove(Type const target) throw(linkedListExceptions::NoSuchKey);
    virtual bool exists(Type const target) const;
    virtual void writeAll() const;
    //! index-based access for elements,
    //! amort.O(1) in case sequential calls
    virtual Type& operator[](int index) throw(linkedListExceptions::OutOfRange);

private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;

    ListElement *currPointer;
    int currPointerPosition;

    void deleteAll();
};

template<typename Type>
struct LinkedList<Type>::ListElement
{
    Type value;
    int count;
    ListElement *next;

    ListElement(Type const newValue)
    {
        next = NULL;
        count = 0;
        value = newValue;
    }
};

template<typename Type>
LinkedList<Type>::LinkedList() :
    List<Type>(),
    head(NULL),
    tail(NULL),
    currPointer(NULL),
    currPointerPosition(0)
{
}

template<typename Type>
LinkedList<Type>::~LinkedList()
{
    deleteAll();
    head = NULL;
    tail = NULL;
}

template<typename Type>
Type& LinkedList<Type>::operator[](int index) throw(linkedListExceptions::OutOfRange)
{
    if (index < 0 || index > this->size())
        throw linkedListExceptions::OutOfRange();

    if (currPointerPosition > index)
    {
        currPointer = head;
        currPointerPosition = 0;
    }

    while (currPointerPosition != index)
    {
        currPointer = currPointer->next;
        currPointerPosition++;
    }

    return currPointer->value;
}

template<typename Type>
void LinkedList<Type>::add(Type const newValue) throw (linkedListExceptions::BadNewKey)
{
    if (this->exists(newValue))
        throw linkedListExceptions::BadNewKey();

    ListElement *newElement = new ListElement(newValue);

    if (this->isEmpty())
    {
        head = newElement;
        currPointer = head;
        tail = head;
    }
    else
    {
        tail->next = newElement;
        tail = tail->next;
    }
    this->elementsCount++;
}

template<typename Type>
void LinkedList<Type>::remove(Type const target) throw(linkedListExceptions::NoSuchKey)
{
    if (!this->exists(target))
        throw linkedListExceptions::NoSuchKey();

    if (head->value == target)
    {
        ListElement *temp = head;
        head = head->next;
        delete temp;
        this->elementsCount--;
        if (this->elementsCount)
            tail = NULL;
        return;
    }

    ListElement *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->next->value == target)
            break;
        else
            temp = temp->next;
    }

    if (temp == NULL)
        return;

    ListElement *deathWalker = temp->next;
    temp->next = deathWalker->next;
    delete deathWalker;
}

template<typename Type>
bool LinkedList<Type>::exists(Type const target) const
{
    ListElement *temp = head;

    while (temp != NULL)
        if (temp->value == target)
            return true;
        else
            temp = temp->next;

    return false;
}

template<typename Type>
void LinkedList<Type>::writeAll() const
{
    ListElement *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}

template<typename Type>
void LinkedList<Type>::deleteAll()
{
    ListElement *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}


