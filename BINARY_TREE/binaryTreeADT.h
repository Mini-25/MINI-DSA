#ifndef BINARY_SEARCH_TREE_ADT_H
#define BINARY_SEARCH_TREE_ADT_H

class BinarySearchTreeADT
{
public:
    virtual void insert(int value) = 0;
    virtual void inordertraversal() const = 0;
    virtual void preordertraversal() const = 0;
    virtual void postordertraversal() const = 0;
};

#endif 
