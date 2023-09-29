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
        Insert(length_, value);
    }

    template <typename... Args>
    void Prepend(T first, Args... rest)
    {
        Prepend(first);
        Prepend(rest...);
    }

    void Prepend(T value)
    {
        Insert(0, value);
    }

    void Insert(int index, T value)
    {
        if (index < 0 || (index > length_))
        {
            return;
        }

        Node* newNode = new Node(value);

        if (length_ == 0)
        {
            head_ = newNode;
            tail_ = newNode;
        }
        else if (index == length_)
        {
            tail_->next = newNode;
            newNode->previous = tail_;
            tail_ = newNode;
        }
        else
        {
            Node* targetNode = GetNode(index);
            if (targetNode)
            {
                Node* previousNode = targetNode->previous;
                if (previousNode)
                {
                    previousNode->next = newNode;
                    newNode->previous = previousNode;
                }
                else
                {
                    head_ = newNode;
                }

                newNode->next = targetNode;
                targetNode->previous = newNode;
            }
        }

        ++length_;
    }
    
    void Delete(int index)
    {
        if (index < 0 || (index >= length_))
        {
            return;
        }

        Node* targetNode = GetNode(index);
        if (targetNode)
        {
            if (length_ == 1)
            {
                head_ = nullptr;
                tail_ = nullptr;
            }
            else
            {
                if (!targetNode->next)
                {
                    tail_ = targetNode->previous;
                    tail_->next = nullptr;
                }
                else if (!targetNode->previous)
                {
                    head_ = targetNode->next;
                    head_->previous = nullptr;
                }
                else
                {
                    targetNode->previous->next = targetNode->next;
                    targetNode->next->previous = targetNode->previous;
                }
            }

            delete(targetNode);
            --length_;
        }
    }

    void DeleteLast()
    {
        Delete(length_ - 1);
    }

    void DeleteFirst()
    {
        Delete(0);
    }

    void Print()
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

    bool Set(int index, int value)
    {
        bool success = false;

        Node* targetNode = GetNode(index);
        if (targetNode)
        {
            targetNode->value = value;
            success = true;
        }

        return success;
    }

    // Interview question - Swap first and last
    //
    // Implement a member function called swapFirstLast() that swaps the values of the first and last
    // nodes in the list. If the length of the list is less than 2, the function should not perform
    // any operation.
    // 
    // Input:
    // The function is a member of the DoublyLinkedList class, which has a head and a tail pointer,
    // as well as a length attribute.
    //
    // Output:
    // No explicit output is returned. However, the function should modify the doubly linked list
    // such that the values of the first and last nodes are swapped.
    // 
    // Constraints:
    // The doubly linked list may be empty, have only one node, or have two or more nodes.
    // 
    // Example:
    // 
    // Consider the following doubly linked list:
    // 
    //     Head: 1
    //     Tail: 5
    //     Length: 5
    //      
    //     Doubly Linked List:
    //     1 <-> 2 <-> 3 <-> 4 <-> 5
    // 
    // After calling swapFirstLast(), the list should be:
    // 
    //     Head: 5
    //     Tail: 1
    //     Length: 5
    //      
    //     Doubly Linked List:
    //     5 <-> 2 <-> 3 <-> 4 <-> 1

    void SwapFirstLast()
    {
        if (length_ < 2)
        {
            return;
        }

        std::swap(head_->value, tail_->value);
    }

    // Interview question - Reverse list
    // Implement a member function called reverse() that reverses the order of the nodes in the list.
    //
    // Input:
    // The function is a member of the DoublyLinkedList class, which has a head and a tail pointer, 
    // as well as a length attribute.
    // 
    // Output:
    // No explicit output is returned. However, the function should modify the doubly linked list
    // such that the order of the nodes is reversed.
    // 
    // Constraints:
    // The doubly linked list may be empty, have only one node, or have two or more nodes.

    void Reverse()
    {
        if (length_ < 2)
        {
            return;
        }

        Node* currentNode = head_;
        Node* nextNode = nullptr;
        while (currentNode)
        {
            nextNode = currentNode->next;
            std::swap(currentNode->next, currentNode->previous);
            currentNode = nextNode;
        }

        std::swap(head_, tail_);
    }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int length_ = 0;
};

