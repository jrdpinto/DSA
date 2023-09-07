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
        deleteNode(length_ - 1);
    }

    void deleteFirst()
    {
        deleteNode(0);
    }

    void deleteNode(int index)
    {
        _ASSERT(index < length_);
        if (length_ < 1 || index > length_)
        {
            return;
        }

        // Find the target node, and the preceeding/following nodes if they exist
        Node* previous = nullptr;
        Node* next = nullptr;
        Node* current = head_;

        for (int i = 0; i <= index; ++i)
        {
            if (i < index)
            {
                previous = current;
                current = current->next;
            }
            else
            {
                next = current->next;
            }
        }

        // Ensure that head and tail are updated
        if (current == head_)
        {
            head_ = next;
        }

        if (current == tail_)
        {
            tail_ = previous;
        }

        delete(current);
        --length_;

        if (previous)
        {
            previous->next = next;
        }
    }

    // TODO:
    void reverseList()
    {

    }
};
