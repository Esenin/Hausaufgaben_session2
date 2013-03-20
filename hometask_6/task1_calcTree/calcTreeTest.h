#pragma once

#include <QtTest/QTest>
#include <fstream>

#include "calcTree.h"

class CalcTreeTest : public QObject
{
    Q_OBJECT
public:
    CalcTreeTest()
        : zero(1e-7)
    {
    }

protected:
    void processFile(char const fileName[])
    {
        FILE *fInput = fopen(fileName, "r");
        char buffer[strMaxLen] = {};

        fgets(buffer, strMaxLen, fInput);
        mainTree->setNewTree(buffer);

        fclose(fInput);
    }

private slots:
    void initTestCase()
    {
        mainTree = new CalcTree;
        processFile("test.txt");
    }

    void printTest()
    {
        printf("\nHere the calcTree >>>\n");
        mainTree->printTree();
        printf("End of tree >>>\n\n");
    }

    void calculationTest()
    {
        QVERIFY(qAbs(mainTree->calculateTree() - 4) < zero);
    }

    void veryHardTest()
    {
        mainTree->setNewTree("(+ (* (- 5 6) 7) (/ (+ 1 2) 3) )");
        QVERIFY(qAbs(mainTree->calculateTree() - (-6)) < zero);
    }

    void strangeTest()
    {
        mainTree->setNewTree("(+ 1 (20))");
        QVERIFY(qAbs(mainTree->calculateTree() - (21)) < zero);
    }

    void cleanupTestCase()
    {
        delete mainTree;
    }

private:
    CalcTree *mainTree;
    qreal zero;
};
