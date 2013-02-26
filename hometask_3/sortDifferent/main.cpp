/*!
    autodocumentation test begin
    @author Esenin
*/
#include <iostream>
#include <stdlib.h> /// for random
#include "quickSorter.h"
#include "bubbleSorter.h"

using namespace std;

//! This function make sort and display array
/*!
    @param object any sorter class, contains array to sort
*/
void sortTesting(Sorter *object)
{
    cout << "Current array:\n";
    object->print();
    object->sort();
    cout << "Sorted array:\n";
    object->print();
    cout << endl;
}

//! Fill your array with numbers
void fillArray(int *array, int size)
{
    int const maxRand = 50;
    for (int i = 0; i < size; i++)
        array[i] = rand() % maxRand;
}

int main()
{
    int size = 0;
    cout << "Enter array size:\n";
    cin >> size;

    int mainArray[size];
    fillArray(mainArray, size);

    Sorter *quickSortObject = new QuickSorter(mainArray, size);
    Sorter *bubbleSortObject = new BubbleSorter(mainArray, size);

    cout << "Testing QuickSorter object...\n";
    sortTesting(quickSortObject);
    cout << "Testing BubleSort object...\n";
    sortTesting(bubbleSortObject);

    //! Deleting objects causes output hint tests that desructor really works
    delete quickSortObject;
    delete bubbleSortObject;

    cout << "done\n";

    return 0;
}

