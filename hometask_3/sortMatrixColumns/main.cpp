/*!
    autodocumentation test begin
    @author Esenin
*/
#include <iostream>
#include <stdlib.h>
#include "quickSorter.h"

using namespace std;

//! Fill square matrix with random numbers
/*!
  @param array sqare matrix
  @param size size of matrix
*/
void fillArray(int *array[], int const rowSize, int const colSize)
{
    int const randomMax = 50;

    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < colSize; j++)
            array[i][j] = rand() % randomMax;
}
//! Creates array sized as user input
/*!
  @return reference to created array
*/
int** createArray(int &rowCount, int &colCount)
{
    cout << "Enter rows count and then column counts (e.g. 3 4)\n";
    cin >> rowCount;
    cin >> colCount;

    int **array = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        array[i] = new int[colCount];
    return array;
}


int main()
{
    int rowCount = 0;
    int colCount = 0;

    int **mainArray = createArray(rowCount, colCount);

    fillArray(mainArray, rowCount, colCount);

    QuickSorter arraySorter(mainArray, rowCount, colCount);
    cout << "Array before:\n";
    arraySorter.print();

    cout << "Sorted array:\n";
    arraySorter.sort();
    arraySorter.print();

    for (int i = 0; i < rowCount; i++)
        delete[] mainArray[i];
    delete[] mainArray;

    cout << "done\n";
    return 0;
}

