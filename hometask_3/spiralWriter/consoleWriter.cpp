#include "consoleWriter.h"

using namespace std;

ConsoleWriter::ConsoleWriter(int *array[], int size) :
    Writer(array, size)
{
}

void ConsoleWriter::print(int *array[], Point current, Point next)
{
    int i = current.x;
    int j = current.y;
    while (i != next.x || j != next.y)
    {
        cout << array[j][i] << " ";
        nextStep(i, j, next);
    }
}
