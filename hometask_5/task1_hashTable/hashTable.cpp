#include "hashTable.h"

HashTable::HashTable(int elementsMaxCount)
    : tableSize(elementsMaxCount)
{
    table = new QList<QString>[tableSize];

    setHashFunc(hashDefaultFunc);
}

HashTable::~HashTable()
{
    delete[] table;
}

void HashTable::addValue(QString const word)
{
    if (!table[hash(word)].contains(word))
        table[hash(word)].push_back(word);
}

bool HashTable::removeValue(QString const word)
{
    return (table[hash(word)].removeOne(word));
}

void HashTable::printStatistics() const
{
    int maxCollisions = 0;
    int maxCollisIndex = -1;
    int wordsCount = 0;
    for (int i = 0; i < tableSize; i++)
    {
        wordsCount += table[i].size();
        if (table[i].size() > maxCollisions)
        {
            maxCollisions = table[i].size();
            maxCollisIndex = i;
        }
    }
    printf("HashTable stat:\n");
    printf("Number of cells in hash table: %d\n", tableSize);
    printf("All different words total: %d\n", wordsCount);
    printf("Load factor is: %f \n", ((float)wordsCount / tableSize));
    printf("Most loaded cell is: %d, with %d elements\n\n", maxCollisIndex, maxCollisions);
}

bool HashTable::exists(const QString string)
{
    return table[hash(string)].contains(string);
}

void HashTable::setHashFunc(Function hashFunc)
{
    hashFunction = hashFunc;

    QList<QString> *newTable = new QList<QString>[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        while (!table[i].isEmpty())
        {
            QString word = table[i].takeFirst();
            newTable[hash(word)].push_back(word);
        }
    }
    delete[] table;
    table = newTable;
}

int HashTable::hash(const QString &string)
{
    return hashFunction(string) % tableSize;
}

int HashTable::hashDefaultFunc(QString string)
{
    return string.size();
}

