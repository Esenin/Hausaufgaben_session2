#include "operatorNode.h"

using namespace treeNodes;
using namespace operators;

OperatorNode::OperatorNode(QChar const &symbol)
{
    value = getOperator(symbol);
}

void OperatorNode::writeSelf() const
{
    std::cout << operatorToChar(value) << ")";
}

qreal OperatorNode::calculateTree() const
{
    return calculate(leftChild->calculateTree(), rightChild->calculateTree(), value);
}

char OperatorNode::operatorToChar(int const &action) const
{
    switch (action)
    {
    case plus:
        return '+';
    case minus:
        return '-';
    case multiply:
        return '*';
    case divide:
        return '/';
    }
    return '\0';
}

Operators OperatorNode::getOperator(QChar const &symbol) const
{
    int const notFound = -1;
    QString operators = "+-*/";
    int result = operators.indexOf(symbol);
    if (result == notFound)
        result = 0;
    return static_cast<Operators>(result);
}


