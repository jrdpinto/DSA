#pragma once
#include <iostream>
#include <sstream>
#include <initializer_list>


template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node* next = nullptr;
    
        Node(T value)
        {
            this->value = value;
        }
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int length_ = 0;

public:
    LinkedList() = default;

    LinkedList(std::initializer_list<T> initialValues)
    {
        for (auto value : initialValues)
        {
            append(value);
        }
    }

    ~LinkedList()
    {
        clear();
    }

    int GetLength()
    {
        return length_;
    }

    void clear()
    {
        Node* currentNode = head_;
        while (currentNode != nullptr)
        {
            Node* nextNode = nullptr;
            if (currentNode->next)
            {
                nextNode = currentNode->next;
            }

            delete(currentNode);
            currentNode = nextNode;

            --length_;
        }
    }

    void append(T value)
    {
        Node* newNode = new Node(value);

        if (!head_)
        {
            head_ = newNode;
        }

        Node* previousTail = tail_;
        if (previousTail)
        {
            previousTail->next = newNode;
        }
        tail_ = newNode;

        ++length_;
    }

    void prepend(T value)
    {
        Node* newNode = new Node(value);
        Node* previousHead = head_;
        head_ = newNode;

        if (previousHead)
        {
            head_->next = previousHead;
        }

        ++length_;
    }

    void printList()
    {
        Node* currentNode = head_;
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

    void deleteLast()
    {
        if (!tail_)
        {
            return;
        }

        // Find the node that points to the last node
        Node* previousNode = nullptr;
        if (tail_ != head_)
        {
            Node* currentNode = head_;
            while (currentNode)
            {
                if (currentNode->next && currentNode->next == tail_)
                {
                    previousNode = currentNode;
                    break;
                }
                
                currentNode = currentNode->next;
            }
        }

        delete(tail_);
        --length_;

        if (previousNode)
        {
            previousNode->next = nullptr;
            tail_ = previousNode;
        }
        else
        {
            head_ = tail_ = nullptr;
        }
    }

    // TODO:
    void reverseList()
    {

    }
};
