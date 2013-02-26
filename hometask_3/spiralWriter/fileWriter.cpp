#include "fileWriter.h"

using namespace std;

FileWriter::FileWriter(int *array[], int size) :
    Writer(array, size)
{
}

FileWriter::~FileWriter()
{
    // do nothing
}

void FileWriter::print(int *array[], Point current, Point next)
{
    ofstream file;
    file.open("out.txt", ios::out | ios::app);

    int i = current.x;
    int j = current.y;
    while ((i != next.x) || (j != next.y))
    {
        file << array[j][i] << " ";
        nextStep(i, j, next);
    }
    file.close();
}

