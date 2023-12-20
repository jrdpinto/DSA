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

        bool Insert(Node* newNode)
        {
            bool nodeInserted = false;
            Node** pointerToTargetNode = nullptr;

            if (newNode->value > this->value)
            {
                pointerToTargetNode = &right;
            }
            else if (newNode->value < this->value)
            {
                pointerToTargetNode = &left;
            }

            if (pointerToTargetNode)
            {
                Node*& targetNode = *pointerToTargetNode;
                if (targetNode)
                {
                    nodeInserted = (targetNode)->Insert(newNode);
                }
                else
                {
                    nodeInserted = true;
                    targetNode = newNode;
                }
            }

            return nodeInserted;
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

    bool Insert(T value)
    {
        Node* newNode = new Node(value);
        if (root_)
        {
            return root_->Insert(newNode);
        }
        else
        {
            root_ = newNode;
            return true;
        }
    }

private:
    Node* root_ = nullptr;
};