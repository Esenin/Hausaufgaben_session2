#pragma once

#include <QtCore/QList>
#include <QtCore/QString>
#include <stdio.h>

//! Type to take some hash-function
typedef int (*Function)(QString);

//! @class Hashtable is interesting in use 'setHashFunc' to change subject
class HashTable
{
public:
    //! Remember to put table max size in constructor
    HashTable(int elementsMaxCount);
    ~HashTable();

    void addValue(QString const word);

    //! returns true on success, false otherwise
    bool removeValue(QString const word);

    //! prints table size, number of elements, load-factor and most-loaded-cell
    void printStatistics() const;

    bool exists(QString const string);

    //! @arg hashFunc function like   int foo(QString)
    void setHashFunc(Function hashFunc);

private:
    int const tableSize;
    QList<QString> *table;

    //! it uses function from hashFunction
    int hash(QString const &string);

    //! This function works since creation
    static int hashDefaultFunc(QString string);

    //! This contains link to hash function
    Function hashFunction;
};
