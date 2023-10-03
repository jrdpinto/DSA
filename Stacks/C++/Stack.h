#pragma once
#include <initializer_list>
#include <iostream>
#include <sstream>

template <typename T>
class Stack
{
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
    
        Node(T value)
        {
            this->value = value;
        }
    };

    Stack() = default;

    Stack(std::initializer_list<T> initialValues)
    {
        for (auto value : initialValues)
        {
            Push(value);
        }
    }

    ~Stack()
    {
        Clear();
    }

    int GetHeight()
    {
        return height_;
    }

    void Clear()
    {
        Node* currentNode = top_;
        while (currentNode != nullptr)
        {
            Node* nextNode = nullptr;
            if (currentNode->next)
            {
                nextNode = currentNode->next;
            }

            delete(currentNode);
            currentNode = nextNode;

            --height_;
        }

        top_ = nullptr;
    }

    void Push(T value)
    {
        Node* newNode = new Node(value);
        if (top_)
        {
            newNode->next = top_;
        }

        top_ = newNode;
        ++height_;
    }

    T Pop()
    {
        if (top_)
        {
            T temp = top_->value;

            Node* next = top_->next;
            delete(top_);
            top_ = next;

            --height_;

            return temp;
        }
        else
        {
            throw std::underflow_error("Pop() called on empty stack");
        }
    }

    void Print()
    {
        Node* currentNode = top_;
        std::stringstream ss;
        while (currentNode)
        {
            ss << currentNode->value;

            currentNode = currentNode->next;
            if (currentNode)
            {
                ss << ",";
            }
        }

        std::cout << "Values: " << ss.str() << std::endl;
    }

private:
    Node* top_ = nullptr;
    int height_ = 0;
};