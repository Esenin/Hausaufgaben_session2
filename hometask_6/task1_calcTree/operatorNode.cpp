#include "operatorNode.h"

using namespace treeNodes;
using namespace operators;

OperatorNode::OperatorNode(char const &symbol)
{
    value = getOperator(symbol);
}

void OperatorNode::writeSelf()
{
    std::cout << operatorToChar(value) << ")";
}

qreal OperatorNode::calculateTree()
{
    return calculate(leftChild->calculateTree(), rightChild->calculateTree(), value);
}

char OperatorNode::operatorToChar(int const &action)
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

Operators OperatorNode::getOperator(char const &symbol)
{
    switch (symbol)
    {
    case '+':
    {
        return plus;
    }
    case '-':
    {
        return minus;
    }
    case '*':
    {
        return multiply;
    }
    case '/':
    {
        return divide;
    }
    default:
    {
        return plus;
    }
    }
}


