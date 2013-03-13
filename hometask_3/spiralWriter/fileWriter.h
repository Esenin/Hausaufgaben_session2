#pragma once

#include <fstream>

#include "writer.h"

//! Writes matrix spiral to file
/*!
  You can find output in "out.txt"
*/
class FileWriter : public writerNamespace::Writer
{
public:
    FileWriter(int *array[], int size);
    void print(int *array[], Point current, Point next);
};

