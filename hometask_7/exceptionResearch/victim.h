#pragma once

#include <iostream>

class Victim
{
public:
    Victim()
    {
        std::cout << " --->   good constructor\n";
    }

    ~Victim()
    {
        std::cout << " --->   good destructor\n";
    }
};


