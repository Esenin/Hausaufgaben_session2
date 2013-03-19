#pragma once

#include <stdlib.h>
#include <iostream>

#include "operandNode.h"
#include "operatorNode.h"

int const strMaxLen = 255;

//! @class CalcTree makes math-expressions file processing
class CalcTree
{
public:
    CalcTree();
    ~CalcTree();
    //! @param string filename with math expressions
    void setNewTree(char const string[]);
    //! prints expression-tree to console
    void printTree();
    qreal calculateTree();

private:
    treeNodes::Node *root;

    int strSize(const char *string);
    bool isOperator(const char &symbol);
    bool isDigit(const char &symbol);
    void clear();

    //! sequenced recursive expression processing
    int addNode(treeNodes::Node *&current, const char *string, int curPos);
};

