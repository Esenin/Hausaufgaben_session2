/*!
    autodocumentation test begin
    @author Esenin
*/

#include <iostream>
#include "consoleWriter.h"
#include "fileWriter.h"

using namespace std;
using namespace writerNamespace;

bool canDivByTwo(int x)
{
    return (x & 1) == 0;
}

//! really just print out your array to console
void printArray(int *array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

//! Fill square matrix with random numbers
/*!
  @param array sqare matrix
  @param size size of matrix
*/
void arrFillNumb(int *array[], int size)
{
    int const twoDigitCol = 9;
    int const threeDigitCol = 99;

    int identy = twoDigitCol;
    if (size > 10)
        identy = threeDigitCol;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            array[i][j] = ++identy;
}

//! Interaction with user
/*!
  @return bool says you must write to console out
*/
bool mustConsoleWrite()
{
    cout << "Choose the way how to write:\n"
         << "1) to console\n"
         << "2) to file 'out.txt' \n"
         << "(put 1 or 2):\n";
    int choice = 1;
    cin >> choice;

    return choice == 1;
}

//! separeted func just to use dynamic linking
void writeByObject(Writer *object)
{
    cout << endl;
    object->work();
}

int main()
{
    int arrSize = 3;
    cout << "Enter array size (would be filled with numbers automatically):\n";
    cin >> arrSize;
    if (canDivByTwo(arrSize))
        arrSize++;

    int **mainArray = new int*[arrSize];
    for (int i = 0; i < arrSize; i++)
        mainArray[i] = new int[arrSize];

    arrFillNumb(mainArray, arrSize);

    cout << "Current array is:\n";
    printArray(mainArray, arrSize);

    if (mustConsoleWrite())
    {
        Writer *conObject = new ConsoleWriter(mainArray, arrSize);
        writeByObject(conObject);
        delete conObject;
    }
    else
    {
        Writer *fileObject = new FileWriter(mainArray, arrSize);
        writeByObject(fileObject);
        delete fileObject;
        cout << "Spiral was placed into file";
    }

    for (int i = 0; i < arrSize; i++)
        delete[] mainArray[i];
    delete[] mainArray;

    cout << endl;
    return 0;
}

