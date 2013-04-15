#include "rBTree.h"

struct RBTree::Node
{
    int value;
    int count;
    bool isRed;
    Node *leftChild;
    Node *rightChild;

    Node()
    {
        isRed = false;
        value = 0;
        count = 0;
        leftChild = NULL;
        rightChild = NULL;
    }

    void operator= (const int &newValue)
    {
        isRed = true;
        value = newValue;
        count = 1;
        if (!leftChild)
            leftChild = new Node();
        if (!rightChild)
            rightChild = new Node();
    }
    void operator= (const QPair<int, int> &newData)
    {
        value = newData.first;
        count = newData.second;
    }
};

RBTree::RBTree()
    : totalRemove(false)
{
    curPath.clear();
    root = new Node(); // Null-leaf;
}

RBTree::~RBTree()
{
    root = NULL;
}

void RBTree::add(const int &value)
{
    curPath.clear();
    addTo(root, value);
}

void RBTree::removeOne(const int &value)
{
    curPath.clear();
    totalRemove = false;
    remove(root, value);
}

void RBTree::removeAllAs(const int &value)
{
    curPath.clear();
    totalRemove = true;
    remove(root, value);
}

RBTree::Node *RBTree::grandParent() const
{
    if (curPath.size() < 3)
        return NULL;

    return curPath.at(curPath.size() - 3);
}

RBTree::Node *RBTree::parent() const
{
    if (curPath.size() < 2)
        return NULL;

    return curPath.at(curPath.size() - 2);
}

RBTree::Node *RBTree::sibling() const
{
    if (!parent())
        return NULL;

    if (parent()->leftChild == current())
        return parent()->rightChild;
    else
        return parent()->leftChild;
}

RBTree::Node *RBTree::uncle() const
{
    Node *grandpa = grandParent();
    if (!grandpa)
        return NULL;

    if (grandpa->leftChild == parent())
        return grandpa->rightChild;
    else
        return grandpa->leftChild;
}

void RBTree::switchToGrandpa()
{
    Node *grandpa = grandParent();
    if (grandpa == NULL)
    {
        curPath.clear();
        return;
    }

    while(curPath.last() != grandpa)
        curPath.removeLast();
}

bool RBTree::isLeaf(const Node *current) const
{
    return (current->leftChild == NULL && current->rightChild == NULL);
}

bool RBTree::hasOneChild(const RBTree::Node *current) const
{
    return (isLeaf(current->leftChild) != isLeaf(current->rightChild));
}

void RBTree::addTo(Node *&current, const int &newValue)
{
    curPath.append(current);

    if (isLeaf(current))
    {
        (*current) = newValue;
        isRootCorrection();
        return;
    }
    else
        if (current->value == newValue)
        {
            current->count++;
            return;
        }

    if (newValue < current->value)
        addTo(current->leftChild, newValue);
    if (newValue > current->value)
        addTo(current->rightChild, newValue);
}

void RBTree::rotateRight(Node *current)
{
    Node *newHead = current->leftChild;

    rotatePathCorrection(current, newHead);

    current->leftChild = newHead->rightChild;
    newHead->rightChild = current;
}

void RBTree::rotateLeft(RBTree::Node *current)
{
    Node *newHead = current->rightChild;

    rotatePathCorrection(current, newHead);

    current->rightChild = newHead->leftChild;
    newHead->leftChild = current;
}

void RBTree::transformToLeaf(RBTree::Node *&current)
{
    if (current->leftChild)
    {
        delete current->leftChild;
        current->leftChild = NULL;
    }
    if (current->rightChild)
    {
        delete current->rightChild;
        current->rightChild = NULL;
    }
    current->count = 0;
    current->value = 0;
    current->isRed = false;
}

QPair<int, int> RBTree::popMostLeftChild(RBTree::Node *&current)
{
    if(!isLeaf(current->leftChild))
        return popMostLeftChild(current->leftChild);
    else
    {
        QPair<int, int> result = QPair<int, int>(current->value, current->count);
        Node *temp = current;
        current = current->rightChild;
        delete temp->leftChild;
        delete temp;
        return result;
    }
}

void RBTree::parentNotification(RBTree::Node *oldNode, RBTree::Node *newNode)
{
    if (root == oldNode)
    {
        root = newNode;
        return;
    }

    Node *parent = curPath.at(curPath.indexOf(oldNode) - 1);
    if (parent->leftChild == oldNode)
        parent->leftChild = newNode;
    else
        parent->rightChild = newNode;
}

void RBTree::rotatePathCorrection(Node *oldNode, Node *newNode)
{
    const int notFound = -1;
    parentNotification(oldNode, newNode);

    if (curPath.indexOf(newNode) != notFound)
        curPath.removeOne(oldNode);
    else
        curPath.insert(curPath.indexOf(oldNode), newNode);
}

void RBTree::isRootCorrection()
{
    if (parent() == NULL)
        current()->isRed = false;
    else
        parentValidation();
}

void RBTree::parentValidation()
{
    if (!parent()->isRed)
        return;
    else
        parentCorrection();
}

void RBTree::parentCorrection()
{
    if ((uncle() != NULL) && (uncle()->isRed) && (parent()->isRed))
    {
        parent()->isRed = false;
        uncle()->isRed = false;
        grandParent()->isRed = true;
        switchToGrandpa();
        isRootCorrection();
    }
    else
        middleRotatation();
}

void RBTree::middleRotatation()
{
    if (current() == parent()->rightChild && parent() == grandParent()->leftChild)
    {
        rotateLeft(parent());
        curPath.append(current()->leftChild);
    }
    else
        if (current() == parent()->leftChild && parent() == grandParent()->rightChild)
        {
            rotateRight(parent());
            curPath.append(current()->rightChild);
        }

    topRotation();
}

void RBTree::topRotation()
{
    parent()->isRed = false;
    grandParent()->isRed = true;
    if (current() == parent()->leftChild && parent() == grandParent()->leftChild)
        rotateRight(grandParent());
    else
        rotateLeft(grandParent());
}

void RBTree::remove(Node *&current, const int &value)
{
    if (current == NULL)
        throw;

    curPath.append(current);

    if (current->value < value)
    {
        remove(current->rightChild, value);
        return;
    }
    if (current->value > value)
    {
        remove(current->leftChild, value);
        return;
    }

    if (!totalRemove && (current->count - 1 > 0))
    {
        current->count--;
        return;
    }
    if (hasOneChild(current))
    {
        deleteSingleChild();
    }
    else
    {
        if (isLeaf(current->rightChild))
        {
            transformToLeaf(current);

        }
        else
            (*current) = popMostLeftChild(current->rightChild);
    }
}

void RBTree::rootBreakCase()
{
    if (parent() != NULL)
        redBrotherCorrection();
}

void RBTree::deleteSingleChild()
{
    Node *badNode = current();
    Node *child = isLeaf(badNode->leftChild)? badNode->rightChild : badNode->leftChild;

    parentNotification(badNode, child);
    curPath.removeOne(current());
    if (!badNode->isRed)
    {
        if (child->isRed)
            child->isRed = false;
        else
            {
                curPath.append(child);
                rootBreakCase();
            }
    }

    delete ((badNode->leftChild == child)? badNode->rightChild : badNode->leftChild);
    delete badNode;
}

void RBTree::redBrotherCorrection()
{
    Node *brother = sibling();
    if (brother->isRed)
    {
        parent()->isRed = true;
        brother->isRed = false;
        if (current() == parent()->leftChild)
            rotateLeft(parent());
        else
            rotateRight(parent());
    }

    if (!parent()->isRed && !brother->isRed && (!brother->leftChild->isRed && !brother->rightChild->isRed))
    {
        brother->isRed = true;
        curPath.removeLast();
        rootBreakCase();
    }
    else
        blackBrotherCorrection();
}

void RBTree::blackBrotherCorrection()
{
    Node *brother = sibling();
    if (parent()->isRed && !brother->isRed && (!brother->leftChild->isRed && !brother->rightChild->isRed))
    {
        brother->isRed = true;
        parent()->isRed = false;
    }
    else
        differentChildrenCorrection();
}

void RBTree::differentChildrenCorrection()
{
    Node *brother = sibling();
    if (!brother->isRed)
    {
        if (current() == parent()->leftChild && (!brother->rightChild->isRed && brother->leftChild->isRed))
        {
            brother->isRed = true;
            brother->leftChild->isRed = false;

            rotateRight(brother);
        }
        else
            if (current() == parent()->rightChild && (!brother->leftChild->isRed && brother->rightChild->isRed))
            {
                brother->isRed = true;
                brother->rightChild->isRed = false;

                rotateLeft(brother);
            }
    }
    redBrothersChildRotation();
}

void RBTree::redBrothersChildRotation()
{
    Node *brother = sibling();

    brother->isRed = parent()->isRed;
    parent()->isRed = false;
    if (current() == parent()->leftChild)
    {
        brother->rightChild->isRed = false;
        rotateLeft(parent());
    }
    else
    {
        brother->leftChild->isRed = false;
        rotateRight(parent());
    }
}

bool RBTree::exists(const int value)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->value == value)
            return true;
        if (value < temp->value)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    return false;
}

RBTree::Node *RBTree::current() const
{
    if (curPath.size() == 0)
        return NULL;

    return curPath.last();
}


