#include "LinkedList.h"
#include <cmath>

using namespace std;

template <typename T>
void RunMiddleNodeTest(LinkedList<T>&& list)
{
    std::cout << std::endl << "Finding middle node in: ";
    list.Print();

    auto* middleNode = list.FindMiddleNode();
    if (middleNode)
    {
        std::cout << "Middle node: " << middleNode->value << std::endl;
    }
}

// Interview Question - Partition List
// Objective: You have a linked list where each node represents a binary digit (0 or 1).
// The goal of the binaryToDecimal function is to convert this binary number,
// represented by the linked list, into its decimal equivalent.
//
//Function Signature: int binaryToDecimal()

int BinaryToDecimal(LinkedList<char>& binaryList)
{
    int decimalValue = 0;
    int position = 0;
    int length = binaryList.GetLength() - 1;
    LinkedList<char>::Node* current = binaryList.GetNodeAtIndex(0);

    while (current)
    {
        decimalValue += current->value * (int)pow(2, length - position);

        current = current->next;
        ++position;
    }

    return decimalValue;
}

int main()
{
    {
        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();

        std::cout << "Prepending with 0" << std::endl;
        testList.Prepend(0);
        testList.Print();

        std::cout << "Reverse" << std::endl;
        testList.Reverse();
        testList.Print();

        std::cout << "Deleting last" << std::endl;
        testList.DeleteLast();
        testList.Print();

        std::cout << "Deleting 2" << std::endl;
        testList.DeleteNodeAtIndex(2);
        testList.Print();

        int numElements = testList.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting first element" << std::endl;
            testList.DeleteFirst();
            testList.Print();
        }

        LinkedList<char> testList2{'h', 'e', 'l', 'l', 'o'};
        testList2.Print();

        std::cout << "Inserting character" << std::endl;
        testList2.Insert(testList2.GetLength() - 1, 'o');
        testList2.Print();
        testList2.Insert(0, ' ');
        testList2.Print();
        testList2.Insert(0, 'y');
        testList2.Print();
        testList2.Insert(0, 'h');
        testList2.Print();
        testList2.Insert(0, 'W');
        testList2.Print();

        numElements = testList2.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting first element" << std::endl;
            testList2.DeleteNodeAtIndex(0);
            testList2.Print();
        }
    }

    {
        // Coding exercise - Find middle node
        RunMiddleNodeTest(LinkedList<int>{1, 2, 3, 4, 5});
        RunMiddleNodeTest(LinkedList<int>{1, 2, 3, 4, 5, 6});
        RunMiddleNodeTest(LinkedList<int>{1, 2});
        RunMiddleNodeTest(LinkedList<int>{1});
        RunMiddleNodeTest(LinkedList<int>{});
    }
    
    {
        // Coding exercise - Detect loop
        std::cout << "Running loop tests" << std::endl;
        LinkedList<int> testList2{1};
        testList2.Print();
        std::printf("List %s a loop \n", testList2.HasLoop() ? "has" : "does not have");

        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();
        std::printf("List %s a loop \n", testList.HasLoop() ? "has" : "does not have");

        std::cout << "Linking 3 to 2" << std::endl;
        LinkedList<int>::Node* thirdNode = testList.GetNodeAtIndex(2);
        LinkedList<int>::Node* secondNode = testList.GetNodeAtIndex(1);
        LinkedList<int>::Node* fourthNode = thirdNode->next;
        thirdNode->next = testList.GetNodeAtIndex(1);
        std::printf("List %s a loop \n", testList.HasLoop() ? "has" : "does not have");

        // Need to fix loop to prevent issues with deconstructor
        thirdNode->next = fourthNode;
    }

    {
        // Coding exercise - Find nth node from the end
        std::cout << std::endl;
        std::cout << "Running 'nth node' from the end tests" << std::endl;
        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();
        
        std::cout << "Retrieving 2cnd last node" << std::endl;
        LinkedList<int>::Node* returnedNode = testList.FindKthFromEnd(2);
        std::cout << "Returned node: " << (returnedNode ? std::to_string(returnedNode->value) : "Null") << std::endl;

        std::cout << "Retrieving 6th last node" << std::endl;
        returnedNode = testList.FindKthFromEnd(6);
        std::cout << "Returned node: " << (returnedNode ? std::to_string(returnedNode->value) : "Null") << std::endl;

        std::cout << "Retrieving 5th last node" << std::endl;
        returnedNode = testList.FindKthFromEnd(5);
        std::cout << "Returned node: " << (returnedNode ? std::to_string(returnedNode->value) : "Null") << std::endl;

        std::cout << "Retrieving last node" << std::endl;
        returnedNode = testList.FindKthFromEnd(1);
        std::cout << "Returned node: " << (returnedNode ? std::to_string(returnedNode->value) : "Null") << std::endl;
    }

    {
        // Coding exercise - partition list
        std::cout << std::endl;
        std::cout << "Running partition test" << std::endl;
        LinkedList<int> testList{1,4,3,2,5,2};
        testList.Print();

        std::cout << "Partitioning list around a value of '3'" << std::endl;
        testList.PartitionList(3);
        testList.Print();

        std::cout << std::endl;
        std::cout << "Running partition test" << std::endl;
        LinkedList<int> testList2{1,4,3,2,5,2};
        testList2.Print();

        std::cout << "Partitioning list around a value of '0'" << std::endl;
        testList2.PartitionList(0);
        testList2.Print();
    }

    {
        // Coding exercise - remove duplicates
        std::cout << std::endl;
        std::cout << "Running duplicates test" << std::endl;
        LinkedList<int> testList{1,2,3,2,4,5,3};
        testList.Print();

        std::cout << "Removing duplicates" << std::endl;
        testList.RemoveDuplicates();
        testList.Print();

        LinkedList<int> testList2{1,1,3,4,4,5,3};
        testList2.Print();

        std::cout << "Removing duplicates" << std::endl;
        testList2.RemoveDuplicates();
        testList2.Print();
    }

    {
        // Coding exercise - binary to decimal
        std::cout << std::endl;
        std::cout << "Running binary to decimal test" << std::endl;
        LinkedList<char> testList{1,0,1,1};
        testList.Print();

        std::cout << "Converted to binary: " << BinaryToDecimal(testList) << std::endl;
    }

    {
        // Coding exercise - reverse between
        std::cout << std::endl;
        std::cout << "Running reverse between test" << std::endl;
        LinkedList<int> testList{1,2,3,4};
        testList.Print();

        std::cout << "Reversing between indices 1 to 2: " << std::endl;
        testList.ReverseBetween(1, 2);
        testList.Print();

        std::cout << "Reversing between indices 0 to 3: " << std::endl;
        testList.ReverseBetween(0, 3);
        testList.Print();

        std::cout << "Reversing between indices 0 to 1: " << std::endl;
        testList.ReverseBetween(0, 1);
        testList.Print();
    }

    return 0;
}
