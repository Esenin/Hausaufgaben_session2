#pragma once

#include <iostream>
#include <QObject>
#include <QtTest/QTest>

#include "corruptedClass.h"

using std::cout;
using std::endl;

class ExceptionTest : public QObject
{
    Q_OBJECT
private slots:

    void initTestCase()
    {
        bool flag = false;
        try
        {
            sampleObj = new CorruptedClass;
        }
        catch (int const &error)
        {
            flag = true;
            cout << "We've catched an exception here with id: " << error << std::endl;
        }
        QVERIFY(flag);
    }

    void init()
    {
        cout << endl;
    }s

    void testFunction()
    {
        cout << "usage of object with wrong constructor:\n" << "class method:\n";
        cout << sampleObj->random();
        QVERIFY(true);
    }

    void testVariable()
    {
        cout << "class variable (must be 14):\n";
        cout << sampleObj->publicInteger << endl;
        QVERIFY(true);
    }

    void cleanup()
    {
        cout << endl;
    }

    void cleanupTestCase()
    {
        delete sampleObj;
    }

private:
    CorruptedClass *sampleObj;
};
