#include "sorter.h"

using std::swap;
using std::cout;
using std::endl;

Sorter::Sorter(int array[], int size)
{
    insideArray = new int[size];
    for (int i = 0; i < size; i++)
        insideArray[i] = array[i];
    arrSize = size;
}

Sorter::~Sorter()
{
    delete[] insideArray;
    cout << "Object destroing\n";
}


void Sorter::print()
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << insideArray[i] << " ";
    }
    cout << endl;
}
