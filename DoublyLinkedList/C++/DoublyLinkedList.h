#pragma once
#include <iostream>
#include <sstream>
#include <initializer_list>

template <typename T>
class DoublyLinkedList
{
public:
    struct Node
    {
        T value;
        Node* previous = nullptr;
        Node* next = nullptr;

        Node(T value)
        {
            this->value = value;
        }
    };

    DoublyLinkedList() = default;

    DoublyLinkedList(std::initializer_list<T> initialValues)
    {
        for (auto value : initialValues)
        {
            Append(value);
        }
    }

    ~DoublyLinkedList()
    {
        Clear();
    }

    int GetLength()
    {
        return length_;
    }

    void Clear()
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

        head_ = tail_ = nullptr;
    }

    template <typename... Args>
    void Append(T first, Args... rest)
    {
        Append(first);
        Append(rest...);
    }

    void Append(T value)
    {
        Node* newNode = new Node(value);

        if (!head_)
        {
            head_ = newNode;
        }
        else
        {
            Node* previousTail = tail_;
            if (previousTail)
            {
                previousTail->next = newNode;
                newNode->previous = previousTail;
            }
        }

        tail_ = newNode;

        ++length_;
    }

    template <typename... Args>
    void Prepend(T first, Args... rest)
    {
        Prepend(first);
        Prepend(rest...);
    }

    void Prepend(T value)
    {
        Node* newNode = new Node(value);

        if (head_)
        {
            head_->previous = newNode;
            newNode->next = head_;
        }
        else
        {
            // The list is empty. The new node becomes both the head and the tail.
            tail_ = newNode;
        }

        head_ = newNode;
        ++length_;
    }

    void DeleteLast()
    {
        if (!tail_)
        {
            return;
        }

        Node* lastNode = tail_;

        if (tail_->previous)
        {
            // If the tail has a previous node, make that node the new tail
            tail_ = tail_->previous;
            tail_->next = nullptr;
        }
        else
        {
            // If the tail does not have a previous node, it is the only node in the list
            head_ = nullptr;
            tail_ = nullptr;
        }

        delete(lastNode);
        --length_;
    }

    void DeleteFirst()
    {
        if (!head_)
        {
            return;
        }

        Node* temp = head_;

        if (temp->next)
        {
            head_ = temp->next;
            head_->previous = nullptr;
        }
        else
        {
            head_ = nullptr;
            tail_ = nullptr;
        }

        delete(temp);
        --length_;
    }

    void PrintList()
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

    Node* GetNode(int index)
    {
        Node* targetNode = nullptr;
        if (index >= length_ || index < 0)
        {
            return targetNode;
        }

        int currentIndex;
        if (index > (int)length_ / 2)
        {
            targetNode = tail_;
            currentIndex = length_ - 1;
        }
        else
        {
            targetNode = head_;
            currentIndex = 0;
        }

        while (currentIndex != index && targetNode)
        {
            if (currentIndex < index)
            {
                ++currentIndex;
                targetNode = targetNode->next;
            }
            else
            {
                --currentIndex;
                targetNode = targetNode->previous;
            }
        }

        return targetNode;
    }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int length_ = 0;
};

