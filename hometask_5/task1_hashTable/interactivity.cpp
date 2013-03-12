#include "interactivity.h"

using std::cout;
using std::cin;
using std::endl;

Interactivity::Interactivity(HashTable &table)
{
    hashTable = &table;
}

void Interactivity::executeConsole()
{
    cout << endl;
    int input = 1;
    while (input)
    {
        cout << "Put number of command you want\n";
        cout << "1) Add new value to hashtable\n"
             << "2) Delete value from hashtable\n"
             << "3) Show stat of hashtable\n"
             << "4) Change hash-function\n"
             << "0) to exit\n"
             << "> ";

        cin >> input;

        switch(input)
        {
        case 1:
        {
            addMenu();
            break;
        }
        case 2:
        {
            removeMenu();
            break;
        }
        case 3:
        {
            hashTable->printStatistics();
            break;
        }
        case 4:
        {
            changeFunctionMenu();
            break;
        }
        }
    }
}

void Interactivity::addMenu()
{
    int const maxSize = 100;
    cout << "Enter new value:\n";
    char input[maxSize] = {};
    cin >> input;
    hashTable->addValue(QString(input));
}

void Interactivity::removeMenu()
{
    int const maxSize = 100;
    cout << "Enter value for removing:\n";
    char input[maxSize] = {};
    cin >> input;
    if (hashTable->removeValue(QString(input)))
        cout << "success!\n";
    else
        cout << "This element does not exists\n";
}

void Interactivity::changeFunctionMenu()
{
    cout << "What will be new hash function?\n"
         << "1) hashing by size of value\n"
         << "2) hashing as in Rabin-Karp algo\n"
         << "3) mixed variant of two hashes above\n"
         << "0) no, no, no.. Let as is\n"
         << "> ";
    int input = 0;
    cin >> input;
    switch(input)
    {
    case 1:
    {
        hashTable->setHashFunc(hashBySize);
        break;
    }
    case 2:
    {
        hashTable->setHashFunc(hashWithPrimePower);
        break;
    }
    case 3:
    {
        hashTable->setHashFunc(hashMixed);
        break;
    }
    }
    cout << "done\n";
}





