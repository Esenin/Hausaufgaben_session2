#pragma once

#include <QtCore/QString>

//! @file myHashFunctions.h contains all hash functions for hashtable

static int hashBySize(QString string)
{
    return string.size();
}

//! Rabin-Karp hashing
static int hashWithPrimePower(QString string)
{
    int hash = 0;
    int const prime = 37;
    int curSalt = 1;
    for (int i = 0; i < string.size(); i++)
    {
        hash += (string.at(i).toAscii() - 'a') * curSalt;
        curSalt *= prime;
    }

    return (hash > 0)? hash : -hash;
}

static int hashMixed(QString string)
{
    int hash = hashBySize(string) | hashWithPrimePower(string);
    return (hash > 0)? hash : -hash;
}
