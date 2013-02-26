#pragma once

#include <iostream>

//! Sorter class interface
/*!  Class includes all you need
    to inherit different sorters
*/
class Sorter
{
public:
    //! Base construcor for regular sorter class
    /*!
    @param array your sort subject
    @param size int size of array
    */
    Sorter(int array[], int size);

    //! Destructor must be virtual
    virtual ~Sorter();

    //! Pure virtual function you may override in your class
    virtual void sort() = 0;
    void print();

protected:
    int *insideArray;
    int arrSize;
};

