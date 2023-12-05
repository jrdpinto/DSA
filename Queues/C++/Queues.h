#pragma once
#include <initializer_list>
#include <iostream>
#include <sstream>

template <typename T>
class Queue
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

    Queue() = default;

    Queue(std::initializer_list<T> initialValues)
    {
        for (auto value : initialValues)
        {
            Enqueue(value);
        }
    }

    ~Queue()
    {
    }

    void Enqueue(T value)
    {
        Node* newNode = new Node(value);
        if (last_)
        {
            last_->next = newNode;
            last_ = newNode;
        }
        else
        {
            first_ = last_ = newNode;
        }

        ++length_;
    }

    template <typename T, typename... Args> void Enqueue(T first, Args... args)
    {
        Enqueue(first);
        Enqueue(args...);
    }

    T Dequeue()
    {
        T value;

        if (first_)
        {
            value = first_->value;
            
            Node* temp = first_;

            if (temp->next)
            {
                first_ = temp->next;
            }
            else if (temp == last_)
            {
                first_ = last_ = nullptr;
            }

            delete(temp);

            --length_;
        }

        return value;
    }

    void Print()
    {
        Node* currentNode = first_;
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

    int GetLength()
    {
        return length_;
    }

private:
    Node* first_ = nullptr;
    Node* last_ = nullptr;
    int length_ = 0;
};
