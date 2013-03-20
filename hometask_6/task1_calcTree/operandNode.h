#pragma once

#include <QtCore/QString>

#include "node.h"

namespace treeNodes
{

class OperandNode : public Node
{
public:
    OperandNode(QString const &figure);

    qreal calculateTree() const;

protected:
    void writeSelf() const;
};

}

