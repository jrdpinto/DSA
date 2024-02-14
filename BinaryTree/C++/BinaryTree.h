﻿#pragma once
#include <iostream>
#include <queue>
#include <initializer_list>

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

    BinaryTree(std::initializer_list<T> initialList)
    {
        for (const T& value : initialList)
        {
            Insert(value);
        }
    }

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

    void BreadthFirstSearch()
    {
        std::queue<Node*> traversalQueue;

        if (root_)
        {
            traversalQueue.push(root_);
        }

        while(!traversalQueue.empty())
        {
            Node* currentNode = traversalQueue.front();
            traversalQueue.pop();

            std::cout << currentNode->value << " ";

            if (currentNode->left)
            {
                traversalQueue.push(currentNode->left);
            }

            if (currentNode->right)
            {
                traversalQueue.push(currentNode->right);
            }
        }

        std::cout << std::endl;
    }

    void DepthFirstPreOrderTraversal()
    {
        if (root_)
        {
            DepthFirstPreOrderTraversal(root_);
            std::cout << std::endl;
        }
    }

    // For each node, the left node and all of its children are visited recursively before visiting
    // the right node
    void DepthFirstPreOrderTraversal(Node* node)
    {
        std::cout << node->value << " ";

        if (node->left)
        {
            DepthFirstPreOrderTraversal(node->left);
        }

        if (node->right)
        {
            DepthFirstPreOrderTraversal(node->right);
        }
    }

private:
    Node* root_ = nullptr;
};