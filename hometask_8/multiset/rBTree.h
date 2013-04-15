#pragma once

#include <stdlib.h>
#include <QtCore/QList>
#include <QtCore/QPair>
#include <QtCore/QDebug>

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

    void add(const int &value);
    void removeOne(const int &value);
    void removeAllAs(const int &value);
    bool exists(const int value);

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
    QPair<int, int>  popMostLeftChild(Node *&current);

    //! show parent their new children
    void parentNotification(Node *oldNode, Node *newNode);
    void rotatePathCorrection(Node *oldNode, Node *newNode);

    void addTo(Node *&current, const int &newValue);
    //! recoursive downhill correction, insert_case 1: new node is root
    void isRootCorrection();
    void parentValidation();
    void parentCorrection();
    void middleRotatation();
    void topRotation();

    void remove(Node *&current, const int &value);

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


