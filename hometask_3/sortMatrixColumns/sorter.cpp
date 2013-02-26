#include "sorter.h"

using std::swap;
using std::cout;
using std::endl;

Sorter::Sorter(int *array[], int const rowSize, int const colSize) :
    rowCount(rowSize),
    colCount(colSize)
{
    insideArray = array;
}


void Sorter::print()
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << insideArray[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


