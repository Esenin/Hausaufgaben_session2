#include "operandNode.h"

using namespace treeNodes;

OperandNode::OperandNode(QString const &figure)
{
    value = figure.toInt();
}

void OperandNode::writeSelf() const
{
    std::cout << value << " ";
}

qreal OperandNode::calculateTree() const
{
    return value;
}
