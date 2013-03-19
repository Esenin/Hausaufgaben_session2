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

int CalcTree::strSize(char const *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}

bool CalcTree::isDigit(char const &symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

void CalcTree::clear()
{
    if (root != NULL)
        delete root;
    root = NULL;
}

bool CalcTree::isOperator(char const &symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

void CalcTree::setNewTree(char const string[])
{
    int const firstCharPos = 1;
    clear();
    addNode(root, string, firstCharPos);
}


int CalcTree::addNode(Node *&current, char const *string, int curPos)
{
    int strLen = strSize(string);
    bool isEditing = false;
    char word[strMaxLen] = {};
    int wordSize = 0;


    while (curPos < strLen)
    {
        if (isOperator(string[curPos]))
            current = new OperatorNode(string[curPos]);
        if (isDigit(string[curPos]))
        {
            isEditing = true;
            word[wordSize++] = string[curPos];
        }
        else
            if (isEditing)
            {
                word[wordSize++] = '\0';
                current->addChild(new OperandNode(word));
                isEditing = false;
                wordSize = 0;
            }
        if (string[curPos] == '(')
        {
            Node *branch = NULL;
            curPos = addNode(branch, string, curPos + 1);
            current->addChild(branch);
        }
        else
            if (string[curPos] == ')')
                return curPos;
        curPos++;
    }
    return curPos;
}

void CalcTree::printTree()
{
    root->print();
    cout << endl;
}

qreal CalcTree::calculateTree()
{
    return root->calculateTree();
}





