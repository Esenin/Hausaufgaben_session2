#include "linkedList.h"

struct LinkedList::ListElement
{
    int value;
    int count;
    ListElement *next;

    ListElement(const int newValue)
    {
        next = NULL;
        count = 0;
        value = newValue;
    }
};

LinkedList::LinkedList() :
    List(),
    head(NULL),
    tail(NULL),
    currPointer(NULL),
    currPointerPosition(0)
{

}

LinkedList::~LinkedList()
{
    deleteAll();
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}


int LinkedList::getElementsCount()
{
    return elementsCount;
}

int& LinkedList::operator[](int index)
{
    if (index < 0)
        return head->value;

    if (index >= elementsCount)
        return tail->value;

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


void LinkedList::add(const int newValue)
{
    ListElement *newElement = new ListElement(newValue);

    if (isEmpty())
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
    elementsCount++;
}

void LinkedList::remove(int target)
{
    if (head->value == target)
    {
        ListElement *temp = head;
        head = head->next;
        delete temp;
        if (--elementsCount)
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


bool LinkedList::isExists(const int target) const
{
    ListElement *temp = head;

    while (temp != NULL)
        if (temp->value == target)
            return true;
        else
            temp = temp->next;

    return false;
}

void LinkedList::writeAll() const
{
    ListElement *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}


void LinkedList::deleteAll()
{
    ListElement *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
