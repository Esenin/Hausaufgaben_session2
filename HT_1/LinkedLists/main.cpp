#include <iostream>
#include "sortedArrayList.h"
#include "linkedList.h"

using namespace std;

void addSomeTestNumbers(List *testList)
{
    testList->add(13);
    testList->add(5);
    testList->add(7);
    testList->add(3);
    testList->add(17);
    testList->add(14);
}

void testing(List *arrList, List *pointerList)
{
    addSomeTestNumbers(arrList);
    addSomeTestNumbers(pointerList);

    cout << "Array list contains:\n";
    arrList->writeAll();
    cout << "PointerList contains:\n";
    pointerList->writeAll();

    cout << "Deleting '5'\n";

    arrList->remove(5);
    pointerList->remove(5);

    cout << "Array list contains:\n";
    arrList->writeAll();
    cout << "PointerList contains:\n";
    pointerList->writeAll();

    cout << "Getting third element:\n";
    cout << "ArrayList: " << (*arrList)[2] << "\n";
    cout << "LinkedList: " << (*pointerList)[2] << "\n";

    cout << "done\n";
}

int main()
{
    List *arrayList = new SortedArrayList;
    List *linkedList = new LinkedList;

    testing(arrayList, linkedList);

    delete arrayList;
    delete linkedList;

    return EXIT_SUCCESS;
}

