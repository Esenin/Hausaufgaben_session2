#include "operandNode.h"

using namespace treeNodes;

OperandNode::OperandNode(char const *figure)
{
    value = 0;
    int index = 0;
    while (figure[index] != '\0')
    {
        value += value * 10 + (figure[index] - '0') ;
        index++;
    }
}

void OperandNode::writeSelf()
{
    std::cout << value << " ";
}

qreal OperandNode::calculateTree()
{
    return value;
}
