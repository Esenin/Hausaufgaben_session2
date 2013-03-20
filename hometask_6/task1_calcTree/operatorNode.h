#pragma once

#include <QtCore/QString>

#include "node.h"

namespace treeNodes
{

class OperatorNode : public Node
{
public:
    OperatorNode(QChar const &symbol);

    qreal calculateTree() const;

protected:
    void writeSelf() const;
    char operatorToChar(int const &action) const;
    operators::Operators getOperator(QChar const &symbol) const;
};

}
