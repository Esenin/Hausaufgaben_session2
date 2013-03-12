#pragma once

#include <iostream>

#include "hashTable.h"
#include "myHashFunctions.h"


//! @class Interactivity provides user console interface
class Interactivity
{
public:
    //! Class works with hashtable, put it here
    Interactivity(HashTable &table);

    //! run this function to start
    void executeConsole();

private:
    void addMenu();
    void removeMenu();
    void changeFunctionMenu();

    HashTable *hashTable;
};

