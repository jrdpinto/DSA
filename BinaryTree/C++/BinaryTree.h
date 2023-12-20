#pragma once
#include <iostream>

template <class T>
class BinaryTree
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

        bool Contains(const T& value)
        {
            bool valueFound = this->value == value;

            if(!valueFound)
            {
                if (left && value <= this->value)
                {
                    valueFound = left->Contains(value);
                }
                else if (right && value >= this->value)
                {
                    valueFound = right->Contains(value);
                }
            }

            return valueFound;
        }
    };

    BinaryTree() = default;

    ~BinaryTree()
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

    bool Contains(const T& value)
    {
        if (root_)
        {
            return root_->Contains(value);
        }
        else
        {
            return false;
        }
    }

private:
    Node* root_ = nullptr;
};