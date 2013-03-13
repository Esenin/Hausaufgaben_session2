#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "arrayStack.h"
#include "linkedStack.h"

class StackTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
        {
            linkedStack = new LinkedStack;
            arrStack = new ArrayStack;
        }

        void pushTest()
        {
            int const count = 10;
            int data[count] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 8};
            for (int i = 0; i < count; i++)
            {
                linkedStack->push(QString::number(data[i]));
                arrStack->push(QString::number(data[i]));
            }

            QCOMPARE(linkedStack->top().toInt(), 8);
            QCOMPARE(arrStack->top().toInt(), 8);
        }

        void popTest()
        {
            QCOMPARE(linkedStack->pop().toInt(), 8);
            QCOMPARE(linkedStack->pop().toInt(), 2);

            QCOMPARE(arrStack->pop().toInt(), 8);
            QCOMPARE(arrStack->pop().toInt(), 2);
        }

        void cleanTest()
        {
            linkedStack->clear();
            QCOMPARE(linkedStack->top().toInt(), NULL);

            arrStack->clear();
            QCOMPARE(arrStack->top().toInt(), NULL);
        }


        void cleanupTestCase()
        {
            delete linkedStack;
            delete arrStack;
        }

private:
    ArrayStack *arrStack;
    LinkedStack *linkedStack;

};
