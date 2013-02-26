#pragma once

#include <fstream>
#include "writer.h"

//! Writes matrix spiral to file
/*!
  You can find output in "out.txt"
*/
class FileWriter : public Writer
{
public:
    FileWriter(int *array[], int size);
    virtual ~FileWriter();
    void print(int *array[], Point current, Point next);
};

