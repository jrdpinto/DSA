#pragma once
#include <iostream>
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
        Node<T>* newNode = new Node<T>(value);
        Node<T>* previousHead = head_;
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
        while (currentNode)
        {
            std::cout << "Value: " << currentNode->value << std::endl;
            currentNode = currentNode->next;
        }
    }

    // TODO:

    void deleteLast()
    {
        
    }

    void reverseList()
    {

    }
};
