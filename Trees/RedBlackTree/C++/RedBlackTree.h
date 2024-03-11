#pragma once
#include <initializer_list>
#include <iostream>

template <class T>
class RedBlackTree
{
public:
    enum class Colour
    {
        Red,
        Black
    };

    struct Node
    {
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
        Colour colour = Colour::Red;

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
            newNode->colour = Colour::Black;
            root_ = newNode;
        }

        return newNode;
    }

    bool IsHeightBalanced() const
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

    int Depth()
    {
        if (!root_)
        {
            return 0;
        }

        int currentDepth = 0, totalDepth = 0;
        auto postOrderTraversal = [&] (auto& self, Node* node) -> void
        {
            ++currentDepth;
            if (currentDepth > totalDepth)
            {
                totalDepth = currentDepth;
            }

            if (node->left)
            {
                self(self, node->left);
                --currentDepth;
            }

            if (node->right)
            {
                self(self, node->right);
                --currentDepth;
            }
        };

        postOrderTraversal(postOrderTraversal, root_);

        return totalDepth;
    }

    void DepthFirstInOrderTraversal() const
    {
        if (root_)
        {
            std::cout << "In order traversal: ";
            DepthFirstInOrderTraversal(root_);
            std::cout << std::endl;
        }
    }

    void DepthFirstInOrderTraversal(Node* node) const
    {
        if (node->left)
        {
            DepthFirstInOrderTraversal(node->left);
        }

        std::cout << node->value << " ";

        if (node->right)
        {
            DepthFirstInOrderTraversal(node->right);
        }
    }

private:

    Node* root_ = nullptr;

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
            *pointerToTargetNode = newNode;
            newNode->parent = node;

            Balance(newNode);
        }

        return newNode;
    }

    void Balance(Node* node)
    {
        Node* parent = node->parent;
        if (node == root_)
        {
            node->colour = Colour::Black;
            return;
        }

        Node* grandparent = parent->parent;
        if (grandparent == nullptr)
        {
            return;
        }
        
        Node* uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

        if (parent->colour == Colour::Black)
        {
            return;
        }
        else if (uncle && uncle->colour == Colour::Red)
        {
            parent->colour = Colour::Black;
            uncle->colour = Colour::Black;
            grandparent->colour = Colour::Red;
            Balance(grandparent);
            return;
        }
        else
        {
            if (node == parent->right && parent == grandparent->left)
            {
                // Left-Right case
                RotateLeft(parent);
                node = node->left;
            }
            else if (node == parent->left && parent == grandparent->right)
            {
                // Right-Left case
                RotateRight(parent);
                node = node->right;
            }

            parent = node->parent;
            grandparent = parent->parent;

            if (node == parent->left)
            {
                // Left-Left case
                RotateRight(grandparent);
            }
            else
            {
                // Right-Right case
                RotateLeft(grandparent);
            }

            parent->colour = Colour::Black;
            grandparent->colour = Colour::Red;
        }
    }

    void RotateLeft(Node* node)
    {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left)
        {
            rightChild->left->parent = node;
        }

        rightChild->parent = node->parent;

        if (node->parent)
        {
            if (node == node->parent->left)
            {
                node->parent->left = rightChild;
            }
            else
            {
                node->parent->right = rightChild;
            }
        }
        else
        {
            root_ = rightChild;
        }

        rightChild->left = node;
        node->parent = rightChild;
    }

    void RotateRight(Node* node)
    {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right)
        {
            leftChild->right->parent = node;
        }

        leftChild->parent = node->parent;

        if (node->parent)
        {
            if (node == node->parent->right)
            {
                node->parent->right = leftChild;
            }
            else
            {
                node->parent->left = leftChild;
            }
        }
        else
        {
            root_ = leftChild;
        }

        leftChild->right = node;
        node->parent = leftChild;
    }
};