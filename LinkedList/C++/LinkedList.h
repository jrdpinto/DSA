#pragma once
#include <iostream>


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

    Node* head_;
    Node* tail_;
    int length_ = 0;

public:
    LinkedList(T value)
    {
        Node* newNode = new Node(value);
        head_ = newNode;
        tail_ = newNode;
        length_ = 1;
    }

    ~LinkedList()
    {
        int count = 0;
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
            ++count;

            _ASSERT(count <= length_);
        }
    }

    void append(T value)
    {
        Node* newNode = new Node(value);
        Node* previousTail = tail_;
        previousTail->next = newNode;
        tail_ = newNode;
        ++length_;
    }

    void prepend(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* previousHead = head_;
        head_ = newNode;
        head_->next = previousHead;
        ++length_;
    }
};
