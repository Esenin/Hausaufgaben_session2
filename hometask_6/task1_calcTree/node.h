#pragma once

#include <stdlib.h> // for NULLptr
#include <iostream>
#include <qglobal.h> // for qreal

namespace treeNodes
{
namespace operators
{
enum Operators
{
    plus = 0
    , minus
    , multiply
    , divide
};
}
//! @class Node is container for operands/operators with some useful functions
class Node
{
public:
    Node();
    virtual ~Node();

    //! print writes subtrees, then self
    void print() const;
    //! just calculates both of subtrees and then self
    virtual qreal calculateTree() const = 0;

    //! solution for encapsulation problem.
    void addChild(Node *child);
protected:
    virtual void writeSelf() const = 0;

    //! simple calculator
    qreal calculate(qreal const &first, qreal const &second, int const &action) const;

    Node *leftChild;
    Node *rightChild;
    int value;
};

}
