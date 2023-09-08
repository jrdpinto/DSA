﻿#pragma once
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

    Node* GetNode(int index, Node*& previousNode)
    {
        Node* node = nullptr;
        previousNode = nullptr;

        _ASSERT(index < length_);
        if (length_ < 1 || index >= length_)
        {
            return node;
        }

        node = head_;
        for (int i = 0; i < index; ++i)
        {
            previousNode = node;
            node = node->next;
        }

        return node;
    }

public:
    LinkedList() = default;

    LinkedList(std::initializer_list<T> initialValues)
    {
        for (auto value : initialValues)
        {
            Append(value);
        }
    }

    ~LinkedList()
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
    }

    void Append(T value)
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

    void Prepend(T value)
    {
        Insert(0, value);
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

    void DeleteLast()
    {
        DeleteNode(length_ - 1);
    }

    void DeleteFirst()
    {
        DeleteNode(0);
    }

    void DeleteNode(int index)
    {
        Node* previous = nullptr;
        Node* current = GetNode(index, previous);

        if (current)
        {
            Node* next = current->next;

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
    }

    void SetNode(int index, T value)
    {
        Node* prevNode = nullptr;
        Node* targetNode = GetNode(index, prevNode);
        if (targetNode)
        {
            targetNode->value = value;
        }
    }

    bool Insert(int index, T value)
    {
        bool success = false;
        Node* prevNode = nullptr;
        Node* targetNode = GetNode(index, prevNode);

        if (targetNode)
        {
            Node* newNode = new Node(value);
            newNode->next = targetNode;

            if (prevNode)
            {
                prevNode->next = newNode;
            }

            if (targetNode == head_)
            {
                head_ = newNode;
            }

            ++length_;
            success = true;
        }

        return success;
    }

    // TODO:
    void ReverseList()
    {

    }
};
