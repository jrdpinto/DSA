#pragma once
#include <initializer_list>
#include <iostream>

template <class T>
class RedBlackTree
{
public:
    struct Node
    {
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
        int height = 1;

        Node(T value) : value(value) {}

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

        int BalanceFactor()
        {
            return (left ? left->height : 0) - (right ? right->height : 0);
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

    RedBlackTree() = default;

    RedBlackTree(std::initializer_list<T> initialList)
    {
        for (const T& value : initialList)
        {
            Insert(value);
        }
    }

    ~RedBlackTree()
    {
        if (root_)
        {
            delete root_;
        }
    }

    Node* Insert(T value)
    {
        Node* newNode;

        if (root_)
        {
            newNode = RInsert(root_, value);
        }
        else
        {
            newNode = new Node(value);
            root_ = newNode;
        }

        return newNode;
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

    int Height()
    {
        if (!root_)
        {
            return 0;
        }

        return Height(root_);
    }

    bool IsHeightBalanced()
    {
        bool isHeightBalanced = true;

        if (root_)
        {
            auto getHeight = [](auto& self, Node* node, bool& heightBalanced) -> int
                {
                    int leftTreeHeight = 0, rightTreeHeight = 0;

                    if (node->left)
                    {
                        leftTreeHeight = self(self, node->left, heightBalanced);
                        if (!heightBalanced)
                        {
                            return -1;
                        }
                    }

                    if (node-> right)
                    {
                        rightTreeHeight = self(self, node->right, heightBalanced);
                        if (!heightBalanced)
                        {
                            return -1;
                        }
                    }

                    heightBalanced = std::abs(leftTreeHeight - rightTreeHeight) <= 1;

                    return std::max(leftTreeHeight, rightTreeHeight) + 1;
                };
            
            getHeight(getHeight, root_, isHeightBalanced);
        }

        return isHeightBalanced;
    }

private:
    Node* root_ = nullptr;
    
    int Height(Node* node)
    {
        int currentHeight = 0, totalHeight = 0;
        auto postOrderTraversal = [&] (auto& self, Node* node) -> void
        {
            ++currentHeight;
            if (currentHeight > totalHeight)
            {
                totalHeight = currentHeight;
            }

            if (node->left)
            {
                self(self, node->left);
                --currentHeight;
            }

            if (node->right)
            {
                self(self, node->right);
                --currentHeight;
            }
        };

        postOrderTraversal(postOrderTraversal, root_);

        return totalHeight;
    }

    //     5           3 
    //    /           / \ 
    //   3    ->     2   5
    //  /    
    // 2   
    Node* RotateRight(Node* targetNode) 
    {
        Node* middleNode = targetNode->left;
        Node* middleNodeRightSubtree = middleNode->right;

        middleNode->right = targetNode;
        targetNode->left = middleNodeRightSubtree;

        targetNode->height = std::max(targetNode->left ? targetNode->left->height : 0,
            targetNode->right ? -targetNode->right->height : 0) + 1;
        middleNode->height = std::max(middleNode->left ? middleNode->left->height : 0,
            middleNode->right ? middleNode->right->height : 0) + 1;

        if (targetNode == root_)
        {
            root_ = middleNode;
        }

        return middleNode;
    }

    //  2             4 
    //   \           / \ 
    //    4    ->   2   5
    //     \          
    //      5         
    Node* RotateLeft(Node* targetNode) 
    {
        Node* middleNode = targetNode->right;
        Node* middleNodeLeftSubTree = middleNode->left;

        middleNode->left = targetNode;
        targetNode->right = middleNodeLeftSubTree;

        targetNode->height = std::max(targetNode->left ? targetNode->left->height : 0,
            targetNode->right ? -targetNode->right->height : 0) + 1;
        middleNode->height = std::max(middleNode->left ? middleNode->left->height : 0,
            middleNode->right ? middleNode->right->height : 0) + 1;

        if (targetNode == root_)
        {
            root_ = middleNode;
        }

        return middleNode;
    }

    Node* RInsert(Node* node, T& value)
    {
        if (node->value == value)
        {
            return nullptr;
        }

        Node* newNode = nullptr;

        Node** pointerToTargetNode = (value > node->value) ? &node->right : &node->left;
        if (*pointerToTargetNode)
        {
            newNode = RInsert(*pointerToTargetNode, value);
        }
        else
        {
            newNode = new Node(value);
            *pointerToTargetNode = &*newNode;
        }

        if (newNode)
        {
            node->height = std::max(node->left ? node->left->height : 0, node->right ? node->right->height : 0) + 1;

            int balanceFactor = node->BalanceFactor();

            if (balanceFactor > 1)
            {
                // Rebalances the tree when the left sub tree is taller than the right sub tree
                if (newNode->value < node->left->value)
                {
                    RotateRight(node);
                }
                // Rebalances the tree when the inserted node is on the right of the left sub tree
                else if (newNode->value > node->left->value)
                {
                    node->left = RotateLeft(node->left);
                    RotateRight(node);
                }
            }
            else if (balanceFactor < -1)
            {
                // Rebalances the tree when the right sub tree is taller than the left sub tree
                if (newNode->value > node->right->value)
                {
                    RotateLeft(node);
                }
                // Rebalances the tree when the inserted node is on the left of the right sub tree
                else if (newNode->value < node->right->value)
                {
                    node->right = RotateRight(node->right);
                    RotateLeft(node);
                }
            }
        }

        return newNode;
    }
};