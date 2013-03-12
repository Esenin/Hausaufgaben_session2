#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "hashTable.h"
#include "myHashFunctions.h"

class HashTableTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        int const size = 100;
        mTable = new HashTable(size);
    }

    void addToTable()
    {
        mTable->addValue(QString(42));
        QVERIFY(mTable->isExists(QString(42)));
    }

    void searchTableTest()
    {
        QVERIFY(!mTable->isExists(QString(25)));
        mTable->addValue(QString(25));
        QVERIFY(mTable->isExists(QString(25)));
    }

    void removeTest()
    {
        mTable->removeValue(QString(42));
        QVERIFY(!mTable->isExists(QString(42)));
        mTable->addValue(QString(2012));
        mTable->removeValue(QString(2012));
        QVERIFY(!mTable->isExists(QString(2012)));
    }

    void changeFunctionTest()
    {
        mTable->addValue(QString(21));
        mTable->setHashFunc(hashMixed);
        QVERIFY(mTable->isExists(QString(21)));
    }

    void cleanupTestCase()
    {
        delete mTable;
    }

private:
    HashTable *mTable;
};


