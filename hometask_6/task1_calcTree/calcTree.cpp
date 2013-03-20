#include "calcTree.h"

using namespace treeNodes;
using std::cout;
using std::endl;

CalcTree::CalcTree()
    : root(NULL)
{
}

CalcTree::~CalcTree()
{
    clear();
}

void CalcTree::clear()
{
    if (root != NULL)
        delete root;
    root = NULL;
}

bool CalcTree::isOperator(QChar const &symbol) const
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

void CalcTree::setNewTree(QString const string)
{
    int const firstCharPos = 1;
    clear();
    addNode(root, string, firstCharPos);
}


int CalcTree::addNode(Node *&current, QString const string, int curPos)
{
    QRegExp separators("[()+-*/ ]");
    int strLen = string.size();
    QString figure("");
    figure.clear();

    while (curPos < strLen)
    {
        if (isOperator(string.at(curPos)))
            current = new OperatorNode(string.at(curPos));

        if (string.at(curPos).isDigit())
        {
            figure = string.mid(curPos, separators.indexIn(string, curPos + 1) - curPos);
            curPos += figure.size();

            if (current != NULL)
                current->addChild(new OperandNode(figure));
            else
                current = new OperandNode(figure);
            figure.clear();
        }

        if (string.at(curPos) == '(')
        {
            Node *branch = NULL;
            curPos = addNode(branch, string, curPos + 1);
            current->addChild(branch);
        }
        else
            if (string.at(curPos) == ')')
                return curPos;
        curPos++;
    }
    return curPos;
}

void CalcTree::printTree() const
{
    root->print();
    cout << endl;
}

qreal CalcTree::calculateTree()
{
    return root->calculateTree();
}





