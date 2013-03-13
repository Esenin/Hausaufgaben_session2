#pragma once

#include <iostream>

#include "writer.h"

//! This class prints some matrix elements to console
class ConsoleWriter : public writerNamespace::Writer
{
public:
    ConsoleWriter(int *array[], int size);
    //! realise class subj
    void print(int *array[], Point current, Point next);
};


