#pragma once

#include <iostream>
#include <stdlib.h>

#include "victim.h"

class CorruptedClass
{
public:
    CorruptedClass()
        : publicInteger(error)
    {
        std::cout << " ---> Corrupted class constructor here\n";
        throw error;
    }

    ~CorruptedClass()
    {
        std::cout << " ---> Corrupted class destructor here\n";
    }

    int random()
    {
        return rand() % error;
    }

    int publicInteger;

private:
    Victim object;
    static int const error = 14;
};


