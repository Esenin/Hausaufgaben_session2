#include <iostream>

#include "hashTable.h"
#include "hashTableTest.h"
#include "interactivity.h"

using namespace std;

int main()
{
    cout << "Hashtable unit-tesing:\n\n";

    HashTableTest test;
    QTest::qExec(&test);

    int const tableSize = 100;
    HashTable table(tableSize);
    Interactivity terminal(table);

    terminal.executeConsole();

    return 0;
}


