#pragma once
#include <iostream>

template <class T>
class BinaryTreeNode
{
public:
    T _value;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;

    BinaryTreeNode(T value)
        : _value(value)
        , _left(nullptr)
        , _right(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        if (_left)
        {
            delete _left;
        }

        if (_right)
        {
            delete _right;
        }
    }

    void Add(T value)
    {
        if (value < _value)
        {
            AddToNodeOrSetValue(_left, value);
        }
        else if (value > _value)
        {
            AddToNodeOrSetValue(_right, value);
        }
    }

private:

    void AddToNodeOrSetValue(BinaryTreeNode* node, T value)
    {
        if (node)
        {
            node->Add(value);
        }
        else
        {
            node = new BinaryTreeNode<T>(value);
        }
    }
};
