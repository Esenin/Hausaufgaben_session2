#pragma once

#include <stdlib.h>
#include <QtCore/QList>
#include <QtCore/QPair>
#include <QtCore/QDebug>

template <typename Type>
//! @class RBTree is container based on RedBlack balanced Tree
/*!
  implementation details: zero-leafs are real
  "path list" is used instead of parent-links
  */
class RBTree
{
public:
    RBTree();
    ~RBTree();

    void add(const Type &value);
    void removeOne(const Type &value);
    void removeAllAs(const Type &value);
    bool exists(const Type value) const;

protected:
    struct Node;
    Node *current() const;
    Node *parent() const;
    Node *sibling() const;
    Node *grandParent() const;
    Node *uncle() const;
    void switchToGrandpa();
    bool isLeaf(const Node *current) const;
    bool hasOneChild(const Node *current) const;
    void rotateRight(Node *current);
    void rotateLeft(Node *current);
    void transformToLeaf(Node *&current);
    QPair<Type, int>  popMostLeftChild(Node *&current);

    //! show parent their new children
    void parentNotification(Node *oldNode, Node *newNode);
    void rotatePathCorrection(Node *oldNode, Node *newNode);

    void addTo(Node *&current, const Type &newValue);
    //! recoursive downhill correction, insert_case 1: new node is root
    void isRootCorrection();
    void parentValidation();
    void parentCorrection();
    void middleRotatation();
    void topRotation();

    void remove(Node *&current, const Type &value);

    //! recoursive downhill for delete balance correction
    void deleteSingleChild();
    void rootBreakCase();
    void redBrotherCorrection();
    void blackBrotherCorrection();
    void differentChildrenCorrection();
    void redBrothersChildRotation();

private:
    QList<Node *> curPath;
    Node *root;
    bool totalRemove;
};


//Implementation

template <typename Type>
struct RBTree<Type>::Node
{
    Type value;
    int count;
    bool isRed;
    Node *leftChild;
    Node *rightChild;

    Node()
    {
        isRed = false;
        count = 0;
        leftChild = NULL;
        rightChild = NULL;
    }

    void operator= (const Type &newValue)
    {
        isRed = true;
        value = newValue;
        count = 1;
        if (!leftChild)
            leftChild = new Node();
        if (!rightChild)
            rightChild = new Node();
    }
    void operator= (const QPair<Type, int> &newData)
    {
        value = newData.first;
        count = newData.second;
    }
};

template <typename Type>
RBTree<Type>::RBTree()
    : totalRemove(false)
{
    curPath.clear();
    root = new Node(); // Null-leaf;
}

template <typename Type>
RBTree<Type>::~RBTree()
{
    root = NULL;
}

template <typename Type>
void RBTree<Type>::add(const Type &value)
{
    curPath.clear();
    addTo(root, value);
}

template <typename Type>
void RBTree<Type>::removeOne(const Type &value)
{
    curPath.clear();
    totalRemove = false;
    remove(root, value);
}

template <typename Type>
void RBTree<Type>::removeAllAs(const Type &value)
{
    curPath.clear();
    totalRemove = true;
    remove(root, value);
}

template <typename Type>
typename RBTree<Type>::Node *RBTree<Type>::grandParent() const
{
    if (curPath.size() < 3)
        return NULL;

    return curPath.at(curPath.size() - 3);
}

template <typename Type>
typename RBTree<Type>::Node *RBTree<Type>::parent() const
{
    if (curPath.size() < 2)
        return NULL;

    return curPath.at(curPath.size() - 2);
}

template <typename Type>
typename RBTree<Type>::Node *RBTree<Type>::sibling() const
{
    if (!parent())
        return NULL;

    if (parent()->leftChild == current())
        return parent()->rightChild;
    else
        return parent()->leftChild;
}

template <typename Type>
typename RBTree<Type>::Node *RBTree<Type>::uncle() const
{
    Node *grandpa = grandParent();
    if (!grandpa)
        return NULL;

    if (grandpa->leftChild == parent())
        return grandpa->rightChild;
    else
        return grandpa->leftChild;
}

template <typename Type>
void RBTree<Type>::switchToGrandpa()
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

template <typename Type>
bool RBTree<Type>::isLeaf(const Node *current) const
{
    return (current->leftChild == NULL && current->rightChild == NULL);
}

template <typename Type>
bool RBTree<Type>::hasOneChild(const RBTree::Node *current) const
{
    return (isLeaf(current->leftChild) != isLeaf(current->rightChild));
}

template <typename Type>
void RBTree<Type>::addTo(Node *&current, const Type &newValue)
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

template <typename Type>
void RBTree<Type>::rotateRight(Node *current)
{
    Node *newHead = current->leftChild;

    rotatePathCorrection(current, newHead);

    current->leftChild = newHead->rightChild;
    newHead->rightChild = current;
}

template <typename Type>
void RBTree<Type>::rotateLeft(RBTree::Node *current)
{
    Node *newHead = current->rightChild;

    rotatePathCorrection(current, newHead);

    current->rightChild = newHead->leftChild;
    newHead->leftChild = current;
}

template <typename Type>
void RBTree<Type>::transformToLeaf(RBTree::Node *&current)
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

template <typename Type>
QPair<Type, int> RBTree<Type>::popMostLeftChild(RBTree::Node *&current)
{
    if(!isLeaf(current->leftChild))
        return popMostLeftChild(current->leftChild);
    else
    {
        QPair<Type, int> result = QPair<Type, int>(current->value, current->count);
        Node *temp = current;
        current = current->rightChild;
        delete temp->leftChild;
        delete temp;
        return result;
    }
}

template <typename Type>
void RBTree<Type>::parentNotification(RBTree::Node *oldNode, RBTree::Node *newNode)
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

template <typename Type>
void RBTree<Type>::rotatePathCorrection(Node *oldNode, Node *newNode)
{
    const int notFound = -1;
    parentNotification(oldNode, newNode);

    if (curPath.indexOf(newNode) != notFound)
        curPath.removeOne(oldNode);
    else
        curPath.insert(curPath.indexOf(oldNode), newNode);
}

template <typename Type>
void RBTree<Type>::isRootCorrection()
{
    if (parent() == NULL)
        current()->isRed = false;
    else
        parentValidation();
}

template <typename Type>
void RBTree<Type>::parentValidation()
{
    if (!parent()->isRed)
        return;
    else
        parentCorrection();
}

template <typename Type>
void RBTree<Type>::parentCorrection()
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

template <typename Type>
void RBTree<Type>::middleRotatation()
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

template <typename Type>
void RBTree<Type>::topRotation()
{
    parent()->isRed = false;
    grandParent()->isRed = true;
    if (current() == parent()->leftChild && parent() == grandParent()->leftChild)
        rotateRight(grandParent());
    else
        rotateLeft(grandParent());
}

template <typename Type>
void RBTree<Type>::remove(Node *&current, const Type &value)
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

template <typename Type>
void RBTree<Type>::rootBreakCase()
{
    if (parent() != NULL)
        redBrotherCorrection();
}

template <typename Type>
void RBTree<Type>::deleteSingleChild()
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

template <typename Type>
void RBTree<Type>::redBrotherCorrection()
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

template <typename Type>
void RBTree<Type>::blackBrotherCorrection()
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

template <typename Type>
void RBTree<Type>::differentChildrenCorrection()
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

template <typename Type>
void RBTree<Type>::redBrothersChildRotation()
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

template <typename Type>
bool RBTree<Type>::exists(const Type value) const
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

template <typename Type>
typename RBTree<Type>::Node *RBTree<Type>::current() const
{
    if (curPath.size() == 0)
        return NULL;
    return curPath.last();
}

