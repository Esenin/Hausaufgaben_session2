#include "node.h"

using namespace treeNodes;
using namespace operators;
using std::cout;
using std::endl;

Node::Node()
    : leftChild(NULL)
    , rightChild(NULL)
    , value(0)
{
}

Node::~Node()
{
    if (leftChild != NULL)
        delete leftChild;
    if (rightChild != NULL)
        delete rightChild;
}

void Node::print() const
{
    if (leftChild != NULL)
    {
        cout << "(";
        leftChild->print();
    }
    if (rightChild != NULL)
        rightChild->print();
    writeSelf();
}

void Node::addChild(Node *child)
{
    if (leftChild == NULL)
        leftChild = child;
    else
    {
        if (rightChild == NULL)
            rightChild = child;
        else
            delete child;  // to avoid memory leak
    }
}

qreal Node::calculate(qreal const &first, qreal const &second, int const &action) const
{
    double const zero = 1e-15;
    switch (action)
    {
    case plus:
        return first + second;
    case minus:
        return first - second;
    case multiply:
        return first * second;
    case divide:
    {
        if (second < zero)
            return 0;
        else
            return first / second;
    }
    }
    return 0;
}
