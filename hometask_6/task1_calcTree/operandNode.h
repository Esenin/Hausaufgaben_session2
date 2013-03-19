#pragma once

#include "node.h"

namespace treeNodes
{

class OperandNode : public Node
{
public:
    OperandNode(char const *figure);

    qreal calculateTree();

protected:
    void writeSelf();
};

}

