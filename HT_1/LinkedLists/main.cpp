#include <iostream>
#include "linkedArrayList.h"
#include "linkedList.h"

using namespace std;

void testing(List *arrList, List *pointerList)
{
    arrList->add(5);
    pointerList->add(5);

    arrList->add(7);
    pointerList->add(7);

    arrList->add(3);
    pointerList->add(3);

    cout << "Array list contains:\n";
    arrList->writeAll();
    cout << "PointerList contains:\n";
    pointerList->writeAll();

    cout << "Deleting '5'";

    arrList->remove(5);
    pointerList->remove(5);

    cout << "Array list contains:\n";
    arrList->writeAll();
    cout << "PointerList contains:\n";
    pointerList->writeAll();
}


int main()
{
    List *arrayList = new LinkedArrayList;
    List *linkedList = new LinkedList;

    testing(arrayList, linkedList);

    return EXIT_SUCCESS;
}

