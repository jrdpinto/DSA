#pragma once
#include <iostream>
#include <sstream>
#include <initializer_list>


template <typename T>
class LinkedList
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

        head_ = tail_ = nullptr;
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

    void Reverse()
    {
        if (length_ <= 1)
        {
            return;
        }

        Node* previousTail = tail_;
        Node* previousHead = head_;

        Node* currentNode = head_;
        Node* previousNode = nullptr;
        while (currentNode != nullptr)
        {
            Node* nextNode = currentNode->next;
            currentNode->next = previousNode;

            // Move down the list
            previousNode = currentNode;
            currentNode = nextNode;
        }

        head_ = previousTail;
        tail_ = previousHead;
    }

    Node* GetNodeAtIndex(int index)
    {
        Node* previousNode = nullptr;
        return GetNode(index, previousNode);
    }

    // Interview Question - Find Middle Node
    // Implement a member function, findMiddleNode(), which finds and returns the middle node of the linked 
    // list.
    // NOTE: THIS LINKEDLIST IMPLEMENTATION DOES NOT HAVE A LENGTH MEMBER VARIABLE.
    // 
    // Function Signature:
    // Node* findMiddleNode();
    // 
    // Input:
    //     The linked list can have any number of nodes (0 to n).
    //     Node values are integers.
    // 
    // Output:
    //     Return a pointer to the middle node of the linked list.
    //     If the list has an even number of nodes, return the second middle node (the one closer to the
    //     end).
    // 
    // Constraints:
    //     You are not allowed to use any additional data structures (such as arrays) or modify the existing 
    //     data structure.
    //     You can only traverse the linked list once.

    Node* FindMiddleNode()
    {
        Node* currentNode = head_;
        Node* lookAheadNode = currentNode;

        while (lookAheadNode != nullptr && lookAheadNode != tail_)
        {
            currentNode = currentNode->next;

            // Move 'lookAheadNode', two nodes ahead. When this node reaches the tail, the 'currentNode'
            // will be at the middle.
            lookAheadNode = lookAheadNode->next;
            if (lookAheadNode)
            {
                lookAheadNode = lookAheadNode->next;
            }
        }

        return currentNode;
    }

    // Interview Question - Has Loop
    //
    // Implement a function called hasLoop to detect if a given singly-linked list contains a loop (a cycle) or not.
    // The function should return true if a loop is detected in the linked list, and false otherwise. 
    //
    // You should use the Floyd's cycle-finding algorithm (also known as the "tortoise and the hare" algorithm) to
    // detect the loop. This algorithm uses two pointers, a slow pointer, and a fast pointer. The slow pointer
    // moves one step at a time, while the fast pointer moves two steps at a time. If there is a loop in the linked
    // list, the two pointers will eventually meet at some point. If there is no loop, the fast pointer will reach
    // the end of the list.

    bool HasLoop()
    {
        Node* slow = head_;
        Node* fast = head_;
        bool hasLoop = false;

        while (!hasLoop && fast != nullptr)
        {
            slow = slow->next;

            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }

            hasLoop = fast != nullptr && slow == fast;
        }

        return hasLoop;
    }

private:
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
};
