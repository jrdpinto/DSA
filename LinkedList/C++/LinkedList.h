#pragma once
#include <iostream>
#include <sstream>
#include <initializer_list>
#include <cassert>

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
            }
        }

        tail_ = newNode;

        ++length_;
    }

    void Prepend(T value)
    {
        Insert(0, value);
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

    void DeleteLast()
    {
        DeleteNodeAtIndex(length_ - 1);
    }

    void DeleteFirst()
    {
        DeleteNodeAtIndex(0);
    }

    void DeleteNodeAtIndex(int index)
    {
        Node* previous = nullptr;
        Node* target = GetNode(index, previous);

        DeleteNode(target, previous);
    }

    void DeleteNode(Node* target, Node* previous)
    {
        if (target)
        {
            Node* next = target->next;

            // Ensure that head and tail are updated
            if (target == head_)
            {
                head_ = next;
            }

            if (target == tail_)
            {
                tail_ = previous;
            }

            delete(target);
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
        while (currentNode)
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

    // Interview question - Reverse between
    // Implement the reverseBetween member function for the LinkedList class, which reverses the nodes
    // of the list from the indexes m to n (the positions are 0-indexed).
    //
    // Function Signature: void reverseBetween(int m, int n)
    //
    // Example:
    // Consider the following singly linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    //
    // For the given list, the function ll.reverseBetween(1, 3) should modify the list to be:
    // 1 -> 4 -> 3 -> 2 -> 5 -> nullptr
    // 
    // The sublist from the indexes from 1 to 3 has been reversed.

    void ReverseBetween(int m, int n)
    {
        if (length_ <= 1 || n >= length_ || m >= length_ || n - m < 1)
        {
            return;
        }

        Node* nodeBeforeStartIndex = nullptr;
        Node* nodeAtStartIndex = GetNode(m, nodeBeforeStartIndex);

        if (!nodeAtStartIndex)
        {
            return;
        }

        Node* currentNode = nodeAtStartIndex;
        Node* previousNode = nodeBeforeStartIndex;
        Node* nextNode = nullptr;

        int currentIndex = m;
        while (currentNode && currentIndex <= n)
        {
            nextNode = currentNode->next;
            currentNode->next = previousNode;

            // Move down the list
            previousNode = currentNode;
            currentNode = nextNode;

            ++currentIndex;
        }

        // Update the start node and the node before it to ensure that they point to the correct
        // nodes in the list.
        if (nodeBeforeStartIndex)
        {
            nodeBeforeStartIndex->next = previousNode;
        }
        else
        {
            // If there is no node before the start index, the end index is now the head
            head_ = previousNode;
        }

        // If there is no node following the last node in the sequence, this node becomes the tail
        nodeAtStartIndex->next = nextNode;
        if (!nextNode)
        {
            tail_ = nodeAtStartIndex;
        }
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

    // Interview Question - Find Kth Node From End
    // 
    // Implement the findKthFromEnd member function for the LinkedList class, which returns the k-th node
    // from the end of the linked list WITHOUT USING THE LENGTH of the list.
    // 
    // If the value of k is greater than the length of the list, the function should return nullptr.
    // 
    // Function signature:
    // 
    // Node* findKthFromEnd(int k)
    // 
    // Example:
    // 
    // Consider the following singly linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    // For the given list, the function ll.findKthFromEnd(2) should return the node with value 4, as it
    // is the 2nd node from the end of the list.

    Node* FindKthFromEnd(int k)
    {
        if (k < 1 || head_ == nullptr)
        {
            return nullptr;
        }

        Node* target = head_;
        Node* lookAhead = target;
        int requiredDistanceBetweenNodes = k - 1;

        int distanceBetweenNodes = 0;
        while (lookAhead->next)
        {
            if (distanceBetweenNodes < requiredDistanceBetweenNodes)
            {
                lookAhead = lookAhead->next;
                ++distanceBetweenNodes;

                // If we have reached the end of the list and we do not have the
                // required distance between nodes, the list is shorter than the
                // requested node.
                if (!lookAhead->next && distanceBetweenNodes < requiredDistanceBetweenNodes)
                {
                    target = nullptr;
                }
            }
            else
            {
                target = target->next;
                lookAhead = lookAhead->next;
            }
        }

        return target;
    }


    // Interview Question - Partition List
    //
    // Implement the partitionList member function for the LinkedList class, which partitions the list such
    // that all nodes with values less than x come before nodes with values greater than or equal to x.
    //
    // Note: This linked list class does NOT have a tail which will make this method easier to implement.
    //
    // The original relative order of the nodes should be preserved.
    //
    // Function Signature:
    // 
    // void partitionList(int x)
    // 
    // Example:
    // 
    // Consider the following singly linked list:
    // 
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2 -> nullptr
    // 
    // For the given list, the function ll.partitionList(3) should modify the list to be:
    // 
    // 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> nullptr
    // 
    // All nodes with values less than 3 come before nodes with values greater than or equal to 3, and their
    // original relative order is preserved.

    void PartitionList(T x)
    {
        Node* left = nullptr;
        Node* leftHead = nullptr;
        Node* right = nullptr;
        Node* rightHead = nullptr;
        
        Node* currentNode = head_;
        while (currentNode)
        {
            if (currentNode->value < x)
            {
                if (left)
                {
                    left->next = currentNode;
                    left = left->next;
                }
                else
                {
                    left = currentNode;
                    leftHead = left;
                }
            }
            else
            {
                if (right)
                {
                    right->next = currentNode;
                    right = right->next;
                }
                else
                {
                    right = currentNode;
                    rightHead = right;
                }
            }

            currentNode = currentNode->next;
        }

        // Merge lists if required and update head (and tail)
        if (leftHead || rightHead)
        {
            head_ = leftHead ? leftHead : rightHead;
            
            if (left)
            {
                if (rightHead)
                {
                    left->next = rightHead;
                    tail_ = right;
                }
                else
                {
                    tail_ = left;
                }
            }
            else if (right)
            {
                tail_ = right;
            }

            tail_->next = nullptr;
        }
    }

    // Interview Question - Remove duplicates
    //
    // Implement the removeDuplicates member function for the LinkedList class, which removes all
    // duplicate values from a singly linked list. The function should preserve the original order
    // of the non-duplicate elements.
    // 
    // Note: This linked list class does NOT have a tail which will make this method easier to implement.
    // 
    // Function Signature:
    // 
    // void removeDuplicates()
    //
    // Example:
    // Consider the following singly linked list:
    // 1 -> 2 -> 3 -> 2 -> 4 -> 5 -> 3 -> nullptr
    // 
    // For the given list, after calling the function ll.removeDuplicates(), the list should be modified to be:
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    // 
    // All duplicate values have been removed, and the remaining elements maintain their original order.

    void RemoveDuplicates()
    {
        Node* current = head_;

        while (current)
        {
            Node* scanner = current->next;
            Node* previous = current;

            while (scanner)
            {
                if (current->value == scanner->value)
                {
                    Node* next = scanner->next;

                    DeleteNode(scanner, previous);
                    scanner = next;
                }
                else
                {
                    previous = scanner;
                    scanner = scanner->next;
                }
            }

            current = current->next;
        }
    }

    // Interview Question - Bubble Sort (Linked List)
    // Source: C++ Data Structures & Algorithms + LEETCODE Exercises
    // https://www.udemy.com/course/data-structures-algorithms-cpp/learn/quiz/6025584#overview
    // 
    // In this exercise, you will implement a method to sort a singly linked list using the Bubble
    // Sort algorithm. The goal is to sort the linked list in ascending order without creating any 
    // new nodes. You will only rearrange the value fields of the existing nodes.
    // Constraints: Do not create new nodes; only change the value fields of existing nodes.

    void BubbleSort()
    {
        std::cout << "Bubble sort" << std::endl;

        for (int i = 0; i < length_; ++i)
        {
            Node* currentNode = head_;
            Node* prev = nullptr;

            // Iterate until the second last node
            while (currentNode->next)
            {
                Node* nextNode = currentNode->next;
                if (currentNode->value > nextNode->value)
                {
                    currentNode->next = nextNode->next;
                    nextNode->next = currentNode;

                    if (prev)
                    {
                        prev->next = nextNode;
                    }
                    else
                    {
                        // Head has changed
                        head_ = nextNode;
                    }

                    prev = nextNode;

                    if (currentNode->next == nullptr)
                    {
                        tail_ = currentNode;
                    }
                }
                else
                {
                    prev = currentNode;
                    currentNode = currentNode->next;
                }
            }
        }
    }

    // Interview Question - Selection Sort (Linked List)
    // Source: C++ Data Structures & Algorithms + LEETCODE Exercises
    // https://www.udemy.com/course/data-structures-algorithms-cpp/learn/quiz/6025586#content 
    // 
    // Implement the selectionSort() method to sort a singly linked list using the Selection Sort algorithm.
    // The goal is to sort the linked list in ascending order, but you can only change the value fields of 
    // the existing nodes. 

    void SelectionSort()
    {
        std::cout << "Selection sort" << std::endl;

        Node* currentNode = head_;
        while(currentNode)
        {
            Node* minNode = currentNode;
            Node* nextNode = currentNode->next;

            while(nextNode)
            {
                if (nextNode->value < minNode->value)
                {
                    minNode = nextNode;
                }

                nextNode = nextNode->next;
            }

            if (currentNode != minNode)
            {
                std::swap(currentNode->value, minNode->value);
            }

            currentNode = currentNode->next;
        }
    }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int length_ = 0;

    Node* GetNode(int index, Node*& previousNode)
    {
        Node* node = nullptr;
        previousNode = nullptr;

        assert(index < length_);
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
