#pragma once

#include <stdlib.h>
#include <iostream>
#include <QtCore/QString>
#include <QtCore/QRegExp>

#include "operandNode.h"
#include "operatorNode.h"

int const strMaxLen = 255;

//! @class CalcTree sets up BinTree and provides some functions
class CalcTree
{
public:
    CalcTree();
    ~CalcTree();
    //! @param string math expression
    void setNewTree(QString const string);
    //! prints expression-tree to console
    void printTree() const;
    qreal calculateTree();

private:
    treeNodes::Node *root;

    //! sequenced recursive expression processing
    int addNode(treeNodes::Node *&current, QString const string, int curPos);

    bool isOperator(QChar const &symbol) const;
    void clear();
};

