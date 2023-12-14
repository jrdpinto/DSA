#pragma once
#include <iostream>

template <class T>
class BinaryTreeNode
{
public:
    struct Node
    {
        T value;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(T value) : value(value)
        {
        }

        ~Node()
        {
            if (left)
            {
                delete left;
            }

            if (right)
            {
                delete right;
            }
        }
    };

    BinaryTreeNode() = default;

    ~BinaryTreeNode()
    {
        if (root_)
        {
            delete root_;
        }
    }

    void Insert(T value)
    {
        //if (value < value_)
        //{
        //    AddToNodeOrSetValue(left_, value);
        //}
        //else if (value > value_)
        //{
        //    AddToNodeOrSetValue(right_, value);
        //}
    }

private:
    Node* root_ = nullptr;

    /*void AddToNodeOrSetValue(BinaryTreeNode* node, T value)
    {
        if (node)
        {
            node->Add(value);
        }
        else
        {
            node = new BinaryTreeNode<T>(value);
        }
    }*/
};
