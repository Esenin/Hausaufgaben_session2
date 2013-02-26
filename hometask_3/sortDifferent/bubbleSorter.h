#pragma once

#include "sorter.h"

//!  Bubble sort realisation class
/*!
  inherited from interface
  Doesnt need own destructor
*/


class BubbleSorter : public Sorter
{
public:
    BubbleSorter(int array[], int size);
    //! essential override func
    void sort();
protected:
    //! main function of this class
    /*!
        bubble sort realisation
    */
    void bSort(int *array, int first, int last);
};

