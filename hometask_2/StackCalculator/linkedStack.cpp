#include "linkedStack.h"

struct LinkedStack::ListElement
{
    QString value;
    ListElement *next;
    ListElement *prev;

    ListElement(const QString newValue)
    {
        next = NULL;
        prev = NULL;
        value = newValue;
    }
};

LinkedStack::LinkedStack() :
    Stack(),
    head(NULL),
    tail(NULL)
{

}

LinkedStack::~LinkedStack()
{
    deleteAll();
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}


void LinkedStack::push(const QString newValue)
{
    ListElement *newElement = new ListElement(newValue);

    if (isEmpty())
    {
        head = newElement;
        tail = head;
    }
    else
    {
        newElement->prev = tail;
        tail->next = newElement;
        tail = tail->next;
    }
    elementsCount++;
}

QString LinkedStack::pop()
{
    if (isEmpty())
        return QString::number(0);

    QString result = tail->value;
    ListElement *temp = tail;
    tail = tail->prev;
    delete temp;
    elementsCount--;

    if (isEmpty())
        head = NULL;
    else
        tail->next = NULL;

    return result;
}

QString LinkedStack::top()
{
    if (elementsCount == 0)
        return QString::number(0);
    QString result = tail->value;
    return result;
}

void LinkedStack::clear()
{
    deleteAll();
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}


void LinkedStack::deleteAll()
{
    ListElement *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
