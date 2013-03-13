#include "sorter.h"

using std::swap;
using std::cout;
using std::endl;

Sorter::Sorter(int *array, int const size)
    : arrSize(size)
{
    insideArray = array;
}

Sorter::~Sorter()
{
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
