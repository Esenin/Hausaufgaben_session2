#pragma once

#include "node.h"

namespace treeNodes
{

class OperatorNode : public Node
{
public:
    OperatorNode(char const &symbol);

    qreal calculateTree();

protected:
    void writeSelf();
    char operatorToChar(int const &action);
    operators::Operators getOperator(char const &symbol);
};

}
